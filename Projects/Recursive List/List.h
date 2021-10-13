#pragma once

#include <cstdlib>
#include "Node.h"

namespace list_2
{
	class List
	{
		Node *head;

		// helper function for the destructor
		// add other helper functions here to complete your program.
		// they should all contain one or more Node* as parameters
		void addEnd(Node *n, int d);
		void destroy(Node *n);
		void print(Node *n);
		void insert(Node *n, int d);
		void find(Node *n, int &d);
		void size(Node *n, int &size);
	public:
		// postcondition: list is initialized
		List(){head = NULL;}
		// postcondition: all nodes are destroyed using recursion
		~List();

		// postcondition: add element d at the end of the list
		//                using recursion
		void addEnd(int d);
		// postcondition: print the list using recursion
		void print();
		// precondition: list is in sorted order
		//                 (don't use addEnd with this function)
		// postcondition: d is inserted into the list so the list maintains
		//                sorted order. using recursison.
		void insert(int d);

		// postcondition: if d is in the list then find returns true
		//                else find returns false
		bool find (int d);

		// postcondition: size is returned. Must be calculated using recursion.
		int size();

	};
}