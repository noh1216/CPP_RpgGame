#include<iostream>
#include "screenPrint.h";


#define COMMAND_SIZE 256

#define COLS 156
#define LINE 50


using namespace std;

void init();
void mainMenu();

int main() {
	bool run = true;

	init();

	// Game start
	while (run) {
		mainMenu();
	}
}

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	char screenCommand[COMMAND_SIZE];

	sprintf(screenCommand, "mode con cols=%d lines=%d | title Game", COLS, LINE);
	system(screenCommand);
}

void mainMenu() {
	int selectedNumber = printMenu();
	switch (selectedNumber)
	{
	case 1:
		// main adventure
		break;
	case 2:
		// loading data
		break;
	case 3:
		// menual
		printMenual();
.,ㅡ,.	case 4:
		// exit game
		exit(0);
		break;
	default:
		system("cls");
		string errorMessage = "잘못된 입력입니다. 다시 입력해주세요";
		gotoXY(COLS - (COLS/2 + errorMessage.length() / 2), LINE/2);
		cout << errorMessage;
		Sleep(1400);
		selectedNumber = printMenu();
	}
}