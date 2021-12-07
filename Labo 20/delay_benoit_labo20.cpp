/**
 * @file delay_benoit_labo20.cpp
 * @author Delay Benoit (benoit.delay@heig-vd.ch)
 * @brief Coder une fonction exponentielle
 * @version 1.0
 * @date 2021-11-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <cmath>

using namespace std;

const int TAB_SIZE = 500;

int countNumber(int number);

void splitNumber(int number, int tab[]);

void printTab(const int tab[], int size);

void printFinalNumber(const int tab[], const int size);


int main()
{
    int tab[TAB_SIZE] = {0};
    int nGoal = 6;
    int carry = 0;

    cout << "Veuillez entre n factorielle svp: " << endl;
    cin >> nGoal;

    splitNumber(1,tab);

    for(int n = 1; n < nGoal + 1; n++)
    {
        for(int i = 0; i < 500; i++)
        {
            tab[i] *= n;
            tab[i] += carry;
            carry = tab[i] / 10;
            tab[i] %= 10;
        }
    }
    printFinalNumber(tab,500);
}

/**
 * @brief Permet de compter le nombre de chiffre d'un nombre
 * 
 * @param number nombre a copter
     */
int countNumber(int number)
{
    int count = 0;
    while(number != 0)
    {
        count++;
        number /= 10;
    }
    return count;
}

/**
 * @brief Permet de separer un nombre en plusieurd chiffre a chaque place du tableau
 * 
 * @param number chiffre a partager
 * @param tab tableau qui servira de conteneur
 */
void splitNumber(int number, int tab[])
{
    int tmpNumber = number;
    int count = 0;
    do
    {
        tab[count] = tmpNumber % 10;
        tmpNumber /= 10;
        count++;
    } while (tmpNumber != 0);
    
}

/**
 * @brief Permet d'afficher le nombre reel sans les zeros avant et dans le bon ordre
 * 
 * @param tab tableau a afficher
 * @param size taille du tableau
 */
void printFinalNumber(const int tab[], const int size)
{
    bool isNumber = false;
    cout << "Factorielle = ";
    for(int i = size; i > 0; i--)
    {

        if((tab[i-1] != 0) || (isNumber))
        {
            isNumber = true;
            cout << tab[i-1];
        }
    }
}

/**
 * @brief [DEBUG] permet d'afficher le tableau
 * 
 * @param tab tableau a imprimer
 * @param size taille du tableau
 */
void printTab(const int tab[], int size)
{
    cout << "[";
    for(int i = 0; i < size; i++)
    {
        cout << tab[i];
    }
    cout << "]" << endl;
}