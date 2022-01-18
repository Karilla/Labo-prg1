//
// Created by bdela on 13/01/2022.
//

#include "Sint.h"

using namespace std;

const string ERROR_STRING_NUM = "ERROR TO CONVERT STRING TO SUINT, CHARACTER IS NOT A DIGIT AT POS ";

Sint::Sint(int nb)
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

Sint::Sint(std::string nb)
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

void Sint::handleZero()
{
    if(number == 0)
    {
        sign = false;
    }
}

Sint &Sint::operator+=(const Sint &rhs)
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

Sint &Sint::operator-=(const Sint &rhs)
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
    this->handleZero();
    return *this;
}

Sint &Sint::operator*=(const Sint &rhs)
{
    this->number *= rhs.number;
    this->sign = this->sign ^ rhs.sign;
    this->handleZero();
    return *this;
}

Sint& Sint::operator/=(const Sint &rhs)
{
    this->number /= rhs.number;
    this->sign = this->sign ^ rhs.sign;
    if(this->sign)
    {
        this->number += 1;
    }
    this->handleZero();
    return *this;
}

Sint& Sint::operator%=(const Sint &rhs)
{
    *this = (*this - (*this / rhs) * rhs);
    this->handleZero();
    return *this;
}

Sint Sint::rand(int nbDigits)
{
    static random_device device;
    mt19937 gen(device());
    uniform_int_distribution<> randInt(0,1);

    Sint temp;
    temp.sign = randInt(gen);
    temp.number = Uint::rand(nbDigits);
    return temp;
}

int Sint::comp(const Sint &u1, const Sint &u2)
{
    if(!u1.sign and !u2.sign)
    {
        return Uint::comp(u1.number, u2.number);
    }
    else if(!u1.sign and u2.sign)
    {
        return 1;
    }
    else if(u1.sign and !u2.sign)
    {
        return -1;
    }
    else
    {
        switch (Uint::comp(u1.number,u2.number)) {
            case -1:
                return 1;
            case 0:
                return 0;
            case 1:
                return -1;
            default:
                cerr << "Cé KASé" << endl;
        }
    }
}

//----------------------------------------------------------------------
//Fonction amie
Sint operator*(Sint lhs, const int scalaire)
{
    Sint temp;
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
    temp.handleZero();
    return temp;
}

std::ostream &operator<<(std::ostream &lhs, const Sint &rhs)
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

Sint operator*(Sint lhs, const Sint &rhs)
{
    lhs *= rhs;
    lhs.handleZero();
    return lhs;
}

Sint operator/(Sint lhs, const Sint &rhs)
{
    lhs /= rhs;
    return lhs;
}

Sint operator%(Sint lhs, const Sint &rhs)
{
    lhs %= rhs;
    lhs.handleZero();
    return lhs;
}

Sint operator+(Sint lhs, const Sint &rhs)
{
    lhs += rhs;
    lhs.handleZero();
    return lhs;
}

Sint operator-(Sint lhs, const Sint &rhs)
{
    lhs -= rhs;
    lhs.handleZero();
    return lhs;
}

bool operator==(const Sint &lhs, const Sint &rhs)
{
    if(Sint::comp(lhs, rhs) == 0)
    {
        return true;
    }
    return false;
}

bool operator!=(const Sint &lhs, const Sint &rhs)
{
    return  !(lhs == rhs);
}

bool operator<=(const Sint &lhs, const Sint &rhs)
{
    if(lhs == rhs or lhs < rhs)
    {
        return true;
    }
    return false;
}

bool operator>=(const Sint &lhs, const Sint &rhs)
{
    if(lhs == rhs or lhs > rhs)
    {
        return true;
    }
    return false;
}

bool operator<(const Sint &lhs, const Sint &rhs)
{
    if(Sint::comp(lhs,rhs) == -1)
    {
        return true;
    }
    return false;
}

bool operator>(const Sint &lhs, const Sint &rhs)
{
    if(Sint::comp(lhs,rhs) == 1)
    {
        return true;
    }
    return false;
}
