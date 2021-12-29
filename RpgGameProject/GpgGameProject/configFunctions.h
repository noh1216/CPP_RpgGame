#pragma once
#include<Windows.h>
#include<iostream>
#include<conio.h>


// This section defines the functions used throughout the program
// Function to define : gotoXY, CursorView, keyboard input, calculate center position
// Data preprocessing : keyboard ascii codes Up Down Enter, 
//						screen size COLS(width) LINE(height), reserved memory


// Ascii codes
#define UP 72
#define DOWN 80
#define ENTER 13

// screen size
#define COLS 156
#define LINE 50

// preSizing
#define COMMAND_SIZE 256

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
				return 10;
			}
		}
	}
}

int* calculateCenter(int wSize, int hSize) {
	int *centerPos=new int[2];
	centerPos[0] = COLS / 2 - (wSize / 2);
	centerPos[1] = LINE / 2 - (hSize / 2);
	return centerPos;
}
