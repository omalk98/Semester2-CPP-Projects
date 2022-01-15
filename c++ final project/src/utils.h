//==============================================
// Name:           Omar Hussein
// Student Number: 118073204
// Email:          ohussein2@myseneca.ca
// Section:        NAA
// Final Project:  Milestone 1
// Date:		   Mar 13, 2021
//==============================================
// I decalre that all the code included in this module
// including the header have been written by myself.
// No content was copied other than the code provided
// in the workshop file by the professor.
#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H
#include <iostream>
namespace sdds {
	extern bool debug; // making sdds::debug variable global to all the files
					   // which include: "utils.h"
	int getTime(); // returns the time of day in minutes
	int getInt(const char* prompt = nullptr);
	int getInt(int min, int max, const char* prompt = nullptr,
		const char* errorMessage = nullptr, bool showRangeAtError = true);
	char* getcstr(const char* prompt = nullptr,
		std::istream& istr = std::cin, char delimiter = '\n');
	int validateNum(const char* string = nullptr, bool negative = true);

	template <typename type>
	void removeDynamicElement(type* array[], int index, int& size) {
		delete array[index];
		for (int j = index; j < size; j++) {
			array[j] = array[j + 1];
		}
		size--;
	}
}
#endif // !SDDS_UTILS_H_

