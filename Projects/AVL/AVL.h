#pragma once
#include <string>
#include "Node.h"

constexpr int BALANCED			= 0;
constexpr int TREE_LEFT			= -1;
constexpr int TREE_RIGHT		= 1;
constexpr int LEFT_TREE_TWO		= -2;
constexpr int RIGHT_TREE_TWO	= 2;

class AVL
{
private:

	int treeSize;

	void Print(Node* n, int size);

	// Tree Balancers
	int GetBalance(Node*& node);
	// Tree rotations
	Node* Rebalance(Node*& node, int val);
	Node* RotateLeft(Node*& node);
	Node* RotateRight(Node*& node);
	void UpdateHeight(Node*& node);
	int GetHeight(Node* n);

	Node* Search(int v, Node*& node);

	bool IsLeaf(Node* n);

	string InOrder(Node* n);
	string PostOrder(Node* n);
	string PreOrder(Node* n);

public:
	AVL();
	~AVL();

	Node* root;
	
	int Size();
	int GetHeight();

	// Tree Operations
	void Insert(int v);
	Node* Insert(int v, Node*& node);
	void Delete(Node*& node);
	Node* Search(int v);
	void Space();

	// Print functions
	void Print();
	string InOrder();
	string PostOrder();
	string PreOrder();
	
	//	void Erase(int v, Node *& n);
	//	void EraseNode(Node *& n);
};

