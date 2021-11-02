#pragma once
#include <string>
#include "Node.h"

class BST
{
private:
	// Tree Functions
	void Destroy(Node*& node);
	void Print(Node* n, int size);
	bool IsLeaf(Node* n);
	Node* Search(int v, Node*& node);

	// Print Functions
	string InOrder(Node* node);
	string PreOrder(Node* node);
	string PostOrder(Node* node);

	// Tree Modifiers
	virtual Node* Insert(int v, Node*& node);
	virtual Node* Delete(int v, Node*& node);
	Node* Delete(Node*& node);

	Node* MinValue(Node*& node);
	Node* GetInOrderSuccessor(Node*& node, Node*& root);

protected:
	int GetHeight(Node* node);

public:
	// Constructor/Destructor
	BST();
	~BST();

	// Properties
	int treeSize;
	Node* root;

	void UpdateHeight(Node*& node);
	int GetHeight();
	int Size();
	void Print();

	// Tree Modifier Operations
	void Insert(int v);
	void Delete(int v);

	// void Space();
	Node* Search(int v);

	// Print Order Functions
	string InOrder();
	string PreOrder();
	string PostOrder();
};

