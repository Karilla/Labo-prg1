/*
*/
#include <iostream>

using namespace std;

void ex_3_28(void);

int main()
{
    
}

void ex_3_28(void)
{
    double moyenneHarmoniqueD = 0;
    int n = 10000000;

    for(int i = 1; i < n; i++ )
    {
        moyenneHarmoniqueD += 1.0/i;
    }

    cout << "Serie harmonique de type double de 1 a 10E7 = " << moyenneHarmoniqueD << endl;

    moyenneHarmoniqueD = 0;
    for(int i = n ; i > 0; i--)
    {
        moyenneHarmoniqueD += (1.0/i);
    }
    cout << "Serie harmonique de type double de 10E7 a 1 = " << moyenneHarmoniqueD << endl;

    float moyenneHarmoniqueF = 0;
    n = 10000000;

    for(int i = 1; i < n; i++ )
    {
        moyenneHarmoniqueF += 1.0f/i;
    }

    cout << "Serie harmonique de type float de 1 a 10E7 = " << moyenneHarmoniqueF << endl;

    moyenneHarmoniqueF = 0;
    for(int i = n ; i > 0; i--)
    {
        moyenneHarmoniqueF += (1.0f/i);
    }
    cout << "Serie harmonique de type float de 10E7 a 1 = " << moyenneHarmoniqueF << endl;
}