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
#ifndef SDDS_LINE_H
#define SDDS_LINE_H
#include <iostream>
#include "LblShape.h"
namespace sdds {
	class Line : public LblShape {
		int m_length = 0;
	public:
		Line();
		Line(const char* label, int len);
		void getSpecs(std::istream& in)override;
		void draw(std::ostream& os)const override;
	};
}
#endif //!SDDS_LINE_H