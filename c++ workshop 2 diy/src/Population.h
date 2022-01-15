//==============================================
// Name:           Omar Hussein
// Student Number: 118073204
// Email:          ohussein2@myseneca.ca
// Section:        NAA
// Workshop:       2 (diy)
// Date:	       Jan 26, 2021
//==============================================

#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_
namespace sdds {

    struct Population {
        char* m_pCode;
        int m_popCount;
    };
    bool load(Population&);
    bool load(const char filename[]);
    int display(const Population&);
    void display();
    void deallocateMemory();
}
#endif 