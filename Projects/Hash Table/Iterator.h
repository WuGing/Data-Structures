/*
*I Joshua Sutherland have not used any code other than my
* own(or that in the textbook) for this project.I also have
* not used any function or data - structure from the Standard
* - Template Library.I understand that any violation of this
* disclaimer will result in a 0 for the project.
*/

// Template CLASS PROVIDED: Iterator 

#pragma once
#include "Node.h"

namespace list_1
{
	template<typename RecordType>
	class Iterator
	{
	public:
		// Constructor
		Iterator<RecordType> (Node<RecordType> *np)
		{
			n = np;
		}

		// precondition: is_item is true
		// post condition n points to the next item in the list
		void operator++()
		{
			if (is_item())
				n = n->next;
		}

		// precondition: 
		// postcondition: returns true if there is a valid item
		bool is_item()
		{
			if (n)
				return true;
			else
				return false;
		}

		std::string get_name()
		{
			return n->symbol;
		}

		// precondition: is_item == true
		// postcondition returns data that n is pointing at
		RecordType operator* ()
		{
			if (is_item())
				return n->data;
		}

	private:
		Node<RecordType>* n;

	};
}
