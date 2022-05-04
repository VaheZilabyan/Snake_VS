#include "Globals.h"
#include "Draw.h"
#include "Input.h"
#include "Enum.h"
#include "Logic.h"
#include "Setup.h"
#include "Infinity.h"
#include "Levels.h"
#include "record.h"

#include <Windows.h>
#include <string>
#include <iostream>
#include <fstream>
#include <time.h>
#include <conio.h>

void switch_menu(short int menu_point) //menu
{
	switch (menu_point)
	{
	case 1:
		system("cls");
		print_name();
		gotoxy(55, 10);
		std::cout << "\033[1;32m" << "Play" << "\033[0m\n" << std::endl;
		gotoxy(55, 12);
		std::cout << "instruction \n" << std::endl;
		gotoxy(55, 14);
		std::cout << "About \n" << std::endl;
		gotoxy(55, 16);
		std::cout << "Records \n" << std::endl;
		gotoxy(55, 18);
		std::cout << "Reset \n" << std::endl;
		gotoxy(55, 20);
		std::cout << "Quit \n" << std::endl;
		break;
	case 2:
		system("cls");
		print_name();
		gotoxy(55, 10);
		std::cout << "Play \n" << std::endl;
		gotoxy(55, 12);
		std::cout << "\033[1;32m" << "instruction" << "\033[0m\n " << std::endl;
		gotoxy(55, 14);
		std::cout << "About \n" << std::endl;
		gotoxy(55, 16);
		std::cout << "Records \n" << std::endl;
		gotoxy(55, 18);
		std::cout << "Reset \n" << std::endl;
		gotoxy(55, 20);
		std::cout << "Quit \n" << std::endl;
		break;
	case 3:
		system("cls");
		print_name();
		gotoxy(55, 10);
		std::cout << "Play \n" << std::endl;
		gotoxy(55, 12);
		std::cout << "instruction \n" << std::endl;
		gotoxy(55, 14);
		std::cout << "\033[1;32m" << "About" << "\033[0m\n " << std::endl;
		gotoxy(55, 16);
		std::cout << "Records \n" << std::endl;
		gotoxy(55, 18);
		std::cout << "Reset \n" << std::endl;
		gotoxy(55, 20);
		std::cout << "Quit \n" << std::endl;
		break;
	case 4:
		system("cls");
		print_name();
		gotoxy(55, 10);
		std::cout << "Play \n" << std::endl;
		gotoxy(55, 12);
		std::cout << "instruction \n" << std::endl;
		gotoxy(55, 14);
		std::cout << "About \n" << std::endl;
		gotoxy(55, 16);
		std::cout << "\033[1;32m" << "Records" << "\033[0m\n " << std::endl;
		gotoxy(55, 18);
		std::cout << "Reset \n" << std::endl;
		gotoxy(55, 20);
		std::cout << "Quit \n" << std::endl;
		break;
	case 5:
		system("cls");
		print_name();
		gotoxy(55, 10);
		std::cout << "Play \n" << std::endl;
		gotoxy(55, 12);
		std::cout << "instruction \n" << std::endl;
		gotoxy(55, 14);
		std::cout << "About \n" << std::endl;
		gotoxy(55, 16);
		std::cout << "Records \n" << std::endl;
		gotoxy(55, 18);
		std::cout << "\033[1;32m" << "Reset" << "\033[0m\n " << std::endl;
		gotoxy(55, 20);
		std::cout << "Quit \n" << std::endl;
		break;
	case 6:
		system("cls");
		print_name();
		gotoxy(55, 10);
		std::cout << "Play \n" << std::endl;
		gotoxy(55, 12);
		std::cout << "instruction \n" << std::endl;
		gotoxy(55, 14);
		std::cout << "About \n" << std::endl;
		gotoxy(55, 16);
		std::cout << "Records \n" << std::endl;
		gotoxy(55, 18);
		std::cout << "Reset \n" << std::endl;
		gotoxy(55, 20);
		std::cout << "\033[1;32m" << "Quit" << "\033[0m\n " << std::endl;
		break;
	}
}

int main()
{
	const int menu_size = 6;
	short int menu_point = 0;
	const int ENTER = 13;
	const int SPACE = 32;
	const int DOWN = 80;
	const int UP = 72;
	//const int LEFT = 75;
	//const int RIGHT = 77;

	print_name();
	print_menu();

	while (true) {
		switch (_getch()) {
		case DOWN: case 's':
			++menu_point;
			if (menu_point == menu_size + 1)
			{
				menu_point = 1;
			}
			switch_menu(menu_point);
			break;

		case UP: case 'w':
			--menu_point;
			if (menu_point == 0)
			{
				menu_point = 6;
			}
			switch_menu(menu_point);
			break;

		case ENTER:
			if (menu_point == 1)
			{
				if (deleting_record == true)
				{
					std::fstream records_file;
					records_file.open("records.txt", std::ios::out | std::ios::trunc);
				}
				deleting_record = false;

				system("cls");
				gotoxy(55, 12);
				std::cout << "2 Modes\n";
				gotoxy(45, 14);
				std::cout << "1.infinity\n";
				gotoxy(62, 14);
				std::cout << "2.Arcade\n";
				switch (_getch()) {
				case '1':
					system("cls");
					print_start();
					infinity();
					break;
				case '2':
					system("cls");
					print_easy();
					easy_level();
					if (next == true) {
						system("cls");
						print_medium();
						medium_level();
					}
					if (next == true) {
						system("cls");
						print_hard();
						hard_level();
					}
					break;
				default:
					break;
				}
				break;
			}

			if (menu_point == 2)
			{
				system("cls");
				std::ifstream fin("instruction.txt");
				std::string str;
				while (!fin.eof())
				{
					str = "";
					getline(fin, str);
					std::cout << str << std::endl;
				}
				break;
			}

			if (menu_point == 3)
			{
				system("cls");
				std::ifstream fin("about.txt");
				std::string str;
				while (!fin.eof())
				{
					str = "";
					getline(fin, str);
					std::cout << str << std::endl;
				}
				break;
			}

			if (menu_point == 4)
			{
				system("cls");
				deleting_record == false ? records() : no_records();
				break;
			}
			if (menu_point == 5)
			{
				is_not_empty = false;
				system("cls");
				delete_records();
				deleting_record = true;
				break;
			}

			if (menu_point == 6)
			{
				goto EXIT;
			}
			break;

		case SPACE:
			system("cls");
			print_name();
			print_menu();
			break;
		}
	}

	/*Setup();
	while (!GameOver) {
		draw();
		input();
		logic();
		if (score <= 5)
			Sleep(50);
		else Sleep(10);
	}
	system("cls");
	lose();
	*/
	EXIT:
	return 0;
}

