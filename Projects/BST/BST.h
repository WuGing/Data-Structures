#pragma once
#include <string>
#include "Node.h"

class BST
{
private:
	// Properties
	int treeSize;
	Node* root;

	// Tree Functions
	void Destroy(Node*& node);
	void Print(Node* n, int size);
	bool IsLeaf(Node* n);

	// Print Functions
	string InOrder(Node* node);
	string PreOrder(Node* node);
	string PostOrder(Node* node);

	// Tree Modifiers
	void Insert(int v, Node*& node);
	void Delete(int v, Node*& node);
	void Delete(Node*& node);

public:
	// Constructor/Destructor
	BST();
	~BST();

	int Size();
	void Print();

	// Tree Modifier Operations
	void Insert(int v);
	void Delete(int v);
	
	// void Space();
	// Node* Search(int v);

	// Print Order Functions
	string InOrder();
	string PreOrder();
	string PostOrder();
};

