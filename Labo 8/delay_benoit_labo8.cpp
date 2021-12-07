/*
Nom: Delay
Prenom: Benoit
Date: 04/10/2021
Labo: Labo 8
But: Calculer le volume d'une boille de lait
*/
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    const double PI = atan(1)*4;

    double r1, r2;
    double h1, h2, h3;

    //Recuperation des données de l'utilisateur
    cout << "Entrer les valeurs dans l'ordre suivant : r1, r2, h1, h2, h3" << endl;
    cin >> r1 >> r2 >> h1 >> h2 >> h3;

    //Calcul du grand cylindre
    double vCylindre1 = pow(r1,2) * PI * h1;

    //Calcul du petit cylindre
    double vCylindre2 = pow(r2,2) * PI * h2;

    //Calcule du cone tronque
    double vTruncCone = h3 * (PI/3) * (pow(r1,2) + pow(r2,2) + (r1 * r2));

    //Calcule du volume totale
    double vBoille = vCylindre1 + vCylindre2 + vTruncCone;
    
    //Affichage du volume de la boille
    cout << "Volume totale d'une boille a lait : " << vBoille << endl;
}