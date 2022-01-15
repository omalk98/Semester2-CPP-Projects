//==============================================
// Name:           Omar Hussein
// Student Number: 118073204
// Email:          ohussein2@myseneca.ca
// Section:        NAA
// Workshop:       3 (diy)
// Date:		   Feb 3, 2021
//==============================================
// I decalre that all the code included in this module
// including the header have been written by myself.
// No content was copied other than the code provided
// in the workshop file.
#include <iostream>
#include "cstring.h"
#include "CalorieList.h"
using namespace std;
namespace sdds {

	int  CalorieList::Cals()const
	{
		int tCals = 0;
		for (int i = 0; i < this->m_noOfItems; ++i)
			tCals += this->m_items[i].calorie();
		return tCals;
	}

	void  CalorieList::Title()const
	{
		this->boarder();
		cout.setf(ios::left);
		cout << "|  ";
		cout.width(50);
		if (this->isValid())
			cout << "Daily Calorie Consumption";
		else
			cout << "Invalid Calorie Consumption list";
		cout << " |\n";
		this->edge();

		cout.setf(ios::left); // the function edge will unset ios::left
		cout << "| ";
		cout.width(30);
		cout << "Food name" << " | Cals | ";
		cout.width(10);
		cout << "When" << " |\n";
		this->edge();
	}

	void  CalorieList::footer()const
	{
		this->edge();
		if (this->isValid())
		{
			cout << "| ";
			cout.width(29);
			cout << "Total Calories for today: ";
			cout.width(8);
			cout << this->Cals() << " | ";
			cout.width(10);
			cout << "" << " |\n";
		}
		else
		{
			cout.setf(ios::left);
			cout.width(5);
			cout << "|" << "Invalid Calorie Consumption list";
			cout.unsetf(ios::left);
			cout.width(18);
			cout << "|\n";
		}
		this->boarder();
	}

	void  CalorieList::setEmpty()
	{
		this->m_noOfItems = 0;
		this->m_itemsAdded = 0;
	}

	bool  CalorieList::isValid()const
	{
		bool ok = false;
		if (this->m_items != nullptr)
			for (int i = 0; i < this->m_noOfItems; ++i)
			{
				ok = this->m_items[i].isValid();
				if (!ok) break;
			}
		return ok;
	}

	void  CalorieList::init(int size)
	{
		if (size > 0)
		{
			this->m_noOfItems = size;
			this->m_itemsAdded = 0;
			this->m_items = new Food[size];
		}
		else this->setEmpty();
	}

	bool  CalorieList::add(const char* item_name, int calories, int when)
	{
		bool ok = false;
		if (this->m_itemsAdded < this->m_noOfItems)
		{
			this->m_items[this->m_itemsAdded].set(item_name, calories, when);
			++this->m_itemsAdded;
			ok = true;
		}
		return ok;
	}

	void  CalorieList::display()const
	{
		this->Title();
		for (int i = 0; i < this->m_noOfItems; ++i)
			this->m_items[i].display();
		this->footer();
	}

	void  CalorieList::deallocate()
	{
		delete[] this->m_items;
		this->m_items = nullptr;
	}

	void CalorieList::boarder()const
	{
		char old;
		cout.setf(ios::left);
		old = cout.fill('-');
		cout.width(53);
		cout << "+" << "+\n";
		cout.fill(old);
		cout.unsetf(ios::left);
	}

	void CalorieList::edge()const
	{
		char old;
		cout.setf(ios::left);
		old = cout.fill('-');
		cout.width(33);
		cout << "+";
		cout.width(7);
		cout << "+";
		cout.width(13);
		cout << "+" << "+\n";
		cout.fill(old);
		cout.unsetf(ios::left);
	}
}
