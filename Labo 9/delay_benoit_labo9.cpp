/*
Prenom: Benoit
Nom: Delay
Date: 08/10/2021
Projet: Labo 9
But: Écrire un programme permettant de convertir des températures données en degrés
Celsius vers des degrés Fahrenheit et vice-versa.
*/
#include <iostream>
#include <iomanip>

using namespace std;
int main()
{
    char choice;
    double temperatureToConvert;
    double converetedTemperature;

    //Recuperation du choix du sens de la conversion par l'utilisateur
    cout << "Programme de conversion fahrenheit<->Celsium" << endl;
    cout << "Indiquez le sens de conversion, c pour fahreheit a celsius et f de celsius a fahrenheit :";
    cin >> choice;

    //Mise en page de l'affichage
    cout << setprecision(4);

    //Si l'utilisateur veut convertir des fahrenheit
    if(choice == 'c')
    {
        //Recupere la temperature a convertir de l'utilisateur
        cout << "Indiquez en fahrenheit la temperature a convertir" << endl;
        cin >> temperatureToConvert;

        //Convertit la temperature
        converetedTemperature = (temperatureToConvert -32.0) * (5.0 / 9.0);

        //Affiche le resultat en fahrenheit
        cout << "Temperature = " << converetedTemperature << "C" << endl;
    }
    //Si l'utilisateur veut convertir des celsius
    else if (choice == 'f')
    {
        //Recupere la temperature a convertir de l'utilisateur
        cout << "Indiquez en celsius la temperature a convertir" << endl;
        cin >> temperatureToConvert;

        //Convertit la temperature
        converetedTemperature = (temperatureToConvert * (9.0 / 5.0)) + 32.0;

        //Affiche le resultat en celsius
        cout << "Temperature = " << converetedTemperature << "F" << endl;
    }
    //Si mauvaise entree de l'utilisateur
    else
    {
        //Indique a l'utilisateur qu'il a entre un mauvais caractere
        cout << "Wrong choice exit program..." << endl;
    }
    
}