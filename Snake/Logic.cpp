#include "Logic.h"
#include "Globals.h"
#include "Enum.h"

#include <stdlib.h>
#include <time.h>

void logic()
{
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;
	for (int i = 1; i < nTail; ++i)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}

	switch (dir)
	{
	case UP:
		y--;
		break;
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case DOWN:
		y++;
		break;
	case STOP:
		GameOver = false;
		break;
	}
	//if (x == width - 1 || x == 0 || y == 0 || y == height - 1)
		//GameOver = true;
//	if (x >= width - 1 || x <= 0 || y <= 0 || y >= height - 1)
//		GameOver = true;

	if (x >= width - 1)
		x = 0;
	else if (x < 0)
		x = width - 2;
	if (y >= height)
		y = 0;
	else if (y < 0)
		y = height - 1;

	for (int i = 0; i < nTail; ++i)
	{
		if (tailX[i] == x && tailY[i] == y)
			GameOver = true;
	}

	if (x == fruitX && y == fruitY)
	{
		score++;
		srand(time(NULL));
		fruitX = (rand() % ((width - 1) - 1)) + 1;
		fruitY = (rand() % ((height - 1) - 1)) + 1;
		nTail++;
	}
}

void logic_medium()
{
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;
	for (int i = 1; i < nTail; ++i)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}

	switch (dir)
	{
	case UP:
		y--;
		break;
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case DOWN:
		y++;
		break;
	case STOP:
		GameOver = false;
		break;
	}

	int a = width / 4;
	int b = 3 * width / 4;

	if ((x >= width - 1 && (y <= a || y >= b)) || (x <= 0 && (y <= a || y >= b)) ||
		(y <= 0 && (x <= a || x >= b)) || (y >= height - 1 && (x <= a || x >= b)))
		GameOver = true;

	if (x >= width - 1 && (y > a && y < b))
		x = 0;
	else if (x < 0 && (y > a && y < b))
		x = width - 2;
	if (y >= height && (x > a && x < b))
		y = 0;
	else if (y < 0 && (x > a && x < b))
		y = height - 1;
    
	for (int i = 0; i < nTail; ++i)
	{
		if (tailX[i] == x && tailY[i] == y)
			GameOver = true;
	}

	if (x == fruitX && y == fruitY)
	{
		score++;
		srand(time(NULL));
		fruitX = (rand() % ((width - 1) - 1)) + 1;
		fruitY = (rand() % ((height - 1) - 1)) + 1;
		nTail++;
	}
}

void logic_hard()
{
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;
	for (int i = 1; i < nTail; ++i)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}

	switch (dir)
	{
	case UP:
		y--;
		break;
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case DOWN:
		y++;
		break;
	case STOP:
		GameOver = false;
		break;
	}

	int a = width / 5;
	int b = 2 * width / 5;

	if ((x >= width - 1 && (y <= a || y >= b)) || (x <= 0 && (y <= height - b || y >= height - a)) ||
		(y == 0 || y == height - 1) || (y == height / 2 && (x <= width / 4 || x > 3 * width / 4)) ||
		(x == width / 4 && (y >= height / 2 && y <= height - a) || (x == 3 * width / 4 && (y >= a && y <= height / 2))))
		GameOver = true;

	if (x >= width - 1 && (y > a && y < b)) { //b 10?
		x = 0;
		y = height - y;
	}
	else if (x < 0 && (y > height - b && y < height - a)) {
		x = width - 2;
		y = height - y;
	}

	for (int i = 0; i < nTail; ++i)
	{
		if (tailX[i] == x && tailY[i] == y)
			GameOver = true;
	}

	if (x == fruitX && y == fruitY)
	{
		score++;
		srand(time(NULL));
		fruitX = (rand() % ((width - 1) - 1)) + 1;
		fruitY = (rand() % ((height - 1) - 1)) + 1;
		nTail++;
	}
}