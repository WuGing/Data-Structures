/*
* Adelson-Velsky and Landis (AVL) Tree
*
* This is a self-balancing Binary Search Tree (BST).
* The height difference of two child subtrees can not
* be more than one.
*
* Lookup, Insertion, and Deletion all take O(log n) time,
* in terms of average and worst case, n being the number
* of nodes in the tree prior to operation.
*
* Insertion and Deletion may require the tree to be
* rebalanced by one or more rotations.
*/

#include "AVL.h"
#include "../BST/BST.cpp"
#include "../BST/Node.cpp"
#include <iostream>
#include <iomanip>

using namespace std;

/// <summary>
/// Constructor
/// </summary>
AVL::AVL()
{ }

/// <summary>
/// Destructor
/// </summary>
AVL::~AVL()
{ }

#pragma region AVL Tree Functions
/// <summary>
/// Inserts a value to the tree, comparing
/// to the value at our current node
/// </summary>
/// <remarks>
/// Average O(log n)
/// Worst case O(log n)
/// </remarks>
/// <param name="v">Value to add to tree</param>
/// <param name="node">Place in tree being evaluated</param>
/// <returns></returns>
Node* AVL::Insert(int v, Node*& node)
{
	// if the current location is empty, we create a new node
	if (node == nullptr)
	{
		treeSize++;					// Increment the total size of the tree
		return new Node(v);			// return a new node object
	}
	// if the current location is not empty
	else {
		Node* temp;

		// if the value is less than the current node
		if (v < node->val)
		{
			// we insert a new node on the left side
			temp = Insert(v, node->left);
			temp->parent = node;
			node->left = temp;
		}
		// if the value is more than the current node
		else if (v > node->val)
		{
			// we insert a new node on the right side
			temp = Insert(v, node->right);
			temp->parent = node;
			node->right = temp;
		}

		// TODO: Going to need to re-add some sort of DUP reponse
		UpdateHeight(node);				// update height
		return Rebalance(node, v);		// rebalance nodes if necessary
	}
}

/// <summary>
/// 
/// </summary>
/// <param name="v"></param>
/// <param name="node"></param>
/// <returns></returns>
Node* AVL::Delete(int v, Node*& node)
{
	if (v < node->val)
	{
		node->left = Delete(v, node->left);

		UpdateHeight(node);
		return Rebalance(node, v);
	}
	else if (v > node->val)
	{
		node->right = Delete(v, node->right);

		UpdateHeight(node);
		return Rebalance(node, v);
	}
	else if (v == node->val)
	{
		// some delete needs to happen here

		// we're going to have to check if there are children
		if (node->right != nullptr && node->left != nullptr)
		{
			Node* successor = nullptr;	// min from right child?
			// node = successor;
		}
		else if (node->left == nullptr)
		{
			node = node->right;
			treeSize--;
		}
		else if (node->right == nullptr)
		{
			node = node->left;
			treeSize--;
		}
		else {
			// no children in node being removed
		}
	}
	else {
		// value doesn't exist in tree
		cout << "Value not found in tree" << endl;
	}
}
#pragma endregion

#pragma region Balance Functions
/// <summary>
/// Returns the high difference of a 
/// nodes children
/// </summary>
/// <param name="node"></param>
/// <returns></returns>
int AVL::GetBalance(Node*& node)
{
	// if node is null, well... 
	if (node == nullptr)
	{
		return 0;
	}

	// get the difference between the heights
	return GetHeight(node->right) - GetHeight(node->left);
}

/// <summary>
/// Corrects an imbalance at a given node 
/// due to an addition in the right subtree 
/// of nodes' right child
/// </summary>
/// <param name="node"></param>
Node* AVL::RotateLeft(Node*& node)
{
	Node* nodeRight = node->right;		// grab the right child of node (this will be our new top)
	node->right = nodeRight->left;		// the node's right child to nodeRight's left child
	nodeRight->left = node;				// set nodeRight's left child to node

	// calculate the new height
	node->height = 1 + max(GetHeight(node->left), GetHeight(node->right));
	nodeRight->height = 1 + max(GetHeight(nodeRight->left), GetHeight(nodeRight->right));

	return nodeRight;					// nodeRight is now node (ie, is now top)
}

/// <summary>
/// Corrects an imbalance at a given node
/// due to an addition in the left subtree
/// of node's left child
/// </summary>
/// <param name="node"></param>
Node* AVL::RotateRight(Node*& node)
{
	Node* nodeLeft = node->left;		// grab the left child of node (this will be our new top)
	node->left = nodeLeft->right;		// Set node's left child to nodeLeft's right child
	nodeLeft->right = node;				// Set nodeLeft's right child to node

	// calculate the new height
	node->height = 1 + max(GetHeight(node->left), GetHeight(node->right));
	nodeLeft->height = 1 + max(GetHeight(nodeLeft->left), GetHeight(nodeLeft->right));

	return nodeLeft;					// nodeLeft is now node (ie, is now top)
}

/// <summary>
/// Checks if a node is balanced
/// </summary>
/// <param name="node"></param>
/// <returns></returns>
Node* AVL::Rebalance(Node*& node, int val)
{
	int balance = GetBalance(node);

	// Right Right case
	if (balance > TREE_RIGHT && val > node->right->val)
	{
		return RotateLeft(node);
	}

	// Left Left case
	if (balance < TREE_LEFT && val < node->left->val)
	{
		return RotateRight(node);
	}

	// Right Left case
	// Corrects an imbalance at a given node
	// due to an addition in the left subtree
	// of the node's right child
	if (balance > TREE_RIGHT && val < node->right->val)
	{
		node->right = RotateRight(node->right);
		return RotateLeft(node);
	}

	// Left Right case
	// Corrects an imbalance at a given node 
	// due to an addition in the right subtree
	// of node's left child
	if (balance < TREE_LEFT && val > node->left->val)
	{
		node->left = RotateLeft(node->left);
		return RotateRight(node);
	}

	UpdateHeight(node);

	return node;
}
#pragma endregion