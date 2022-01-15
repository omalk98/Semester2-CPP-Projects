//==============================================
// Name:           Omar Hussein
// Student Number: 118073204
// Email:          ohussein2@myseneca.ca
// Section:        NAA
// Workshop:       3 (lab)
// Date:		   Feb 3, 2021
//==============================================
// I decalre that all the code included in this module
// including the header have been written by myself.
// No content was copied other than the code provided
// in the workshop file.
#include <iostream>
#include "cstring.h"
#include "Item.h"
using namespace std;
namespace sdds {

	//Item::Item() 
	//{
	//	this->m_itemName[0] = '\0';
	//	this->m_price = 0;
	//	this->m_taxed = 0;
	//}
	void Item::setName(const char* name)
	{
		strnCpy(this->m_itemName, name, 20);
		this->m_itemName[20] = '\0';
	}

	void Item::setEmpty()
	{
		const char empty = '\0';
		this->setName(&empty);
		this->m_price = 0.0;
		this->m_taxed = false;
	}

	void Item::set(const char* name, double price, bool taxed)
	{
		if (name != nullptr && price > 0)
		{
			this->setName(name);
			this->m_price = price;
			this->m_taxed = taxed;
		}
		else this->setEmpty();
	}

	void Item::display()const
	{
		int oldPrec;
		char oldFill;
		if (this->isValid())
		{
			cout << "| ";
			cout.setf(ios::left);
			oldFill = cout.fill('.');
			cout.width(20);
			cout << this->m_itemName << " | ";
			cout.unsetf(ios::left);
			cout.fill(oldFill);

			cout.setf(ios::fixed);
			oldPrec = cout.precision(2);
			cout.width(7);
			cout << this->m_price << " | ";
			cout.precision(oldPrec);
			cout.unsetf(ios::fixed);

			cout.setf(ios::left);
			cout.width(3);
			if (this->m_taxed)
				cout << "Yes";
			else
				cout << "No";
			cout << " |" << endl;
			cout.unsetf(ios::left);
		}
		else
		{
			cout << "| ";
			oldFill = cout.fill('x');
			cout.width(20);
			cout << "" << " | ";
			cout.width(7);
			cout << "" << " | ";
			cout.width(3);
			cout << "" << " |" << endl;
			cout.fill(oldFill);
		}
	}

	bool Item::isValid()const
	{
		return !(this->m_itemName[0] == '\0' || this->m_price <= 0);
	}

	double Item::price()const
	{
		return this->m_price;
	}

	double Item::tax()const
	{
		const double GST = 0.13;
		return (this->m_taxed) ? (this->m_price * GST) : 0;
	}
}
