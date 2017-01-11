#include "stdafx.h"
#include "connector.h"
bool inGame;
const int height = 18;
const int width = 24;
definedFruit fruit;
definedSnake snake;
definedTail tail;
int gameScore;
enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirecton dir;
void fruitSetUp() {
	fruit.x = rand() % width;
	fruit.y = rand() % height;
}
void snakeSetUp() {
	snake.x = width / 2;
	snake.y = height / 2;
}
void gameDraw(){

	system("cls");
	for (int i = 0; i < width + 2; i++)
		cout << "#";
	cout << endl;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0)
				cout << "#";
			if (i == snake.y && j == snake.x)
				cout << "O";
			else if (i == fruit.y && j == fruit.x)
				cout << "F";
			else
			{
				bool print = false;
				for (int k = 0; k < tail.length; k++)
				{
					if (tail.x[k] == j && tail.y[k] == i)
					{
						cout << "o";
						print = true;
					}
				}
				if (!print)
					cout << " ";
			}


			if (j == width - 1)
				cout << "#";
		}
		cout << endl;
	}
	for (int i = 0; i < width + 2; i++)
		cout << "#";
	cout << endl;
	cout << "Score:" << gameScore << endl;
}
void gameInput()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		}
	}
}
void gameLogic()
{
	int prevX = tail.x[0];
	int prevY = tail.y[0];
	int prev2X, prev2Y;
	tail.x[0] = snake.x;
	tail.y[0] = snake.y;
	for (int i = 1; i < tail.length; i++)
	{
		prev2X = tail.x[i];
		prev2Y = tail.y[i];
		tail.x[i] = prevX;
		tail.y[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
	switch (dir)
	{
	case LEFT:
		snake.x--;
		break;
	case RIGHT:
		snake.x++;
		break;
	case UP:
		snake.y--;
		break;
	case DOWN:
		snake.y++;
		break;
	default:
		break;
	}
	if (snake.x > width || snake.x < 0 || snake.y > height || snake.y < 0)
	  inGame = false;

	for (int i = 0; i < tail.length; i++)
		if (tail.x[i] == snake.x && tail.y[i] == snake.y)
			inGame = false;

	if (snake.x == fruit.x && snake.y == fruit.y)
	{
		gameScore += 10;
		fruitSetUp();
		tail.length++;
	}
}
void game() {
	inGame = true;
	fruitSetUp();
	snakeSetUp();
	while (inGame == true) {
		gameDraw();
		gameInput();
		gameLogic();
		Sleep(100);
	}
	gameOverScreen();
}