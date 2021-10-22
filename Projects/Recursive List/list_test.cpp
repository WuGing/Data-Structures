// FILE: list_test.cpp
// An interactive test program for the list class


// *** NOTE ***
// you should not have to change this file.
// *** NOTE ***

#include <cctype>       // Provides toupper
#include <iostream>     // Provides cout and cin
#include <cstdlib>      // Provides EXIT_SUCCESS
#include "List.h"  // With value_type defined as an int

using namespace std;
using namespace list_2;

// PROTOTYPES for functions used by this test program:
void DisplayMenu( );
// Postcondition: A menu of choices for this program has been written to cout.

char GetUserCommand( );
// Postcondition: The user has been prompted to enter a one character command.
// The next character has been read (skipping blanks and newline characters), 
// and this character has been returned.

int GetNumber( );
// Postcondition: The user has been prompted to enter a real number. The
// number has been read, echoed to the screen, and returned by the function.



int main( )
{
    List test; // A list that we’ll perform tests on
    char choice;   // A command character entered by the user
    
    cout << "I have initialized an empty sequence of real numbers." << endl;

    do
    {
        DisplayMenu( );
        choice = toupper(GetUserCommand( ));
        switch (choice)
        {
			
            case 'S': cout << "Size is " << test.size( ) << '.' << endl;
                      break;
            case 'I': test.insert(GetNumber( ));
                      break;
			case 'F': if (test.find(GetNumber()))
						  cout << "The number is in the list" << endl;
					  else
						  cout << "The number is not in the list" << endl;
					  break;					
            case 'A': test.addEnd(GetNumber( ));
                      break;
			case 'P': test.print();
					  break;
			case 'Q': cout << "Ridicule is the best test of truth." << endl;
                      break;
            default:  cout << choice << " is invalid." << endl;
        }
    }
    while ((choice != 'Q'));

    return EXIT_SUCCESS;
}

void DisplayMenu( )
// Library facilities used: iostream.h
{
    cout << endl; // Print blank line before the menu
    cout << "The following choices are available: " << endl;
    cout << " P   Print a copy of the entire sequence" << endl;
    cout << " S   Print the result from the size( ) function" << endl;
	cout << " F   Find a number in the list using the find() function" << endl;
    cout << " I   Insert a new number with the insert(...)" << endl;
    cout << " A   Add a new number with the addEnd(...) function" << endl;
    cout << " Q   Quit this test program" << endl;
}

char GetUserCommand( )
// Library facilities used: iostream
{
    char command;

    cout << "Enter choice: ";
    cin >> command; // Input of characters skips blanks and newline character

    return command;
}

int GetNumber( )
// Library facilities used: iostream
{
   int result;
    
    cout << "Please enter an integer: ";
    cin  >> result;
    cout << result << " has been read." << endl;
    return result;
}
