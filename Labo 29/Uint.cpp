//
// Created by bdela on 14/12/2021.
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

        for(int i = vector2Size; i < vector1Size; i++)
        {
            temp.vectorNumber.push_back(number.vectorNumber[i] + carry);
            carry = 0;
        }
    }
    return temp;
}

Uint operator+(Uint lhs, const Uint& rhs)
{
    lhs += rhs;
    return lhs;
}