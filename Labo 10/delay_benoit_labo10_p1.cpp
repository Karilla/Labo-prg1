/*
Nom: Delay
Prenom: Benoit
Date: 12/10/2021
Labo: Labo 10
But: Ecrire un programme C++ qui, après avoir demandé à l'utilisateur de saisir un no de mois (1
pour janvier, 2 pour février, etc), affiche combien le mois choisi compte de jour.
*/
#include <iostream>

using namespace std;

int main()
{
    //Recupere l'entree de l'utilisateur
    int month;
    cout << "Veuillez saisir le mois a evaluer : ";
    cin >> month;

    //Effectue une operation logique pour afficher le nombre de jour d'un mois
    cout << ((month == 2) ? "Le jour a 28 ou 29 jour" : 
    ((month == 4 || month == 6 || month == 9 || month == 11)  
    ? "Le jour a 30 jour" : "Le mois a 31 jours")); 
}