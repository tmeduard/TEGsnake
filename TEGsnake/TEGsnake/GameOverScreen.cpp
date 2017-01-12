#include "stdafx.h"
#include "connector.h"
bool inScreen;
void screenDraw(int score) {
	system("cls");
	if (inScreen == true) {
		cout << endl << endl << endl << endl << endl << endl << endl;
		cout << "			";
		cout << "Game Over";
		cout << endl;
		cout << "			";
		cout << "Your score is:" << score;
		cout << endl << endl << endl;
		cout << "		";
		cout << "PRESS ENTER TO RETURN TO MENU";
	}
}
void versusDraw(int score1, int score2) {
	system("cls");
	if (inScreen == true) {
		cout << endl << endl << endl << endl << endl << endl << endl;
		cout << "			";
		cout << "Game Over";
		cout << endl;
		cout << "			";
		if (score1 < score2) {
			cout << "The winner is: Player2";
		}
		else {
			if (score1 > score2) {
				cout << "The winner is: Player1";
			}
			else cout << "Everyone is a winner";
		}
		cout << endl << endl << endl;
		cout << "			";
		cout << "PRESS ENTER TO RETURN TO MENU";
	}
}
void gameOverScreen(int nrPlayers,int score1,int score2) {
	inScreen = true;
	if (nrPlayers == 1) {
		screenDraw(score1);
		while (inScreen == true) {
			switch (_getch())
			{
			case VK_RETURN:
				inScreen = false;
				menu();
			}
		}
	}
	else {
		versusDraw(score1,score2);
		while (inScreen == true) {
			switch (_getch())
			{
			case VK_RETURN:
				inScreen = false;
				menu();
			}
		}
	}
}