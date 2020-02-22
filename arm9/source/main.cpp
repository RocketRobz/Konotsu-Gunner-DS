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

#include "player.h"
#include "level.h"

#include "soundbank.h"
#include "soundbank_bin.h"

bool fadeType = true;				// false = out, true = in

//mm_sound_effect mus_ALTIT;

void InitSound() {
	mmInitDefaultMem((mm_addr)soundbank_bin);
	
	/*mmLoadEffect( MOD_ALTIT );

	mus_ALTIT = {
		{ MOD_ALTIT } ,			// id
		(int)(1.0f * (1<<10)),	// rate
		0,		// handle
		255,	// volume
		128,	// panning
	};*/

	mmLoad(MOD_ALTIT);
	mmSetModuleTempo(0x390);
	mmStart(MOD_ALTIT, MM_PLAY_LOOP);
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

	//fatInitDefault();

	InitSound();	
	graphicsInit();
	playerGraphicLoad();
	fontInit();

	setPlayerPosition(128, 0);

	while (1) {
		clearText();
		levelMode();
		swiWaitForVBlank();
	}

	return 0;
}
