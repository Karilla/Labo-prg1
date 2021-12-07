/**
 * @file delay_benoit_labo27.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-12-07
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <algorithm>
#include <string>
#include <iostream>
#include <random>
#include <functional>

using namespace std;

const int P = 30011;
const int Q = 30029;
const int E = 310237;
constexpr int = P * Q;

int expMod(long long base, int exposant, int modulo);

bool isPrime(int number);

int pgdcEuclide(int number1, int number2);

int extentedEuclide(int a, int b, int& privateKey);

const long MAX_VALUE = numeric_limits<int32_t>::max();
auto genNumberArrow = bind(uniform_int_distribution<int>(2,numeric_limits<int>::max()), mt19937(234567898));

int main()
{
    string text;
    getline(cin,text,'\0');
    int textToEncrypt = 0;
    for(int i = 0; i < text.size(); i+=3)
    {
        for(int j = 0; j < 3; j++)
        {
            textToEncrypt = textToEncrypt | (int)text[i + j];
            textToEncrypt = (textToEncrypt | (int)text[i + j]) << 8;
        }
    }
}

/**
 * @brief Calcule l'exposant modualaire 
 * @param base base de l'exposant
 * @param exposant exposant de la fonction
 * @param modulo modulo de la fonction
 * @return valeur du resultat de la fonction
 */
int expMod(long long base, int exposant, int modulo)
{
    //Initialise la variable qui sera retournée
    int result = 1;

    //Tant que l'exposant est superieur a 0
    while(exposant > 0)
    {
        //Si l'exposant est pair
        if((exposant % 2) == 0)
        {
            //Calcule un nouvel exposant 
            base = (base * base) % modulo;
            exposant = exposant/2;
        }
        //Si l'exposant est impair
        else
        {
            //Calcul le resultat et reduit de 1 l'exposant
            result = (result * base) % modulo;
            exposant--;
        }
    }
    return result;
}

/**
 * @brief Fonction pour determiner si un nombre est pair    
 * 
 * @param number valeur a evaluer
 * @return true si premier sinon false 
 */
bool isPrime(int number)
{
    //Si le nombre est inferieur a 2
    if(number < 2)
    {
        return false;
    }
    //Si le nombres est 2
    else if(number == 2)
    {
        //Il est forcement premier
        return true;
    }
    else if (number == 3)
    {
        return true;
    }
    else
    {
        for(int i = 0; i < 10; i++)
        {
            int tmp = genNumberArrow() % number;
            if(expMod(tmp, number - 1, number) != 1)
            {
                return false;
            }
            int q = 1;
            int u = number - 1;

            while ((u % 2 == 0) and (q == 1))
            {
                u = u / 2;
                
                q = expMod(tmp, u, number);
                 
                if((q != 1) and (q != (number -1)))
                {
                    return false;
                }
            }
        }
        return true;
    }
}

/**
 * @brief Calcule le pgdc entre 2 nombres avec l'alogorythme d'euclide
 * 
 * @param number1 premier nombre 
 * @param number2 deuxieme nombre
 * @return int valeur du pgdc des 2 nombres
 */
int pgdcEuclide(int number1, int number2)  
{
    //Variable qui va stocker temporairement un resultat
    int tmp = 0;

    //Temps que le deuxieme nombre est different de 0
    while(number2 != 0)
    {
        //Calcul le reste de a % b
        tmp = number2;
        number2 = number1 % number2;
        number1 = tmp;
    }

    //Retourne le pgdc
    return number1;
}

/**
 * @brief Calcule inverse de b mod a si a et b sont premiers entre eux, plus grand diviseur commun r entre a et b
 * 
 * @param a valeur de a
 * @param b valeur de b
 * @param d reference sur d, l'inverse de b mod a
 * @return pgdc reference sur le pgdc entre a et b
 */
int extentedEuclide(int a, int b, int& d)
{
    int pgdc = a;
    int rPrime = b;
    d = 0;
    int dPrime = 1;
    int tmp = 0;
    int tmpD, tmpR;
    while(rPrime != 0)
    {
        tmp = pgdc / rPrime;
        tmpR = pgdc;
        tmpD = d;
        pgdc = rPrime;
        d = dPrime;
        rPrime = tmpR - tmp * rPrime;
        dPrime =  tmpD - tmp * dPrime;
    }
    if(d < 0)
    {
        d += a;
    }
    return pgdc;
}