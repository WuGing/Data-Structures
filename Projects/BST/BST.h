#pragma once

#include "Node.h"
class BST
{
public:
	BST();
	~BST();
	Node *root;
	void insert(int v, Node *& node);
	int size();
	void print(Node *n, int size);
	void erase(int v, Node *& n);
	void eraseNode(Node *& n);
	void inorder(Node *n);
	void preorder(Node *n);
	void postorder(Node *n);
	void destroy(Node *& node);
	bool is_leaf(Node *n);
	int treeSize;
};

