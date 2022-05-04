#pragma once
#ifndef GLOBALS_H_
#define GLOBALS_H_   
#include "Enum.h"

const int height = 20;
const int width = 20;

extern bool GameOver;
extern int x, y;
extern int fruitX, fruitY;
extern int tailX[100], tailY[100];
extern int nTail;
extern int score;
extern bool next;
extern bool is_not_empty;	// (if == true)-> not empty ;else empty 
extern bool deleting_record;	//if == true -> nothing to delete;else records will be deleted
extern Edirection dir;

#endif 


