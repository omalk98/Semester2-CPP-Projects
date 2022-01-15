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
#include "Bill.h"
using namespace std;
namespace sdds {

	double Bill::totalTax()const
	{
		double tTax = 0;
		for (int i = 0; i < this->m_noOfItems; ++i)
			tTax += this->m_items[i].tax();
		return tTax;
	}

	double  Bill::totalPrice()const
	{
		double tPrice = 0;
		for (int i = 0; i < this->m_noOfItems; ++i)
			tPrice += this->m_items[i].price();
		return tPrice;
	}

	void  Bill::Title()const
	{
		this->boarder();
		if (this->isValid())
		{
			cout.setf(ios::left);
			cout << "| ";
			cout.width(36);
			cout << this->m_title << " |\n";
		}
		else this->invalid();
		this->edge();

		cout.setf(ios::left); // the function edge will unset ios::left
		cout << "| ";
		cout.width(20);
		cout << "Item Name";
		cout << " | ";
		cout.width(7);
		cout << "Price" << " + Tax |\n";
		this->edge();
	}

	void  Bill::footer()const
	{
		int old;
		this->edge();
		if (this->isValid())
		{
			cout.setf(ios::fixed);
			old = cout.precision(2);
			cout << "| ";
			cout.width(26);
			cout << "Total Tax: ";
			cout.width(10);
			cout << this->totalTax() << " |\n";

			cout << "| ";
			cout.width(26);
			cout << "Total Price: ";
			cout.width(10);
			cout << this->totalPrice() << " |\n";

			cout << "| ";
			cout.width(26);
			cout << "Total After Tax: ";
			cout.width(10);
			cout << (this->totalTax() + this->totalPrice()) << " |\n";
			cout.unsetf(ios::fixed);
			cout.precision(old);
		}
		else this->invalid();

		this->boarder();
	}

	void  Bill::setEmpty()
	{
		this->m_title[0] = '\0';
		this->m_items = nullptr;
	}

	bool  Bill::isValid()const
	{
		bool ok = false;
		if (this->m_title[0] != '\0' && this->m_items != nullptr)
			for (int i = 0; i < this->m_noOfItems; ++i)
				ok = this->m_items[i].isValid();
		return ok;
	}

	void  Bill::init(const char* title, int noOfItems)
	{
		if (title != nullptr && noOfItems > 0)
		{
			this->m_noOfItems = noOfItems;
			this->m_itemsAdded = 0;
			strnCpy(this->m_title, title, 36);
			this->m_title[36] = '\0';
			this->m_items = new Item[noOfItems];
		}
		else this->setEmpty();
	}

	bool  Bill::add(const char* item_name, double price, bool taxed)
	{
		bool ok = false;
		if (this->m_itemsAdded < this->m_noOfItems)
		{
			this->m_items[this->m_itemsAdded].set(item_name, price, taxed);
			++this->m_itemsAdded;
			ok = true;
		}
		return ok;
	}

	void  Bill::display()const
	{
		this->Title();
		for (int i = 0; i < this->m_noOfItems; ++i)
			this->m_items[i].display();
		this->footer();
	}

	void  Bill::deallocate()
	{
		delete[] this->m_items;
		this->m_items = nullptr;
	}

	void Bill::boarder()const
	{
		cout << "+--------------------------------------+" << endl;
	}

	void Bill::edge()const
	{
		char old;
		cout.setf(ios::left);
		old = cout.fill('-');
		cout.width(23);
		cout << "+";
		cout.width(10);
		cout << "+";
		cout.width(6);
		cout << "+" << "+\n";
		cout.fill(old);
		cout.unsetf(ios::left);
	}

	void Bill::invalid()const
	{
		cout.setf(ios::left);
		cout << "| ";
		cout.width(36);
		cout << "Invalid Bill" << " |\n";
		cout.unsetf(ios::left);
	}
}
