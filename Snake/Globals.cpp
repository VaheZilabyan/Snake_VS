#include "Globals.h"
#include "Enum.h"

bool GameOver;
int x, y;
int fruitX, fruitY;
int tailX[100], tailY[100];
int nTail;
int score;
bool next;
bool is_not_empty; // (if == true)-> not empty ;else empty
bool deleting_record; //if == true -> nothing to delete;else records will be deleted
Edirection dir;
