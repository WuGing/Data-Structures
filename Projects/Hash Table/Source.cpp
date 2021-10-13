/*
*I Joshua Sutherland have not used any code other than my
* own(or that in the textbook) for this project.I also have
* not used any function or data - structure from the Standard
* - Template Library.I understand that any violation of this
* disclaimer will result in a 0 for the project.
*/

#include <iostream>
#include <fstream>
#include <string>
#include "Hash.h"

using namespace std;
void ReadTable(Table<double>&);
void EvaluateCompounds(Table<double>&);
double EvalMolecule(Table<double>& hash, string molecule);
double EvalAtom(Table<double>& hash, string atom, int quantity);

int main()
{
	Table<double> table;
	ReadTable(table);

	EvaluateCompounds(table);

	system("PAUSE");
	return EXIT_SUCCESS;
}

void ReadTable(Table<double>& hash)
{
	ifstream file;
	string input;
	file.open("PeriodicTableElements.txt", ios::in);

	if (file.is_open())
	{
		while (file.good())
		{
			// Retrieves Atomic Number
			getline(file, input, ' ');

			// Retrieves Symbol
			getline(file, input, ' ');
			string symbol = input.c_str();

			// Retrieves Atomic Weight
			getline(file, input);
			double weight = atof(input.c_str());

			hash.insert(weight, symbol);
		}
	}
	file.close();
}

void EvaluateCompounds(Table<double>& hash)
{
	ifstream compoundFile;
	string input;
	compoundFile.open("formulas.txt.txt", ios::in);
	while (compoundFile.good())
	{
		double total = 0;
		string molecule;
		getline(compoundFile, molecule);
		if (!molecule.empty())
			cout << molecule << " = " << EvalMolecule(hash, molecule) << endl;
	}
	compoundFile.close();
}

double EvalMolecule(Table<double>& hash, string molecule)
{
	string atom = "0";
	atom.clear();
	int quantity = 0;
	const int PLACESHIFT = 10;
	double total = 0;

	for (int i = 0; i < (int)molecule.length(); i++)
	{
		if (isupper(molecule[i]))
		{
			if (!atom.empty())
			{
				total += EvalAtom(hash, atom, quantity);
				atom.clear();
				quantity = 0;
			}
		atom += molecule[i];
		}

		else if (isdigit(molecule[i]))
		{
			quantity = (quantity * PLACESHIFT);
			quantity += molecule[i] - '0';
		}

		else if (islower(molecule[i]))
		{
			atom += molecule[i];
		}

		else if (molecule[i] == '(')
		{
			if (!atom.empty())
			{
				total += EvalAtom(hash, atom, quantity);
				atom.clear();
				quantity = 0;
			}

			double subTotal = 0;
			int subQuantity = 0;

			subTotal = EvalMolecule(hash, molecule.substr(i + 1));
			while (i < (int) molecule.length() && molecule[i] != ')'){ i++; }
			while (i + 1 < (int)molecule.length() && isdigit(molecule[i+1]))
			{
				++i;
				subQuantity = (subQuantity * PLACESHIFT);
				subQuantity += molecule[i] - '0';
			}
			if (subQuantity == 0)
			{
				subQuantity += 1;
			}

			total += (subTotal * subQuantity);
		}
		else if (molecule[i] == ')')
		{
			total += EvalAtom(hash, atom, quantity);
			return total;
		}
	}
	if (!atom.empty())
		total += EvalAtom(hash, atom, quantity);

	return total;
}

double EvalAtom(Table<double>& hash, string atom, int quantity)
{
	if (quantity < 1)
		quantity = 1;

	double singleWeight = hash[atom];
	double totalWeight = singleWeight * quantity;

	return totalWeight;
}