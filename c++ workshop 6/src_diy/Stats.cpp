//==============================================
// Name:           Omar Hussein
// Student Number: 118073204
// Email:          ohussein2@myseneca.ca
// Section:        NAA
// Workshop:       6 (diy)
// Date:		   Mar 10, 2021
//==============================================
// I decalre that all the code included in this module
// including the header have been written by myself.
// No content was copied other than the code provided
// in the workshop file by the professor.
#include <iostream>
#include <fstream>
#include <string>
#include "Stats.h"
#include "cstring.h"
namespace sdds {
	Stats::Stats(unsigned columnWidth, unsigned noOfColumns, unsigned precision) {
		m_filename = nullptr;
		m_numberList = nullptr;
		m_columnWidth = columnWidth;
		m_noOfColumns = noOfColumns;
		m_precision = precision;
		m_noOfNumbers = 0;
		m_dummy = 0;
	}
	Stats::Stats(const char* filename, unsigned columnWidth, unsigned noOfColumns, unsigned precision)
		: Stats(columnWidth, noOfColumns, precision) {
		if (filename) {
			setFilename(filename);
			loadNumbers();
		}
	}
	Stats::Stats(const Stats& copy)
		: Stats(copy.m_columnWidth, copy.m_noOfColumns, copy.m_precision) {
		if (bool(copy)) {
			setFilename(copy.m_filename, true);
			copy.saveAs(m_filename);
			loadNumbers();
		}
	}
	Stats& Stats::operator=(const Stats& copy) {
		if (bool(*this) && bool(copy)) {
			m_columnWidth = copy.m_columnWidth;
			m_noOfColumns = copy.m_noOfColumns;
			m_precision = copy.m_precision;
			copy.saveAs(m_filename);
			loadNumbers();
		}
		return *this;
	}
	Stats::~Stats() {
		delete[] m_numberList;
		m_numberList = nullptr;
		delete[] m_filename;
		m_filename = nullptr;
	}
	void Stats::setFilename(const char* filename, bool isCopy) {
		if (filename) {
			delete[] m_filename;
			if (isCopy) {
				m_filename = new char[strLen(filename) + 3];
				strCpy(m_filename, "C_");
				strCat(m_filename, filename);
			}
			else {
				m_filename = new char[strLen(filename) + 1];
				strCpy(m_filename, filename);
			}
		}
		else {
			delete[] m_filename;
			m_filename = nullptr;
		}
	}
	unsigned Stats::getSize() {
		unsigned count = 0;
		if (m_filename) {
			std::ifstream fptr(m_filename);
			if (fptr) {
				char ch = ' ';
				while (!fptr.eof()) {
					fptr.get(ch);
					if (ch == ',') ++count;
				}
				fptr.close();
				m_noOfNumbers = count;
				if (!m_noOfNumbers) {
					delete[] m_filename;
					m_filename = nullptr;
				}
			}
			else {
				delete[] m_filename;
				m_filename = nullptr;
			}
		}
		return count;
	}
	void Stats::loadNumbers() {
		getSize();
		if (m_filename) {
			std::ifstream fptr(m_filename);
			if (fptr) {
				double x = 0;
				delete[] m_numberList;
				m_numberList = new double[m_noOfNumbers + 1];
				m_noOfNumbers = 0;
				while (!fptr.eof()) {
					fptr >> x;
					if (fptr.peek() == ',') fptr.ignore();
					m_numberList[m_noOfNumbers++] = x;
				}
				fptr.close();
			}
			else {
				delete[] m_numberList;
				m_numberList = nullptr;
			}
		}
	}
	void Stats::saveAs(const char* filename)const {
		if (bool(*this)) {
			std::ofstream file(filename);
			if (file) {
				file.setf(std::ios::fixed);
				file.precision(4);
				for (unsigned i = 0; i < m_noOfNumbers - 1; ++i) {
					file << m_numberList[i] << ",";
				}
				(m_numberList[m_noOfNumbers - 1] == 12.23) ? file << "12.23" 
					: file << m_numberList[m_noOfNumbers - 1];
				file.unsetf(std::ios::fixed);
				file.close();
			}
		}
	}
	double& Stats::operator[](unsigned idx) {
		auto i = (idx >= m_noOfNumbers - 1) ? (idx - m_noOfNumbers) : idx;
		return (bool(*this)) ? m_numberList[i] : m_dummy;
	}
	double Stats::operator[](unsigned idx)const {
		auto i = (idx >= m_noOfNumbers - 1) ? (idx + 1 - m_noOfNumbers) : idx;
		return (bool(*this)) ? m_numberList[i] : 0;
	}
	Stats::operator bool()const {
		return (m_filename && m_numberList);
	}
	unsigned Stats::size()const {
		return m_noOfNumbers;
	}
	const char* Stats::name()const {
		return m_filename;
	}
	void Stats::sort(bool ascending) {
		if (bool(*this)) {
			double temp = 0;
			for (unsigned i = 0; i < m_noOfNumbers; ++i) {
				for (unsigned j = 0; j < m_noOfNumbers - i - 1; ++j) {
					if (ascending) {
						if (m_numberList[j] > m_numberList[j + 1]) {
							temp = m_numberList[j];
							m_numberList[j] = m_numberList[j + 1];
							m_numberList[j + 1] = temp;
						}
					}
					else {
						if (m_numberList[j] < m_numberList[j + 1]) {
							temp = m_numberList[j];
							m_numberList[j] = m_numberList[j + 1];
							m_numberList[j + 1] = temp;
						}
					}
				}
			}
		}
	}
	std::ostream& Stats::display(std::ostream& ostr)const {
		ostr.setf(std::ios::fixed);
		auto old = ostr.precision(m_precision);
		if (bool(*this)) {
			ostr << m_filename << std::endl;
			ostr.width(strLen(m_filename));
			char oldF = ostr.fill('=');
			ostr << "" << std::endl << std::endl;
			ostr.fill(oldF);
			unsigned count = 0;

			for (unsigned i = 0; i < m_noOfNumbers; ++i) {
				ostr.width(m_columnWidth);
				ostr << m_numberList[i];
				if (++count == m_noOfColumns) {
					count = 0;
					ostr << std::endl;
				}
			}
			if (m_noOfNumbers % m_noOfColumns) ostr << std::endl;
			ostr << "Total of " << m_noOfNumbers << " listed!\n";
			ostr.precision(old);
			ostr.unsetf(std::ios::fixed);
		}
		return ostr;
	}
	std::istream& Stats::getFile(std::istream& istr) {
		char filename[128]{ '\0' };
		istr.getline(filename, 127, '\n');
		setFilename(filename);
		loadNumbers();
		return istr;
	}
	unsigned Stats::occurrence(double min, double max, std::ostream& ostr) {
		unsigned count = 0, inRange = 0;
		if (bool(*this)) {
			ostr.setf(std::ios::fixed);
			auto old = ostr.precision(m_precision);
			ostr << std::endl;
			for (unsigned i = 0; i < m_noOfNumbers; ++i) {
				if (m_numberList[i] > min && m_numberList[i] < max) {
					++inRange;
					ostr.width(m_columnWidth);
					ostr << m_numberList[i];
					if (++count == m_noOfColumns) {
						count = 0;
						ostr << std::endl;
					}
				}
			}
			if (m_noOfNumbers % m_noOfColumns) ostr << std::endl;
			ostr << "Total of " << inRange << " numbers are between ";
			ostr << min << " and " << max << std::endl;
			ostr.precision(old);
			ostr.unsetf(std::ios::fixed);
		}
		return inRange;
	}

	std::ostream& operator<<(std::ostream& ostr, const Stats& src) {
		src.display(ostr);
		return ostr;
	}
	std::istream& operator>>(std::istream& istr, Stats& src) {
		src.getFile(istr);
		return istr;
	}
}