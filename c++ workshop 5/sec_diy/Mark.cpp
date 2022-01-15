//==============================================
// Name:           Omar Hussein
// Student Number: 118073204
// Email:          ohussein2@myseneca.ca
// Section:        NAA
// Workshop:       5 (diy)
// Date:		   Feb 15, 2021
//==============================================
// I decalre that all the code included in this module
// including the header have been written by myself.
// No content was copied other than the code provided
// in the workshop file by the professor.
#include "Mark.h"
namespace sdds{
	Mark::Mark(){
		this->m_grade = 0;
	}
	Mark::Mark(int grd) : Mark() {
		if (grd >= 0 && grd <= 100) this->m_grade = grd;
		else this->m_grade = -1;
	}
	Mark::operator int()const {
		return (this->m_grade >= 0 && this->m_grade <= 100) ? this->m_grade : 0;
	}
	Mark::operator double()const {
		if (this->m_grade >= 50 && this->m_grade < 60)
			return 1 + (double(this->m_grade % 10) / 10);
		else if (this->m_grade >= 60 && this->m_grade < 70)
			return 2 + (double(this->m_grade % 10) / 10);
		else if (this->m_grade >= 70 && this->m_grade < 80)
			return 3 + (double(this->m_grade % 10) / 10);
		else if (this->m_grade >= 80 && this->m_grade <= 100)
			return 4 + (double(this->m_grade % 20) / 20);
		else return 0;
	}
	Mark::operator char()const {
		if (this->m_grade >= 0 && this->m_grade < 50)
			return 'F';
		else if (this->m_grade >= 50 && this->m_grade < 60)
			return 'D';
		else if (this->m_grade >= 60 && this->m_grade < 70)
			return 'C';
		else if (this->m_grade >= 70 && this->m_grade < 80)
			return 'B';
		else if (this->m_grade >= 80 && this->m_grade <= 100)
			return 'A';
		else return 'X';
	}
	Mark& Mark::operator +=(int addGrd) {
		(this->m_grade >= 0 && this->m_grade + addGrd <= 100) ? this->m_grade += addGrd : this->m_grade = -1;
		return *this;
	}
	Mark& Mark::operator =(int grd) {
		(grd >= 0 && grd <= 100) ? this->m_grade = grd : this->m_grade = -1;
		return *this;
	}
	int operator +=(int& num, Mark& mark){
		return (int(mark) >= 0) ? num += int(mark) : num;
	}
}