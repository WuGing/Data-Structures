#pragma once

using namespace std;

class Node
{
public:
	Node(int v);
	~Node(){};
	Node *left;
	Node *right;
	int val;
};