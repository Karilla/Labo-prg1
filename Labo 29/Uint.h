//
// Created by bdela on 14/12/2021.
//

#ifndef LABO_29_UINT_H
#define LABO_29_UINT_H

#include <cstdint>
#include <string>
#include <vector>
#include <iostream>

class Uint {
    friend Uint operator+(Uint lhs, const Uint& rhs);
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

    Uint& operator +=(const Uint& number);

    void print();

private:

    std::vector<uint64_t> vectorNumber;

    /**
     *
     * @param u1
     * @param u2
     * @return
     */
    int comp(Uint u1, Uint u2);
};


#endif //LABO_29_UINT_H
