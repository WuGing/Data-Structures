/*
* I Joshua Sutherland, Section 001, have not used any code other than my
* own (or that in the textbook) for this project.I also have not used any
* function or data-structure from the Standard - Template Library. I
* understand that any violation of this disclaimer will result in a 0 for
* the project.
*/

#include <iostream>
#include "BST.h"
#include "Source.h"

using namespace std;

int main()
{
	BST tree; // A sequence that we’ll perform tests on
	char choice;   // A command character entered by the user

	cout << "An empty tree has been created." << endl;

	do
	{
		print_menu();
		choice = toupper(get_user_command());
		switch (choice)
		{
		case PRINT: 
			do
			{
				print_choice_menu();
				choice = toupper(get_user_command());
				switch (choice)
				{
				case PRINT: tree.print(tree.root, tree.size());
					break;
				case PREORDER: tree.preorder(tree.root);
					break;
				case INORDER: tree.inorder(tree.root);
					break;
				case POSTORDER: tree.postorder(tree.root);
					break;
				case QUIT_PRINT:
					break;
				default: cout << choice << " is invalid." << endl;
				}
			} while (choice != QUIT_PRINT);
			break;
		case SIZE: cout << "Size is " << tree.size() << '.' << endl;
			break;
		case INSERT: tree.insert(get_number(), tree.root);
			break;
		case ERASE: tree.erase(get_number(), tree.root);
			cout << "Number has been removed." << endl;
			break;
		case QUIT: cout << "Ridicule is the best test of truth." << endl;
			break;
		default:  cout << choice << " is invalid." << endl;
		}
	} while ((choice != QUIT));

	return EXIT_SUCCESS;
}

void print_menu()
// Library facilities used: iostream.h
{
	cout << endl; // Print blank line before the menu
	cout << "The following choices are available: " << endl;
	cout << " P   Print options menu will be printed" << endl;
	cout << " S   Print the result from the size() function" << endl;
	cout << " I   Insert a new number with the insert(...) function" << endl;
	cout << " E   Erase a number from the tree with the erase(...) function" << endl;
	cout << " Q   Quit this test program" << endl;
}

void print_choice_menu()
{
	cout << endl;
	cout << "The following choices are available: " << endl;
	cout << " P  The print() function will be called printing the tree" << endl;
	cout << " R  Print the tree using the preorder traversal" << endl;
	cout << " N  Print the tree using an inorder traversal" << endl;
	cout << " O  Print the tree using a postorder traversal" << endl;
	cout << " X  Exit the print menu" << endl;
}

char get_user_command()
// Library facilities used: iostream
{
	char command;

	cout << "Enter choice: ";
	cin >> command; // Input of characters skips blanks and newline character

	return command;
}

int get_number()
// Library facilities used: iostream
{
	int result;

	cout << "Please enter a real number for the sequence: ";
	cin >> result;
	cout << result << " has been read." << endl;
	return result;
}