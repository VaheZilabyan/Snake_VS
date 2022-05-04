#include "Setup.h"
#include "Globals.h"
#include "Draw.h"
#include "Input.h"
#include "Logic.h"

#include <Windows.h>
#include <time.h>

void Setup()
{
	GameOver = false;
	score = 0;
	nTail = 0;
	next = false;
	dir = STOP;
	srand(time(nullptr));
	x = width / 2 - 1;
	y = height / 2 - 1;
	do {
		fruitX = (rand() % (width - 2)) + 2;
		fruitY = (rand() % (height - 2)) + 2;
	} while (fruitX != x && fruitY != y);
}