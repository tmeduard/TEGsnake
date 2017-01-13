#include "stdafx.h"
#include "connector.h"
int k = 0;
bool inMenu;
void menuDraw() {
	if (inMenu == true)
	{
		system("cls");
		if (k % 5 == 0)
			cout << "SOLO PLAY" << endl << endl;
		else cout << "solo play" << endl << endl;
		if (k % 5 == 1)
			cout << "ONE vs ONE" << endl << endl;
		else cout << "one vs one" << endl << endl;
		if (k % 5 == 2)
			cout << "SCOREBOARD" << endl << endl;
		else cout << "scoreboard" << endl << endl;
		if (k % 5 == 3)
			cout << "GAME INFO" << endl << endl;
		else cout << "game info" << endl << endl;
		if (k % 5 == 4)
			cout << "EXIT" << endl << endl;
		else cout << "exit" << endl << endl;
		cout << endl << endl << endl;
		cout << "UP/DOWN ARROW AND ENTER TO NAVIGATE";
	}
}
void menuSelect() {
	if (k % 5 == 0)
	{
		inMenu = false;
		game();
	}

	if (k % 5 == 2)
	{
		inMenu = false;
		scoreMenu();
	}
	if (k % 5 == 1) {
		inMenu = false;
		versusGame();
	}
	if (k % 5 == 4) {
		inMenu = false;
	}
	if (k % 5 == 3) {
		system("cls");
		cout << " F = NORMAL FRUIT" << endl << endl;
		cout << " M = TAIL -1" << endl << endl;
		cout << " I = WALL COLLISION IMMUNITY TILL NEXT FRUIT IS EATEN" << endl << endl;
		cout << " SINGLE PLAYER COMMANDS : W , A , S , D " << endl << endl;
		cout << " 1V1 COMMANDS : PLAYER 1 : W , A , S , D" << endl << endl;
		cout << "		PLAYER 2 : UP , DOWN , RIGHT , LEFT ARROWS" << endl << endl;
		cout << endl << endl << endl;
		cout << "BACK TO MENU(LEFT ARROW)";
		while (inMenu == true)
			if (_kbhit())
			{
				switch (_getch())
				{
					case KB_LEFT:
						inMenu = false;
						menu();
					break;
				}
			}
	}
}
void menuInput() {
	if (_kbhit())
	{
		switch (_getch())
		{
		case KB_UP:
			k--;
			if (k<0)
				k = 4;
			menuDraw();
			break;
		case KB_DOWN:
			k++;
			if (k>4)
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
