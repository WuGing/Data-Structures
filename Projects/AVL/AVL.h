#pragma once
#include <string>
#include "Node.h"

constexpr int BALANCED = 0;
constexpr int TREE_LEFT = -1;
constexpr int TREE_RIGHT = 1;
constexpr int LEFT_TREE_TWO = -2;
constexpr int RIGHT_TREE_TWO = 2;

class AVL
{
private:
	// Properties
	int treeSize;
	Node* root;

	// Tree Functions
	void Destroy(Node*& node);
	void Print(Node* n, int size);
	bool IsLeaf(Node* node);

	// Print Functions
	string InOrder(Node* node);
	string PostOrder(Node* node);
	string PreOrder(Node* node);

	// Tree Balancers
	int GetBalance(Node*& node);
	Node* Rebalance(Node*& node, int val);
	Node* RotateLeft(Node*& node);
	Node* RotateRight(Node*& node);
	void UpdateHeight(Node*& node);
	int GetHeight(Node* n);

	Node* Search(int v, Node*& node);


public:
	// Constructor/Destructor
	AVL();
	~AVL();

	int GetHeight();
	int Size();
	void Print();

	// Tree Modifier Operations
	void Insert(int v);
	Node* Insert(int v, Node*& node);

	void Delete(int v);
	Node* Delete(int v, Node*& node);

	// TODO: Playing around with deletes
	void Erase(int v, Node*& node);
	void Erase(Node*& node);

	// void Space();
	Node* Search(int v);

	// Print Order Functions
	string InOrder();
	string PostOrder();
	string PreOrder();
};

