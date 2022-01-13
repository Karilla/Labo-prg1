/*******************************************************************************
Programme de test de la classe Uint
Cryptage et décryptage de fichiers avec la technique de C. Cocks (RSA)
*******************************************************************************/

/*
 * TODO implementer modpow
 * TODO continuer d'implementer le * entre 2 SUint
 * TODO implementer le -
 * TODO implementer le +
 * TODO implementer le /
 * TODO implementer le %
 */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <limits>
#include "SUint.h"
using namespace std;

int main()
{
    SUint u1(20);

    SUint u2 = u1 * 2;

    cout << u2 << endl;
}