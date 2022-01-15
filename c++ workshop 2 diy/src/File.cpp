//==============================================
// Name:           Omar Hussein
// Student Number: 118073204
// Email:          ohussein2@myseneca.ca
// Section:        NAA
// Workshop:       2 (diy)
// Date:	       Jan 26, 2021
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds {
	FILE* fptr;
	bool openFile(const char filename[]) {
		fptr = fopen(filename, "r");
		return fptr != NULL;
	}
	int noOfRecords() {
		int noOfRecs = 0;
		char ch;
		while (fscanf(fptr, "%c", &ch) == 1) {
			noOfRecs += (ch == '\n');
		}
		rewind(fptr);
		return noOfRecs;
	}
	void closeFile() {
		if (fptr) fclose(fptr);
	}
	bool read(char* post) {
		bool ok = fscanf(fptr, " %[^,],", post) == 1;
		return ok;
	}
	bool read(int& pop) {
		bool ok = fscanf(fptr, " %d\n", &pop) == 1;
		return ok;
	}
}