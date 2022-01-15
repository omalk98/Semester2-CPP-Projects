//==============================================
// Name:           Omar Hussein
// Student Number: 118073204
// Email:          ohussein2@myseneca.ca
// Section:        NAA
// Final Project:  Milestone 3
// Date:		   Mar 23, 2021
//==============================================
// I decalre that all the code included in this module
// including the header have been written by myself.
// No content was copied other than the code provided
// in the workshop file by the professor.
#ifndef SDDS_TICKET_H
#define SDDS_TICKET_H
#include <iostream>
#include "Time.h"
#include "IOAble.h"
namespace sdds {
    class Ticket : public IOAble {
        Time m_time;
        int m_number;
    public:
        Ticket(int number);
        operator Time()const;
        int number()const;
        void resetTime();
        std::ostream& csvWrite(std::ostream& ostr)const override;
        std::istream& csvRead(std::istream& istr) override;
        std::ostream& write(std::ostream& ostr)const override;
        std::istream& read(std::istream& istr) override;
    };
}
#endif //!SDDS_TICKET_H