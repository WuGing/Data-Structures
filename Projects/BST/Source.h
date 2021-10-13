#pragma once

void print_menu();
void print_choice_menu();
char get_user_command();
int get_number();

#define PRINT 0x50
#define SIZE 0x53
#define ERASE 0x45
#define INSERT 0x49
#define QUIT 0x51
#define PREORDER 0x52
#define INORDER 0x49
#define POSTORDER 0x4F
#define QUIT_PRINT 0x58