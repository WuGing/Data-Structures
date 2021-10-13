/*
*I Joshua Sutherland have not used any code other than my
* own(or that in the textbook) for this project.I also have
* not used any function or data - structure from the Standard
* - Template Library.I understand that any violation of this
* disclaimer will result in a 0 for the project.
*/

#include "Queue.h"
#include "Graph.h"
#include "Searches.h"
#include <iostream>

using namespace std;
using namespace main_savitch_15;

void GraphInit(graph<int>& mGraph);
void Search(int g);

#define TOTAL_VERTEX 6

int main()
{
	//Initialize your graph using
		//add_edge and add_vertex
	graph<int> mGraph;
	cout << "Initializing graph...\n\n";
	GraphInit(mGraph);

	//Do a depth - first search and display the order of the vertices traversed
		//Display the order in which dfs is executed.
		//Use the sample graph that is in the book on page 754.
	cout << "Depth first traversal of graph: " << endl;
	cout << "First vertex displayed at head of print out." << endl;
	for (int i = 0; i <= TOTAL_VERTEX; i++)
	{
		depth_first(Search, mGraph, i);
		cout << "\n";
	}

	cout << endl;
	//Do a breadth - first search and display the order of the vertices traversed
		//Display the order in which bfs is executed.
		//Use the sample graph that is in the book on page 754.
	cout << "Bredth first traversal of graph: " << endl;
	cout << "First vertex displayed at head of print out." << endl;
	for (int i = 0; i <= TOTAL_VERTEX; i++)
	{
		breadth_first(Search, mGraph, i);
		cout << "\n";
	}
	
	cout << "\n\n";
	system("PAUSE");
	return 0;
}

void GraphInit(graph<int>& mGraph)
{

	for (int i = 0; i <= TOTAL_VERTEX; i++)
	{
		mGraph.add_vertex(i);
	}

	mGraph.add_edge(0, 1);
	mGraph.add_edge(2, 0);
	mGraph.add_edge(1, 3);
	mGraph.add_edge(3, 0);
	mGraph.add_edge(0, 4);
	mGraph.add_edge(3, 5);
	mGraph.add_edge(3, 6);
	mGraph.add_edge(6, 1);
}

void Search(int g)
{
	cout << g << " ";
}