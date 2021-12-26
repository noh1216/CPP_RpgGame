#pragma once

#include <iostream>
#include<Windows.h>

using namespace std;

void gotoXY(int x, int y);
int printMenu();

// function define
void gotoXY(int x, int y) { // change console output position
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int printMenu() {
	system("cls");
	int input;
	gotoXY(3, 10);
	cout << "1 - start adventure";
	gotoXY(3, 15);
	cout << "2 - loading data";
	gotoXY(3, 20);
	cout << "3 - menual";
	gotoXY(0, 49);
	cout << "input : ";
	cin >> input;
	return input;
}
