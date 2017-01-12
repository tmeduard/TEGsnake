#include "stdafx.h"
#include "connector.h"
int k = 0;
bool inMenu;
void menuDraw() {
	if (inMenu == true)
	{
		system("cls");
		if (k % 4 == 0)
			cout << "SOLO PLAY" << endl << endl;
		else cout << "solo play" << endl << endl;
		if (k % 4 == 1)
			cout << "ONE vs ONE" << endl << endl;
		else cout << "one vs one" << endl << endl;
		if (k % 4 == 2)
			cout << "SCOREBOARD" << endl << endl;
		else cout << "scoreboard" << endl << endl;
		if (k % 4 == 3)
			cout << "EXIT" << endl << endl;
		else cout << "exit" << endl << endl;
	}
}
void menuSelect() {
	if (k % 4 == 0)
	{
		inMenu = false;
		game();
	}

	if (k % 4 == 2)
	{
		inMenu = false;
		scoreMenu();
	}
	if (k % 4 == 3)
		inMenu = false;
}
void menuInput() {
	if (_kbhit())
	{
		switch (_getch())
		{
		case KB_UP:
			k--;
			if (k<0)
				k = 3;
			menuDraw();
			break;
		case KB_DOWN:
			k++;
			if (k>3)
				k = 0;
			menuDraw();
			break;
		case VK_RETURN:
			menuSelect();
			break;

		}
	}
}
void menu() {
	inMenu = true;
	menuDraw();
	while (inMenu == true) {
		menuInput();
	}

}
