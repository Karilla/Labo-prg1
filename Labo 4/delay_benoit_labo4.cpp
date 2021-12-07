/*
Nom: Delay
Prenom: Benoit
Date: 28/09/2021
Labo: Labo 4
Projet: Afficher les limites des differents type en cpp
*/
#include <iostream>
#include <limits>

using namespace std;

int main()
{
    cout << "signed char (8 bits) : " << (int)numeric_limits<char>::lowest() << " .. " 
    << (int)numeric_limits<char>::max() << endl;

    cout << "unsigned char (8 bits) : " << (int)numeric_limits<unsigned char>::lowest() << " .. " 
    << (int)numeric_limits<unsigned char>::max() << endl;

    cout << "signed short (16 bits) : " << numeric_limits<short>::lowest() << " .. " 
    << numeric_limits<short>::max() << endl;

    cout << "unsigned short (16 bits) : " << numeric_limits<unsigned short>::lowest() << " .. " 
    << numeric_limits<unsigned short>::max() << endl;

    cout << "signed int (32 bits) : " << numeric_limits<int>::lowest() << " .. " 
    << numeric_limits<int>::max() << endl;

    cout << "unsigned int (32 bits) : " << numeric_limits<unsigned int>::lowest() << " .. " 
    << numeric_limits<unsigned int>::max() << endl;

    cout << "signed long (32 bits) : " << numeric_limits<long>::lowest() << " .. " 
    << numeric_limits<long>::max() << endl;

    cout << "unsigned long (32 bits) : " << numeric_limits<unsigned long>::lowest() << " .. " 
    << numeric_limits<unsigned long>::max() << endl;

    cout << "signed long long (64 bits) : " << numeric_limits<long long>::lowest() << " .. " 
    << numeric_limits<long long>::max() << endl;

    cout << "unsigned long long  (64 bits) : " << numeric_limits<unsigned long long>::lowest() << " .. " 
    << numeric_limits<unsigned long long>::max() << endl;

    cout << "float (32 bits) : lowest" << numeric_limits<float>::lowest() << endl << "min : "
    << numeric_limits<float>::min() << endl << "max : " << numeric_limits<float>::max() 
    << endl << "epsilon : " << numeric_limits<float>::epsilon() << endl;

    cout << "double (64 bits) : lowest" << numeric_limits<double>::lowest() << endl << "min : "
    << numeric_limits<double>::min() << endl << "max : " << numeric_limits<double>::max() 
    << endl << "epsilon : " << numeric_limits<double>::epsilon() << endl;

    cout << "long double  (80 bits) : lowest" << numeric_limits<long double >::lowest() << endl << "min : "
    << numeric_limits<long double >::min() << endl << "max : " << numeric_limits<long double >::max() 
    << endl << "epsilon : " << numeric_limits<long double >::epsilon() << endl;
}