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
#ifndef SDDS_PATIENT_H
#define SDDS_PATIENT_H
#include <iostream>
#include "Ticket.h"
#include "IOAble.h"
namespace sdds {
    class Patient : public IOAble {
        char* m_name{ nullptr };
        int m_ohipNo = 0;
        Ticket m_ticket;
        bool m_fileIOFlag;
    public:
        Patient(int number = 0, bool fileIO = false);
        ~Patient() override;
        Patient(const Patient&) = delete;
        Patient& operator=(const Patient&) = delete;
        virtual char type()const = 0;
        bool fileIO()const;
        void fileIO(bool fileIO);
        bool operator==(const char c)const;
        bool operator==(const Patient& patient)const;
        void setArrivalTime();
        operator Time()const;
        int number()const;
        std::ostream& csvWrite(std::ostream& ostr)const override;
        std::istream& csvRead(std::istream& istr) override;
        std::ostream& write(std::ostream& ostr)const override;
        std::istream& read(std::istream& istr) override;
    };
}
#endif //!SDDS_PATIENT_H