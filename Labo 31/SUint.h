//
// Created by bdela on 13/01/2022.
//

#ifndef LABO_31_SUINT_H
#define LABO_31_SUINT_H

#include "Uint.h"
#include <iostream>
#include <cctype>

class SUint {

    friend std::ostream &operator<<(std::ostream &lhs, const SUint &rhs);

    friend SUint operator*(SUint lhs, const Uint &rhs);

    friend SUint operator*(SUint lhs, const int scalaire);

public:

    SUint() = default;

    SUint(std::string number);

    SUint(int number);

    SUint &operator*=(const SUint &rhs);

private:
    Uint number;
    bool sign;
};


#endif //LABO_31_SUINT_H
