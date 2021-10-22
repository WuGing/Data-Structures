#pragma once
void DisplayMenu();
void DisplayPrintChoiceMenu();
void PrintHeight();
char GetUserCommand();
int GetNumber();

constexpr char HEIGHT	= 0x48;
constexpr char INSERT	= 0x49;
constexpr char PRINT	= 0x50;
constexpr char QUIT		= 0x51;