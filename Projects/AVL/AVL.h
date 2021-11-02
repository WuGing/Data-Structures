#pragma once
#include <string>
#include "../BST/BST.h"
#include "../BST/Node.h"

constexpr int BALANCED = 0;
constexpr int TREE_LEFT = -1;
constexpr int TREE_RIGHT = 1;
constexpr int LEFT_TREE_TWO = -2;
constexpr int RIGHT_TREE_TWO = 2;

class AVL : public BST
{
private:
	// Tree Modifiers
	Node* Insert(int v, Node*& node);
	Node* Delete(int v, Node*& node);

	// AVL Specific Functions
	// Tree Balancers
	int GetBalance(Node*& node);
	Node* Rebalance(Node*& node, int val);
	Node* RotateLeft(Node*& node);
	Node* RotateRight(Node*& node);

public:
	// Constructor/Destructor
	AVL();
	~AVL();

	// Shouldn't need any special public 
	// functions aside from what BST gives us
};

