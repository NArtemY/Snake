#include <iostream>
#include "conio.h"
using namespace std;

void Draw(int x, int y, int score, int fruitx, int fruity, int CountElem, int ElemX[], int ElemY[]){
	system("cls");	
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 30; j++) {
			bool print = true;
			if (x == j && y == i) {
				cout << "O";
				continue;
			}
			else if (i == 29 || i == 0 || j == 29 || j == 0) cout << "#";
			else if (fruitx == j && fruity == i) {
				cout << "d";
				continue;
			}
			else {
				for (int k = 0; k < CountElem; k++) {
					if (ElemX[k] == j && ElemY[k] == i) {
						cout << "o";
						print = false;
					}
				}
			}
			if (i == 29 || i == 0);
			else{
				if (print) cout << " ";
			}
		}
		cout << endl;
	}
}

int Input(int Course){
	if (_kbhit()) {
		switch (_getch()) {
		case 'a': Course = 2; break;
		case 'w': Course = 3; break;
		case 'd': Course = 1; break;
		case 's': Course = 4; break;
		}
	}
	return Course;
}