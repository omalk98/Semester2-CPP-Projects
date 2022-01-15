//==============================================
// Name:           Omar Hussein
// Student Number: 118073204
// Email:          ohussein2@myseneca.ca
// Section:        NAA
// Workshop:       3 (diy)
// Date:		   Feb 3, 2021
//==============================================
#ifndef SDDS_FOOD_H
#define SDDS_FOOD_H
namespace sdds {
    class Food {
        char m_foodName[31];
        int m_calorie;
        int m_time;
        void setName(const char*);
    public:
        void setEmpty();
        void set(const char*, int, int);
        void display()const;
        bool isValid()const;
        int calorie()const;
        int time()const;
        Food();
    };
}
#endif