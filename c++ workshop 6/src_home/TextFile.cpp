//==============================================
// Name:           Omar Hussein
// Student Number: 118073204
// Email:          ohussein2@myseneca.ca
// Section:        NAA
// Workshop:       6 (lab)
// Date:		   Mar 5, 2021
//==============================================
// I decalre that all the code included in this module
// including the header have been written by myself.
// No content was copied other than the code provided
// in the workshop file by the professor.
#include <iostream>
#include <fstream>
#include <string>
#include "TextFile.h"
#include "cstring.h"
using namespace std;
namespace sdds {

	Line::operator const char* () const {
		return (const char*)m_value;
	}
	Line& Line::operator=(const char* lineValue) {
		delete[] m_value;
		m_value = new char[strLen(lineValue) + 1];
		strCpy(m_value, lineValue);
		return *this;
	}
	Line::~Line() {
		delete[] m_value;
	}
	Line::Line() {
		m_value = nullptr;
	}

	TextFile::TextFile(unsigned pageSize) {
		m_textLines = nullptr;
		m_filename = nullptr;
		m_noOfLines = 0;
		m_pageSize = pageSize;
	}
	TextFile::TextFile(const char* filename, unsigned pageSize) : TextFile(pageSize) {
		if (filename) {
			setFilename(filename);
			loadText();
		}
	}
	TextFile::~TextFile() {
		delete[] m_textLines;
		m_textLines = nullptr;
		delete[] m_filename;
		m_filename = nullptr;
	}
	void TextFile::setEmpty() {
		delete[] m_textLines;
		m_textLines = nullptr;
		delete[] m_filename;
		m_filename = nullptr;
		m_noOfLines = 0;
	}
	void TextFile::setFilename(const char* fname, bool isCopy) {
		delete[] m_filename;
		m_filename = nullptr;
		if (isCopy) {
			m_filename = new char[strLen(fname) + 3];
			strCpy(m_filename, "C_");
			strCat(m_filename, fname);
		}
		else {
			m_filename = new char[strLen(fname) + 1];
			strCpy(m_filename, fname);
		}
	}
	unsigned TextFile::lines()const {
		return m_noOfLines;
	}
	TextFile::operator bool()const {
		return (m_filename);
	}
	const char* TextFile::name()const {
		return m_filename;
	}
	ostream& operator<<(ostream& ostr, const TextFile& text) {
		text.view(ostr);
		return ostr;
	}
	istream& operator>>(istream& istr, TextFile& text) {
		text.getFile(istr);
		return istr;
	}
	void TextFile::setNoOfLines() {
		ifstream fptr(m_filename);
		if (fptr) {
			char ch;
			while (!fptr.eof()) {
				fptr.get(ch);
				if (ch == '\n') ++m_noOfLines;
			}
			++m_noOfLines;
			fptr.clear();
			fptr.seekg(0);
			fptr.close();
			if (!m_noOfLines) {
				delete[] m_filename;
				m_filename = nullptr;
			}
		}
		else {
			delete[] m_filename;
			m_filename = nullptr;
		}
	}
	void TextFile::saveAs(const char* fileName)const {
		if (fileName) {
			ofstream file(fileName);
			if (file) {
				for (unsigned i = 0; i < m_noOfLines; ++i)
					file << m_textLines[i] << endl;
				file.close();
			}
		}
	}
	void TextFile::loadText() {
		setNoOfLines();
		if (m_filename) {
			ifstream fptr(m_filename);
			if (fptr) {
				delete[] m_textLines;
				m_textLines = new Line[m_noOfLines];
				string fLine;
				m_noOfLines = 0;
				while (!fptr.eof()) {
					getline(fptr, fLine, '\n');
					m_textLines[m_noOfLines++] = fLine.c_str();
				}
				fptr.close();
			}
		}
	}
	TextFile::TextFile(const TextFile& src) : TextFile(src.m_pageSize) {
		if (bool(src)) {
			setFilename(src.m_filename, true);
			src.saveAs(m_filename);
			loadText();
		}
	}
	TextFile& TextFile::operator =(const TextFile& src) {
		if (bool(*this) && bool(src)) {
			src.saveAs(m_filename);
			loadText();
			m_noOfLines = src.m_noOfLines;
		}
		return *this;
	}
	ostream& TextFile::view(ostream& ostr)const {
		if (m_filename) {
			ostr << m_filename << endl;
			ostr.fill('=');
			ostr.width(strLen(m_filename));
			ostr << "" << endl;
			for (unsigned i = 0, count =1; i < m_noOfLines; ++i, ++count) {
				ostr << m_textLines[i] << endl;
				if (count == m_pageSize) {
					count = 0;
					pause();
				}
			}
		}
		return ostr;
	}
	void TextFile::pause()const {
		char ch = ' ';
		while (ch != '\n') {
			cin.clear();
			cout << "Hit ENTER to continue...";
			cin.get(ch);
		}
	}
	istream& TextFile::getFile(istream& istr) {
		char filename[128];
		istr.getline(filename, 127, '\n');
		setFilename(filename);
		loadText();
		return istr;
	}
	const char* TextFile::operator[](unsigned index)const {
		auto i = (index >= m_noOfLines - 1) ? (index + 1 - m_noOfLines) : index;
		return (m_filename) ? (const char*)m_textLines[i] : nullptr;
	}
}