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
eDirecton dir, prevDir;
char prevFruit;
void fruitSetUp() {
	prevFruit = fruit.value;
	fruit.x = rand() % width;
	fruit.y = rand() % height;
	if (rand() % 10 >= 0 && rand() % 10 <= 6)
		fruit.value = 'F';
	if (rand() % 10 >= 7 && rand() % 10 <= 8)
		fruit.value = 'M';
	if (rand() % 10 == 9 )
		fruit.value = 'I';
}
void snakeSetUp() {
	dir = STOP;
	prevDir = STOP;
	gameScore = 0;
	tail.length = 0;
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
				cout << fruit.value;
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
	cout << endl << " " << fruit.value << " = ";
	if (fruit.value == 'F')
		cout << "NORMAL FRUIT";
	if (fruit.value == 'M')
		cout << "TAIL -1";
	if (fruit.value == 'I')
		cout << "WALL COLLISION IMMUNITY TILL NEXT FRUIT IS EATEN";
}
void deathCondition(char condition) {
	if (condition == 'I') {
		if (snake.x >= width)
			snake.x = 0;
		else if (snake.x < 0)
				snake.x = width - 1;
		if (snake.y >= height)
			snake.y = 0;
		else if (snake.y < 0)
				snake.y = height - 1;
	}
	else if (snake.x > width || snake.x < 0 || snake.y > height || snake.y < 0)
				inGame = false;
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
	}
	if ((dir == LEFT && prevDir == RIGHT) || (dir == RIGHT && prevDir == LEFT) || (dir == UP && prevDir == DOWN) || (dir == DOWN && prevDir == UP))
		if (tail.length != 0)
			inGame = false;
	prevDir = dir;
	deathCondition(prevFruit);
	for (int i = 0; i < tail.length; i++)
		if (tail.x[i] == snake.x && tail.y[i] == snake.y)
			inGame = false;

	if (snake.x == fruit.x && snake.y == fruit.y)
	{
		if (fruit.value == 'F') {
			gameScore += 10;
			fruitSetUp();
			tail.length++;
		}
		else if (fruit.value == 'I') {
				gameScore += 10;
				fruitSetUp();
				tail.length++;
			}
			else if (fruit.value == 'M' && tail.length != 0) {
					gameScore += 10;
					fruitSetUp();
					tail.length--;
				}
				else if (fruit.value == 'M' && tail.length == 0) {
						gameScore += 10;
						fruitSetUp();
					}

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
	newScores(gameScore);
	gameOverScreen(1,gameScore,0);
}