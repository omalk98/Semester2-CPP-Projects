//==============================================
// Name:           Omar Hussein
// Student Number: 118073204
// Email:          ohussein2@myseneca.ca
// Section:        NAA
// Workshop:       8 (lab)
// Date:		   Mar 22, 2021
//==============================================
// I decalre that all the code included in this module
// including the header have been written by myself.
// No content was copied other than the code provided
// in the workshop file by the professor.
#include <iostream>
#include "Shape.h"
using namespace std;
namespace sdds {
	Shape::~Shape(){}
	ostream& operator<<(ostream& os, const Shape& shape) {
		shape.draw(os);
		return os;
	}
	istream& operator>>(istream& in, Shape& shape) {
		shape.getSpecs(in);
		return in;
	}
}