//==============================================
// Name:           Omar Hussein
// Student Number: 118073204
// Email:          ohussein2@myseneca.ca
// Section:        NAA
// Workshop:       2 (diy)
// Date:	       Jan 26, 2021
//==============================================

#include <iostream>
#include "Population.h"
#include "File.h"
#include "cstring.h"
using namespace std;
namespace sdds {

	int noOfRecs;
	Population* population;

	void sort() {
		int i, j;
		Population temp;
		for (i = noOfRecs - 1; i > 0; i--) {
			for (j = 0; j < i; j++) {
				if (population[j].m_popCount > population[j + 1].m_popCount) {
					temp = population[j];
					population[j] = population[j + 1];
					population[j + 1] = temp;
				}
			}
		}
	}

	bool load(Population& pop)
	{
		bool ok = false;
		int num = 0;
		char postal[8];
		if (read(postal) && read(num))
		{
			pop.m_pCode = new char[strLen(postal) + 1];
			strCpy(pop.m_pCode, postal);
			pop.m_popCount = num;
			ok = true;
		}
		return ok;
	}

	bool load(const char filename[])
	{
		bool ok = false;
		int i = 0;

		if (openFile(filename))
		{
			noOfRecs = noOfRecords();
			population = new Population[noOfRecs];

			for (i = 0; i < noOfRecs; ++i)
				if (!load(population[i]))
					break;
			if (i != noOfRecs)
				cout << "Error: incorrect number of records read; the data is possibly corrupted." << endl;
			else ok = true;

			closeFile();
		}
		else
			cout << "Could not open data file: " << filename << endl;

		return ok;
	}
	int display(const Population& pop)
	{
		cout << pop.m_pCode << ": ";
		cout.width(6);
		cout << pop.m_popCount << endl;
		return pop.m_popCount;
	}

	void display()
	{
		int total = 0;
		cout << "Postal Code: population" << endl;
		cout << "-------------------------" << endl;
		sort();
		for (int i = 0; i < noOfRecs; ++i)
		{
			cout.width(2);
			cout << i + 1 << "- ";
			total += display(population[i]);
		}
		cout << "-------------------------" << endl;
		cout << "Population of Canada: " << total << endl;
	}

	void deallocateMemory()
	{
		for (int i = 0; i < noOfRecs; ++i)
		{
			delete[] population[i].m_pCode;
			population[i].m_pCode = nullptr;
		}
		delete[] population;
		population = nullptr;
	}
}