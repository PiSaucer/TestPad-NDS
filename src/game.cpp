#include <nds.h>
#include <stdio.h>

void clear_btn_line() {
	iprintf("\x1b[6;0H                              \x1b[39m\n");
}
	
int main(void) {
	touchPosition touchXY;

	PrintConsole topScreen;
	PrintConsole bottomScreen;

	videoSetMode(MODE_0_2D);
	videoSetModeSub(MODE_0_2D);

	vramSetBankA(VRAM_A_MAIN_BG);
	vramSetBankC(VRAM_C_SUB_BG);

	consoleInit(&topScreen, 3,BgType_Text4bpp, BgSize_T_256x256, 31, 0, true, true);
	consoleInit(&bottomScreen, 3,BgType_Text4bpp, BgSize_T_256x256, 31, 0, false, true);

	consoleSelect(&topScreen);
	iprintf("\x1b[2;12HTestPad\n");
	iprintf("\x1b[4;9H\x1b[32mpisaucer.com\x1b[39m\n");
	iprintf("\x1b[6;9H\x1b[32;1mPress Any Key\x1b[39m\n");
 
	while(1) {
		swiWaitForVBlank();

		scanKeys();
		unsigned int keys = keysDown();

		consoleSelect(&topScreen);
		if (keys & KEY_START) {
			clear_btn_line();
			iprintf("\x1b[6;7H\x1b[32;1mSTART was pressed.\x1b[39m\n");
		} else if (keys & KEY_SELECT) {
			clear_btn_line();
			iprintf("\x1b[6;6H\x1b[32;1mSELECT was pressed.\x1b[39m\n");
		} else if (keys & KEY_A) {
			clear_btn_line();
			iprintf("\x1b[6;9H\x1b[32;1mA was pressed.\x1b[39m\n");
		} else if (keys & KEY_B) {
			clear_btn_line();
			iprintf("\x1b[6;9H\x1b[32;1mB was pressed.\x1b[39m\n");
		} else if (keys & KEY_X) {
			clear_btn_line();
			iprintf("\x1b[6;9H\x1b[32;1mX was pressed.\x1b[39m\n");
		} else if (keys & KEY_Y) {
			clear_btn_line();
			iprintf("\x1b[6;9H\x1b[32;1mY was pressed.\x1b[39m\n");
		} else if (keys & KEY_L) {
			clear_btn_line();
			iprintf("\x1b[6;9H\x1b[32;1mL was pressed.\x1b[39m\n");
		} else if (keys & KEY_R) {
			clear_btn_line();
			iprintf("\x1b[6;9H\x1b[32;1mR was pressed.\x1b[39m\n");
		} else if (keys & KEY_UP) {
			clear_btn_line();
			iprintf("\x1b[6;9H\x1b[32;1mUP was pressed.\x1b[39m\n");
		} else if (keys & KEY_DOWN) {
			clear_btn_line();
			iprintf("\x1b[6;7H\x1b[32;1mDOWN was pressed.\x1b[39m\n");
		} else if (keys & KEY_LEFT) {
			clear_btn_line();
			iprintf("\x1b[6;7H\x1b[32;1mLEFT was pressed.\x1b[39m\n");
		} else if (keys & KEY_RIGHT) {
			clear_btn_line();
			iprintf("\x1b[6;7H\x1b[32;1mRIGHT was pressed.\x1b[39m\n");
		} else if (keys & KEY_TOUCH) {
			clear_btn_line();
			iprintf("\x1b[6;7H\x1b[32;1mTOUCH was pressed.\x1b[39m\n");
		} else if (keys & KEY_LID) {
			clear_btn_line();
			iprintf("\x1b[6;9H\x1b[32;1mPress Any Key\x1b[39m\n");
		}

		// Read the touch screen and print the results on the bottom screen
		touchRead(&touchXY);
		consoleSelect(&bottomScreen);
		iprintf("\x1b[0;0HTouch x = %04X, %04X\n", touchXY.rawx, touchXY.px);
		iprintf("Touch y = %04X, %04X\n", touchXY.rawy, touchXY.py);
	}

	return 0;
}