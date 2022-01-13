/*******************************************************************************
Programme de test de la classe Uint
Cryptage et décryptage de fichiers avec la technique de C. Cocks (RSA)
*******************************************************************************/

/*
 * TODO implementer modpow
 * TODO implementer le -
 * TODO implementer le %
 */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <limits>
#include "SUint.h"
using namespace std;

bool isPrime(Uint number);

Uint expMod(Uint base, Uint exposant, Uint modulo);

int main()
{
    SUint u1(-4);
    SUint u2(-9);

    cout << (u1 - (u1 / u2) * u2) << endl;

    SUint u3 = SUint::rand(20);

    cout << u3 << endl;
}

bool isPrime(Uint number)
{

}

Uint expMod(Uint base, Uint exposant, Uint modulo)
{

}