#pragma once
void print_menu();
void print_choice_menu();
void print_height();
char get_user_command();
int get_number();

constexpr char HEIGHT	= 0x48;
constexpr char INSERT	= 0x49;
constexpr char PRINT	= 0x50;
constexpr char QUIT		= 0x51;