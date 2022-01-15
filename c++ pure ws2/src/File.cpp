//==============================================
// Name:           Omar Hussein
// Student Number: 118073204
// Email:          ohussein2@myseneca.ca
// Section:        NAA
// Workshop:       2 (diy)
// Date:	       Jan 26, 2021
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <string>
#include "File.h"

#include <cstdio>
using namespace std;
namespace sdds {
	ifstream fptr;
	bool openFile(const char filename[])
	{
		fptr.open(filename);
		return !fptr.fail();
	}

	int noOfRecords()
	{
		int noOfRecs = 0;
		string line;
		while (!fptr.eof())
		{
			fptr >> line;
			++noOfRecs;
		}
		fptr.clear();
		fptr.seekg(0);
		return noOfRecs;
	}

	void closeFile()
	{
		if (fptr.is_open()) fptr.close();
	}

	bool read(char* name)
	{
		fptr.getline(name, 8, ',');
		return !fptr.fail();
	}

	bool read(int& x)
	{
		fptr >> x;
		return !fptr.fail();
	}
}