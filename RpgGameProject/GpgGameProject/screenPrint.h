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
		int symbolPos = 0;
		
		while (1) {
			system("cls");
			int* center = calculateCenter(titles[1].size(), SIZE);
			for (int i = 0; i < SIZE; i++) {
				gotoXY(center[0]-3, center[1]+i-2); // UI position
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
		ifstream ifs("./menual.txt");
		if (ifs.fail()) {
			cout << "menual error";
		}

		char c;
		string fileContent = "";
		int hSize = 0;
		while (ifs.get(c)) {
			 fileContent += c;
			 if (c == '\n') {
				 hSize++;
			 }
		}
		int *center = calculateCenter(fileContent.size(), hSize);
		gotoXY(center[0], center[1]-10);
		cout << fileContent;
		keyboardInput();
	}
}
