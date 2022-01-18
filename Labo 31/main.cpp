/*******************************************************************************
Programme de test de la classe Uint
Cryptage et décryptage de fichiers avec la technique de C. Cocks (RSA)
*******************************************************************************/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <limits>
#include <iomanip>
#include <chrono>
#include "Sint.h"

using namespace std;

bool isPrime(Uint nb);

Uint expMod(Uint base, Uint exposant, Uint modulo);

Uint extendedEuclide(Uint a, Uint b, Uint &d);

int main()
{
    cout << "--------WELCOME IN RSA KEY GENERATOR V1--------" << endl;
    cout << "Pls insert the number of digit of your key" << endl;
    int nbDigit;
    cin >> nbDigit;

    Uint p;
    Uint q;
    //Recupere p et q et s'assure que les valeurs sont correctes
    do
    {
        p = Uint::rand(nbDigit);
        q = Uint::rand(nbDigit);

        if(p == q)
        {
            cerr << "p = " << p << " Q = " << q << endl;
        }
    }while ((p == q) or
            (!isPrime(p)) or
            (!isPrime(q)));

    cout << "60%" << endl;
    Uint phi = (p - 1) * (q - 1);
    cout << "66%" << endl;

    Uint publicKey;
    Uint reste;
    do
    {
        publicKey = Uint::rand(nbDigit);
    } while (!(publicKey < phi) or
             (extendedEuclide(publicKey, phi,reste) != 1));
    cout << "80%" << endl;
    Uint privateKey;
    Uint keysize = p * q;
    cout << "90%" << endl;
    cout << "phi = " << phi <<endl;
    cout << "public key = " << publicKey << endl;
    extendedEuclide(phi,publicKey,privateKey);
    cout << "100%" << endl;
    cout << "publicKey = " << publicKey << " " << keysize << endl;
    cout << "privateKey = " << privateKey << " " << keysize << endl;

}

bool isPrime(Uint nb)
{
    Uint two(2);
    if(nb < two){return false;}
    if(nb == two){return true;}

    for(int i = 0; i < 10; i++)
    {
        Uint a = (Uint::rand(nb.getSize()) % nb) + 1;
        Uint exp = nb - 1;

        if(expMod(a, exp, nb) != 1){
            return false;
        }
        Uint q(1);
        while(exp % 2 == 0 and q == 1)
        {
            exp /= 2;
            q = expMod(a,exp,nb);
            if(q != 1 and q != (nb - 1)){
                return false;
            }

        }

    }
    return true;
}

Uint expMod(Uint base, Uint exposant, Uint modulo)
{
    Uint result = 1;
    while (exposant > 0)
    {
        if(exposant % 2 == 0)
        {
            base = (base * base) % modulo;
            exposant /= 2;
        }
        else
        {
            result = (result * base) % modulo;
            --exposant;
        }
    }
    return result;
}

Uint extendedEuclide(Uint a, Uint b, Uint &d)
{
    Sint pgdc = a;
    Sint rPrime = b;
    Sint dTemp = 0;
    Sint dPrime = 1;
    Sint tmp = 0;
    Sint tmpD, tmpR;
    while(rPrime != 0)
    {
        tmp = pgdc / rPrime;
        tmpR = pgdc;
        tmpD = dTemp;
        pgdc = rPrime;
        dTemp = dPrime;
        rPrime = tmpR - tmp * rPrime;
        dPrime =  tmpD - tmp * dPrime;
    }
    if(dTemp < 0)
    {
        dTemp += a;
    }
    d = (Uint)dTemp;
    return (Uint)pgdc;
}