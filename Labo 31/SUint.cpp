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

SUint &SUint::operator+=(const SUint &rhs)
{
    if(!this->sign and !rhs.sign)
    {
        this->number += rhs.number;
    }
    else if(this->sign and !rhs.sign)
    {
        if(this->number >= rhs.number)
        {
            this->number -= rhs.number;
            this->sign = true;
        }
        else
        {
            this->number = rhs.number - this->number;
            this->sign = false;
        }
    }
    else if(!this->sign and rhs.sign)
    {
        if(this->number >= rhs.number)
        {
            this->number -= rhs.number;
            this->sign = false;
        }
        else
        {
            this->number = rhs.number - this->number;
            this->sign = true;
        }
    }
    else
    {
        this->number += rhs.number;
        this->sign = true;
    }

    return *this;
}

SUint &SUint::operator-=(const SUint &rhs)
{
    if(!this->sign and !rhs.sign)
    {
        if(this->number >= rhs.number)
        {
            this->number -= rhs.number;
            this->sign = false;
        }
        else
        {
            this->number = rhs.number - this->number;
            this->sign = true;
        }
    }
    else if(!this->sign and rhs.sign)
    {
        this->number += rhs.number;
    }
    else if(this->sign and !rhs.sign)
    {
        this->number += rhs.number;
        this->sign = true;
    }
    else
    {
        if(this->number >= rhs.number)
        {
            this->number -= rhs.number;
            this->sign = true;
        }
        else
        {
            this->number = rhs.number - this->number;
            this->sign = false;
        }
    }

    return *this;
}

SUint &SUint::operator*=(const SUint &rhs)
{
    this->number *= rhs.number;
    this->sign = this->sign ^ rhs.sign;
    return *this;
}

SUint& SUint::operator/=(const SUint &rhs)
{
    this->number /= rhs.number;
    this->sign = this->sign ^ rhs.sign;
    if(this->sign)
    {
        this->number += 1;
    }
    return *this;
}

SUint& SUint::operator%=(const SUint &rhs)
{
    *this = (*this - (*this / rhs) * rhs);
    return *this;
}

SUint SUint::rand(int nbDigits)
{
    static random_device device;
    mt19937 gen(device());
    uniform_int_distribution<> randInt(0,1);

    SUint temp;
    temp.sign = randInt(gen);
    temp.number = Uint::rand(nbDigits);
    return temp;
}

//----------------------------------------------------------------------
//Fonction amie
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

SUint operator*(SUint lhs, const SUint &rhs)
{
    lhs *= rhs;
    return lhs;
}

SUint operator/(SUint lhs, const SUint &rhs)
{
    lhs /= rhs;
    return lhs;
}

SUint operator%(SUint lhs, const SUint &rhs)
{
    lhs %= rhs;
    return lhs;
}

SUint operator+(SUint lhs, const SUint &rhs)
{
    lhs += rhs;
    return lhs;
}

SUint operator-(SUint lhs, const SUint &rhs)
{
    lhs -= rhs;
    return lhs;
}