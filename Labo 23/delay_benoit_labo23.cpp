/**
 * @file delay_benoit_labo23.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-11-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>

using namespace std;
using vectorNumber = vector<int>;

vectorNumber multiplyDoubleVectorNumber(vectorNumber vector1, vectorNumber vector2);

vectorNumber multiplyScalaireVectorNumber(vectorNumber vector, int n);

void printVector(vectorNumber vector);

int main()
{
    vectorNumber test(0);
    test.push_back(0);
    test.push_back(0);
    test.push_back(1);

    printVector(multiplyScalaireVectorNumber(test,3));
}

/**
 * @brief 
 * 
 * @param vector1 
 * @param vector2 
 * @return vectorNumber 
 */
vectorNumber multiplyDoubleVectorNumber(vectorNumber vector1, vectorNumber vector2)
{
    
}

/**
 * @brief 
 * 
 * @param vector 
 * @param n 
 * @return vectorNumber 
 */
vectorNumber multiplyScalaireVectorNumber(vectorNumber vector, int n)
{
    vectorNumber resultVector(0);
    int tmp = 0;
    int carry = 0;

    for(int i = 0; i < vector.size(); i++)
    {
        tmp = vector[i] * n;
        tmp += carry;
        carry = tmp / 10;
        resultVector.push_back(tmp % 10);
    }
    
    return resultVector;
}

/**
 * @brief 
 * 
 * @param vector 
 */
void printVector(vectorNumber vector)
{
    for(size_t i = vector.size(); i > 0 ; i--)
    {
        cout << vector[i-1];
    }
    cout << endl;
}