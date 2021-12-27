#pragma once
#include<Windows.h>
#include<iostream>
#include<conio.h>

#define UP 72
#define DOWN 80
#define ENTER 13

#define COLS 156
#define LINE 50

namespace gets {
	int getCOLS() {
		return COLS;
	}
	int getLINE() {
		return LINE;
	}
}

void gotoXY(int x, int y) { // change console output position
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void CursorView() {
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1; // cursor size option
	cursorInfo.bVisible = false; // cursor visible True, False
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

int keyboardInput() {
	char key;
	while (1) {
		if (_kbhit()) {
			key = _getch();
			if (key == -32) {
				key = _getch();
				switch (key)
				{
				case UP:
					return -1;
				case DOWN:
					return 1;
				default:
					return 0;
					break;
				}
			}
			else {
				if (key == ENTER) {
					return 10;
				}
			}
		}
	}
}