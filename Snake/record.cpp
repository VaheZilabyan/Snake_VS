#include <iostream>
#include <string>
#include <fstream>

#include "Draw.h"
#include "Globals.h"

void records_deleted()
{
    system("cls");
    print_name();
    print_menu();
    gotoxy(55, 22);
    std::cout << "\033[1;31m" << "ALL RECORDS DELETED" << "\033[0m\n";
}

void no_records()
{
    system("cls");
    print_name();
    print_menu();
    gotoxy(55, 22);
    std::cout << "\033[1;31m" << "NO RECORDS" << "\033[0m\n";
}

void records()
{
    std::string players_records;
    std::fstream records_file;
    records_file.open("records.txt");
    is_not_empty = false;
    gotoxy(15, 0);
    std::cout << "\033[1;31mRECORDS OF PLAYERS \033[0m\n\n";
    gotoxy(0, 3);
    std::cout << "NICKNAME";  
    gotoxy(15, 3);
    std::cout << "|";
    gotoxy(17, 3);
    std::cout << "MODE";
    gotoxy(28, 3);
    std::cout << "|";
    gotoxy(30, 3);
    std::cout << "\t\033[1;32mWin \033[0m" << "or" << "\033[1;31m lose \033[0m \n";
    std::cout << "_________________________________________________\n";
    while (getline(records_file, players_records))
    {
        is_not_empty = true;
        std::cout << players_records << "\n";
    }
    if (is_not_empty != true)
    {
        print_name();
        no_records();
    }
    records_file.close();
}

void delete_records()
{
    std::string players_records;
    std::fstream records_file;
    records_file.open("records.txt");
    if (deleting_record == false)
    {
        remove("records.txt");
        records_deleted();
        records_file.close();
    }
    else
    {
        system("cls");
        print_name();
        print_menu();
        gotoxy(55, 22);
        std::cout << "\033[1;31m" << "NOTHING TO DELETE" << "\033[0m\n";
    }
}