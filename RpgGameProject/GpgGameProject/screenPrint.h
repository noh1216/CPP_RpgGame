#pragma once

#include <iostream>
#include <fstream>
#include <Windows.h>
#include "configFunctions.h"

using namespace std;

namespace printMenuMenager{
	int printMenu() {
		system("cls");
		const int SIZE = 4;
		string titles[SIZE] = { " 새 게임" ," 불러오기" ," 설명서" , " 게임종료" };
		char symbol = ' ', uniqueSymbol='>';
		int symbolPos = 0, cols = gets::getCOLS(), line = gets::getLINE();
		
		while (1) {
			system("cls");
			for (int i = 0; i < SIZE; i++) {
				gotoXY(cols / 2 - (titles[0].size() / 2)-3, line/2-(SIZE/2)+i-2); // UI position
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
		//fstream menual = ifstream()
	}
}
