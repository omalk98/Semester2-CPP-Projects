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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Patient.h"
#include "utils.h"
using namespace std;
namespace sdds {
	Patient::Patient(int number, bool fileIO) : m_ticket(number), m_fileIOFlag{ fileIO } {}
	Patient::~Patient() {
		delete[] m_name;
		m_name = nullptr;
	}
	bool Patient::fileIO() const {
		return m_fileIOFlag;
	}
	void Patient::fileIO(bool fileIO) {
		m_fileIOFlag = fileIO;
	}
	bool Patient::operator==(const char c) const {
		return (type() == c);
	}
	bool Patient::operator==(const Patient& patient) const {
		return (type() == patient.type());
	}
	void Patient::setArrivalTime() {
		m_ticket.resetTime();
		cin.ignore();
	}
	Patient::operator Time() const {
		return m_ticket.operator Time();
	}
	int Patient::number() const {
		return m_ticket.number();;
	}
	ostream& Patient::csvWrite(ostream& ostr) const {
		ostr << type() << "," << m_name << "," << m_ohipNo << ",";
		m_ticket.csvWrite(ostr);
		return ostr;
	}
	istream& Patient::csvRead(istream& istr) {
		delete[] m_name;
		m_name = getcstr(nullptr, istr, ',');
		istr >> m_ohipNo;
		istr.ignore();
		m_ticket.csvRead(istr);
		return istr;
	}
	ostream& Patient::write(ostream& ostr) const {
		m_ticket.write(ostr);
		ostr << endl;
		for (auto i = 0; m_name[i] != '\0' && i < 25; ++i) {
			ostr << m_name[i];
		}
		ostr << ", OHIP: " << m_ohipNo;
		ostr.unsetf(ios::fixed);
		return ostr;
	}
	istream& Patient::read(istream& istr) {
		m_name = getcstr("Name: ", istr);
		m_ohipNo = getInt(100000000, 999999999, "OHIP: ", "Invalid OHIP Number, ");
		return istr;
	}
}