#include<iostream>
#include "screenPrint.h"
#include "configFunctions.h"

#define COMMAND_SIZE 256

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

	sprintf(screenCommand, "mode con cols=%d lines=%d | title Game", COLS, LINE); // screen size config
	system(screenCommand);

	CursorView(); // cursor config
}

void mainMenu() {
	int selectedMenu = printMenuMenager::printMenu();
	switch (selectedMenu)
	{
	case 1:
		// main adventure
		break;
	case 2:
		// loading data
		break;
	case 3:
		// menual
		printMenuMenager::printMenual();
	case 4:
		// exit game
		exit(0);
		break;
	default:
		cout << "ERROR" << endl;
		exit(0);
	}
}