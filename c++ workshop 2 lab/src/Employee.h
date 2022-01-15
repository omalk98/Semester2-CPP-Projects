//==============================================
// Name:           Omar Hussein
// Student Number: 118073204
// Email:          ohussein2@myseneca.ca
// Section:        NAA
// Workshop:       2 (lab)
// Date:	       Jan 26, 2021
//==============================================

#ifndef SDDS_EMPLOYEE_H_
#define SDDS_EMPLOYEE_H_

#define DATAFILE "employees.csv"
namespace sdds {
    struct Employee {
        char* m_name;
        int m_empNo;
        double m_salary;
    };
    void sort();
    bool load(Employee&);
    bool load();
    void display(const Employee&);
    void display();
    void deallocateMemory();
}
#endif