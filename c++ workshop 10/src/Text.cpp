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
#include <fstream>
#include "cstring.h"
#include "Text.h"
using namespace std;
namespace sdds {
   int Text::getFileLength() const {
      int len = 0;
      ifstream fin(m_filename);
      while (fin) {
         fin.get();
         len += !!fin;
      }
      return len;
   }

   Text::operator bool() const {
       return m_filename;
   }

   void Text::setFilename(const char* filename) {
       if (filename) {
           m_filename = new char[strLen(filename) + 1];
           strCpy(m_filename, filename);
       }
       else m_filename = nullptr;
   }

   void Text::setEmpty() {
       delete[] m_filename;
       m_filename = nullptr;
       delete[] m_content;
       m_content = nullptr;
   }

   const char& Text::operator[](int index) const {
       return m_content[index];
   }

   Text::Text(const char* filename) : m_content{ nullptr } {
       setFilename(filename);
   }

   Text::Text(const Text& src) : Text() {
       *this = src;
   }
   Text& Text::operator=(const Text& src) {
       if (bool(src) && (&src != this)) {
           setFilename(src.m_filename);
           read();
       }
       else setEmpty();
       return *this;
   }
   Text::~Text() {
       setEmpty();
   }
   void Text::read() {
       int len = getFileLength();
       if (len) {
           m_content = new char[len + 1];
           ifstream file(m_filename);
           if (file) {
               int i = 0;
               while(!file.eof()){    
                file.get(m_content[i++]);
               }
               m_content[len] = '\0';
               file.close();
           }
       }
   }

   void Text::write(ostream& os)const {
       if (m_content) os << m_content;
   }
   ostream& operator<<(ostream& os, const Text& text) {
       text.write(os);
       return os;
   }
}