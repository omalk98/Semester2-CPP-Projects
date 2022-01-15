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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "LblShape.h"
namespace sdds {
	const char* LblShape::label() const {
		return m_label;
	}
	void LblShape::getSpecs(std::istream& in) {
		char label[128];
		in.getline(label, 128, ',');
		if (in) {
			m_label = new char[strlen(label) + 1];
			strcpy(m_label, label);
		}
	}
	LblShape::LblShape(){}
	LblShape::LblShape(const char* label) {
		if (label) {
			m_label = new char[strlen(label) + 1];
			strcpy(m_label, label);
		}
	}
	LblShape::~LblShape() {
		delete[] m_label;
		m_label = nullptr;
	}
}