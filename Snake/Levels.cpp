#include "Levels.h"
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

void easy_level()
{
	std::cout << "\n";
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
		Sleep(30);
		if (score == 10) {
			Sleep(1000);
			break;
		}
	}
	if (GameOver) {
		system("cls");
		print_lose();
		records_file << "\033[1;31m  " << "\t \tARCADE\t\tLOSE" << "\033[0m \n";
		next = false;
	}
	else {
		system("cls");
		print_next_level();
		next = true;		
	}
}

void medium_level()
{
	Setup();
	while (!GameOver) {
		draw_medium();
		input();
		logic_medium();
		if (score <= 5)
			Sleep(25);
		else
			Sleep(10);
		if (score == 10) {
			Sleep(1000);
			break;
		}
	}
	std::fstream records_file;
	records_file.open("records.txt", std::ios::app);
	if (GameOver) {
		system("cls");
		print_lose();
		records_file << "\033[1;31m  " << "\t \tARCADE\t\tLOSE" << "\033[0m \n";
		next = false;
	}
	else {
		system("cls");
		print_next_level();
		next = true;
	}
}

void hard_level()
{
	Setup();
	while (!GameOver) {
		draw_hard();
		input();
		logic_hard();
		if (score <= 5)
			Sleep(25);
		else Sleep(10);
		if (score == 10) {
			Sleep(1000);
			break;
		}
	}
	std::fstream records_file;
	records_file.open("records.txt", std::ios::app);
	if (GameOver) {
		system("cls");
		print_lose();
		records_file << "\033[1;31m  " << "\t \tARCADE\t\tLOSE" << "\033[0m \n";
		next = false;
	}
	else {
		system("cls");
		print_win();
		records_file << "\033[1;32m  " << "\t \tARCADE\t\tWIN" << "\033[0m \n";
		next = true;
	}
}

