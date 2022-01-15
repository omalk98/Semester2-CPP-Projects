//==============================================
// Name:           Omar Hussein
// Student Number: 118073204
// Email:          ohussein2@myseneca.ca
// Section:        NAA
// Workshop:       7 (lab)
// Date:		   Mar 17, 2021
//==============================================
// I decalre that all the code included in this module
// including the header have been written by myself.
// No content was copied other than the code provided
// in the workshop file by the professor.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>
#include "cstring.h"
#include "MotorVehicle.h"
using namespace std;
namespace sdds {
	void MotorVehicle::setaddress(const char* address) {
		strCpy(m_currentAddress, address);
	}
	void MotorVehicle::setlp(const char* lp) {
		if (lp) {
			strCpy(m_licensePlate, lp);
		}
	}
	void MotorVehicle::setyear(unsigned int year) {
		m_yearManufactured = year;
	}
	MotorVehicle::MotorVehicle() {
		m_licensePlate[0] = '\0';
		strCpy(m_currentAddress, "Factory");
		m_yearManufactured = 0;
	}

	MotorVehicle::MotorVehicle(const char* lp, unsigned int year, const char* loc) : MotorVehicle() {
		setyear(year);
		if (lp) {
			if (strLen(lp) <= 8) {
				setlp(lp);
			}
		}
		if (strCmp(loc, "Factory")) {
			moveTo(loc);
		}
	}
	void MotorVehicle::moveTo(const char* address) {
		if (address){
			if (strCmp(m_currentAddress, address)) {
				cout << "|" << setw(8) << m_licensePlate << "| "
					 << "|" << setw(20) << m_currentAddress << " ---> "
					 << left << setw(20) << address << "|" << right << endl;
				setaddress(address);
			}
		}
	}

	ostream& MotorVehicle::write(ostream& os) const {
		os << "| " << m_yearManufactured << " | "
			<< m_licensePlate << " | " << m_currentAddress;
		return os;
	}

	istream& MotorVehicle::read(istream& in) {
		char entry[128] = "\0";
		cout << "Built year: ";
		in.getline(entry, 5);
		setyear(stoi(entry));
		entry[0] = '\0';
		cout << "License plate: ";
		in.getline(entry, 9, '\n');
		setlp(entry);
		entry[0] = '\0';
		cout << "Current location: ";
		in.getline(entry, 64, '\n');
		setaddress(entry);
		return in;
	}
	ostream& operator<<(ostream& os, const MotorVehicle& vehicle) {
		vehicle.write(os);
		return os;
	}
	istream& operator>>(istream& in, MotorVehicle& vehicle) {
		vehicle.read(in);
		return in;
	}
}