#include <nds.h>
#include "gl2d.h"
#include <maxmod9.h>

#include "graphics/graphics.h"
#include "graphics/fontHandler.h"

extern bool fadeType;
extern int screenMode;

static bool inited = false;

static int bgYpos = 0;

extern glImage tileImage[(128 / 16) * (128 / 16)];
extern glImage titleImage[(256 / 32) * (192 / 32)];

void menuScreen(void) {
	if (!inited) {
		inited = true;
		fadeType = true;
	}

	printLargeCentered(false, 96, "Press START to play");

	scanKeys();
	int pressed = keysDown();
	
	if (pressed & KEY_START) {
		fadeType = false;
		while (!screenFadedOut());
		screenMode = 2;
	}
}

void renderMenuTop(void) {
	for (int x = 0; x < 16; x++) {
		for (int y = 0; y < 13; y++) {
			glSprite((x*16), (y*16)+bgYpos, GL_FLIP_NONE, &tileImage[1]);
		}
	}
	for (int x = 0; x < 8; x++) {
		for (int y = 0; y < 6; y++) {
			glSprite(x*32, y*32, GL_FLIP_NONE, &titleImage[(y*8)+x]);
		}
	}
}

void renderMenuBottom(void) {
	for (int x = 0; x < 16; x++) {
		for (int y = 0; y < 13; y++) {
			glSprite((x*16), (y*16)+bgYpos, GL_FLIP_NONE, &tileImage[1]);
		}
	}

	bgYpos--;
	if (bgYpos < -8) bgYpos = 0;
}
