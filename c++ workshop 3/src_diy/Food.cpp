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
#include "Food.h"
using namespace std;
namespace sdds {

	Food::Food()
	{
		this->m_foodName[0] = '\0';
		this->m_calorie = 0;
		this->m_time = 0;
	}

	void Food::setName(const char* name)
	{
		strnCpy(this->m_foodName, name, 30);
		this->m_foodName[30] = '\0';
	}

	void Food::setEmpty()
	{
		const char empty = '\0';
		this->setName(&empty);
		this->m_calorie = 0;
		this->m_time = 0;
	}

	void Food::set(const char* name, int calories, int when)
	{
		if (name != nullptr && 
			(calories >= 0 && calories <= 3000) && 
				(when >= 1 && when <= 4))
		{
			this->setName(name);
			this->m_calorie = calories;
			this->m_time = when;
		}
		else this->setEmpty();
	}

	void Food::display()const
	{
		char oldFill;
		if (this->isValid())
		{
			cout << "| ";
			cout.setf(ios::left);
			oldFill = cout.fill('.');
			cout.width(30);
			cout << this->m_foodName << " | ";
			cout.unsetf(ios::left);
			cout.fill(oldFill);

			cout.width(4);
			cout << this->m_calorie << " | ";

			cout.setf(ios::left);
			cout.width(10);
			switch (this->m_time)
			{
			case 1:
				cout << "Breakfast";
				break;
			case 2:
				cout << "Lunch";
				break;
			case 3:
				cout << "Dinner";
				break;
			case 4:
				cout << "Snack";
				break;
			}
			cout << " |\n";
			cout.unsetf(ios::left);
		}
		else
		{
			cout << "| ";
			oldFill = cout.fill('x');
			cout.width(30);
			cout << "" << " | ";
			cout.width(4);
			cout << "" << " | ";
			cout.width(10);
			cout << "" << " |\n";
			cout.fill(oldFill);
		}
	}

	bool Food::isValid()const
	{
		return !(this->m_foodName[0] == '\0' || 
			this->m_calorie < 0 || this->m_calorie > 3000 ||
				this->m_time < 1 || this->m_time > 4);
	}

	int Food::calorie()const
	{
		return this->m_calorie;
	}

	int Food::time()const
	{
		return this->m_time;
	}
}