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
#include <iostream>
#include <string>
#include "Truck.h"
using namespace std;
namespace sdds {
	void Truck::setMaxCargo(double maxCargo) {
		m_MAX_KG_CAPACITY = maxCargo;
	}
	void Truck::setCurrentCargo(double cargo) {
		m_currentCapacity = cargo;
	}
	Truck::Truck() : MotorVehicle() {
		m_MAX_KG_CAPACITY = 0;
		m_currentCapacity = 0;
	}

	Truck::Truck(const char* lp, unsigned int year, double capacity, const char* loc)
	: MotorVehicle(lp, year, loc) {
		setMaxCargo(capacity);
		setCurrentCargo();
	}

	bool Truck::addCargo(double cargo) {
		if (m_currentCapacity == m_MAX_KG_CAPACITY) {
			return false;
		}
		else if (m_currentCapacity + cargo < m_MAX_KG_CAPACITY) {
			setCurrentCargo(m_currentCapacity + cargo);
			return true;
		}
		else if (m_currentCapacity + cargo >= m_MAX_KG_CAPACITY) {
			setCurrentCargo(m_MAX_KG_CAPACITY);
			return true;
		}
		return false;
	}

	bool Truck::unloadCargo() {
		if (m_currentCapacity > 0) {
			setCurrentCargo();
			return true;
		}
		return false;
	}

	ostream& Truck::write(std::ostream& os)const {
		MotorVehicle::write(os);
		os << " | " << m_currentCapacity << "/" << m_MAX_KG_CAPACITY;
		return os;
	}

	istream& Truck::read(std::istream& in) {
		MotorVehicle::read(in);
		char entry[128] = "\0";
		cout << "Capacity: ";
		in.getline(entry, 10);
		setMaxCargo(stoi(entry));
		entry[0] = '\0';
		cout << "Cargo: ";
		in.getline(entry, 10);
		setCurrentCargo(stoi(entry));
		entry[0] = '\0';
		return in;
	}

	ostream& operator<<(ostream& os, const Truck& vehicle) {
		vehicle.write(os);
		return os;
	}

	istream& operator>>(istream& in, Truck& vehicle) {
		vehicle.read(in);
		return in;
	}

}