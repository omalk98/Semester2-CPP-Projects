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
#include <iostream>
#include "TriagePatient.h"
#include "utils.h"
using namespace std;
namespace sdds {
   int nextTriageTicket = 1;

   TriagePatient::TriagePatient() : Patient(nextTriageTicket++){}
   TriagePatient::~TriagePatient() {
	   delete[] m_symptoms;
	   m_symptoms = nullptr;
   }
   char TriagePatient::type() const {
	   return 'T';
   }
   istream& TriagePatient::csvRead(istream& istr) {
	   delete[] m_symptoms;
	   Patient::csvRead(istr);
	   istr.ignore();
	   m_symptoms = getcstr(nullptr, istr);
	   nextTriageTicket = number() + 1;
	   return istr;
   }
   ostream& TriagePatient::csvWrite(ostream& ostr) const {
	   Patient::csvWrite(ostr);
	   return ostr << "," << m_symptoms;
   }
   istream& TriagePatient::read(std::istream& istr) {
	   if (fileIO()) csvRead(istr);
	   else {
		   delete[] m_symptoms;
		   Patient::read(istr);
		   m_symptoms = getcstr("Symptoms: ", istr);
	   }
	   return istr;
   }
   ostream& TriagePatient::write(ostream& ostr) const {
	   if (fileIO()) csvWrite(ostr);
	   else {
		   ostr << "TRIAGE" << endl;
		   Patient::write(ostr);
		   ostr << endl << "Symptoms: " << m_symptoms << endl;
	   }
	   return ostr;
   }
}