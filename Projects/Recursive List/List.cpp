/* I Joshua Sutherland have not used any code other than 
 * my own(or that in the textbook) for this project.I also 
 * have not used any function or data - structure from the 
 * Standard - Template Library.I understand that any violation 
 * of this disclaimer will result in a 0 for the project.
 */

#include "List.h"
#include <iostream>

using namespace std;

namespace list_2{

	List::~List()
	{
		destroy(head);
	};

	void List::destroy(Node *n)
	{
		if (n == nullptr)
			return;

		if (n->data != NULL)
		{
			Node *temp = n;
			n = temp->next;
			delete temp;
			temp = nullptr;
		}

		if (n != nullptr)
			destroy(n);
	}

	void List::addEnd(int d)
	{
		if (head == nullptr)
			head = new Node(d);

		else
			addEnd(head, d);
	};

	void List::addEnd(Node* n, int d)
	{
		if (n->next != nullptr)
			addEnd(n->next, d);

		else
			n->next = new Node(d);
	}

	bool List::find(int d)
	{
		if (head == nullptr)
			return false;

		else if (head->data == d)
			return true;

		else
			find(head->next, d);

		return d;
	};

	void List::find(Node *n, int &d)
	{
		if (n == nullptr)
		{
			d = 0;
			return;
		}

		else if (n->data == d)
		{
			d = 1;
			return;
		}

		else
			find(n->next, d);
	};

	void List::insert(int d)
	{
		if (head == nullptr)
			head = new Node(d);

		else
			insert(head, d);
	};

	void List::insert(Node *n, int d)
	{
		if (n->next != nullptr && d >= n->next->data)
			insert(n->next, d);

		else if (d < n->data)
		{
			Node* temp = new Node(d);	// stored on the heap
			temp->next = head;
			head = temp;
		}

		else
		{	
			Node *temp = n;			// current position
			Node *NN = new Node(d);	// new node that holds the int d
			// d needs to be added to the place where n is pointing
			NN->next = temp->next;		// the next of the new node is the current node
			n->next = NN;					// current position of n becomes the 
		}
	}

	void List::print()
	{
		if (head == nullptr)
			return;

		else
			print(head);
	};

	void List::print(Node* n)
	{
		if (n == nullptr)
			return;

		else
		{
			cout << n->data << endl;
			print(n->next);
		}
		
	};

	int List::size()
	{
		int listSize = 0;

		if (head == nullptr)
			return listSize;

		else
			size(head, listSize);

		return listSize;
	};

	void List::size(Node* n, int &listSize)
	{
		if (n == nullptr)
			return;

		else
			size(n->next, ++listSize);

	}
}