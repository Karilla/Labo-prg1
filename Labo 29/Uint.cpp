//
// Created by bdela on 14/12/2021
//
#include "Uint.h"

using namespace std;

Uint::Uint()
{

}

Uint::Uint(uint64_t number)
{
    while(number > 0)
    {
        vectorNumber.push_back(number % 10);
        number /= 10;
    }
}

Uint::Uint(std::string number)
{
    for(int i = number.size(); i  > 0; i--)
    {
        vectorNumber.push_back(number[i -1] - '0');
    }
}

int Uint::comp(Uint u1, Uint u2)
{
    size_t u1Size = u1.vectorNumber.size();
    size_t u2Size = u2.vectorNumber.size();

    if(u1Size > u2Size)
    {
        return 1;
    }
    else if (u1Size < u2Size)
    {
        return -1;
    }
    else
    {
        for(int i = u1Size; i > 0; i--)
        {
            if(u1.vectorNumber[i-1] > u2.vectorNumber[i - 1])
            {
                return 1;
            }
            else if(u1.vectorNumber[i-1] < u2.vectorNumber[i - 1])
            {
                return -1;
            }
        }
        return 0;
    }
}

Uint& Uint::operator+=(const Uint& number)
{
    Uint temp;
    size_t vector1Size = number.vectorNumber.size();
    size_t vector2Size = this->vectorNumber.size();
    int carry = 0;

    if(vector2Size == vector1Size)
    {
        for(int i = 0; i < vector2Size; i++)
        {
            temp.vectorNumber.push_back((number.vectorNumber[i] + this->vectorNumber[i] + carry) % 10);
            carry = (number.vectorNumber[i] + this->vectorNumber[i] + carry) / 10;
        }

        if(carry)
        {
            temp.vectorNumber.push_back(carry);
        }
    }
    else if(vector2Size > vector1Size)
    {
        for(int i = 0; i < vector1Size; i++)
        {
            temp.vectorNumber.push_back((number.vectorNumber[i] + this->vectorNumber[i] + carry) % 10);
            carry = (this->vectorNumber[i] + number.vectorNumber[i] + carry) / 10;
        }

        for(int i = vector1Size; i < vector2Size; i++)
        {
            temp.vectorNumber.push_back(this->vectorNumber[i] + carry);
            carry = 0;
        }
    }
    else if(vector1Size > vector2Size)
    {
        for(int i = 0; i < vector2Size; i++)
        {
            temp.vectorNumber.push_back((this->vectorNumber[i] + number.vectorNumber[i] + carry) % 10);
            carry = (number.vectorNumber[i] + this->vectorNumber[i] + carry) / 10;
        }

        for(size_t i = vector2Size; i < vector1Size; i++)
        {
            temp.vectorNumber.push_back(number.vectorNumber[i] + carry);
            carry = 0;
        }
    }
    *this = temp;
    return *this;
}

Uint& Uint::operator-=(const Uint& number)
{
    size_t vector1Size = this->vectorNumber.size();
    size_t vector2Size = number.vectorNumber.size();
    Uint numberCopy = number;
    Uint temp;

    if(vector2Size > vector1Size)
    {
        cerr << "ERREUR: RESULTAT NEGATIF" << endl;
        Uint error(404);
        return error;
    }
    else if(vector1Size > vector2Size)
    {
        //numberCopy.vectorNumber.resize(vector1Size, 0);
        for(size_t i = 0; i < vector1Size; i++)
        {

        }
    }
    else
    {

    }
}

Uint& Uint::operator++()
{
    *this += Uint(1);
    return *this;
}

Uint Uint::operator++(int)
{
    Uint temp = *this;
    temp += Uint(1);
    return temp;
}

Uint Uint::operator=(const int rhs)
{
    Uint temp(rhs);
    return temp;
}

Uint Uint::operator=(const std::string rhs)
{
    Uint temp(rhs);
    return temp;
}

Uint& Uint::operator*=(const Uint &rhs)
{
    size_t vector1Size = this->vectorNumber.size();
    size_t vector2Size = rhs.vectorNumber.size();
    Uint temp(0);
    int x;

    if(vector1Size > vector2Size)
    {
        for(int i = vector2Size; i > 0;i--)
        {
            x = rhs.vectorNumber[i-1] * pow(10,i-1);
            temp+= (*this * (rhs.vectorNumber[i-1] * pow(10,i-1)));
        }
    }
    else
    {
        for(int i = vector1Size; i > 0;i--)
        {
            temp+= (rhs * (int)(this->vectorNumber[i-1] * pow(10,i - 1)));
        }
    }
    *this = temp;
    return temp;
}

Uint operator-(Uint lhs, const Uint& rhs)
{
    lhs -= rhs;
    return lhs;
}

Uint operator+(Uint lhs, const Uint& rhs)
{
    lhs += rhs;
    return lhs;
}

Uint operator*(Uint lhs, const Uint& rhs)
{
    lhs *= rhs;
    return lhs;
}

Uint operator*(Uint lhs, const int scalaire)
{
    Uint tmpObject;
    int tmp = 0;
    int carry = 0;
    for(int i = 0; i < lhs.vectorNumber.size(); i++)
    {
        tmp = lhs.vectorNumber[i] * scalaire;
        tmp += carry;
        carry = tmp / 10;
        tmpObject.vectorNumber.push_back(tmp % 10);
    }
    if(carry)
    {
        while(carry > 0)
        {
            tmpObject.vectorNumber.push_back(carry % 10);
            carry /= 10;
        }
    }
    return tmpObject;
}

std::ostream& operator<<(std::ostream& lhs, const Uint& rhs)
{
    for(int i = rhs.vectorNumber.size(); i > 0; i--)
    {
        lhs << rhs.vectorNumber[i-1];
    }
    return lhs;
}
bool operator<(const Uint& lhs, const Uint& rhs)
{
    if(Uint::comp(lhs,rhs) == -1)
    {
        return true;
    }
    return false;
}

bool operator<=(const Uint& lhs, const Uint& rhs)
{
    if(Uint::comp(lhs,rhs) <= 0)
    {
        return true;
    }
    return false;
}

bool operator==(const Uint& lhs, const Uint& rhs)
{
    if(Uint::comp(lhs,rhs) == 0)
    {
        return true;
    }
    return false;
}

bool operator>(const Uint& lhs, const Uint& rhs)
{
    if(Uint::comp(lhs,rhs) == 1)
    {
        return true;
    }
    return false;
}

bool operator>=(const Uint& lhs, const Uint& rhs)
{
    if(Uint::comp(lhs,rhs) >= 0)
    {
        return true;
    }
    return false;
}