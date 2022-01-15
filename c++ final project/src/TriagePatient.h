#ifndef SDDS_TRIAGEPATIENT_H
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
#define SDDS_TRIAGEPATIENT_H
#include <iostream>
#include "Patient.h"
namespace sdds {
	class TriagePatient : public Patient {
		char* m_symptoms{ nullptr };
	public:
		TriagePatient();
		~TriagePatient() override;
		char type()const override;
		std::istream& csvRead(std::istream& istr) override;
		std::ostream& csvWrite(std::ostream& ostr)const override;
		std::istream& read(std::istream& istr) override;
		std::ostream& write(std::ostream& ostr)const override;
	};
}
#endif // !SDDS_TRIAGEPATIENT_H


