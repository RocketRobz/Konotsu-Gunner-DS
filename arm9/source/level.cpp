#include <nds.h>
#include "gl2d.h"
#include <maxmod9.h>

#include "graphics/fontHandler.h"
#include "graphics/graphics.h"

#include "bottomImage.h"
#include "tiles.h"

#define bgTile 11
#define grayBlockTile 17

static int floorXpos = 0;

static int bottomTexID, tileTexID;
static glImage bottomImage[(256 / 32) * (192 / 32)];
static glImage tileImage[(128 / 16) * (128 / 16)];

//extern mm_sound_effect snd_jump;

void levelGraphicLoad(void) {
	bottomTexID = glLoadTileSet(bottomImage, // pointer to glImage array
							32, // sprite width
							32, // sprite height
							256, // bitmap width
							192, // bitmap height
							GL_RGB16, // texture type for glTexImage2D() in videoGL.h
							TEXTURE_SIZE_256, // sizeX for glTexImage2D() in videoGL.h
							TEXTURE_SIZE_256, // sizeY for glTexImage2D() in videoGL.h
							TEXGEN_OFF, // param for glTexImage2D() in videoGL.h
							4, // Length of the palette to use (16 colors)
							(u16*) bottomImagePal, // Load our 16 color tiles palette
							(u8*) bottomImageBitmap // image data generated by GRIT
							);

	tileTexID = glLoadTileSet(tileImage, // pointer to glImage array
							16, // sprite width
							16, // sprite height
							128, // bitmap width
							128, // bitmap height
							GL_RGB16, // texture type for glTexImage2D() in videoGL.h
							TEXTURE_SIZE_128, // sizeX for glTexImage2D() in videoGL.h
							TEXTURE_SIZE_128, // sizeY for glTexImage2D() in videoGL.h
							GL_TEXTURE_WRAP_S | GL_TEXTURE_WRAP_T | TEXGEN_OFF | GL_TEXTURE_COLOR0_TRANSPARENT, // param for glTexImage2D() in videoGL.h
							16, // Length of the palette to use (16 colors)
							(u16*) tilesPal, // Load our 16 color tiles palette
							(u8*) tilesBitmap // image data generated by GRIT
							);
}

void levelMode(void) {
	scanKeys();
	int pressed = keysDown();
}

void levelGraphicDisplay(void) {
	glBoxFilled(0, 0, 256, 192, RGB15(255/8, 255/8, 255/8));
	for (int x = 0; x < 256; x += 16) {
		for (int y = 0; y < 192; y += 16) {
			glSprite(x, y, GL_FLIP_NONE, &tileImage[bgTile]);
		}
	}
	for (int floorRenderCount = 0; floorRenderCount < 256; floorRenderCount += 16) {
		glSprite(floorRenderCount+floorXpos, 176, GL_FLIP_NONE, &tileImage[grayBlockTile]);
	}
}

void levelGraphicBottomDisplay(void) {
	for (int x = 0; x < 8; x++) {
		for (int y = 0; y < 6; y++) {
			glSprite(x*32, y*32, GL_FLIP_NONE, &bottomImage[(y*8)+x]);
		}
	}
}
