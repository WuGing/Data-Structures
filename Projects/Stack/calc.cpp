/* I Joshua Sutherland have not used any code other than
* my own(or that in the textbook) for this project.I also
* have not used any function or data - structure from the
* Standard - Template Library.I understand that any violation
* of this disclaimer will result in a 0 for the project.
*/

#include <iostream>
#include <fstream>
#include <string>
#include "stack1.h"

using namespace std;
using namespace main_savitch_7A;

bool isLeftParan(const char &entry);
bool isOperand(const char &entry);
bool isOperation(const char &entry);
bool stackIsLeftParan(const char &stackEntry);
bool stackIsPrecedent(const char &stackEntry, const char &entry);
bool isNull(const char &entry);

const char MULTIPLY = '*';
const char DIVIDE = '/';
const char ADD = '+';
const char SUBTRACT = '-';

int main()
{
	// pick a file to read in

	// read in a line of the file
	ifstream infixFile;
	char charHolder[20];
	int i;
	infixFile.open("tests.txt");
	stack<char> S = stack<char>();


	if (infixFile.fail())
	{
		cerr << "Could not open input file." << endl;
		exit(0);
	}

	while (infixFile && infixFile.peek() != EOF){

		// read in the line
		infixFile >> charHolder;
		i = 0;

		// do
		do
		{
			if (isNull(charHolder[i]))
				cout << endl;
			// if the next input is a "("
			if (isLeftParan(charHolder[i]))
				//read the left parenthesis and push it onto the stack
				S.push(charHolder[i++]);

			// else if the next input is a # or other operand
			else if (isdigit(charHolder[i]) || isOperand(charHolder[i]))
				// read the operand and write it to the output
				cout << charHolder[i++];

			// else if the next input is one of the operation symbols
			else if (isOperation(charHolder[i]))
			{
				while ( (!S.empty()) && (!stackIsLeftParan(S.top())) && (stackIsPrecedent(S.top(), charHolder[i])) )
				{
					//print the top operation and pop it
					cout << S.top();
					S.pop();
				}

				S.push(charHolder[i++]);
			}

			else
			{
				i++;
				while (!stackIsLeftParan(S.top()))
				{
					cout << S.top();
					S.pop();
				}
				if (stackIsLeftParan(S.top()) == false)
					cerr << "Unbalanced Parentheses. Halting..." << endl;
				if (stackIsLeftParan(S.top()))
					S.pop();
			}

		} while (charHolder[i] != NULL);

		while (!S.empty())
		{
			cout << S.top();
			S.pop();
		}

		cout << endl;
	}

	infixFile.close();
	system("PAUSE");
}

bool isOperand(const char &entry)
{
	char c = entry;
	if (c == ')')
		return false;
	if (!isdigit(c) && !isOperation(c))
		return true;
	else return false;
}

bool isOperation(const char &entry)
{
	char c = entry;
	if (c == '*' ||
		c == '/' ||
		c == '+' ||
		c == '-')
		return true;
	else return false;
}

bool isLeftParan(const char &entry)
{
	char c = entry;
	if (c == '(')
		return true;
	else return false;
}

bool stackIsPrecedent(const char &stackEntry, const char &entry)
{
	char se = stackEntry;
	char c = entry;

	switch (se)
	{
	case MULTIPLY:
			return true;
	case DIVIDE:
		if (c == MULTIPLY)
			return false;
		else
			return true;
	case ADD:
		if (c == MULTIPLY || c == DIVIDE)
			return false;
		else return true;
	case SUBTRACT:
		if (c == SUBTRACT || c == ADD)
			return true;
		else return false;
	}

}

bool stackIsLeftParan(const char &stackEntry)
{
	char c = stackEntry;
		if (c == '(')
			return true;
	else return false;
}

bool isNull(const char &entry)
{
	if (entry == NULL)
		return true;
	else return false;
}