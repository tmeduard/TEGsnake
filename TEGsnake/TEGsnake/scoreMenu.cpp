#include "stdafx.h"
#include "connector.h"
bool inScoreMenu;
int contor;
void scoreMenuSelect() {
	if (contor % 3 == 0)
	{
		inScoreMenu = false;
		score();
	}

	if (contor % 3 == 1)
	{
		inScoreMenu = false;
	}
	if (contor % 3 == 2)
		inScoreMenu = false;
}
void scoreMenuDraw() {
	if (inScoreMenu == true)
	{
		system("cls");
		if (contor % 3 == 0)
			cout << "SOLO PLAY SCORE" << endl << endl;
		else cout << "solo play score" << endl << endl;
		if (contor % 3 == 1)
			cout << "ONE vs ONE SCORE" << endl << endl;
		else cout << "one vs one score" << endl << endl;
		if (contor % 3 == 2)
			cout << "PLAYER vs COMPUTER SCORE" << endl << endl;
		else cout << "player vs computer score" << endl << endl;
	}
	cout <<endl<< "BACK TO MENU ( LEFT ARROW )";
}
void scoreInput() {
	if (_kbhit())
	{
		switch (_getch())
		{
		case KB_UP:
			contor--;
			if (contor<0)
				contor = 2;
			scoreMenuDraw();
			break;
		case KB_DOWN:
			contor++;
			if (contor>2)
				contor = 0;
			scoreMenuDraw();
			break;
		case VK_RETURN:
			scoreMenuSelect();
			break;
		case KB_LEFT:
			inScoreMenu = false;
			menu();
		}
	}
}
void scoreMenu() {
	inScoreMenu = true;
	scoreMenuDraw();
	while (inScoreMenu == true) {
		scoreInput();
	}
}