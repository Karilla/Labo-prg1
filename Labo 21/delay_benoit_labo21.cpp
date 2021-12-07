/**
 * @file delay_benoit_labo21.cpp
 * @author Delay Benoit (benoit.delay@heig-vd.ch)
 * @brief Exercice sur les tableaux
 * @version 1.0
 * @date 2021-11-17
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>

using namespace std;

bool isInVector(int value, vector<int> vector);

int destroyDuplicate(int tab[], const int size);

void printTab(const int tab[], int size);

int main()
{
    int tab[6] = {1,1,2,2,3,3};
    destroyDuplicate(tab,6);
    printTab(tab,3);
}

int destroyDuplicate(int tab[], const int size)
{
    vector<int> numberFound;
    for(int i = 0; i < size; i++)
    {
        if(isInVector(tab[i], numberFound))
        {
            cout << "Doublon haha" << endl;
        }
        else
        {
            cout << "Nouveau numer haha " << tab[i] << endl;
            numberFound.push_back(tab[i]);
        }
    }
    for(int i = 0; i < numberFound.size(); i++)
    {
        tab[i] = numberFound[i];
    }
    return numberFound.size();
}

bool isInVector(int value, vector<int> vector)
{
    for(int i = 0; i < vector.size(); i++)
    {
        if(vector[i] == value)
        {
            return true;
        }
    }
    return false;
}

void printTab(const int tab[], int size)
{
    cout << "[";
    for(int i = 0; i < size; i++)
    {
        cout << tab[i];
    }
    cout << "]" << endl;
}