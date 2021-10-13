// Template CLASS PROVIDED: Iterator 

#pragma once
#include "Node.h"

namespace list_1
{
	class Iterator
	{
	public:
		// Constructor
		Iterator (Node *np);

		// precondition: is_item is true
		// post condition n points to the next item in the list
		void operator++();

		// precondition: 
		// postcondition: returns true if there is a valid item
		bool is_item();

		// precondition: is_item == true
		// postcondition returns data that n is pointing at
		int operator* ();

	private:
		Node* n;

	};
}
