/*
* I Joshua Sutherland, Section 001, have not used any code other than my
* own (or that in the textbook) for this project.I also have not used any
* function or data-structure from the Standard - Template Library. I
* understand that any violation of this disclaimer will result in a 0 for
* the project.
*/

#include "heap.h"
#include "Source.h"
#include <iostream>
#include <ctype.h>

using namespace std;

int main()
{
	// non-interactive portion
	cout << " Creating default heap of size 20..." << endl;
	heap defaultHeap;
	char choice;
	// interactive portion
	do 
	{
		DisplayMenu();
		choice = toupper(GetUserCommand());
		switch (choice)
		{
		case HEAP_SORT: HeapSort();
			break;
		case INSERT: 
			int item;
			item = (GetItem());
			cout << "Inserting " << item << " into the heap." << endl;
			defaultHeap.Insert(item);
			break;
		case REMOVE_FRONT: 
			cout << " Removing front item from heap..." << endl;
			cout << " " <<  defaultHeap.RemoveFront() << " removed from heap." << endl;
			break;
		case PRINT: 
			cout << " Printing the heap..." << endl;
			defaultHeap.Print();
			break;
		case PRINT_TREE: 
			cout << " Printing the heap as a tree..." << endl;
			defaultHeap.PrintTree(FRONT);
			break;
		case QUIT:
			break;
		default: cout << choice << " is invalid." << endl;
		}

	} while (choice != QUIT);

	return 0;
}

void HeapSort()
{
	cout << "\nPerforming HeapSort..." << endl;

	int * intArray = nullptr;
	// create an array and fill it
	cout << "\nCreating array of 20 random elements..." << endl;
	AllocateArray(intArray, ARRAY_SIZE);
	
	cout << "\nUnsorted array: ";
	// print out the array that we just created
	for (int i = 0; i < ARRAY_SIZE; i++)
		cout << "" << intArray[i] << " ";

	// create a local heap...
	heap heapTest;

	cout << "\n\nCreating heap and filling with array items..." << endl;
	// one by one fill the heap...
	for (int i = 0; i < ARRAY_SIZE; i++)
		heapTest.Insert(intArray[i]);

	for (int i = 0; i < ARRAY_SIZE; i++)
		intArray[i] = heapTest.RemoveFront();

	cout << "\nPrinting sorted array...\n" << endl;
	for (int i = 0; i < ARRAY_SIZE; i++)
		cout << "" << intArray[i] << " ";
	cout << endl;

}

void AllocateArray(int*& intArray, int size)
{
	intArray = new int[size];

	for (int i = 0; i < size; i++)
	{
		intArray[i] = (rand() % 20);
	}
}

void DisplayMenu()
{
	cout << endl;
	cout << " H   Performs a default HeapSort" << endl;
	cout << " I   Insert an item into the heap" << endl;
	cout << " R   Remove the first item on the heap" << endl;
	cout << " P   Perform a linear print of the heap" << endl;
	cout << " T   Print the heap as a tree" << endl;
	cout << " Q   Quit the program" << endl;
}

char GetUserCommand()
// Library facilities used: iostream
{
	char command;

	cout << " Enter choice: ";
	cin >> command; // Input of characters skips blanks and newline character

	return command;
}


int GetItem()
// Library facilities used: iostream
{
	int integer;
	bool ok = false;

	while (!ok){
		cout << " Enter integer: ";
		// Input of characters skips blanks and newline character
		cin >> integer;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << " Please provide an integer" << endl;
		}
		else
		{
			ok = true;
			return integer;
		}
	}
}