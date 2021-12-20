//
// Created by bdela on 14/12/2021.
//

#ifndef LABO_29_UINT_H
#define LABO_29_UINT_H

#include <cstdint>
#include <string>
#include <vector>
#include <iostream>
#include <cmath>

class Uint {
    friend bool operator<(const Uint& lhs, const Uint& rhs);

    friend bool operator==(const Uint& lhs, const Uint& rhs);

    friend bool operator>(const Uint& lhs, const Uint& rhs);

    friend bool operator>=(const Uint& lhs, const Uint& rhs);

    friend bool operator<=(const Uint& lhs, const Uint& rhs);

    friend Uint operator+(Uint lhs, const Uint& rhs);

    friend Uint operator-(Uint lhs, const Uint& rhs);

    friend Uint operator*(Uint lhs, const Uint& rhs);

    friend Uint operator*(Uint lhs, const int scalaire);

    friend std::ostream& operator<<(std::ostream& lhs, const Uint& rhs);
public:
    /**
     *
     * @param number
     */
    Uint(uint64_t number);

    /**
     *
     * @param number
     */
    Uint(std::string number);

    Uint();

    Uint& operator++();

    Uint operator++(int);

    Uint& operator +=(const Uint& number);

    Uint& operator -=(const Uint& number);

    Uint& operator *=(const Uint& rhs);

    static int comp(Uint u1, Uint u2);
private:

    std::vector<uint64_t> vectorNumber;
};


#endif //LABO_29_UINT_H
