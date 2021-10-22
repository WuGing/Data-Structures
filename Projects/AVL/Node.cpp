/*
* Node class that represents a node in an AVL tree.
* This node type supports 32-bit integers.
*/

#include "Node.h"

using namespace std;

/// <summary>
/// Node constructor
/// </summary>
/// <param name="v">Value to be stored in the node</param>
Node::Node(int v)
{
	val = v;					// value of the node
	left = right = nullptr;		// new nodes have no children
	height = 1;					// nodes are always added as a leaf
};