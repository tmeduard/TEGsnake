#include "stdafx.h"
#include "connector.h"
bool INGame;
const int height = 18;
const int width = 34;
definedFruit Fruit;
definedSnake snake[2];
definedTail tail[2];
int gameScore[2];
enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirecton dir[2], prevDir[2];
char PrevFruit;
int diedFirst;
void versusFruitSetUp() {
	PrevFruit = Fruit.value;
	Fruit.x = rand() % width;
	Fruit.y = rand() % height;
	if (rand() % 10 >= 0 && rand() % 10 <= 6)
		Fruit.value = 'F';
	if (rand() % 10 >= 7 && rand() % 10 <= 8)
		Fruit.value = 'M';
	if (rand() % 10 == 9)
		Fruit.value = 'I';
}
void versusSnakeSetUp() {
	dir[0] = STOP;
	dir[1] = STOP;
	prevDir[0] = STOP;
	prevDir[1] = STOP;
	gameScore[0] = 0;
	gameScore[1] = 0;
	tail[0].length = 0;
	tail[1].length = 0;
	snake[0].x = 3;
	snake[0].y = 2;
	snake[1].x = width - 4;
	snake[1].y = height - 3;
}
void versusGameDraw() {

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
			if (i == snake[0].y && j == snake[0].x)
				cout << "O";
			else if (i == snake[1].y && j == snake[1].x)
					cout << "X";
				else if (i == Fruit.y && j == Fruit.x)
						cout << Fruit.value;
					else
					{
						bool print = false;
						for (int k = 0; k < tail[0].length; k++)
						{
							if (tail[0].x[k] == j && tail[0].y[k] == i)
							{
								cout << "o";
								print = true;
							}
						}
						for (int k = 0; k < tail[1].length; k++)
						{
							if (tail[1].x[k] == j && tail[1].y[k] == i)
							{
								cout << "x";
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
	cout << "P1Score:" << gameScore[0] << "		P2Score:" << gameScore[1] << endl;
	cout << endl << " " << Fruit.value << " = ";
	if (Fruit.value == 'F')
		cout << "NORMAL FRUIT";
	if (Fruit.value == 'M')
		cout << "TAIL -1";
	if (Fruit.value == 'I')
		cout << "WALL COLLISION IMMUNITY TILL NEXT FRUIT IS EATEN";
}
void versusDeathCondition(char condition) {
	if (condition == 'I') {
		if (snake[0].x >= width)
			snake[0].x = 0;
		else if (snake[0].x < 0)
			snake[0].x = width - 1;

		if (snake[0].y >= height)
			snake[0].y = 0;
		else if (snake[0].y < 0)
			snake[0].y = height - 1;

		if (snake[1].x >= width)
			snake[1].x = 0;
		else if (snake[1].x < 0)
			snake[1].x = width - 1;

		if (snake[1].y >= height)
			snake[1].y = 0;
		else if (snake[1].y < 0)
			snake[1].y = height - 1;
	}
	else {
			if (snake[0].x > width-1 || snake[0].x < 0 || snake[0].y > height-1 || snake[0].y < 0) {
				INGame = false;
				diedFirst = 1;
			}

			if (snake[1].x > width-1 || snake[1].x < 0 || snake[1].y > height-1 || snake[1].y < 0) {
				INGame = false;
				diedFirst = 2;
			}
		 }
}
void versusGameInput()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			dir[0] = LEFT;
			break;
		case 'd':
			dir[0] = RIGHT;
			break;
		case 'w':
			dir[0] = UP;
			break;
		case 's':
			dir[0] = DOWN;
			break;
		case KB_LEFT:
			dir[1] = LEFT;
			break;
		case KB_RIGHT:
			dir[1] = RIGHT;
			break;
		case KB_UP:
			dir[1] = UP;
			break;
		case KB_DOWN:
			dir[1] = DOWN;
			break;
		}
	}
}
void versusGameLogic1()
{
	int prevX,prevY;
	int prev2X, prev2Y;

	prevX = tail[0].x[0];

	prevY = tail[0].y[0];

	tail[0].x[0] = snake[0].x;

	tail[0].y[0] = snake[0].y;

	for (int i = 1; i < tail[0].length; i++)
	{
		prev2X = tail[0].x[i];
		prev2Y = tail[0].y[i];
		tail[0].x[i] = prevX;
		tail[0].y[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
	switch (dir[0])
	{
	case LEFT:
		snake[0].x--;
		break;
	case RIGHT:
		snake[0].x++;
		break;
	case UP:
		snake[0].y--;
		break;
	case DOWN:
		snake[0].y++;
		break;
	}
	if ((dir[0] == LEFT && prevDir[0] == RIGHT) || (dir[0] == RIGHT && prevDir[0] == LEFT) || (dir[0] == UP && prevDir[0] == DOWN) || (dir[0] == DOWN && prevDir[0] == UP))
		if (tail[0].length != 0) {
			INGame = false;
			diedFirst = 1;
		}

	prevDir[0] = dir[0];
	versusDeathCondition(PrevFruit);

	for (int i = 0; i < tail[0].length; i++)
		if (tail[0].x[i] == snake[0].x && tail[0].y[i] == snake[0].y) {
			INGame = false;
			diedFirst = 1;
		}


	if (snake[0].x == Fruit.x && snake[0].y == Fruit.y)
	{
		if (Fruit.value == 'F') {
			gameScore[0] += 10;
			versusFruitSetUp();
			tail[0].length++;
		}
		else if (Fruit.value == 'I') {
			gameScore[0] += 10;
			versusFruitSetUp();
			tail[0].length++;
		}
		else if (Fruit.value == 'M' && tail[0].length != 0) {
			gameScore[0] += 10;
			versusFruitSetUp();
			tail[0].length--;
		}
		else if (Fruit.value == 'M' && tail[0].length == 0) {
			gameScore[0] += 10;
			versusFruitSetUp();
		}
	}
}
void versusGameLogic2()
{
	int prevX, prevY;
	int prev2X, prev2Y;

	prevX = tail[1].x[0];

	prevY = tail[1].y[0];

	tail[1].x[0] = snake[1].x;

	tail[1].y[0] = snake[1].y;

	for (int i = 1; i < tail[1].length; i++)
	{
		prev2X = tail[1].x[i];
		prev2Y = tail[1].y[i];
		tail[1].x[i] = prevX;
		tail[1].y[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
	switch (dir[1])
	{
	case LEFT:
		snake[1].x--;
		break;
	case RIGHT:
		snake[1].x++;
		break;
	case UP:
		snake[1].y--;
		break;
	case DOWN:
		snake[1].y++;
		break;
	}
	if ((dir[1] == LEFT && prevDir[1] == RIGHT) || (dir[1] == RIGHT && prevDir[1] == LEFT) || (dir[1] == UP && prevDir[1] == DOWN) || (dir[1] == DOWN && prevDir[1] == UP))
		if (tail[1].length != 0) {
			INGame = false;
			diedFirst = 2;
		}


	prevDir[1] = dir[1];
	versusDeathCondition(PrevFruit);

	for (int i = 0; i < tail[1].length; i++)
		if (tail[1].x[i] == snake[1].x && tail[1].y[i] == snake[1].y) {
			INGame = false;
			diedFirst = 2;
		}


	if (snake[1].x == Fruit.x && snake[1].y == Fruit.y)
	{
		if (Fruit.value == 'F') {
			gameScore[1] += 10;
			versusFruitSetUp();
			tail[1].length++;
		}
		else if (Fruit.value == 'I') {
			gameScore[1] += 10;
			versusFruitSetUp();
			tail[1].length++;
		}
		else if (Fruit.value == 'M' && tail[1].length != 0) {
			gameScore[1] += 10;
			versusFruitSetUp();
			tail[1].length--;
		}
		else if (Fruit.value == 'M' && tail[1].length == 0) {
			gameScore[1] += 10;
			versusFruitSetUp();
		}
	}
}
void versusGame() {
	INGame = true;
	versusFruitSetUp();
	versusSnakeSetUp();
	while (INGame == true) {
		versusGameDraw();
		versusGameInput();
		versusGameLogic1();
		versusGameInput();
		versusGameLogic2();
		if (gameScore[0] + 200 == gameScore[1]) {
			INGame = false;
			gameOverScreen(2, 0, 1);
		}
		else if (gameScore[0] == gameScore[1] + 200) {
				INGame = false;
				gameOverScreen(2, 1, 0);
			}
		Sleep(100);
	}
	if (diedFirst == 1)
		gameOverScreen(2, gameScore[0], gameScore[1]+100);
	else gameOverScreen(2, gameScore[0]+100, gameScore[1]);
}
void computerLogic() {
	if (dir[0] != STOP) {
		if (Fruit.x > snake[1].x) {
			if (snake[1].x < width)
				snake[1].x++;
			else {
				if (snake[1].y > 0)
					snake[1].y++;
				else if (snake[1].y < height)
						snake[1].y--;
			}
		}
		if (Fruit.x < snake[1].x) {
			if (snake[1].x > 0)
				snake[1].x--;
			else {
				if (snake[1].y > 0)
					snake[1].y++;
				else if (snake[1].y < height)
					snake[1].y--;
			}
		}


		if (Fruit.y > snake[1].y) {
			if (snake[1].y < height)
				snake[1].y++;
			else {
				if (snake[1].x > 0)
					snake[1].x++;
				else if (snake[1].x < width)
					snake[1].x--;
			}	
		}
		if (Fruit.y < snake[1].y) {
			if (snake[1].y > 0)
				snake[1].y--;
			else {
				if (snake[1].x > 0)
					snake[1].x++;
				else if (snake[1].x < width)
					snake[1].x--;
			}
		}	
	}

	if (snake[1].x == Fruit.x && snake[1].y == Fruit.y) {
		if (Fruit.value == 'M' || Fruit.value == 'I') {
			if (tail[1].length != 0) {
				versusFruitSetUp();
				tail[1].length--;
				gameScore[1] += 10;
			}
			else {
				versusFruitSetUp();
				gameScore[1] += 10;
			}

		}
		else {
			versusFruitSetUp();
			tail[1].length++;
			gameScore[1] += 10;
		}

	}
	int prevX, prevY;
	int prev2X, prev2Y;

	prevX = tail[1].x[0];

	prevY = tail[1].y[0];

	tail[1].x[0] = snake[1].x;

	tail[1].y[0] = snake[1].y;

	for (int i = 1; i < tail[1].length; i++)
	{
		prev2X = tail[1].x[i];
		prev2Y = tail[1].y[i];
		tail[1].x[i] = prevX;
		tail[1].y[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
}
void computerVersus() {
	INGame = true;
	versusFruitSetUp();
	versusSnakeSetUp();
	while (INGame == true) {
		versusGameDraw();
		versusGameInput();
		versusGameLogic1();
		computerLogic();
		Sleep(100);
	}
	newScores(gameScore[0], 1);
	gameOverScreen(1, gameScore[0], 0);
}