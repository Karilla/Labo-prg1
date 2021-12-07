/*
Nom: Delay
Prenom: Benoit
Date: 22/10/2021
Projet: Labo15
But: Mettre en oeuvre la creation de fonction
*/
#include <iostream>
#include <cmath>

using namespace std;

int exp_mod(int base, int exposant, int modulo);
int pgdc_euclide(int number1, int number2);

int main()
{
    cout << "Pgdc de 354 et de 3456" <<endl;
    cout << pgdc_euclide(5 ,12) << endl;
}

//Entree: base, int, base de l'exponentiel
//        exposant, int, exposant
//        modulo, int, modulo de l'alogorythme
//Sortie: result, int, valeur de l'exponentiel
//But: Calcul l'exponentiel avec la base, l'exposant et le modulo donné 
int exp_mod(int base, int exposant, int modulo)
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
    //Retourne le resultat
    return result;
}

//Entree: number1, int, premier nombre du pgdc
//        number2, int, deuxieme nombre du pgdc
//Sortie: number1, int, valeur du pgdc
//But: Calcul le pgdc avec la methode d'euclide entre 2 nombres
int pgdc_euclide(int number1, int number2)  
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