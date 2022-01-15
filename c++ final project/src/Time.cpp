//==============================================
// Name:           Omar Hussein
// Student Number: 118073204
// Email:          ohussein2@myseneca.ca
// Section:        NAA
// Final Project:  Milestone 1
// Date:		   Mar 13, 2021
//==============================================
// I decalre that all the code included in this module
// including the header have been written by myself.
// No content was copied other than the code provided
// in the workshop file by the professor.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include "Time.h"
#include "utils.h"
using namespace std;
namespace sdds {
	Time& Time::setToNow() {
		if (!debug)
			m_min = getTime();
		else {
			cout << "Enter current time: ";
			read(cin);
		}
		return *this;
	}
	Time::Time(unsigned int min) {
		m_min = min;
	}
	std::ostream& Time::write(std::ostream& ostr) const {
		int min = m_min % 60, hour = m_min / 60;
		char old = ostr.fill('0');
		ostr << setw(2) << hour << ":" << setw(2) << min;
		ostr.fill(old);
		return ostr;
	}

	std::istream& Time::read(std::istream& istr) {
		char ch = 0;
		int a = -1, b = -1;
		istr >> a >> ch >> b;
		if (a < 0 || ch != ':' || b < 0) istr.setstate(ios::failbit);
		else m_min = a * 60 + b;
		return istr;
	}

	Time& Time::operator-=(const Time& D) {
		while (D.m_min > m_min) m_min += 1440;
		m_min -= D.m_min;
		return *this;
	}
	Time Time::operator-(const Time& D)const {
		Time diff(m_min);
		while (D.m_min > diff.m_min) diff.m_min += 1440;
		return diff.m_min -= D.m_min;
	}
	Time& Time::operator+=(const Time& D) {
		m_min += D.m_min;
		return *this;
	}
	Time Time::operator+(const Time& D)const {
		Time sum(m_min);
		return  sum.m_min += D.m_min;
	}

	Time& Time::operator=(unsigned int val) {
		m_min = val;
		return *this;
	}
	Time& Time::operator *= (unsigned int val) {
		m_min *= val;
		return *this;
	}
	Time& Time::operator /= (unsigned int val) {
		m_min /= val;
		return *this;
	}
	Time Time::operator *(unsigned int val)const {
		Time mult(m_min);
		return mult.m_min *= val;
	}
	Time Time::operator /(unsigned int val)const {
		Time div(m_min);
		return div.m_min /= val;
	}

	Time::operator unsigned int()const {
		return m_min;
	}
	Time::operator int()const {
		return (int)m_min;
	}
	std::ostream& operator<<(std::ostream& ostr, const Time& D) {
		D.write(ostr);
		return ostr;
	}
	std::istream& operator>>(std::istream& istr, Time& D) {
		D.read(istr);
		return istr;
	}
}