/*
* Binary Search Tree
*
* This is an ordered, or sorted, binary tree.
* The tree is rooted, with values greater than
* the root being in the right subtree, and values
* lesser than the root being in the left subtree.
*
* Space, Search, Insert, and Delete all have a
* worst case Time Complexity of O(n).
* Search, Insert, and Delete have an average
* time complexity of O(log n), while Space
* maintains an average of O(n).
*/

#include "BST.h"
#include <iostream>
#include <iomanip>
#include <list>

using namespace std;

/// <summary>
/// Constructor
/// </summary>
BST::BST()
{
	root = nullptr;
	treeSize = 0;
}

/// <summary>
/// Destructor
/// </summary>
BST::~BST()
{
	Destroy(root);
}

/// <summary>
/// Removes a node and all of it's children.
/// </summary>
/// <param name="node">Node to be removed</param>
void BST::Destroy(Node*& node)
{
	// if the node is null, we can return
	if (node == nullptr)
	{
		return;
	}

	// We need to remove the nodes children before
	// we can remove the node itself
	Destroy(node->left);
	Destroy(node->right);

	// delete the node
	delete node;
	// set the pointer to null
	node = nullptr;
}

/// <summary>
/// 
/// </summary>
/// <returns></returns>
int BST::Size()
{
	return treeSize;
}

// TODO: Should IsLeaf be a function of Node?
/// <summary>
/// Checks if a given node is a leaf:
/// this means that the node has no
/// children.
/// </summary>
/// <param name="n"></param>
/// <returns></returns>
bool BST::IsLeaf(Node* n)
{
	if (n->left == nullptr && n->right == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/// <summary>
/// Prints a text-based graphical 
/// representation of the Binary
/// Search Tree.
/// </summary>
void BST::Print()
{
	Print(root, treeSize);
}

// TODO: We're going to want to move the 'cout' out of the function
/// <summary>
/// Prints a text-based graphical 
/// representation of the Binary
/// Search Tree.
/// </summary>
/// <param name="n"></param>
/// <param name="size"></param>
void BST::Print(Node* n, int size)
{
	cout << setw(static_cast<int64_t>(4) * size) << "";

	if (n == nullptr)
	{
		cout << "[Empty]" << endl;
	}
	else if (IsLeaf(n))
	{
		cout << n->val << " [leaf]" << endl;
	}
	else
	{
		cout << n->val << endl;
		Print(n->left, size + 1);
		Print(n->right, size + 1);
	}
}

void BST::UpdateHeight(Node*& node)
{
	node->height =
		1 + max(GetHeight(node->left), GetHeight(node->right));
}

int BST::GetHeight()
{
	return GetHeight(root);
}

int BST::GetHeight(Node* node)
{
	if (node == nullptr)
	{
		return 0;
	}

	return node->height;
}

#pragma region BST Functions
/// <summary>
/// Inserts a value to the tree.
/// </summary>
/// <remarks>
/// Average O(log n)
/// Worse case O(log n)
/// </remarks>
/// <param name="v">Value to add to tree</param>
void BST::Insert(int v)
{
	root = Insert(v, root);
}

/// <summary>
/// Insert a value to a subtree.
/// </summary>
/// <remarks>
/// </remarks>
/// <param name="v"></param>
/// <param name="node"></param>
/// <returns></returns>
Node* BST::Insert(int v, Node*& node)
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
			temp->parent = node;				// might be able to remove this
			node->left = temp;
		}
		// if the value is more than the current node
		else if (v > node->val)
		{
			// we insert a new node on the right side
			temp = Insert(v, node->right);
			temp->parent = node;				// might be able to remove this too
			node->right = temp;
		}

		// TODO: Going to need to re-add some sort of DUP response
		UpdateHeight(node);		// update height
		return node;			// rebalance nodes if necessary
	}
}

/// <summary>
/// Delete a value from the tree.
/// </summary>
/// <param name="v"></param>
void BST::Delete(int v)
{
	root = Delete(v, root);
}

/// <summary>
/// Delete a value from a subtree.
/// </summary>
/// <param name="v"></param>
/// <param name="node"></param>
Node* BST::Delete(int v, Node*& node)
{
	// if the node is null, the value doesn't exist
	if (node == nullptr)
	{
		cout << "Value doesn't exist in tree" << endl;
		return node;
	}
	// if the value is in the left tree
	if (v < node->val)
	{
		node->left = Delete(v, node->left);
	}
	// if the value is in the right tree
	else if (v > node->val)
	{
		node->right = Delete(v, node->right);
	}
	else
	{
		return Delete(node);
	}
	return node;
}

/// <summary>
/// Deletes a node from the tree.
/// </summary>
/// <remarks>
/// There are three possible scenarios
/// 1) The Node we're deleting is a leaf
/// 2) The Node we're deleting has one child
/// 3) The Node we're deleting has two children
/// </remarks>
/// <param name="node"></param>
Node* BST::Delete(Node*& node)
{
	Node* temp;

	temp = node;

	// 1. Node has no children
	// we simply remove the leaf from the tree
	if (node->left == nullptr && node->right == nullptr)
	{
		// almost seems overly simple...
		treeSize--;
		return nullptr;
	}

	// 2. Node only has one child
	if (node->left == nullptr)
	{
		temp = node->right;
		delete node;
		treeSize--;
		return temp;
	}
	else if (node->right == nullptr)
	{
		temp = node->left;
		delete node;
		treeSize--;
		return temp;
	}

	// 3. Node has two children
	else
	{
		// find inorder successor of the node.
		// copy contents of the inorder successor to the node
		// and delete the inorder successor. Note
		// that inorder predecessor can also be used.
		temp = MinValue(node->right);

		// copy the inorder successor's content to this node
		node->val = temp->val;
		
		// Delete the inorder successor
		node->right = Delete(node->val, node->right);
		treeSize--;
	}

	return node;
}

/// <summary>
/// 
/// </summary>
/// <param name="node"></param>
/// <param name="some"></param>
/// <returns></returns>
Node* BST::GetInOrderSuccessor(Node*& node, Node*& root)
{
	// if right subtree of node is not null, then
	// successor lies in right subtree.
	if (node->right != nullptr)
	{
		// return the node with minimum key value
		// in the right subtree
		return MinValue(node->right);
	}

	// if the right subtree of node is null, then
	// successor is one of the ancestors.
	Node* parent = node->parent;
	// travel up using ths parent pointer until
	// we see a node which is left child of it's parent
	while (parent != nullptr && root == parent->right) {
		root = parent;
		parent = parent->parent;
	}

	return parent;
}

Node* BST::MinValue(Node*& node)
{
	Node* current = node;

	while (current->left != nullptr)
	{
		current = current->left;
	}

	return current;
}

/// <summary>
/// Searches the tree for a value.
/// </summary>
/// <remarks>
/// </remarks>
/// <param name="v"></param>
/// <returns></returns>
Node* BST::Search(int v)
{
	return Search(v, root);
}

/// <summary>
/// Searches a subtree, checking for a value.
/// </summary>
/// <param name="v"></param>
/// <param name="node"></param>
/// <returns></returns>
Node* BST::Search(int v, Node*& node)
{
	// if the current location is empty, the node doesn't exist
	if (node == nullptr || node->val == v)
	{
		// TODO: re-add handling for the case in which it's null
		// because, source.cpp will need something for that.
		return node;
	}

	// if the value is less than the current node
	if (v < node->val)
	{
		return Search(v, node->left);
	}

	// if the value is more than the current node
	return Search(v, node->right);
}
#pragma endregion

#pragma region Print Functions
/// <summary>
/// Prints the tree InOrder
/// Left, Root, Right
/// </summary>
/// <returns></returns>
string BST::InOrder()
{
	return InOrder(root);
}

/// <summary>
/// Prints a subtree InOrder
/// Left, Root, Right
/// </summary>
/// <param name="n"></param>
/// <returns></returns>
string BST::InOrder(Node* n)
{
	if (n == nullptr)
	{
		return "";
	}

	string inOrder;

	string left = InOrder(n->left);
	string right = InOrder(n->right);

	if (!left.empty())
	{
		inOrder += left + " ";
	}

	inOrder += std::to_string(n->val);

	if (!right.empty())
	{
		inOrder += " " + right;
	}

	return inOrder;
}

/// <summary>
/// Prints the tree in PreOrder
/// Root, Left, Right
/// </summary>
/// <returns></returns>
string BST::PreOrder()
{
	return PreOrder(root);
}

/// <summary>
/// Prints a subtree in PreOrder
/// Root, Left, Right
/// </summary>
/// <param name="n"></param>
/// <returns></returns>
string BST::PreOrder(Node* n)
{
	if (n == nullptr)
	{
		return "";
	}

	string preOrder;

	preOrder += std::to_string(n->val);

	string left = PreOrder(n->left);
	string right = PreOrder(n->right);

	if (!left.empty())
	{
		preOrder += " " + left;
	}

	if (!right.empty())
	{
		preOrder += " " + right;
	}

	return preOrder;
}

/// <summary>
/// Prints the tree in PostOrder
/// Left, Right, Root
/// </summary>
/// <returns></returns>
string BST::PostOrder()
{
	return PostOrder(root);
}

/// <summary>
/// Prints a subtree tree in PostOrder
/// Left, Right, Root
/// </summary>
/// <param name="n"></param>
/// <returns></returns>
string BST::PostOrder(Node* n)
{
	if (n == nullptr)
	{
		return "";
	}

	string postOrder;

	string left = PostOrder(n->left);
	string right = PostOrder(n->right);

	if (!left.empty())
	{
		postOrder += left + " ";
	}

	if (!right.empty())
	{
		postOrder += right + " ";
	}

	postOrder += std::to_string(n->val);

	return postOrder;
}
#pragma endregion