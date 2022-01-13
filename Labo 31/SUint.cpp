//
// Created by bdela on 13/01/2022.
//

#include "SUint.h"


SUint::SUint(int nb)
{
    if(number < 0)
    {
        sign = true;
        number = (nb * -1);
    }
    else
    {
        sign = false;
        number = nb;
    }
}

SUint::SUint(std::string nb)
{
    if(nb.at(nb.size() - 1) == '-')
    {
        sign = true;    
        nb.pop_back();
        number = nb;
    }
    else
    {
        sign = false;
        number = nb;
    }
}