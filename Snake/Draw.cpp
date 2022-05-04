#include "Draw.h"
#include "Globals.h"
#include <iostream>
#include <windows.h>
#include <string>

void gotoxy(int x, int y)
{
	printf("%c[%d;%df", 0x1B, y, x);
}

void draw()
{
	system("cls");

	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
				std::cout << ".";
			else if (i == y && j == x)
				std::cout << "\033[1;32m" << "0" << "\033[0m";
			else if (i == fruitY && j == fruitX)
				std::cout << "\033[1;31m" << "&" << "\033[0m";
			else {
				bool print = false;
				int k;
				for (k = 0; k < nTail; ++k) {
					if (tailX[k] == j && tailY[k] == i) {
						print = true;
						std::cout << "\033[1;32m" << "o" << "\033[0m";
					}
				}
				if (!print)
					std::cout << " ";
			}
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << "\n\nScore: " << score << std::endl;
	std::cout << "W-up" << std::endl;
	std::cout << "S-down" << std::endl;
	std::cout << "A-left" << std::endl;
	std::cout << "D-right" << std::endl;
	std::cout << "Q-quit" << std::endl;
}

void draw_medium()
{
	system("cls");

	int a = width / 4;
	int b = 3 * width / 4;

	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			if ((i == 0 && (j <= a || j >= b)) || (i == height - 1 && (j <= a || j >= b)) ||
				(j == 0 && (i <= a || i >= b)) || (j == width - 1 && (i <= a || i >= b)))
				std::cout << "#";
			else if ((i == 0 && (j > a && j < b)) || (i == height - 1 && (j > a && j < b)) ||
					(j == 0 && (i > a && i < b)) || (j == width - 1 && (i > a && i < b)))
				std::cout << ".";
			else if (i == y && j == x)
				std::cout << "\033[1;32m" << "0" << "\033[0m";
			else if (i == fruitY && j == fruitX)
				std::cout << "\033[1;31m" << "&" << "\033[0m";
			else {
				bool print = false;
				int k;
				for (k = 0; k < nTail; ++k) {
					if (tailX[k] == j && tailY[k] == i) {
						print = true;
						std::cout << "\033[1;32m" << "o" << "\033[0m";
					}
				}
				if (!print)
					std::cout << " ";
			}
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << "\n\nScore: " << score << std::endl;
	std::cout << "W-up" << std::endl;
	std::cout << "S-down" << std::endl;
	std::cout << "A-left" << std::endl;
	std::cout << "D-right" << std::endl;
	std::cout << "Q-quit" << std::endl;
}

void draw_hard()
{
	system("cls");

	int a = width / 5;
	int b = 2 * width / 5;	//a,b-ov kargavorel nayev nersi patery, poxel banadzevy hamel

	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			if	((i == 0 || i == height - 1) ||
				(j == 0 && (i <= height - b || i >= height - a)) || (j == width - 1 && (i <= a || i >= b)) ||
				(i == 10 && (j <= 5 || j >= 15)) || ((j == 5 && (i >= 10 && i <= 16)) || (j == 15 && (i >= 4 && i <= 10))))
				std::cout << "#";
			//else if ((j == 0 && (i >= 13 && i <= 15)) || (j == width - 1 && (i >= 5 && i <= 7)))
				//std::cout << ".";
			else if (i == y && j == x)
				std::cout << "\033[1;32m" << "0" << "\033[0m";
			else if (i == fruitY && j == fruitX)
				std::cout << "\033[1;31m" << "&" << "\033[0m";
			else {
				bool print = false;
				int k;
				for (k = 0; k < nTail; ++k) {
					if (tailX[k] == j && tailY[k] == i) {
						print = true;
						std::cout << "\033[1;32m" << "o" << "\033[0m";
					}
				}
				if (!print)
					std::cout << " ";
			}
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << "\n\nScore: " << score << std::endl;
	std::cout << "W-up" << std::endl;
	std::cout << "S-down" << std::endl;
	std::cout << "A-left" << std::endl;
	std::cout << "D-right" << std::endl;
	std::cout << "Q-quit" << std::endl;
}

void print_name()
{
	std::cout << "\t \t \t \t \t \033[1;32m  * *   *    *      *      *   * *****  \033[0m \n";
	std::cout << "\t \t \t \t \t \033[1;32m *   *  **   *     * *     *  *  *      \033[0m \n";
	std::cout << "\t \t \t \t \t \033[1;32m  *     * *  *    *   *    * *   *****  \033[0m \n";
	std::cout << "\t \t \t \t \t \033[1;32m    *   *  * *   *******   * *   *      \033[0m \n";
	std::cout << "\t \t \t \t \t \033[1;32m *   *  *   **  *       *  *  *  *      \033[0m \n";
	std::cout << "\t \t \t \t \t \033[1;32m  * *   *    * *         * *   * *****  \033[0m \n";
}

void print_menu()
{
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
	std::cout << "Quit \n" << std::endl;
}

void print_win()
{
	std::cout << "\t \t \t \t \t \033[1;32m *           *  ***  *   * \033[0m \n";
	std::cout << "\t \t \t \t \t \033[1;32m  *         *    *   **  * \033[0m \n";
	std::cout << "\t \t \t \t \t \033[1;32m   *   *   *     *   * * * \033[0m \n";
	std::cout << "\t \t \t \t \t \033[1;32m    * * * *      *   *  ** \033[0m \n";
	std::cout << "\t \t \t \t \t \033[1;32m     *   *      ***  *   * \033[0m \n \n";
	std::cout << "\t \t \t \t \t \033[1;32m" << " SPACE - come back to menu" << "\033[0m\n";
}

void print_lose()
{
	std::cout << "\t \t \t \t \t \033[1;31m *      ******  *****  *****  \033[0m \n";
	std::cout << "\t \t \t \t \t \033[1;31m *      *    *  *      *      \033[0m \n";
	std::cout << "\t \t \t \t \t \033[1;31m *      *    *  *****  *****  \033[0m \n";
	std::cout << "\t \t \t \t \t \033[1;31m *      *    *      *  *      \033[0m \n";
	std::cout << "\t \t \t \t \t \033[1;31m *****  ******  *****  *****  \033[0m \n \n";
	std::cout << "\t \t \t \t \t \033[1;32m" << " SPACE - come back to menu" << "\033[0m\n";
}

void print_next_level()
{
	std::string str = "NEXT LEVEL...";
	for (int i = 0; i < str.length(); ++i)
	{
		gotoxy(55 + i, 14);
		std::cout << "\033[1;32m" << str.at(i) << "\033[0m";
		//std::cout << str.at(i);
		Sleep(100);
	}
}

void print_start()
{
	std::string str = "START..";
	for (int i = 0; i < str.length(); ++i)
	{
		gotoxy(55 + i, 14);
		std::cout << "\033[1;32m" << str.at(i) << "\033[0m";
		Sleep(100);
	}
}

void print_easy()
{
	std::string str = "LEVEL EASY...";
	for (int i = 0; i < str.length(); ++i)
	{
		gotoxy(55 + i, 14);
		std::cout << "\033[1;32m" << str.at(i) << "\033[0m";
		Sleep(100);
	}
}

void print_medium()
{
	std::string str = "LEVEL MEDIUM...";
	for (int i = 0; i < str.length(); ++i)
	{
		gotoxy(55 + i, 14);
		std::cout << "\033[1;32m" << str.at(i) << "\033[0m";
		Sleep(100);
	}
}

void print_hard()
{
	std::string str = "LEVEL HARD...";
	for (int i = 0; i < str.length(); ++i)
	{
		gotoxy(55 + i, 14);
		std::cout << "\033[1;32m" << str.at(i) << "\033[0m";
		Sleep(100);
	}
}