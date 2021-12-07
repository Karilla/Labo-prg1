/**
 * @file delay_benoit_labo22.cpp
 * @author Delay Benoit (benoit.delay@heig-vd.ch)
 * @brief Calcule et affiche la sequence de fibonacci
 * @version 1.0
 * @date 2021-11-19
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>

using namespace std;
using vectorNumber = vector<int>;

vector<int> addVector(vector<int> vector1, vector<int> vector2);

void calculDiagonale(vector<vector<int>> matrice, int& leftSum, int& rightSum);

void printVector(vector<int> vector);

vector<vectorNumber> fibonacci(int n);

void printFibonnaci(vector<vectorNumber> fibonnaciSequence);

int main()
{
    int numberSequence;
    cout << "Veuillez selectionner le nombre d'element de la suite de fibonnacci : ";
    cin  >> numberSequence;
    printFibonnaci(fibonacci(numberSequence));
}

/**
 * @brief Additionne 2 vecteur ensemble
 * 
 * @param vector1 premier vecteur
 * @param vector2 deuxieme vecteur
 * @return vector<int> resultat
 */
vector<int> addVector(vector<int> vector1, vector<int> vector2)
{

    vector<int> sumVector(0);
    size_t vector1Size = vector1.size();
    size_t vector2Size = vector2.size();
    int carry = 0;

    if(vector2Size == vector1Size)
    {
        for(int i = 0; i < vector2Size; i++)
        {
            sumVector.push_back((vector2[i] + vector1[i] + carry) % 10);
            carry = (vector1[i] + vector2[i] + carry) / 10;
        }

        if(carry)
        {
            sumVector.push_back(carry);
        }
    }
    else if(vector2Size > vector1Size)
    {
        for(int i = 0; i < vector1Size; i++)
        {   
            sumVector.push_back((vector2[i] + vector1[i] + carry) % 10);
            carry = (vector1[i] + vector2[i] + carry) / 10;
        }
        
        for(int i = vector1Size; i < vector2Size; i++)
        {
            sumVector.push_back(vector2[i] + carry);
            carry = 0;
        } 
    }
    else if(vector1Size > vector2Size)
    {
        for(int i = 0; i < vector2Size; i++)
        {
            sumVector.push_back((vector2[i] + vector1[i] + carry) % 10);
            carry = (vector1[i] + vector2[i] + carry) / 10;
        }
        
        for(int i = vector2Size; i < vector1Size; i++)
        {
            sumVector.push_back(vector1[i] + carry);
            carry = 0;
        } 
    }
    return sumVector;
}

/**
 * @brief Affiche le vecteur
 * 
 * @param vector vecteur a afficher
 */
void printVector(vector<int> vector)
{
    for(size_t i = vector.size(); i > 0 ; i--)
    {
        cout << vector[i-1];
    }
    cout << endl;
}

/**
 * @brief Calcule la suite de fibonnaci
 * 
 * @param n nombre d'element de la sequence
 * @return vector<vectorNumber> vecteur qui contient les vecteurs qui
 * representent les nombres
 */
vector<vectorNumber> fibonacci(int n)
{
    vector<vectorNumber> fibonnaciSequence;
    if(n == 1)
    {
        fibonnaciSequence.push_back(vectorNumber(1,0));
        return fibonnaciSequence;
    }
    else if(n == 2)
    {
        fibonnaciSequence.push_back(vectorNumber(1,0));
        fibonnaciSequence.push_back(vectorNumber(1,1));
        return fibonnaciSequence;
    }
    else
    {
        fibonnaciSequence.push_back(vectorNumber(1,0));
        fibonnaciSequence.push_back(vectorNumber(1,1));

        for(int i = 2; i < n; i++)
        {
            fibonnaciSequence.push_back(addVector(fibonnaciSequence[i - 2],fibonnaciSequence[i - 1]));
        }
        return fibonnaciSequence;
    }
}

/**
 * @brief Affiche la sequence de fibonacci passé en paramenrtre
 * 
 * @param fibonnaciSequence sequence a afficher 
 */
void printFibonnaci(vector<vectorNumber> fibonnaciSequence)
{
    cout << "Sequence de fibonnacci de " << fibonnaciSequence.size() <<
    " elements" << endl;

    for(int i = 0; i < fibonnaciSequence.size(); i ++)
    {
        printVector(fibonnaciSequence[i]);
    }
}