#include<iostream>
#include "screenPrint.h";


#define COMMAND_SIZE 256

int testGit = 1;

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

	const int cols = 156;
	const int line = 50;

	sprintf(screenCommand, "mode con cols=%d lines=%d | title Game", cols, line);
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
		break;
	default:
		selectedNumber = printMenu();
		break;
	}
}