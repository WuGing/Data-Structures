#pragma once

void DisplayMenu();
void DisplayPrintChoiceMenu();
char GetUserCommand();
int GetNumber();

constexpr int PRINT = 0x50;
constexpr int SIZE = 0x53;
constexpr int ERASE = 0x45;
constexpr int INSERT = 0x49;
constexpr int QUIT = 0x51;
constexpr int PREORDER = 0x52;
constexpr int INORDER = 0x49;
constexpr int POSTORDER = 0x4F;
constexpr int QUIT_PRINT = 0x58;