#pragma once

#include <iostream>
#include <Windows.h>
#include <vector>
#include "configFunctions.h"

using namespace std;

namespace printMenuMenager{
	int printMenu() {
		system("cls");
		const int SIZE = 4;
		string titles[SIZE] = { " 새 게임" ," 불러오기" ," 설명서" , " 게임종료" };
		char symbol = ' ', uniqueSymbol='>';
		int symbolPos = 0;
		
		while (1) {
			system("cls");
			int center = calculateCenter(titles[1].size());
			for (int i = 0; i < SIZE; i++) {
				gotoXY(center, LINE/2-(SIZE/2)+i); // UI position
				if (symbolPos == i) {
					cout << uniqueSymbol << titles[i] << '\n';
					continue;
				}
				cout << symbol << titles[i] << '\n';
			}
			int add = keyboardInput(); // keyboard get input
			if (add == 10) {
				return symbolPos + 1;
			}
			symbolPos = (symbolPos + add) < 0 ? SIZE - 1 : (symbolPos + add) >= SIZE ? 0 : symbolPos + add;
		}
		
	}

	void printMenual() {
		system("cls");
		printFileContent("./menual.txt", 10);
		keyboardInput();
	}
}
