#pragma once

#include <iostream>
#include<fstream>
#include<Windows.h>

using namespace std;

void gotoXY(int x, int y);
int printMenu();
void printMenual();

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
	cout << "1 - �� ����";
	gotoXY(3, 15);
	cout << "2 - �ҷ�����";
	gotoXY(3, 20);
	cout << "3 - ����";
	gotoXY(3, 25);
	cout << "4 - ��������";
	gotoXY(0, 49);
	cout << "input : ";
	cin >> input;
	return input;
}

void printMenual() {
	fstream menual = ifstream()
}