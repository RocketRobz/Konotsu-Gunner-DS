#include <nds.h>
#include <fat.h>
#include <stdio.h>
#include <sys/stat.h>
#include <limits.h>

#include <string.h>
#include <unistd.h>
#include <maxmod9.h>
#include "gl2d.h"

#include "graphics/graphics.h"

#include "graphics/fontHandler.h"

#include "logos.h"
#include "mainmenu.h"
#include "player.h"
#include "level.h"

#include "soundbank.h"
#include "soundbank_bin.h"

bool useTwlCfg = false;
int language = 0;

bool wideScreen = false;
bool fadeType = false;				// false = out, true = in
bool fadeColor = true;
int screenMode = 0;

static mm_sound_effect snd_GUNSHT;
static mm_sound_effect snd_AMMOOUT;
static mm_sound_effect snd_HURT;

void InitSound() {
	mmInitDefaultMem((mm_addr)soundbank_bin);
	
	mmLoadEffect( SFX_GUNSHT );
	mmLoadEffect( SFX_AMMOOUT );
	mmLoadEffect( SFX_HURT );

	snd_GUNSHT = {
		{ SFX_GUNSHT } ,			// id
		(int)(1.0f * (1<<10)),	// rate
		0,		// handle
		255,	// volume
		128,	// panning
	};

	snd_AMMOOUT = {
		{ SFX_AMMOOUT } ,			// id
		(int)(1.0f * (1<<10)),	// rate
		0,		// handle
		255,	// volume
		128,	// panning
	};

	snd_HURT = {
		{ SFX_HURT } ,			// id
		(int)(1.0f * (1<<10)),	// rate
		0,		// handle
		255,	// volume
		128,	// panning
	};

	mmLoad(MOD_THMA);
	mmLoad(MOD_ALTIT);
	mmSetModuleVolume(500);
}

void playPromiseMusic() {
	mmStart(MOD_THMA, MM_PLAY_LOOP);
}

void playAltitMusic() {
	mmStart(MOD_ALTIT, MM_PLAY_LOOP);
}

void sndShoot() {
	mmEffectEx(&snd_GUNSHT);
}

void sndAmmoOut() {
	mmEffectEx(&snd_AMMOOUT);
}

void sndHurt() {
	mmEffectEx(&snd_HURT);
}

//---------------------------------------------------------------------------------
void stop (void) {
//---------------------------------------------------------------------------------
	while (1) {
		swiWaitForVBlank();
	}
}

//---------------------------------------------------------------------------------
void doPause(int x, int y) {
//---------------------------------------------------------------------------------
	// iprintf("Press start...\n");
	printSmall(false, x, y, "Press start...");
	while(1) {
		scanKeys();
		if(keysDown() & KEY_START)
			break;
	}
	scanKeys();
}

//---------------------------------------------------------------------------------
int main(int argc, char **argv) {
//---------------------------------------------------------------------------------

	defaultExceptionHandler();

	useTwlCfg = (isDSiMode() && (*(u8*)0x02000400 & 0x0F) && (*(u8*)0x02000404 == 0));
	wideScreen = (strcmp(argv[1], "wide") == 0);

	language = (useTwlCfg ? *(u8*)0x02000406 : PersonalData->language);

	//fatInitDefault();

	InitSound();	
	graphicsInit();
	fontInit();

	initPlayers(2);

	while (1) {
		clearText();
		switch (screenMode) {
			case 0:
			default:
				logoScreen();
				break;
			case 1:
				menuScreen();
				break;
			case 2:
				levelMode();
				break;
		}
		swiWaitForVBlank();
		oamUpdate(&oamSub);
	}

	return 0;
}
