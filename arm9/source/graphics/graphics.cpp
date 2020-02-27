#include <nds.h>
#include "gl2d.h"
#include "FontGraphic.h"

#include "graphics.h"
#include "fontHandler.h"

#include "../logos.h"
#include "../mainmenu.h"
#include "../level.h"

extern bool fadeType;
extern bool fadeColor;
extern int screenMode;
static int screenBrightness = 25;

int bg3;
u16* gfxSub;

bool screenFadedIn(void) { return (screenBrightness == 0); }

bool screenFadedOut(void) { return (screenBrightness > 24); }

// Ported from PAlib (obsolete)
static void SetBrightness(u8 screen, s8 bright) {
	u16 mode = 1 << 14;

	if (bright < 0) {
		mode = 2 << 14;
		bright = -bright;
	}
	if (bright > 31)
		bright = 31;
	*(u16*)(0x0400006C + (0x1000 * screen)) = bright + mode;
}

static void vBlankHandler()
{
	if(fadeType == true) {
		screenBrightness--;
		if (screenBrightness < 0) screenBrightness = 0;
	} else {
		screenBrightness++;
		if (screenBrightness > 25) screenBrightness = 25;
	}
	SetBrightness(0, fadeColor ? screenBrightness : -screenBrightness);
	SetBrightness(1, fadeColor ? screenBrightness : -screenBrightness);

	glBegin2D();
	{
		switch (screenMode) {
			case 0:
			default:
				renderLogo();
				break;
			case 1:
				renderMenuTop();
				break;
			case 2:
				levelGraphicDisplay();
				break;
		}
		updateText(true);
		glColor(RGB15(31, 31, 31));
	}
	glEnd2D();
	GFX_FLUSH = 0;
}

void graphicsInit()
{
	*(u16*)(0x0400006C) |= BIT(14);
	*(u16*)(0x0400006C) &= BIT(15);
	SetBrightness(0, 31);
	SetBrightness(1, 31);
	
	////////////////////////////////////////////////////////////
	videoSetMode(MODE_5_3D);
	videoSetModeSub(MODE_5_2D);

	// Initialize OAM to capture 3D scene
	//initSubSprites();

	// The sub background holds the top image when 3D directed to bottom
	//bgInitSub(3, BgType_Bmp16, BgSize_B16_256x256, 0, 0);

	// Initialize GL in 3D mode
	glScreen2D();

	// Clear the GL texture state
	glResetTextures();

	// Set up enough texture memory for our textures
	// Bank A is just 128kb and we are using 194 kb of
	// sprites
	vramSetBankA(VRAM_A_TEXTURE);
	vramSetBankB(VRAM_B_TEXTURE);
	vramSetBankC(VRAM_C_SUB_BG);
	vramSetBankD(VRAM_D_SUB_SPRITE);
	vramSetBankE(VRAM_E_TEX_PALETTE);
	vramSetBankF(VRAM_F_TEX_PALETTE_SLOT4);
	vramSetBankG(VRAM_G_TEX_PALETTE_SLOT5); // 16Kb of palette ram, and font textures take up 8*16 bytes.
	//vramSetBankH(VRAM_H_SUB_BG_EXT_PALETTE);
	//vramSetBankI(VRAM_I_SUB_SPRITE_EXT_PALETTE);
	
	bg3 = bgInitSub(3, BgType_Bmp16,    BgSize_B16_256x256, 1, 0);
	oamInit(&oamSub, SpriteMapping_1D_32, false);

	// initialize rotate, scale, and scroll
	bgSetRotateScale(bg3, 0, 1<<8, 1<<8);
	bgSetScroll(bg3, 0, 0);

	levelGraphicLoad();

	irqSet(IRQ_VBLANK, vBlankHandler);
	irqEnable(IRQ_VBLANK);
}
