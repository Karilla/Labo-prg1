//
// Created by bdela on 13/01/2022.
//

#include "SUint.h"

using namespace std;

const string ERROR_STRING_NUM = "ERROR TO CONVERT STRING TO SUINT, CHARACTER IS NOT A DIGIT AT POS ";

SUint::SUint(int nb)
{
    if(nb < 0)
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
    if(nb.at(0) == '-')
    {
        sign = true;
        nb.erase(nb.begin(), nb.begin() + 1);
    }
    else
    {
        sign = false;
    }
    for(size_t i = 0; i < nb.size(); i++)
    {
        if(!isdigit(nb.at(i)))
        {
            cerr << ERROR_STRING_NUM << i + sign <<endl;
            nb = "404";
        }
    }
    number = nb;
}

SUint &SUint::operator*=(const SUint &rhs)
{
    this->number *= rhs.number;
    this->sign = this->sign ^ rhs.sign;
    return *this;
}

SUint operator*(SUint lhs, const int scalaire)
{
    SUint temp;
    if(scalaire < 0)
    {
        temp.number = lhs.number * (scalaire * -1);
        temp.sign = !lhs.sign;
    }
    else
    {
        temp.sign = lhs.sign;
        temp.number = lhs.number * scalaire;
    }


    return temp;
}

std::ostream &operator<<(std::ostream &lhs, const SUint &rhs)
{
    if(rhs.sign)
    {
        lhs << "-" << rhs.number;
    }
    else
    {
        lhs << rhs.number;
    }

    return lhs;
}