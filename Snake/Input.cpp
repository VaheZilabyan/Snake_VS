#include "Input.h"
#include "Enum.h"
#include "Globals.h"

#include <conio.h>

void input()
{
	if (_kbhit()) {
		switch (_getch()) {
		case 'w': case 'W':
			dir = UP;
			break;
		case 'a': case 'A':
			dir = LEFT;
			break;
		case 's': case 'S':
			dir = DOWN;
			break;
		case 'd': case 'D':
			dir = RIGHT;
			break;
		case 'q': case 'Q':
			dir = STOP;
			break;
		}
	}
}