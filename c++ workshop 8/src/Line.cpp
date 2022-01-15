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
#include <iomanip>
#include "Line.h"
using namespace std;
namespace sdds {
	Line::Line() : LblShape() {}
	Line::Line(const char* label, int len) : LblShape(label), m_length{ len } {}
	void Line::getSpecs(std::istream& in) {
		int len = 0;
		LblShape::getSpecs(in);
		in >> len;
		in.ignore(1000, '\n');
		m_length = len;
	}
	void Line::draw(std::ostream& os) const {
		if (label() != nullptr && m_length > 2) {
			os << label() << endl << setfill('=') << setw(m_length) << "";
			os.fill(' ');
		}
	}
}