#include "Infinity.h"
#include "Globals.h"
#include "Draw.h"
#include "Input.h"
#include "Logic.h"
#include "Setup.h"
#include "record.h"

#include <Windows.h>
#include <time.h>
#include <iostream>
#include <fstream>

void infinity()
{
	struct player
	{
		char name[20];
	};

	gotoxy(50, 17);
	std::cout << "REGISTRATION\n";
	gotoxy(50, 19);
	std::cout << "Nickname:";
	player x;
	std::cin >> x.name;
	system("cls");
	std::fstream records_file;
	records_file.open("records.txt", std::ios::app);
	records_file << x.name;

	Setup();
	while (!GameOver) {
		draw();
		input();
		logic();
		if (score <= 8)
			Sleep(40);
		else if (score >= 9 || score <= 16)
			Sleep(25);
		else if (score >= 17 || score <= 25)
			Sleep(15);
		else if (score >= 26 || score <= 37)
			Sleep(7);
		else Sleep(3);
	}
	system("cls");
	if (score == 50) {
		print_win();
		records_file << "\033[1;32m  " << "\t \tINFINITY\tWIN" << "\033[0m \n";
	}
	else {
		print_lose();
		records_file << "\033[1;31m  " << "\t \tINFINITY\tLOSE" << "\033[0m \n";
	}
}