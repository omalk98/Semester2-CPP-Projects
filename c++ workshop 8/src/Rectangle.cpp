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
#include "Rectangle.h"
using namespace std;
namespace sdds {
	Rectangle::Rectangle() : LblShape() {}
	Rectangle::Rectangle(const char* label, int width, int height) 
		: LblShape(label), m_width{ width }, m_height{ height } {}
	void Rectangle::getSpecs(std::istream& in) {
		int height = 0, width = 0;
		char comma = '\0';
		LblShape::getSpecs(in);
		in >> width >> comma >> height;
		in.ignore(1000, '\n');
		m_width = width;
		m_height = height;
	}
	void Rectangle::draw(std::ostream& os) const {
		if (label() != nullptr && m_width > 2 && m_height > 2) {
			os << "+" << setfill('-') << setw(m_width - 1) << "+" << endl
				<< setfill(' ') << "|" << setw(m_width - 2) << left << label() << "|" << endl << right;
			for (auto i = 0; i < m_height - 3; ++i) {
				os << "|" << setw(m_width - 1) << "|" << endl;
			}
			os << "+" << setfill('-') << setw(m_width - 1) << "+" << setfill(' ');
		}
	}
}