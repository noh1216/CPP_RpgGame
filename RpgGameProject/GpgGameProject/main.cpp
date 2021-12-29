#include<iostream>
#include "screenPrint.h"
#include "configFunctions.h"

using namespace std;

void init();
int mainMenu();

int main() {
	bool run = true;
	init();

	// Game start
	while (run) {
		int keyCommand = mainMenu();
		if (keyCommand == 0) {
			return 0;
		}
		else if (keyCommand == 1) {
			continue;
		}
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

int mainMenu() {
	int selectedMenu = printMenuMenager::printMenu();
	while (true) {
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
			return 1;
		case 4:
			// exit game
			return 0;
		default:
			cout << "ERROR" << endl;
			return 0;
		}
	}
}