/**
 * @file delay_benoit_labo17.cpp
 * @author Delay Benoit (benoit.delay@heig-vd.ch)
 * @brief 
 * @version 1.0
 * @date 2021-11-08
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <iomanip>

using namespace std;

void syracuse_v1(int number);
void syracuse_v2(int number, int numberIteration);

int main()
{
    syracuse_v1(145); 
    syracuse_v2(145,5);  
}

/**
 * @brief Calcule et affiche la suite de syracuse en partant du nombre de depart
 * 
 * @param number nombre de depart de la suite de syracuse
 */
void syracuse_v1(int number)
 {
    int cntSyracuse = 0;
    
    int currentNumber = number;

    while(currentNumber != 1)
    {
        //Si le chiffre est pair
        if(!(currentNumber % 2)){ currentNumber /= 2;}

        //Si le chiffre est impair
        else{currentNumber = (currentNumber * 3) + 1;}
        cntSyracuse++;

        cout << "Iteration no " << setw(4) << cntSyracuse <<
        " \tsyracuse number " << currentNumber << endl;
    }
}

/**
 * @brief Calcule la suite de nombre de syracuse de n element
 * 
 * @param number nombre de depart de l'iteration
 * @param numberIteration nombre n du nombre de fois qu'on veut
 * appliquer la suite
 */
void syracuse_v2(int number, int numberIteration)
{
    int currentNumber = number;

    for(int i = 0; i < numberIteration; i++)
    {
        //Si le chiffre est pair
        if(!(currentNumber % 2)){ currentNumber /= 2;}

        //Si le chiffre est impair
        else{currentNumber = (currentNumber * 3) + 1;}

        cout << "syracuse number " << currentNumber << endl;
    }
}