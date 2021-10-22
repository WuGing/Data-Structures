/*
* I Joshua Sutherland, Section 001, have not used any code other than my
* own (or that in the textbook) for this project.I also have not used any
* function or data-structure from the Standard - Template Library. I
* understand that any violation of this disclaimer will result in a 0 for
* the project.
*/

#pragma once

#ifndef HEAP_SORT_
#define HEAP_SORT_
	void HeapSort();
#endif

#define HEAP_SORT 0x48
#define INSERT 0x49
#define PRINT 0x50
#define QUIT 0x51
#define REMOVE_FRONT 0x52
#define PRINT_TREE 0x54

const int ARRAY_SIZE = 20;
const int HEAP_SIZE = 20;
const int FRONT = 1;

	char GetUserCommand();
	int GetItem();
	void AllocateArray(int*& intArray, int size);
	void DisplayMenu();
