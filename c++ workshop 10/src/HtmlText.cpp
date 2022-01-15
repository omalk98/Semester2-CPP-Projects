//==============================================
// Name:           Omar Hussein
// Student Number: 118073204
// Email:          ohussein2@myseneca.ca
// Section:        NAA
// Workshop:       10 (lab)
// Date:		   Apr 5, 2021
//==============================================
// I decalre that all the code included in this module
// including the header have been written by myself.
// No content was copied other than the code provided
// in the workshop file by the professor.
#include <iostream>
#include "HtmlText.h"
#include "cstring.h"
using namespace std;
namespace sdds {
	void HtmlText::setTitle(const char* title) {
		if (title) {
			m_title = new char[strLen(title) + 1];
			strCpy(m_title, title);
		}
		else m_title = nullptr;
	}
	HtmlText::HtmlText(const char* filename, const char* title) : Text(filename) {
		setTitle(title);
	}
	void HtmlText::write(std::ostream& os) const {
		bool ms = false;
		os << "<html><head><title>";
		(m_title) ? os << m_title : os << "No Title";
		os << "</title></head>\n<body>\n";
		if (m_title) os << "<h1>" << m_title << "</h1>\n";
			for (auto i = 0; Text::operator[](i) != '\0'; ++i) {
				switch (Text::operator[](i)) {
				case ' ':
					ms ? os << "&nbsp;" : os << " ";
					ms = true;
					break;
				case '<':
					os << "&lt;";
					ms = false;
					break;
				case '>':
					os << "&gt;";
					ms = false;
					break;
				case '\n':
					os << "<br />\n";
					ms = false;
					break;
				default:
					os << Text::operator[](i);
					ms = false;
					break;
				}
			}
			os << "</body>\n</html>";
	}
	HtmlText::~HtmlText() {
		delete[] m_title;
		m_title = nullptr;
	}
	HtmlText::HtmlText(const HtmlText& src) : Text(src) {
		*this = src;
	}
	HtmlText& HtmlText::operator=(const HtmlText& src) {
		if (src.m_title && bool(src) && (&src != this)) {
			Text::operator=(src);
			setTitle(src.m_title);
		}
		return *this;
	}
}