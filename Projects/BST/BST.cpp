/*
* I Joshua Sutherland, Section 001, have not used any code other than my
* own (or that in the textbook) for this project.I also have not used any
* function or data-structure from the Standard - Template Library. I
* understand that any violation of this disclaimer will result in a 0 for
* the project.
*/

#include "BST.h"
#include <iostream>
#include <iomanip>

using namespace std;

BST::BST()
{
	root = nullptr;
	treeSize = 0;
};

BST::~BST()
{
	destroy(root);
};

void BST::destroy(Node *& node)
{
	if (node == nullptr)
		return;
	destroy(node->left);
	destroy(node->right);
	delete node;
	node = nullptr;
}

void BST::insert(int v, Node *& node)
{
	if (node == nullptr)
	{
		node = new Node(v);
		treeSize++;
	}
	else if (v < node->val)
		insert(v, node->left);
	else if (v > node->val)
		insert(v, node->right);
	else if (v == node->val)
		cout << "Cannot have duplicate values in this tree" << endl;
};

void BST::print(Node* n, int size)
{
	cout << setw(4 * size) << "";
	if (n == nullptr)
		cout << "[Empty]" << endl;
	else if (is_leaf(n))
		cout << n->val << " [leaf]" << endl;
	else
	{
		cout << n->val << endl;
		print(n->left, size+1);
		print(n->right, size+1);
	}
};

void BST::erase(int v, Node *& n)
{

	if (n == nullptr)
		return;
	if (v < n->val)
		erase(v, n->left);
	else if (v > n->val)
		erase(v, n->right);
	else eraseNode(n);
};

void BST::eraseNode(Node *& n)
{
	Node *temp;

	temp = n;

	if (n->left == nullptr)
	{
		n = n->right;
		delete temp;
		treeSize--;
	}

	else if (n->right == nullptr)
	{
		n = n->left;
		delete temp;
		treeSize--;
	}

	else
	{
		temp = n->left;
		while (temp->right != nullptr)
			temp = temp->right;
		n->val = temp->val;
		erase(n->val, n->left);
	}
}

void BST::inorder(Node *n)
{
	if (n == nullptr)
		return;
	inorder(n->left);
	cout << n->val << ' ';
	inorder(n->right);
};

void BST::preorder(Node *n)
{
	if (n == nullptr)
		return;
	cout << n->val << ' ';
	preorder(n->left);
	preorder(n->right);
};

void BST::postorder(Node *n)
{
	if (n == nullptr)
		return;
	postorder(n->left);
	postorder(n->right);
	cout << n->val << ' ';
};

bool BST::is_leaf(Node *n)
{
	if (n->left == nullptr && n->right == nullptr)
		return true;
	else 
		return false;
}

int BST::size()
{
	return treeSize;
};