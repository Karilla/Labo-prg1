/*
Nom: Delay
Prenom: Benoit
Date: 04/10/2021
Labo: Labo7
But: Écrire un programme permettant à l’utilisateur d’introduire deux longueurs (sous la
     forme de nombres entiers exprimés en kilomètres, mètres, centimètres et milimètres),
     de les additionner et d’afficher le résultat.
*/
#include <iostream>

using namespace std;

int main()
{
    const int NUMBER_MILIMITER_IN_CENTIMETER = 10;
    const int NUMBER_CENTIMETER_IN_METRE = 100;
    const int NUMBER_METRE_IN_KILOMETER = 1000;

    int firstKilometer, firstMetre, firstCentimeter, firstMilimeter;
    int secondKilometer, secondMetre, secondCentimeter, secondMilimeter;
    int sumKilometer, sumMetre, sumCentimeter, sumMilimeter;
    int carry;

    //Recuperation de la premiere distance
    cout << "Entrer la distance initiale en km m cm mm :" << endl;
    cin >> firstKilometer >> firstMetre >> firstCentimeter >> firstMilimeter;

    //Recuperation de la seconde distance
    cout << "Entrer la distance finale en km m cm mm :" << endl;
    cin >> secondKilometer >> secondMetre >> secondCentimeter >> secondMilimeter;

    //Addition des milimetres
    sumMilimeter = (firstMilimeter + secondMilimeter) % NUMBER_MILIMITER_IN_CENTIMETER;
    carry = (firstMilimeter + secondMilimeter) / NUMBER_MILIMITER_IN_CENTIMETER;

    //Addition des centimetres
    sumCentimeter = (firstCentimeter + secondMilimeter + carry) % NUMBER_CENTIMETER_IN_METRE;
    carry = (firstCentimeter + secondCentimeter + carry) / NUMBER_CENTIMETER_IN_METRE;

    //Addition des metres
    sumMetre = (firstMetre + secondMetre + carry) % NUMBER_METRE_IN_KILOMETER;
    carry = (firstMetre + secondMetre + carry) / NUMBER_METRE_IN_KILOMETER;

    //Addition des kilometres
    sumKilometer = (firstKilometer + secondKilometer + carry) % NUMBER_METRE_IN_KILOMETER;

    //Affichage du resultat
    cout << sumKilometer << "km "
        << sumMetre << "m "
        << sumCentimeter << "cm "
        << sumMilimeter << "mm " << endl;
}