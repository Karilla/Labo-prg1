/*
Nom: Delay
Prenom: Benoit
Date: 13/10/2021
Projet: Labo 11
*/
#include <iostream>
#include <iomanip>

using namespace std;

//Signature des fonctions pour les differents ex
void ex_3_11(void);
void ex_3_12(void);

//Constante pour les multiples
const int MULTIPLE_3 = 3;
const int MULTIPLE_5 = 5;
const int PPMC_3_5 = MULTIPLE_3 * MULTIPLE_5;

//Constante pour calcul de la moyenne
const double NOTE_MAX = 6;
const double NOTE_MIN = 1;
const double NUMBER_OF_NOTE = 4;

//Constante pour les bornes des mentions
const double EXCELLENT = 5.5;
const double VERY_GOOD = 5;
const double GOOD = 4.5;
const double MEDIUM = 4;

int main()
{
    ex_3_11();
    ex_3_12();
}

//Entree: -
//Sortie: -
//But: Ecrire un programme qui calcule une moyenne et affiche une mention
void ex_3_12(void)
{
    //Recupere et test la valeur entree par l'utilisateur
    double note1, note2, note3, note4;
    do
    {
        cout << "Indiquez vos 4 notes ! Les notes sont comprises entre 1 et 6" << endl;
        cin >> note1 >> note2 >> note3 >> note4;
    } while ((note1 > NOTE_MAX || note1 < NOTE_MIN )
            ||(note2 > NOTE_MAX || note2 < NOTE_MIN )
            ||(note3 > NOTE_MAX || note3 < NOTE_MIN )
            ||(note4 > NOTE_MAX || note4 < NOTE_MIN ));

    //Calcul la moyenne des 4 notes
    double moyenne = (note1 + note2 + note3 + note4) / NUMBER_OF_NOTE;

    //Si la moyenne est superieur a 5.5
    if(moyenne > EXCELLENT)
    {
        //Affiche le resultat avec la mention excellente
         cout << "Moyenne = " << fixed << setprecision(1) << moyenne << " - Excellent" << endl;
    }
    //Si la moyenne est superieur a 5
    else if(moyenne > VERY_GOOD)
    {
        //Affiche le resultat avec la mention tres bien
         cout << "Moyenne = " << fixed << setprecision(1) << moyenne << " - Tres bien" << endl;
    }
    //Si la moyenne est superieur a 4.5
    else if(moyenne > GOOD)
    {
        //Affiche le resultat avec la mention bien
         cout << "Moyenne = " << fixed << setprecision(1) << moyenne << " - Bien" << endl;
    }
    //Si la moyenne est superieur ou egale a 4
    else if(moyenne >= MEDIUM)
    {
        //Affiche le resultat avec la mention moyen
         cout << "Moyenne = " << fixed << setprecision(1) << moyenne << " - Moyen" << endl;
    }
    //Si la moyenne est inferieur a 4
    else if(moyenne < MEDIUM)
    {
        //Affiche le resultat avec la mention insuffisant
         cout << "Moyenne = " << fixed << setprecision(1) << moyenne << " - Insuffisant" << endl;
    }
}

//Entree: -
//Sortie: -
//But: Ecrire un programme qui determine si un nombre est multiple de 3, 5 ou les 2
void ex_3_11(void)
{
    //Recupere la valeur entrée par l'utilisateur
    int choice;
    cout << "Indiquez un nombre a tester : ";
    cin >> choice;

    //Si le modulo avec 15 egale 0
    if(!(choice % PPMC_3_5))
    {
        //Affiche que c'est un multiple de 3 et de 5
        cout << "Multiple de 3 et de 5" << endl;
    }
    //Si le modulo avec 3 egale 0
    else if(!(choice % MULTIPLE_3))
    {
        //Affiche que c'est un multiple de 3
        cout << "Multiple de 3" << endl; 
    }
    //Si le modulo avec 5 egale 0
    else if (!(choice % MULTIPLE_5))
    {
        //Affiche que c'est un multiple de 5
        cout << "Multiple de 5" << endl; 
    }
    //Si aucun des modulo n'egale 0
    else
    {
        //Affiche que ce n'est pas un multiple
        cout << "N'est pas un un multiple de 5 ni de 3" << endl; 
    }
}