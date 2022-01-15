//==============================================
// Name:           Omar Hussein
// Student Number: 118073204
// Email:          ohussein2@myseneca.ca
// Section:        NAA
// Workshop:       2 (lab)
// Date:	       Jan 26, 2021
//==============================================

#include <iostream>
#include "cstring.h"  
#include "Employee.h"
#include "File.h"
using namespace std;
namespace sdds {

   int noOfEmployees;
   Employee* employees;


   void sort() {
      int i, j;
      Employee temp;
      for (i = noOfEmployees - 1; i > 0; i--) {
         for (j = 0; j < i; j++) {
            if (employees[j].m_empNo > employees[j + 1].m_empNo) {
               temp = employees[j];
               employees[j] = employees[j + 1];
               employees[j + 1] = temp;
            }
         }
      }
   }

   
   bool load(Employee& emp) {
      bool ok = false;
      char name[128];

      int no = 0;
      double sal = 0;

      if (read(no) && read(sal) && read(name))
      {
          emp.m_name = new char[strLen(name) + 1];
          strCpy(emp.m_name, name);
          emp.m_empNo = no;
          emp.m_salary = sal;
          ok = true;
      }
      return ok;
   }
   bool load() {
      bool ok = false;
      int i = 0;
      if (openFile(DATAFILE)) {
          noOfEmployees = noOfRecords();
          employees = new Employee[noOfEmployees];

          for (i = 0; i < noOfEmployees; ++i)
              if(!load(employees[i]))
                  break;

          if (i != noOfEmployees)
              cout << "Error: incorrect number of records read; the data is possibly corrupted." << endl;
          else
              ok = true;

          closeFile();
      }
      else {
         cout << "Could not open data file: " << DATAFILE<< endl;
      }
      return ok;
   }

   void display(const Employee& emp) {
       cout << emp.m_empNo << ": ";
       cout << emp.m_name << ", ";
       cout << emp.m_salary << endl;
   }

   void display() {
       cout << "Employee Salary report, sorted by employee number" << endl;
       cout << "no- Empno, Name, Salary" << endl;
       cout << "------------------------------------------------" << endl;
       sort();
       for (int i = 0; i < noOfEmployees; ++i) {
           cout << i + 1 << "- ";
           display(employees[i]);
       }
   }

   void deallocateMemory() {
       for (int i = 0; i < noOfEmployees; ++i) {
           delete[] employees[i].m_name;
           employees[i].m_name = nullptr;
       }
       delete[] employees;
       employees = nullptr;
   }

}