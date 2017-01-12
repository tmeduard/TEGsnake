#include "stdafx.h"
#include "connector.h"
bool inScore;
int topScore[10];
void scoreGet() {
	ifstream inFile;
	inFile.open("memScore.inout");
	for (int i = 0; i < 10; i++) {
		inFile >> topScore[i];
	}
	inFile.close();
}
void scoreSet(){
	ofstream outFile;
	outFile.open("memScore.inout");
	for (int i = 0; i < 10; i++)
		outFile << topScore[i] << ' ';
	outFile.close();
}
void newScores(int newSC) {
	int aux;
	if (newSC > topScore[9]) {
		topScore[9] = newSC;
		for (int i = 0; i < 9; i++) {
			for (int j = i + 1; j < 10; j++)
				if (topScore[i] < topScore[j]) {
					aux = topScore[i];
					topScore[i] = topScore[j];
					topScore[j] = aux;
				}
		}
	}
	scoreSet();
}
void scoreDraw() {
		system("cls");
		for (int i = 0; i<10; i++)
			cout << "Locul " << i + 1 << ":  " << topScore[i] << "  puncte" << endl;
		cout << endl << "BACK TO SCORE MENU ( LEFT ARROW ) ";
		cout << endl<<"RESET SCOREBOARD( SPACE )";
		switch (_getch())
		{
		case KB_LEFT:
			inScore = false;
			scoreMenu();
			break;
		case KB_SPACE:
			ofstream outFile;
			outFile.open("memScore.inout");
			for (int i = 0; i < 10; i++)
				outFile << 0 << ' ';
			outFile.close();
			Sleep(100);
			inScore = false;
			score();
		}
	}
void score() {
	scoreGet();
	inScore = true;
	while (inScore == true)
		scoreDraw();
}