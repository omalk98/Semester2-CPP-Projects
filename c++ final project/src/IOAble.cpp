//==============================================
// Name:           Omar Hussein
// Student Number: 118073204
// Email:          ohussein2@myseneca.ca
// Section:        NAA
// Final Project:  Milestone 2
// Date:		   Mar 18, 2021
//==============================================
// I decalre that all the code included in this module
// including the header have been written by myself.
// No content was copied other than the code provided
// in the workshop file by the professor.
#include <iostream>
#include "IOAble.h"
using namespace std;
namespace sdds {
	IOAble::~IOAble() {};
	ostream& operator<<(std::ostream& os, const IOAble& io) {
		return io.write(os);
	}

	istream& operator>>(std::istream& in, IOAble& io) {
		return io.read(in);
	}
}
