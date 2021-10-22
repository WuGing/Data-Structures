#pragma once

using namespace std;

/// <summary>
/// A node class for use in an AVL tree
/// </summary>
class Node
{
public:
	// Constructor/Destructor
	Node(int v);
	~Node() {};
	
	// Properties
	int val;
	int height;
	Node* left;
	Node* right;
};