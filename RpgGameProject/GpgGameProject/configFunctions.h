#pragma once
#include<Windows.h>
#include<fstream>
#include<iostream>
#include<string>
#include<vector>
#include<conio.h>

using namespace std;

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

int calculateCenter(int size) {
	return COLS / 2 - (size / 2);
}

void printFileContent(string filePath, int y) {
	ifstream ifs(filePath);
	if (ifs.fail()) {
		cout << "Error : The file could not be opened by ";
		return;
	}

	// Separate each area of content
	string fileContent = "";
	vector<string> eachLineOfContent;
	char c;
	while (ifs.get(c)) {
		fileContent += c;
		if (c == '\n') {
			eachLineOfContent.push_back(fileContent);
			fileContent = "";
		}
	}
	eachLineOfContent.push_back(fileContent);
	for (int i = 0; i < eachLineOfContent.size(); i++) {
		int center = calculateCenter(eachLineOfContent[i].size());
		gotoXY(center, y + i);
		cout << eachLineOfContent[i];
	}
}