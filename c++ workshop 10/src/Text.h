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
#ifndef SDDS_TEXT_H__
#define SDDS_TEXT_H__
#include <iostream>
namespace sdds {
   class Text {
       char* m_filename{ nullptr };
       char* m_content{ nullptr };
      int getFileLength()const;
      void setFilename(const char*);
      void setEmpty();
   protected:
      const char& operator[](int index)const;
      operator bool()const;
   public:
      Text(const char* filename=nullptr);
      Text(const Text&);
      Text& operator=(const Text&);
      ~Text();

      void read();
      virtual void write(std::ostream& os)const;
   };

   std::ostream& operator<<(std::ostream&, const Text&);
}
#endif // !SDDS_TEXT_H__