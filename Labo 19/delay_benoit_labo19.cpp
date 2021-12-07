    /**
 * @file delay_benoit_labo19.cpp
 * @author delay benoit (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-11-12
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>

using namespace std;

const int SIZE = 10;

void rotateToRight(int tab[], size_t size)
{
    int tmp;
    for(int i = 0; i < size; i++)
    {
        if((i + 1) >= size)
        {
            tab[0] = tab[i];
        }
        else
        {
            tmp = tab[i + 1];
            tab[i + 1] = tab[i];
            
        }
        cout << "i = " << i << endl;
    }
}

int main()
{
    int tab[SIZE] = {0,1,2,3,4,5,6,7,8,9};
    rotateToRight(tab,SIZE);
    for(int i = 0; i < SIZE;i++)
    {
        cout << tab[i] << endl;
    }
}