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
#include <iostream>
#include <iomanip>

using namespace std;

/// <summary>
/// Constructor
/// </summary>
AVL::AVL()
{
	root = nullptr;
	treeSize = 0;
}

/// <summary>
/// Destructor
/// </summary>
AVL::~AVL()
{
	Destroy(root);
}

/// <summary>
/// Removes a node and all of it's children.
/// </summary>
/// <param name="node">Node to be removed</param>
void AVL::Destroy(Node*& node)
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
int AVL::Size()
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
bool AVL::IsLeaf(Node* n)
{
	// we could check the nodes,
	// or we could just realize a height of 1
	// is a leaf
	if (n->height == 1)
	{
		return true;
	}

	return false;
}

/// <summary>
/// Prints a text-based graphical
/// representation of the AVL Tree.
/// </summary>
void AVL::Print()
{
	Print(root, treeSize);
}

// TODO: We're probably going to want move the 'cout' out of the function
/// <summary>
/// Prints a text-based graphical
/// representation of the AVL Tree.
/// </summary>
/// <param name="n"></param>
/// <param name="size"></param>
void AVL::Print(Node* n, int size)
{
	cout << setw(static_cast<int64_t>(4) * size) << "";

	if (n == nullptr)
		cout << "[Empty]" << endl;
	else if (IsLeaf(n))
		cout << n->val << " [leaf]" << endl;
	else
	{
		cout << n->val << endl;
		Print(n->left, size + 1);
		Print(n->right, size + 1);
	}
}

#pragma region AVL Tree Functions
/// <summary>
/// Inserts a value to the tree.
/// </summary>
/// <remarks>
/// Average O(log n)
/// Worst case O(log n)
/// </remarks>
/// <param name="v">Value to add to tree</param>
void AVL::Insert(int v)
{
	root = Insert(v, root);
}

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
Node* AVL::Insert(int v, Node*& node)
{
	// if the current location is empty, we create a new node
	if (node == nullptr)
	{
		treeSize++;					// Increment the total size of the tree
		return new Node(v);			// return a new node object
	}

	// if the value is less than the current node
	if (v < node->val)
	{
		// we insert a new node on the left side
		node->left = Insert(v, node->left);

		UpdateHeight(node);			// update height
		return Rebalance(node, v);		// rebalance nodes if necessary
	}
	// if the value is more than the current node
	else if (v > node->val)
	{
		// we insert a new node on the right side
		node->right = Insert(v, node->right);

		UpdateHeight(node);			// update height
		return Rebalance(node, v);		// rebalance nodes if necessary
	}

	// if the value is already present, return a warning
	cout << "Cannot have duplicate values in this tree" << endl;
	return node;
}

/// <summary>
/// 
/// </summary>
/// <param name="v"></param>
void AVL::Delete(int v)
{
	root = Delete(v, root);
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
			Node* successor = // min from right child?
			node = successor;
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

/// <remarks>
/// Average O(log n)
/// Worst case O(log n)
/// </remarks>
void AVL::Erase(int v, Node *& node)
{
	if (node == nullptr)
	{
		return;
	}
	if (v < node->val)
	{
		Erase(v, node->left);
	}
	else if (v > node->val)
	{
		Erase(v, node->right);
	}
	else
	{
		Erase(node);
	}
}

void AVL::Erase(Node *& node)
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
		Erase(node->val, node->left);
	}
}

/// <summary>
/// Searches the tree for a value.
/// </summary>
/// <remarks>
/// Average O(log n)
/// Worst case O(log n)
/// </remarks>
/// <param name="v">Value to search tree for</param>
/// <returns></returns>
Node* AVL::Search(int v)
{
	return Search(v, root);
}

/// <summary>
/// Searches a subtree, checking for a value.
/// </summary>
/// <remarks>
/// Average O(log n)
/// Worst case O(log n)
/// </remarks>
/// <param name="v">Value to search a subtree for</param>
/// <param name="node">Subtree to search in</param>
/// <returns>Node containing the value</returns>
Node* AVL::Search(int v, Node*& node)
{
	// if the current location is empty, the node doesn't exist
	if (node == nullptr)
	{
		cout << "Value does not exist in the tree" << endl;
		return nullptr;			// return a new node object
	}

	// if the value is less than the current node
	if (v < node->val)
	{
		return Search(v, node->left);
	}
	// if the value is more than the current node
	else if (v > node->val)
	{
		return Search(v, node->right);
	}

	// node value should equal the value we're searching for
	return node;
}
#pragma endregion

#pragma region Print Functions
/// <summary>
/// Prints the tree InOrder
/// Left, Root, Right
/// </summary>
/// <returns></returns>
string AVL::InOrder()
{
	return InOrder(root);
}

/// <summary>
/// Prints a subtree InOrder
/// Left, Root, Right
/// </summary>
/// <param name="n"></param>
/// <returns></returns>
string AVL::InOrder(Node* n)
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
string AVL::PreOrder()
{
	return PreOrder(root);
}

/// <summary>
/// Prints a subtree in PreOrder
/// Root, Left, Right
/// </summary>
/// <param name="n"></param>
/// <returns></returns>
string AVL::PreOrder(Node* n)
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
string AVL::PostOrder()
{
	return PostOrder(root);
}

/// <summary>
/// Prints a subtree tree in PostOrder
/// Left, Right, Root
/// </summary>
/// <param name="n"></param>
/// <returns></returns>
string AVL::PostOrder(Node* n)
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

void AVL::UpdateHeight(Node*& node)
{
	// calculate the new height of our node
	node->height =
		1 + max(GetHeight(node->left), GetHeight(node->right));
}

int AVL::GetHeight() {
	return GetHeight(root);
}

int AVL::GetHeight(Node* node) {
	if (node == nullptr) {
		return 0;
	}

	return node->height;
}
#pragma endregion