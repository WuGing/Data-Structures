/*
* I Joshua Sutherland, Section 001, have not used any code other than my
* own (or that in the textbook) for this project.I also have not used any
* function or data-structure from the Standard - Template Library. I
* understand that any violation of this disclaimer will result in a 0 for
* the project.
*/

#include "heap.h"
#include "Source.h"
#include <math.h>
#include <iostream>
#include <iomanip>

using namespace std;

heap::heap(int size)
{
	heapSize = size;
	heapArray = new int[heapSize];
	currentIndex = 1;
}

heap::heap(const heap& oldHeap)
{
	heapSize = oldHeap.heapSize;
	currentIndex = oldHeap.currentIndex;
	heapArray = new int[oldHeap.heapSize];
	for (int i = 0; i < oldHeap.heapSize; i++)
	{
		heapArray[i] = oldHeap.heapArray[i];
	}
}

heap::~heap()
{
	delete [] heapArray;
	heapArray = nullptr;
}

void heap::Insert(int item)
{
	if (currentIndex >= heapSize)
		cout << " Cannot add item to heap. Heap is full" << endl;
	else 
	{
		currentIndex++;
		// insert item
		heapArray[currentIndex - 1] = item;
		// bubble up
		BubbleUp(currentIndex - 1);
	}
}

int heap::RemoveFront()
{
	if (currentIndex == 0)
		throw string("Heap is empty");
	else
	{
		int temp = heapArray[FRONT];
		heapArray[FRONT] = heapArray[currentIndex - 1];
		currentIndex--;
		if (currentIndex > 0)
			BubbleDown(FRONT);
		return temp;
	}
}

void heap::Print()
{
	cout << " ";
	for (int i = 1; i < currentIndex; i++)
		cout << heapArray[i] << " ";
	cout << endl;
}

void heap::PrintTree(int index, int depth)
{
	if (index < currentIndex){
		// print out indent dependent upon where we are in the array 
		cout << setw(TAB * depth) << "";
		// if index is 1 then don't print an indent
		if (heapArray[index] == 0)
			cout << "[Empty]" << endl;
		// if index is out of current allocation
		else if (index >= currentIndex)
		{
		}
		else if (IsLeaf(index))
			cout << heapArray[index] << " [leaf]" << endl;
		else
		{
			cout << heapArray[index] << endl;
			// left side
			PrintTree(index * CHILD, depth + 1);
			// right side
			PrintTree((index * CHILD) + 1, depth + 1);
		}
	}
}

void heap::BubbleUp(int index)
{
	// variables to help with shifting
	int parentIndex, temp;
	// check that index is valid
	if (index != 0)
	{
		// get the parentIndex
		parentIndex = GetParentIndex(index);
		// check that the parent is larger than the child
		if (heapArray[parentIndex] > heapArray[index])
		{
			// if parent was larger, swap
			temp = heapArray[parentIndex];
			heapArray[parentIndex] = heapArray[index];
			heapArray[index] = temp;
			// check again
			BubbleUp(parentIndex);
		}
	}
}

void heap::BubbleDown(int index)
{
	// variables to help with the shifting
	int leftChildIndex, rightChildIndex, minIndex, temp;

	// retrieve the values of the child indexs
	leftChildIndex = GetLeftChildIndex(index);
	rightChildIndex = GetRightChildIndex(index);

	// check if the indexes exceed the current index
	if (rightChildIndex >= currentIndex)
	{
		// if both indexes exceed current index, return
		if (leftChildIndex >= currentIndex)
			return;
		// else the min index is the left child
		else minIndex = leftChildIndex;
	}
	// if indexes do not exceed heap size
	else
	{
		// if value of left child is less than right
		if (heapArray[leftChildIndex] <= heapArray[rightChildIndex])
			// left child is minIndex
			minIndex = leftChildIndex;
		else
			// else right child is minIndex
			minIndex = rightChildIndex;
	}
	// shift position of the current index if it is in the wrong place
	if (heapArray[index] > heapArray[minIndex])
	{
		// temp for holding moving value
		temp = heapArray[minIndex];
		heapArray[minIndex] = heapArray[index];
		heapArray[index] = temp;
		// check if now sorted properly
		BubbleDown(minIndex);
	}
}

int heap::GetParentIndex(int childIndex)
{
	// check if child is a left child
	if (childIndex % 2 == 0)
	{
		return childIndex / 2;
	}
	// child is a right child
	else
	{
		return (int)ceilf(childIndex / 2);
	}
}

int heap::GetLeftChildIndex(int parentIndex)
{
	if (parentIndex == 0)
		throw string("Heap is not valid");
	else
		return (parentIndex * CHILD);
}

int heap::GetRightChildIndex(int parentIndex)
{
	if (parentIndex == 0)
		throw string("Heap is not valid");
	else
		return (parentIndex * CHILD) + 1;
}

bool heap::IsLeaf(int index)
{
	bool leaf = NULL;
	int leftChildIndex, rightChildIndex;
	leftChildIndex = GetLeftChildIndex(index);
	rightChildIndex = GetRightChildIndex(index);

	if (index == 0)
		throw string("Error in heap");
	else
	{
		if (rightChildIndex >= currentIndex)
		{
			if (leftChildIndex >= currentIndex)
				leaf = true;
			else if (heapArray[leftChildIndex] == NULL)
				leaf = true;
			else
				leaf = false;
		}
		else
		{
			if (heapArray[rightChildIndex] == NULL)
			{
				if (heapArray[leftChildIndex] == NULL)
					leaf = true;
				else
					leaf = false;
			}
			else
				leaf = false;
		}
	}
	return leaf;
}