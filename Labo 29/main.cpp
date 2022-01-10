#include "Uint.h"
#include <iostream>


using namespace std;

Uint gen_random(int nb);

bool prime(Uint nb);

Uint expMod(Uint base, Uint exposant, Uint modulo);

int main()
{

    Uint test(7919);
    if(prime(test))
    {
        cout << "C'est prime !" << endl;
    }
    else
    {
        cout << "C'est pas prime :(" << endl;
    }

    /*
    cout << u3;
    string nombre;
    cout << "Introduire un nombre entier: ";
    cin >> nombre;
    size_t nb = stoul(nombre);
    Uint n;           // Vérification constructeur vide
    n = Uint(nombre); // Vérification constructeur par string

    cout << "Nombre lu " << n << endl; // Vérification opérateur <<
    Uint factorielle(1); // Vérification constructeur par entier (explicite)
    cout << factorielle << endl;

    for (size_t i = 2; i <= nb; ++i)
    {
        factorielle *= i; // Vérification *= size_t
        cout << i << "! = " << factorielle << endl;
    }

    factorielle = 1; // Vérification constructeur par entier implicite
    for (Uint i = 2; i <= n; ++i) // Vérification <= et ++
    {
        factorielle *= i; // Vérification *= Uint
        cout << i << "! = " << factorielle << endl;
    }

    Uint fibo_m2(0), fibo_m1(1), fibonacci;
    for (Uint i = 2; i <= n; ++i)
    {
        fibonacci = fibo_m2 + fibo_m1; // Vérification Uint + Uint
        cout << "fibonacci(" << i << ") = " << fibonacci << endl;
        fibo_m2 = fibo_m1;
        fibo_m1 = fibonacci;
    }
    // Vérification -, > et -=
    for (Uint i = (n - 2); i > 0; i -= 1)
    {
        cout << "fibonacci(" << i << ") = " << fibo_m2 << endl;
        fibonacci = fibo_m1;
        fibo_m1 = fibo_m2;
        fibo_m2 = fibonacci - fibo_m2; // Vérification -
    }
    for (Uint i = n; i > 0; i -= 1)
    {
        cout << i << "! = " << factorielle << endl;
        factorielle = factorielle / i; // Vérification Uint/Uint
    }

    /*
    Uint p;
    do
    {
        p = gen_random(nb); // Vérification gen_random
        cout << p << endl;
    } while (!prime(p));  // Vérification exponentiation modulaire, prime
     */
}

Uint gen_random(int nb)
{
    Uint temp;
    temp = Uint::rand(nb);
    return temp;
}

bool prime(Uint nb)
{
    Uint two(2);
    if(nb < two){return false;}
    if(nb == two){return true;}

    for(int i = 0; i < 10; i++)
    {
        Uint a;
        do {
            a = Uint::rand(nb.getSize());
            cout << a << endl;
        } while (a >= nb);

        if(expMod(a, nb - 1, nb) != 1){return false;}
        Uint q(1);
        Uint u = (nb - 1);

        while(u % 2 == 0 and q == 1)
        {
            u /= 2;
            q = expMod(a,u,nb);
            if(q != 1 and q != (nb - 1)){return false;}

        }

    }
    return true;
}

Uint expMod(Uint base, Uint exposant, Uint modulo)
{
    Uint result(1);
    while (exposant > Uint("0"))
    {
        if(exposant % 2 == 0)
        {
            base = (base * base) % modulo;
            exposant /= 2;
        }
        else
        {
            result = (result * base) % modulo;
            exposant -= 1;
        }
    }
    return result;
}
