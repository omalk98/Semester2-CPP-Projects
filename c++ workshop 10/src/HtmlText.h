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
#ifndef SDDS_HTMLTEXT_H__
#define SDDS_HTMLTEXT_H__
#include <iostream>
#include "Text.h"
namespace sdds {
   class HtmlText :  public Text {
       char* m_title{ nullptr };
       void setTitle(const char*);
   public:
      HtmlText(const char* filename=nullptr, const char* title = nullptr);
      void write(std::ostream& os)const override;
      ~HtmlText();
      HtmlText(const HtmlText&);
      HtmlText& operator=(const HtmlText&);
   };
}
#endif // !SDDS_HTMLTEXT_H__