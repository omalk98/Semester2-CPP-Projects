//==============================================
// Name:           Omar Hussein
// Student Number: 118073204
// Email:          ohussein2@myseneca.ca
// Section:        NAA
// Workshop:       4 (lab)
// Date:		   Feb 9, 2021
//==============================================
// I decalre that all the code included in this module
// including the header have been written by myself.
// No content was copied other than the code provided
// in the workshop file.
#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <iomanip>
#include <cmath>
#include "cstring.h"
#include "Canister.h"
using namespace std;
namespace sdds {

	const double PI = 3.14159265;

	Canister::Canister()
	{
		this->setToDefault();
	}

	Canister::Canister(const char* contentName) : Canister()
	{
		if (contentName)
			this->setName(contentName);
	}

	Canister::Canister(double hieght, double diameter, const char* contentName) : Canister()
	{
		if (hieght >= 10.f && hieght <= 40.f &&
			diameter >= 10.f && diameter <= 30.f)
		{
			this->m_hieght = hieght;
			this->m_diameter = diameter;
		}
		else this->m_usable = false;
		if (contentName && this->m_usable)
			this->setName(contentName);
	}

	Canister::~Canister()
	{
		delete[] this->m_contentName;
		this->m_contentName = nullptr;
	}

	void Canister::setToDefault()
	{
		this->m_contentName = nullptr;
		this->m_diameter = 10.f;
		this->m_hieght = 13.f;
		this->m_contentVolume = 0.f;
		this->m_usable = true;
	}

	Canister& Canister::setContent(const char* contentName)
	{
		if (!contentName)
			this->m_usable = false;
		else if (this->isEmpty())
			this->setName(contentName);
		else if (strCmp(this->m_contentName, contentName))
			this->m_usable = false;

		return *this;
	}

	Canister& Canister::pour(double quantity)
	{
		if (this->m_usable && quantity > 0.f &&
			(quantity + this->volume()) <= this->capacity())
			this->m_contentVolume += quantity;
		else this->m_usable = false;
		return *this;
	}

	Canister& Canister::pour(Canister& C)
	{
		this->setContent(C.m_contentName);
		if (C.volume() > (this->capacity() - this->volume()))
		{
			C.m_contentVolume -= (this->capacity() - this->volume());
			this->m_contentVolume = this->capacity();
		}
		else
		{
			this->pour(C.volume());
			C.m_contentVolume = 0.f;
		}
		return *this;
	}

	double Canister::volume()const
	{
		return this->m_contentVolume;
	}

	ostream& Canister::display()const
	{
		cout << fixed << setprecision(1) << setw(7) << this->capacity();
		cout << "cc (" << this->m_hieght;
		cout << "x" << this->m_diameter << ") Canister";
		if (this->m_usable)
		{
			if (this->m_contentName)
				cout << " of " << setw(7) << this->volume() << "cc  " << this->m_contentName;
		}
		else cout << " of Unusable content, discard!";
		return cout;
	}

	double Canister::capacity()const
	{
		return (PI * (this->m_hieght - 0.267) * pow((this->m_diameter / 2), 2));
	}


	void Canister::setName(const char* Cstr)
	{
		if (Cstr && this->m_usable)
		{
			this->~Canister();
			this->m_contentName = new char[strLen(Cstr) + 1];
			strCpy(this->m_contentName, Cstr);
		}
	}

	bool Canister::isEmpty()const
	{
		return (this->m_contentVolume < 0.00001);
	}

	void Canister::clear()
	{
		this->~Canister();
		this->m_contentVolume = 0.f;
		this->m_usable = true;
	}
}