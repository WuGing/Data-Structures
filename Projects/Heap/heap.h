/*
* I Joshua Sutherland, Section 001, have not used any code other than my
* own (or that in the textbook) for this project.I also have not used any
* function or data-structure from the Standard - Template Library. I
* understand that any violation of this disclaimer will result in a 0 for
* the project.
*/

#pragma once
#include "Source.h"
class heap
{

public:
	// class -structors
	heap(int size = HEAP_SIZE + 1);
	heap(const heap& oldHeap);
	~heap();

	// member variables
	const int FRONT = 1;
	const int CHILD = 2;
	const int TAB = 4;
	int * heapArray;
	int heapSize;
	int currentIndex;

	// functions
	int RemoveFront();
	void Insert(int item);
	void Print();
	void PrintTree(int index, int depth = 0);

private:
	bool IsLeaf(int index);
	int GetParentIndex(int childIndex);
	int GetLeftChildIndex(int childIndex);
	int GetRightChildIndex(int childIndex);
	void BubbleUp(int index);
	void BubbleDown(int index);
};

