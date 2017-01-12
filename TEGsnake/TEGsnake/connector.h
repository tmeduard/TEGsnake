#ifndef CONNECTOR_H_
#define CONNECTOR_H_
#define KB_DOWN 80
#define KB_UP 72
#define KB_LEFT 75
#define KB_RIGHT 77
#define KB_SPACE 32
#include<iostream>
#include<fstream>
#include<conio.h>
#include<Windows.h>
using namespace std;
struct definedSnake {
	int x, y;
};
struct definedTail {
	int x[100];
	int y[100];
	int length;
};
struct definedFruit {
	int x, y;
	char value;
};
void menu();
void game();
void score();
void newScores(int);
void gameOverScreen(int,int,int);
void scoreMenu();
#endif // !CONNECTOR_H_

