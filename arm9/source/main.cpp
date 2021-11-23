#include <nds.h>
#include <fat.h>
#include <stdio.h>
#include <sys/stat.h>
#include <limits.h>

#include <string.h>
#include <unistd.h>
#include "gl2d.h"

#include "graphics/graphics.h"
#include "graphics/fontHandler.h"
#include "sound.h"
#include "myDSiMode.h"
#include "nitrofs.h"

#include "logos.h"
#include "mainmenu.h"
#include "player.h"
#include "level.h"

bool useTwlCfg = false;
u32* twlCfgPointer = (u32*)0x02FFFDFC;
u8* twlCfgAddr = (u8*)0;
int language = 0;

bool wideScreen = false;
bool fadeType = false;				// false = out, true = in
bool fadeColor = true;
int screenMode = 0;

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

	bool fatInited = fatInitDefault();
	bool nitroInited = nitroFSInit(argv[0]);
	if (!fatInited && !nitroInited) {
		consoleDemoInit();
		iprintf("fatInitDefault failed!");
		stop();
	}

	if (dsiFeatures()) {
		if (*twlCfgPointer < 0x02000000 || *twlCfgPointer >= 0x03000000) {
			*twlCfgPointer = 0x02000400;
		}
		twlCfgAddr = (u8*)*twlCfgPointer;
		useTwlCfg = ((twlCfgAddr[0] != 0) && (twlCfgAddr[1] == 0) && (twlCfgAddr[2] == 0) &&
					 (twlCfgAddr[4] == 0));
	}
	wideScreen = (strcmp(argv[1], "wide") == 0);

	language = (useTwlCfg ? twlCfgAddr[6] : PersonalData->language);

	snd();	
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
		snd().updateStream();
	}

	return 0;
}
