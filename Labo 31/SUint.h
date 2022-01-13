//
// Created by bdela on 13/01/2022.
//

#ifndef LABO_31_SUINT_H
#define LABO_31_SUINT_H

#include "Uint.h"

class SUint {
public:

    SUint() = default;

    SUint(std::string number);
    SUint(int number);

private:
    Uint number;
    bool sign;
};


#endif //LABO_31_SUINT_H
