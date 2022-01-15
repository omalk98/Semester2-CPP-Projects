//==============================================
// Name:           Omar Hussein
// Student Number: 118073204
// Email:          ohussein2@myseneca.ca
// Section:        NAA
// Workshop:       8 (lab)
// Date:		   Mar 22, 2021
//==============================================
// I decalre that all the code included in this module
// including the header have been written by myself.
// No content was copied other than the code provided
// in the workshop file by the professor.
#ifndef SDDS_RECTANGLE_H
#define SDDS_RECTANGLE_H
#include<iostream>
#include "LblShape.h"
namespace sdds {
    class Rectangle : public LblShape {
        int m_width = 0;
        int m_height = 0;
    public:
        Rectangle();
        Rectangle(const char* label, int width, int height);
        void getSpecs(std::istream& in) override;
        void draw(std::ostream& os)const override;
    };
}
#endif //!SDDS_RECTANGLE_H