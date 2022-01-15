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
#include "CovidPatient.h"
#include "Ticket.h"
using namespace std;
namespace sdds {
   int nextCovidTicket = 1;

   CovidPatient::CovidPatient() : Patient(nextCovidTicket++) {}
   char CovidPatient::type() const {
	   return 'C';
   }
   istream& CovidPatient::csvRead(istream& istr) {
	   Patient::csvRead(istr);
	   istr.ignore();
	   nextCovidTicket = number() + 1;
	   return istr;
   }
   istream& CovidPatient::read(istream& istr) {
	   if (fileIO()) csvRead(istr);
	   else Patient::read(istr);
	   return istr;
   }
   ostream& CovidPatient::write(ostream& ostr) const {
	   if (fileIO()) csvWrite(ostr);
	   else {
		   ostr << "COVID TEST" << endl;
		   Patient::write(ostr);
		   ostr << endl;
	   }
	   return ostr;
   }
}