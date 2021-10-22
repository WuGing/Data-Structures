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
void BST::Destroy(Node *& node)
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

#pragma region BST Functions
void BST::Insert(int v)
{
	Insert(v, root);
}

void BST::Insert(int v, Node *& node)
{
	if (node == nullptr)
	{
		node = new Node(v);
		treeSize++;
	}
	else if (v < node->val)
	{
		Insert(v, node->left);
	}
	else if (v > node->val)
	{
		Insert(v, node->right);
	}
	else if (v == node->val)
	{
		cout << "Cannot have duplicate values in this tree" << endl;
	}
}

/// <summary>
/// 
/// </summary>
/// <param name="v"></param>
void BST::Delete(int v)
{
	Delete(v, root);
}

/// <summary>
/// 
/// </summary>
/// <param name="v"></param>
/// <param name="node"></param>
void BST::Delete(int v, Node *& node)
{
	// if the node is null, the value doesn't exist
	if (node == nullptr)
	{
		cout << "Value doesn't exist in tree" << endl;
		return;
	}
	if (v < node->val)
	{
		Delete(v, node->left);
	}
	else if (v > node->val)
	{
		Delete(v, node->right);
	}
	else
	{
		Delete(node);
	}
}

/// <summary>
/// 
/// </summary>
/// <param name="node"></param>
void BST::Delete(Node *& node)
{
	Node *temp;

	temp = node;

	if (node->left == nullptr)
	{
		node = node->right;
		delete temp;
		treeSize--;
	}
	else if (node->right == nullptr)
	{
		node = node->left;
		delete temp;
		treeSize--;
	}
	else
	{
		temp = node->left;
		while (temp->right != nullptr)
		{
			temp = temp->right;
		}
		node->val = temp->val;
		Delete(node->val, node->left);
	}
}

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
string BST::InOrder(Node *n)
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
string BST::PreOrder(Node *n)
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
string BST::PostOrder(Node *n)
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