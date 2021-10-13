#pragma once

namespace list_1
{
	struct Node
	{
		int data;
		Node *next;

		// Constructor
		// Postcondition: 
		Node(int d)
		{ 
			data = d;
			next = nullptr;
		};
	};
}