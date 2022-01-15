//==============================================
// Name:           Omar Hussein
// Student Number: 118073204
// Email:          ohussein2@myseneca.ca
// Section:        NAA
// Workshop:       5 (lab)
// Date:		   Feb 15, 2021
//==============================================
// I decalre that all the code included in this module
// including the header have been written by myself.
// No content was copied other than the code provided
// in the workshop file by the professor.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace sdds {
   void Account::setEmpty() {
      m_number = -1;
      m_balance = 0.0;
   }
   // New account
   Account::Account() {  
      m_number = 0;
      m_balance = 0.0;
   }
   Account::Account(int number, double balance ) {
      setEmpty();
      if (number >= 10000 && number <= 99999
         && balance > 0) {
         m_number = number;
         m_balance = balance;
      }
   }
   std::ostream& Account::display() const{
      if (*this) {  
         cout << " ";
         cout << m_number;
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << m_balance;
         cout.unsetf(ios::right);
         cout << " ";
      }
      else if(~*this) {
         cout << "  NEW  |         0.00 ";
      }
      else {
         cout << "  BAD  |    ACCOUNT   ";
      }
      return cout;
   }
   Account::operator bool()const{
       return (this->m_number >= 10000 && this->m_number <= 99999 && this->m_balance >= 0);
   }
   Account::operator int()const{
       return this->m_number;
   }
   Account::operator double()const{
       return this->m_balance;
   }
   bool Account::operator ~()const{
       return (this->m_number == 0);
   }
   Account& Account::operator =(int accNo){
       if (~*this) {
           if (accNo >= 10000 && accNo <= 99999) this->m_number = accNo;
           else this->setEmpty();
       }
       return *this;
   }
   Account& Account::operator =(Account& acc){
       if (~*this && bool(acc)){
           this->m_number = int(acc);
           this->m_balance = double(acc);
           acc.m_number = 0;
           acc.m_balance = 0;
       }
       return *this;
   }
   Account& Account::operator +=(double deposit){
       if (bool(this) && deposit >= 0) this->m_balance += deposit;
       return *this;
   }
   Account& Account::operator -=(double withdraw) {
       if (bool(this) && withdraw >= 0 && (this->m_balance - withdraw) >= 0) this->m_balance -= withdraw;
       return *this;
   }
   Account& Account::operator <<(Account& acc) {
       if (bool(this) && bool(acc) && this->m_number != acc.m_number){
           *this += acc.m_balance;
           acc.m_balance = 0;
       }
       return *this;
   }
   Account& Account::operator >>(Account& acc) {
       if (bool(acc) && bool(this) && this->m_number != acc.m_number) {
           acc += this->m_balance;
           this->m_balance = 0;
       }
       return *this;
   }

   double operator +(const Account& acc1, const Account& acc2) {
       return (bool(acc1) && bool(acc2)) ? (double(acc1) + double(acc2)) : 0;
   }
   double operator +=(double& num, const Account& acc){
       return bool(acc) ? (num += double(acc)) : 0;
   }
}