#include <iostream>
#include "Functions.h"
#include <time.h>

using namespace std;

int main()
{
	srand(time(NULL));
	bool ext = false;
	int x = 15;
	int y = 15;
	int CountElem = 1;
	int ElemX[900], ElemY[900];
	ElemX[0] = x;
	ElemY[0] = y;
	int LastX = ElemX[0], LastY = ElemY[0];
	int Last2X, Last2Y;
	int score = 0;
	int Course = 4;
	int Course1;
	int fruitx = rand() % 28;
	int fruity = rand() % 28;
	while (!ext) {
		//Logic
		Course1 = Course;
		Course = Input(Course);
		for (int i = 0; i <= CountElem; i++) {
			Last2X = ElemX[i];
			Last2Y = ElemY[i];
			ElemX[i] = LastX;
			ElemY[i] = LastY;
			LastX = Last2X;
			LastY = Last2Y;
		}
		switch (Course) {
		case 1: if (Course1 != 2)x++;
				else {
					x--;
					Course = 2;
				}
				break;
		case 2: if (Course1 != 1)x--;
				else {
					x++;
					Course = 1;
				}
				break;
		case 3: if (Course1 != 4)y--;
				else {
					y++;
					Course = 4;
				}
				break;
		case 4: if (Course1 != 3)y++;
				else {
					y--;
					Course = 3;
				}
				break;
		}
		if (x == 29 || x == 0 || y == 29 || y == 0) ext = true;
		for (int i = 0; i < CountElem; i++) {
			if (ElemX[i] == x && ElemY[i] == y) {
				ext = true;
				break;
			}
		}
		if (x == fruitx && y == fruity) {
			fruitx = rand() % 29;
			fruity = rand() % 29;
			score++;
			CountElem++;
		}
		ElemX[0] = x;
		ElemY[0] = y;
		//End of logic
		Draw(ElemX[0], ElemY[0], score, fruitx, fruity, CountElem, ElemX, ElemY);
	}
	cout << "Game over, your score: " << score;
	cin.get();
}
//Right = 1
//Left = 2
//Up = 3
//Down = 4
//Stop = 0