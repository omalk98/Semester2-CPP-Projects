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
#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <iomanip>
#include "Label.h"
#include "cstring.h"

namespace sdds {
	Label::Label()
	{
		strCpy(this->m_frame, "+-+|+-+|");
		this->m_content = nullptr;
	}

	Label::Label(const char* frameArg) : Label()
	{
		if (frameArg) strnCpy(this->m_frame, frameArg, MAX_FRAME_CHARS);
	}


	Label::Label(const char* frameArg, const char* content) : Label(frameArg)
	{
		if (content)
		{
			this->m_content = new char[strLen(content) + 1];
			strCpy(this->m_content, content);
		}
	}

	Label::~Label()
	{
		delete[] this->m_content;
		this->m_content = nullptr;
	}

	void Label::readLabel()
	{
		char temp[MAX_LABEL_LENGTH + 1];
		std::cin.getline(temp, MAX_LABEL_LENGTH, '\n');
		
		this->m_content = new char[strLen(temp) + 1];
		strCpy(this->m_content, temp);

	}

	std::ostream& Label::printLabel()const
	{
		if (this->m_content)
		{
			int len = strLen(this->m_content) + 1;
			std::cout << this->m_frame[0] << std::setw(len + 1) << std::setfill(this->m_frame[1])
				<< this->m_frame[1] << this->m_frame[2] << std::endl << std::setfill(' ');
			std::cout << std::setw(2) << std::left << this->m_frame[7] << std::setw(len) << "" << this->m_frame[3] << std::endl;
			std::cout << std::setw(2) << std::left << this->m_frame[7] << std::setw(len)
				<< this->m_content << this->m_frame[3] << std::endl;
			std::cout << std::setw(2) << std::left << this->m_frame[7] << std::setw(len) << " " << this->m_frame[3] << std::endl;
			std::cout << this->m_frame[6] << std::setw(len + 1) << std::setfill(this->m_frame[5])
				<< this->m_frame[5] << this->m_frame[4];
		}
		return std::cout;
	}
}
