#include "stdafx.h"
#include "connector.h"
bool inScoreMenu;
int contor;
void scoreMenuSelect() {
	if (contor % 2 == 0)
	{
		inScoreMenu = false;
		score();
	}

	if (contor % 2 == 1)
	{
		inScoreMenu = false;
		versusScore();
	}
}
void scoreMenuDraw() {
	if (inScoreMenu == true)
	{
		system("cls");
		if (contor % 2 == 0)
			cout << "SOLO PLAY SCORE" << endl << endl;
		else cout << "solo play score" << endl << endl;
		if (contor % 2 == 1)
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
				contor = 1;
			scoreMenuDraw();
			break;
		case KB_DOWN:
			contor++;
			if (contor>1)
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