//
// Created by bdela on 14/12/2021
//
#include "Uint.h"

using namespace std;

const string ERROR_MESSAGE = "ERREUR: RESULTAT NEGATIF";

Uint::Uint(uint64_t number) {
    if(number)
    {
        while (number > 0) {
            vectorNumber.push_back(number % 10);
            number /= 10;
        }
    }
    else
    {
        vectorNumber.push_back(0);
    }

}


Uint::Uint(std::string number) {
    for (int i = number.size(); i > 0; i--) {
        vectorNumber.push_back(number[i - 1] - '0');
    }
}

//TODO ajouter gestion erreur depassemet du type 64bit
Uint::operator uint64_t()
{
    uint64_t temp;
    for(int i = 0; i < this->vectorNumber.size(); i ++)
    {
        temp += this->vectorNumber[i] * (uint64_t)pow(10,i);
    }
    return temp;
}

void Uint::refactor()
{
    int tempSize = this->getSize();
    for(int i = tempSize; i > 0; i--)
    {
        if(this->vectorNumber[i -1] == 0)
        {
            this->vectorNumber.pop_back();
        }
        else
        {
            return;
        }
    }
    if(vectorNumber.empty())
    {
        vectorNumber.push_back(0);
    }
}

Uint Uint::operator/(int rhs) const
{
    Uint temp = *this;
    temp /= rhs;
    return temp;
}

int Uint::comp(Uint u1, Uint u2) {
    size_t u1Size = u1.vectorNumber.size();
    size_t u2Size = u2.vectorNumber.size();


    if (u1Size > u2Size) {
        return 1;
    } else if (u1Size < u2Size) {
        return -1;
    } else {
        for (int i = u1Size; i > 0; i--) {
            if (u1.vectorNumber[i - 1] > u2.vectorNumber[i - 1]) {
                return 1;
            } else if (u1.vectorNumber[i - 1] < u2.vectorNumber[i - 1]) {
                return -1;
            }
        }
        return 0;
    }
}

Uint Uint::rand(int nbDigits)
{
    static random_device device;
    mt19937 gen(device());
    uniform_int_distribution<> randInt(0,9);

    Uint randTemp;

    for(int i = 0; i < nbDigits - 1; i++)
    {
        randTemp.vectorNumber.push_back(randInt(gen));
    }

    int tempDigit;
    do {
        tempDigit = randInt(gen);
    }while(tempDigit == 0);

    randTemp.vectorNumber.push_back(tempDigit);

    return randTemp;
}

Uint &Uint::operator+=(const Uint &number) {
    Uint temp;
    size_t vector1Size = number.vectorNumber.size();
    size_t vector2Size = this->vectorNumber.size();
    int carry = 0;

    if (vector2Size == vector1Size) {
        for (int i = 0; i < vector2Size; i++) {
            temp.vectorNumber.push_back((number.vectorNumber[i] + this->vectorNumber[i] + carry) % 10);
            carry = (number.vectorNumber[i] + this->vectorNumber[i] + carry) / 10;
        }

        if (carry) {
            temp.vectorNumber.push_back(carry);
        }
    } else if (vector2Size > vector1Size) {
        for (int i = 0; i < vector1Size; i++) {
            temp.vectorNumber.push_back((number.vectorNumber[i] + this->vectorNumber[i] + carry) % 10);
            carry = (this->vectorNumber[i] + number.vectorNumber[i] + carry) / 10;
        }

        for (int i = vector1Size; i < vector2Size; i++) {
            temp.vectorNumber.push_back((this->vectorNumber[i] + carry) % 10);
            carry = (this->vectorNumber[i] + carry) / 10;
        }

        if(carry)
        {
            temp.vectorNumber.push_back(carry);
        }
    } else if (vector1Size > vector2Size) {
        for (int i = 0; i < vector2Size; i++) {
            temp.vectorNumber.push_back((this->vectorNumber[i] + number.vectorNumber[i] + carry) % 10);
            carry = (number.vectorNumber[i] + this->vectorNumber[i] + carry) / 10;
        }

        for (size_t i = vector2Size; i < vector1Size; i++) {
            temp.vectorNumber.push_back((number.vectorNumber[i] + carry) % 10);
            carry = (number.vectorNumber[i] + carry) / 10 ;
        }
        if(carry)
        {
            temp.vectorNumber.push_back(carry);
        }
    }
    *this = temp;
    return *this;
}

Uint& Uint::operator/=(int rhs)
{
    for (size_t i = vectorNumber.size() - 1; i > 0; i--)
    {
        vectorNumber.at(i - 1) += vectorNumber.at(i) % rhs * 10;
        vectorNumber.at(i) /= rhs;
    }
    vectorNumber.at(0) /= rhs;
    while (vectorNumber.size() > 1 && vectorNumber.back() == 0)
        vectorNumber.pop_back();

    return *this;
}

Uint &Uint::operator-=(const Uint &number) {
    size_t vector1Size = this->vectorNumber.size();
    size_t vector2Size = number.vectorNumber.size();
    Uint numberCopy = number;
    Uint temp;

    if (*this < number) {
        cerr << ERROR_MESSAGE << endl;
        Uint error(404);
        *this = error;
        return *this;
    }
    else
    {
        if (this->vectorNumber[vector1Size - 1] < number.vectorNumber[vector2Size - 1]
        and vector2Size == vector1Size)
        {
            cerr << ERROR_MESSAGE << endl;
            Uint error(404);
            *this = error;
            return *this;
        }

        bool report = false;
        for(int i = 0; i < vector2Size; i++)
        {
            if(report)
            {
                if(this->vectorNumber[i] == 0)
                {
                    this->vectorNumber[i] = 9;
                }
                else
                {
                    this->vectorNumber[i] -= 1;
                    report = false;
                }
            }
            if(this->vectorNumber[i] >= number.vectorNumber[i])
            {
                this->vectorNumber[i] -= number.vectorNumber[i];
            }
            else
            {
                report = true;
                this->vectorNumber[i] = (this->vectorNumber[i] + 10) - number.vectorNumber[i];
            }
        }
        if(report)
        {
            size_t index = vector2Size;
            while(report)
            {
                if(this->vectorNumber[index] == 0)
                {
                    this->vectorNumber[index] = 9;
                }
                else
                {
                    report = false;
                    --this->vectorNumber[index];
                }
                index++;
            }
        }
        this->refactor();
        return *this;
    }
}

size_t Uint::getSize()
{
    return this->vectorNumber.size();
}

Uint &Uint::operator/=(const Uint &rhs)
{
    Uint reste;
    *this = divRem(*this,rhs, reste);
    return *this;
}

Uint &Uint::operator%=(const Uint &rhs)
{
    divRem(*this, rhs, *this);
    return *this;
}

Uint &Uint::operator%=(uint32_t rhs)
{
    //Quick and dirty way to get the mod with a uint32_t without divAndRem()
    return *this -= (*this / rhs) * rhs;
}

Uint &Uint::operator++() {
    *this += 1;
    return *this;
}

Uint Uint::operator++(int) {
    Uint temp = *this;
    temp += 1;
    return temp;
}

Uint &Uint::operator--() {
    *this -= 1;
    return *this;
}

Uint Uint::operator--(int) {
    Uint temp = *this;
    temp -= 1;
    return temp;
}

Uint& Uint::operator=(const int rhs) {
    Uint temp(rhs);
    *this = temp;
    return *this;
}

Uint& Uint::operator=(const std::string rhs) {
    Uint temp(rhs);
    *this = temp;
    return *this;
}

Uint &Uint::operator*=(const Uint &rhs) {
    // Use a temporary value to work on it
    Uint temp(0);
    // Iterates on each members of the right value
    for (size_t i = 0; i != rhs.vectorNumber.size(); i++)
    {
        // Adds in temp the result of the multiplication of right and left
        temp += *this * rhs.vectorNumber.at(i);
        // If the size of the right value is too small, insert
        if (i != rhs.vectorNumber.size() - 1)
            vectorNumber.insert(vectorNumber.cbegin(), 0);
    }

    *this = temp;

    return *this;
    /*
    size_t vector1Size = this->vectorNumber.size();
    size_t vector2Size = rhs.vectorNumber.size();
    Uint temp(0);

    if (vector1Size > vector2Size) {
        for (int i = vector2Size; i > 0; i--) {
            temp += (*this * (rhs.vectorNumber[i - 1] * pow(10, i - 1)));
        }
    } else {
        for (int i = vector1Size; i > 0; i--) {
            temp += (rhs * (int) (this->vectorNumber[i - 1] * pow(10, i - 1)));
        }
    }
    *this = temp;
    return temp;
     */
}

/*
 * Uint &Uint::operator/=(uint32_t right)
{
    for (size_t i = iValue.size() - 1; i > 0; i--)
    {
        iValue.at(i - 1) += iValue.at(i) % right * 10;
        iValue.at(i) /= right;
    }
    iValue.at(0) /= right;
    while (iValue.size() > 1 && iValue.back() == 0)
        iValue.pop_back();

    return *this;
}
*/

Uint Uint::divRem(const Uint &dividende, const Uint &divisieur, Uint& reste)
{
    Uint powerOfTwo(1);
    Uint b = divisieur;
    while(b <= dividende)
    {
        powerOfTwo *= 2;
        b *= 2;
    }
    Uint quotient(0);
    reste = dividende;


    while (reste>=divisieur)
    {
        b /= 2;
        powerOfTwo /=  2;

        if(reste >= b)
        {
            quotient += powerOfTwo;
            reste -= b;
        }
    }
    return quotient;
}

Uint operator-(Uint lhs, const Uint &rhs) {
    lhs -= rhs;
    lhs.refactor();
    return lhs;
}

Uint operator+(Uint lhs, const Uint &rhs) {
    lhs += rhs;
    return lhs;
}

Uint operator*(Uint lhs, const Uint &rhs) {
    lhs *= rhs;
    return lhs;
}

Uint Uint::operator/(const Uint &rhs) const
{
    Uint temp = *this;
    temp /= rhs;
    return temp;
}

Uint Uint::operator%(const Uint &rhs) const
{
    Uint temp = *this;
    temp %= rhs;
    return temp;
}

Uint Uint::operator%(uint32_t rhs) const
{
    Uint temp = *this;
    temp %= rhs;
    return temp;
}

Uint operator*(Uint lhs, const int scalaire) {
    Uint tmpObject;
    int tmp = 0;
    int carry = 0;
    for (int i = 0; i < lhs.vectorNumber.size(); i++) {
        tmp = lhs.vectorNumber[i] * scalaire;
        tmp += carry;
        carry = tmp / 10;
        tmpObject.vectorNumber.push_back(tmp % 10);
    }
    if (carry) {
        while (carry > 0) {
            tmpObject.vectorNumber.push_back(carry % 10);
            carry /= 10;
        }
    }
    return tmpObject;
}

std::ostream &operator<<(std::ostream &lhs, const Uint &rhs) {
    for (int i = rhs.vectorNumber.size(); i > 0; i--) {
        lhs << rhs.vectorNumber[i - 1];
    }
    return lhs;
}

//TODO je ne suis pas sur que ca fonctionne a check
std::istream &operator>>(std::istream &lhs, Uint &rhs)
{
    string tempString;

    lhs >> tempString;

    Uint temp(tempString);

    rhs = temp;

    return lhs;

}

bool operator<(const Uint &lhs, const Uint &rhs) {
    if (Uint::comp(lhs, rhs) == -1) {
        return true;
    }
    return false;
}

bool operator<=(const Uint &lhs, const Uint &rhs) {
    if (Uint::comp(lhs, rhs) <= 0) {
        return true;
    }
    return false;
}

bool operator==(const Uint &lhs, const Uint &rhs) {
    if (Uint::comp(lhs, rhs) == 0) {
        return true;
    }
    return false;
}

bool operator>(const Uint &lhs, const Uint &rhs) {
    if (Uint::comp(lhs, rhs) == 1) {
        return true;
    }
    return false;
}

bool operator>=(const Uint &lhs, const Uint &rhs) {
    if (Uint::comp(lhs, rhs) >= 0) {
        return true;
    }
    return false;
}

bool operator!=(const Uint &lhs, const Uint &rhs)
{
    return !(lhs == rhs);
}