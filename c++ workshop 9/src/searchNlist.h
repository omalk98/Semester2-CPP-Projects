//==============================================
// Name:           Omar Hussein
// Student Number: 118073204
// Email:          ohussein2@myseneca.ca
// Section:        NAA
// Workshop:       9 (lab)
// Date:		   Mar 29, 2021
//==============================================
// I decalre that all the code included in this module
// including the header have been written by myself.
// No content was copied other than the code provided
// in the workshop file by the professor.
#ifndef SDDS_SEARCHNLIST_H
#define SDDS_SEARCHNLIST_H
#include <iostream>
#include "Collection.h"
namespace sdds {
	//This function requires any classes that are being passed to it to 
	//have implemented a comparison operator overload and the array size 
	//to be iterated on must be specified. This function also requiers a 
	//destination array that will hold the found matches for the specified
	//key value which must be specified
	template <typename T, typename U>
	bool search(Collection<T>& collection, T* arr , int size, U key) {
		bool valid = false;
		for (auto i = 0; i < size; ++i) {
			if (arr[i] == key) {
				collection.add(arr[i]);
				valid = true;
			}
		}
		return valid;
	}

	//This function requires any classes that are being passed to it to 
	//have implemented an extraction operator overload and the array size 
	//to be iterated on must be specified. This function does not require
	//a title and will only print a title if supplied as a parameter
	template <typename T>
	void listArrayElements(T* arr, int size, const char* title = nullptr) {
		if (title) std::cout << title << std::endl;
		for (auto i = 0; i < size; ++i) {
			std::cout << i + 1 << ": " << arr[i] << std::endl;
		}
	}
}

#endif //!SDDS_SEARCHNLIST_H