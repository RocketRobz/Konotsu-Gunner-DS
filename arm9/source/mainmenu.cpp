#include <nds.h>
#include "gl2d.h"
#include <maxmod9.h>

#include "graphics/graphics.h"
#include "graphics/fontHandler.h"

#include "logo_title.h"
#include "buttn_battle.h"
#include "buttn_create.h"

extern bool fadeType;
extern int screenMode;

static bool inited = false;

static int bgYpos = 0;

static touchPosition touch;

static int titleTexID, battleTexID, createTexID;

extern glImage tileImage[(128 / 16) * (128 / 16)];
static glImage titleImage[(256 / 32) * (192 / 32)];
static glImage battleImage[64 * 64];
static glImage createImage[64 * 64];

void menuGraphicLoad(void) {
	titleTexID = glLoadTileSet(titleImage, // pointer to glImage array
							32, // sprite width
							32, // sprite height
							256, // bitmap width
							192, // bitmap height
							GL_RGB16, // texture type for glTexImage2D() in videoGL.h
							TEXTURE_SIZE_256, // sizeX for glTexImage2D() in videoGL.h
							TEXTURE_SIZE_256, // sizeY for glTexImage2D() in videoGL.h
							TEXGEN_OFF | GL_TEXTURE_COLOR0_TRANSPARENT, // param for glTexImage2D() in videoGL.h
							4, // Length of the palette to use (16 colors)
							(u16*) logo_titlePal, // Load our 16 color tiles palette
							(u8*) logo_titleBitmap // image data generated by GRIT
							);

	battleTexID = glLoadTileSet(battleImage, // pointer to glImage array
							64, // sprite width
							64, // sprite height
							64, // bitmap width
							64, // bitmap height
							GL_RGB16, // texture type for glTexImage2D() in videoGL.h
							TEXTURE_SIZE_64, // sizeX for glTexImage2D() in videoGL.h
							TEXTURE_SIZE_64, // sizeY for glTexImage2D() in videoGL.h
							TEXGEN_OFF, // param for glTexImage2D() in videoGL.h
							16, // Length of the palette to use (16 colors)
							(u16*) buttn_battlePal, // Load our 16 color tiles palette
							(u8*) buttn_battleBitmap // image data generated by GRIT
							);

	createTexID = glLoadTileSet(createImage, // pointer to glImage array
							64, // sprite width
							64, // sprite height
							64, // bitmap width
							64, // bitmap height
							GL_RGB16, // texture type for glTexImage2D() in videoGL.h
							TEXTURE_SIZE_64, // sizeX for glTexImage2D() in videoGL.h
							TEXTURE_SIZE_64, // sizeY for glTexImage2D() in videoGL.h
							TEXGEN_OFF, // param for glTexImage2D() in videoGL.h
							16, // Length of the palette to use (16 colors)
							(u16*) buttn_createPal, // Load our 16 color tiles palette
							(u8*) buttn_createBitmap // image data generated by GRIT
							);
}

void menuGraphicUnload(void) {
	glDeleteTextures(1, &titleTexID);
	glDeleteTextures(1, &battleTexID);
	glDeleteTextures(1, &createTexID);
}

void menuScreen(void) {
	if (!inited) {
		menuGraphicLoad();
		fadeType = true;
		inited = true;
	}

	//printLargeCentered(false, 96, "Press START to play");

	touchRead(&touch);
	scanKeys();
	int pressed = keysDown();
	
	if (pressed & KEY_TOUCH) {
		if (touch.py >= 64 && touch.py < 64+64) {
			if (touch.px >= 32 && touch.px < 32+64) {
				fadeType = false;
				while (!screenFadedOut());
				menuGraphicUnload();
				screenMode = 2;
			}
		}
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

	glSprite(32, 64, GL_FLIP_NONE, battleImage);
	glSprite(160, 64, GL_FLIP_NONE, createImage);

	bgYpos--;
	if (bgYpos < -8) bgYpos = 0;
}
