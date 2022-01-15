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
#ifndef SDDS_SHAPE_H
#define SDDS_SHAPE_H
#include <iostream>
namespace sdds {
	class Shape {
	public:
		virtual ~Shape() = 0;
		virtual void draw(std::ostream& os)const = 0;
		virtual void getSpecs(std::istream& in) = 0;
	};
	std::ostream& operator <<(std::ostream& os, const Shape& shape);
	std::istream& operator >>(std::istream& in, Shape& shape);
}
#endif //!SDDS_SHAPE_H