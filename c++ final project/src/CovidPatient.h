//==============================================
// Name:           Omar Hussein
// Student Number: 118073204
// Email:          ohussein2@myseneca.ca
// Section:        NAA
// Final Project:  Milestone 4
// Date:		   Mar 30, 2021
//==============================================
// I decalre that all the code included in this module
// including the header have been written by myself.
// No content was copied other than the code provided
// in the workshop file by the professor.
#ifndef SDDS_COVIDPATIENT_H_
#define SDDS_COVIDPATIENT_H_
#include <iostream>
#include "Patient.h"
namespace sdds {
	class CovidPatient : public Patient {
	public:
		CovidPatient();
		char type()const override;
		std::istream& csvRead(std::istream& istr) override;
		std::istream& read(std::istream& istr) override;
		std::ostream& write(std::ostream& ostr)const override;
	};
}
#endif // !SDDS_COVIDPATIENT_H_



