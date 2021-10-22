#include <iostream>
#include "Source.h"
#include "Node.h"
#include "AVL.h"

using namespace std;

int main()
{
	AVL tree;		// A sequence that we'll perform tests on
	char choice;	// A command character entered by the user

	cout << "An empty tree has been created." << endl;

	do
	{
		DisplayMenu();
		choice = toupper(GetUserCommand());

		switch (choice)
		{
		case HEIGHT:
			cout << "Height of tree is: " << tree.GetHeight() << endl;
			break;

		case INSERT:
			tree.Insert(GetNumber());
			break;

		case PRINT:
			tree.Print();
			break;

		case QUIT:
			cout << "Ridicule is the best test of truth." << endl;
			break;

		default:
			cout << choice << " is invalid." << endl;
		}
	} while ((choice != QUIT));

	return EXIT_SUCCESS;
}

/// <summary>
/// Prints the menu for our application
/// </summary>
void DisplayMenu()
{
	cout << endl; // Print blank line before the menu
	cout << "The following choices are available: " << endl;
	cout << " H   Print the height of the tree" << endl;
	cout << " I   Insert a new number with the Insert(...) function" << endl;
	cout << " P   Print the tree" << endl;
	cout << " Q   Quit this test program" << endl;
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
	cout << endl;

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