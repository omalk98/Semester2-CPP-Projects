// Name: John De Appolonia
// Email: jde-appolonia@myseneca.ca
// Student ID: 101283208
// Date: 2021/02/20
///////////////////////////////////////////////////
// "I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments."
#define _CRT_SECURE_NO_WARNINGS
#include "Mark.h"

using namespace std;
namespace sdds {


    Mark::Mark() {
        m_value = 0;
    }

    Mark::Mark(int value) : Mark() {
        if (value >= 0 && value <= 100)
        {
            m_value = value;
        }
        else
        {
            m_value = -1;
        }
    }

    Mark::operator int() const {
        if (m_value >= 0 && m_value <= 100)
        {
            return m_value;
        }
        else {
            return 0;
        }
    }

    Mark::operator double()const {

        if (m_value < 50 && m_value > 0) {
            return 0;
        }
        else if (m_value >= 50 && m_value < 60) {
            return 1;
        }
        else if (m_value >= 60 && m_value < 70) {
            return 2;
        }
        else if (m_value >= 70 && m_value < 80) {
            return 3;
        }
        else if (m_value >= 80 && m_value <= 100) {
            return 4;
        }

        else {
            return 0;
        }
    }

    Mark::operator char()const {
        if (m_value < 50 && m_value > 0) {
            return 'F';
        }
        else if (m_value >= 50 && m_value < 60) {
            return 'D';
        }
        else if (m_value >= 60 && m_value < 70) {
            return 'C';
        }
        else if (m_value >= 70 && m_value < 80) {
            return 'B';
        }
        else if (m_value >= 80 && m_value <= 100) {
            return 'A';
        }

        else {
            return 'X';
        }
    }

    Mark& Mark::operator+=(int value) {
        if (m_value >= 0 && m_value + value <= 100 && value >= 0) {
             m_value += value;
        }
        else {
            m_value = -1;
        }
        return *this;
    }

    Mark& Mark::operator=(int value) {
        if (value >= 0 && value <= 100) {
            m_value = value;
        }
        else {
            m_value = -1;
        }
        return *this;
    }

    int operator+=(int& value, Mark& Lo)
    {
        if (int(Lo) >= 0 || int(Lo) <= 100)
        {
            value += int(Lo);
        }
        return value;
    }
}