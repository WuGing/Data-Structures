#include <iostream>
#include "Source.h"
#include "BST.h"

using namespace std;

int main()
{
	BST tree; // A sequence that we’ll perform tests on
	char choice;   // A command character entered by the user

	cout << "An empty tree has been created." << endl;

	do
	{
		DisplayMenu();
		choice = toupper(GetUserCommand());
		switch (choice)
		{
		case PRINT: 
			do
			{
				DisplayPrintChoiceMenu();
				choice = toupper(GetUserCommand());

				switch (choice)
				{
				case PRINT: 
					tree.Print();
					break;

				case PREORDER: 
					cout << tree.PreOrder();
					break;

				case INORDER: 
					cout << tree.InOrder();
					break;

				case POSTORDER: 
					cout << tree.PostOrder();
					break;

				case QUIT_PRINT:
					break;

				default: 
					cout << choice << " is invalid." << endl;
				}
			} while (choice != QUIT_PRINT);
			break;

		case SIZE: 
			cout << "Size is " << tree.Size() << '.' << endl;
			break;

		case INSERT: 
			tree.Insert(GetNumber());
			break;

		case ERASE: 
			tree.Delete(GetNumber());
			cout << "Number has been removed." << endl;
			break;

		case QUIT: cout << "Ridicule is the best test of truth." << endl;
			break;

		default:  
			cout << choice << " is invalid." << endl;
		}
	} while ((choice != QUIT));

	return EXIT_SUCCESS;
}

/// <summary>
/// 
/// </summary>
void DisplayMenu()
{
	cout << endl; // Print blank line before the menu
	cout << "The following choices are available: " << endl;
	cout << " P   Print options menu will be printed" << endl;
	cout << " S   Print the result from the size() function" << endl;
	cout << " I   Insert a new number with the insert(...) function" << endl;
	cout << " E   Erase a number from the tree with the erase(...) function" << endl;
	cout << " Q   Quit this test program" << endl;
}

/// <summary>
/// 
/// </summary>
void DisplayPrintChoiceMenu()
{
	cout << endl;
	cout << "The following choices are available: " << endl;
	cout << " P  The print() function will be called printing the tree" << endl;
	cout << " R  Print the tree using a preorder traversal" << endl;
	cout << " N  Print the tree using an inorder traversal" << endl;
	cout << " O  Print the tree using a postorder traversal" << endl;
	cout << " X  Exit the print menu" << endl;
}

/// <summary>
/// 
/// </summary>
/// <returns></returns>
char GetUserCommand()
{
	char command;

	cout << "Enter choice: ";
	cin >> command; // Input of characters skips blanks and newline character

	return command;
}

/// <summary>
/// 
/// </summary>
/// <returns></returns>
int GetNumber()
{
	int result;

	cout << "Please enter a real number for the sequence: ";
	cin >> result;
	cout << result << " has been read." << endl;
	return result;
}