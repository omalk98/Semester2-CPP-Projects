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
#ifndef SDDS_LBLSHAPE_H
#define SDDS_LBLSHAPE_H
#include <iostream>
#include "Shape.h"
namespace sdds {
    class LblShape : public Shape {
        char* m_label{nullptr};
        LblShape(const LblShape&) = delete;
        LblShape& operator=(const LblShape&) = delete;
    protected:
        const char* label()const;
    public:
        void getSpecs(std::istream& in)override;
        LblShape();
        LblShape(const char* label);
        ~LblShape()override;
    };
}
#endif //!SDDS_LBLSHAPE_H