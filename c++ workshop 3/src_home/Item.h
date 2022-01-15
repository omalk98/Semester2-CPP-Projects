//==============================================
// Name:           Omar Hussein
// Student Number: 118073204
// Email:          ohussein2@myseneca.ca
// Section:        NAA
// Workshop:       3 (lab)
// Date:		   Feb 3, 2021
//==============================================

#ifndef SDDS_ITEM_H
#define SDDS_ITEM_H
namespace sdds {
   class Item {
      char m_itemName[21];
      double m_price;
      bool m_taxed;
      void setName(const char* name);
   public:
      void setEmpty();
      void set(const char* name, double price, bool taxed);
      void display()const;
      bool isValid()const;
      double price()const;
      double tax()const;
      //Item();
   };
}

#endif // !SDDS_SUBJECT_H
