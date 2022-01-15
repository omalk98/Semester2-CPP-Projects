//==============================================
// Name:           Omar Hussein
// Student Number: 118073204
// Email:          ohussein2@myseneca.ca
// Section:        NAA
// Final Project:  Milestone 3
// Date:		   Mar 23, 2021
//==============================================
// I decalre that all the code included in this module
// including the header have been written by myself.
// No content was copied other than the code provided
// in the workshop file by the professor.
#include <iostream>
#include "Ticket.h"
using namespace std;
namespace sdds {
	Ticket::Ticket(int number) : m_number{ number } {}
	Ticket::operator Time() const {
		return m_time;
	}
	int Ticket::number() const {
		return m_number;
	}
	void Ticket::resetTime() {
		m_time.setToNow();
	}
	ostream& Ticket::csvWrite(ostream& ostr) const {
		return ostr << m_number << "," << m_time;
	}
	istream& Ticket::csvRead(istream& istr) {
		istr >> m_number;
		istr.ignore();
		return istr >> m_time;
	}
	ostream& Ticket::write(ostream& ostr) const {
		return ostr << "Ticket No: " << m_number << ", Issued at: " << m_time;
	}
	istream& Ticket::read(istream& istr) {
		return csvRead(istr);
	}
}