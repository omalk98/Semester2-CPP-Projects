//==============================================
// Name:           Omar Hussein
// Student Number: 118073204
// Email:          ohussein2@myseneca.ca
// Section:        NAA
// Workshop:       3 (diy)
// Date:		   Feb 3, 2021
//==============================================

#ifndef SDDS_CALORIELIST_H
#define SDDS_CALORIELIST_H
#include "Food.h"
namespace sdds {
    class CalorieList {
        Food* m_items;
        int m_noOfItems;
        int m_itemsAdded;
        int Cals()const; //chanegs
        void Title()const;
        void footer()const;
        void setEmpty();
        bool isValid()const;
        void boarder()const; //added function
        void edge()const; //added function
    public:
        void init(int);
        bool add(const char*, int, int);
        void display()const;
        void deallocate();
    };
}

#endif