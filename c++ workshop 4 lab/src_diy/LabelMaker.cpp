//==============================================
// Name:           Omar Hussein
// Student Number: 118073204
// Email:          ohussein2@myseneca.ca
// Section:        NAA
// Workshop:       4 (diy)
// Date:		   Feb 10, 2021
//==============================================
// I decalre that all the code included in this module
// including the header have been written by myself.
// No content was copied other than the code provided
// in the workshop file.
#include <iostream>
#include "LabelMaker.h"
namespace sdds {
	LabelMaker::LabelMaker()
	{
		this->m_labels = nullptr;
		this->m_labelCount = 0;
	}

	LabelMaker::LabelMaker(int noOfLabels) : LabelMaker()
	{
		if (noOfLabels > 0)
		{
			this->m_labels = new Label[noOfLabels];
			this->m_labelCount = noOfLabels;
		}
	}

	LabelMaker::~LabelMaker()
	{
		delete[] this->m_labels;
		this->m_labels = nullptr;
	}

	void LabelMaker::readLabels()
	{
		std::cout << "Enter " << this->m_labelCount << " labels:" << std::endl;
		for (auto i = 0; i < this->m_labelCount; ++i)
		{
			std::cout << "Enter label number " << i + 1 << std::endl << "> ";
			this->m_labels[i].readLabel();
		}
	}

	void LabelMaker::printLabels()const
	{
		for (auto i = 0; i < this->m_labelCount; ++i)
			this->m_labels[i].printLabel() << std::endl;
	}
}