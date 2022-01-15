//==============================================
// Name:           Omar Hussein
// Student Number: 118073204
// Email:          ohussein2@myseneca.ca
// Section:        NAA
// Final Project:  Milestone 2
// Date:		   Mar 18, 2021
//==============================================
// I decalre that all the code included in this module
// including the header have been written by myself.
// No content was copied other than the code provided
// in the workshop file by the professor.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Menu.h"
#include "utils.h"
using namespace std;
namespace sdds {
	void Menu::display() const {
		cout << m_text << endl << "0- Exit\n";
	}

	Menu::Menu() : m_text{ nullptr }, m_noOfSel{ 0 } {}

	Menu::Menu(const char* MenuContent, int NoOfSelections) : Menu() {
		m_noOfSel = NoOfSelections;
		if (MenuContent) {
			m_text = new char[strlen(MenuContent) + 1];
			strcpy(m_text, MenuContent);
		}
		else m_text = nullptr;
	}

	Menu::~Menu() {
		delete[] m_text;
		m_text = nullptr;
	}

	int& Menu::operator>>(int& Selection) {
		display();
		Selection = getInt(0, m_noOfSel, "> ", "Invalid option ");
		return Selection;
	}

	Menu::Menu(const Menu& copy) : Menu(nullptr, copy.m_noOfSel) {
		if (copy.m_text) {
			m_text = new char[strlen(copy.m_text) + 1];
			strcpy(m_text, copy.m_text);
		}
	}
}