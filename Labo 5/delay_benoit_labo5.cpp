/*
Nom: Delay
Prenom: Benoit
Date: 28/09/2021
Labo: Labo 5
Projet: Calculer l'heure en fonction d'un angle donné
*/
#include <iostream>

using namespace std;

int main()
{
    const int START_HOUR = 15; 
    const int MINUTE_PER_DEGREE = 2;
    const int NUMBER_MINUTE_IN_HOUR = 60;
    const int START_HOUR_IN_MINUTE = NUMBER_MINUTE_IN_HOUR * START_HOUR;
    const int MAX_CADRAN_HOUR = 12;
    int angle;
    int minute;
    int hour;

    //Recuperation de l'angle saisi par l'utilisateur
    cout << "Veuillez entrer un angle :" << endl;
    cin >> angle;
    angle = angle % 360;

    //Convertit l'angle en minute
    int minute_number = angle * MINUTE_PER_DEGREE;

    //On retire une heure pour pas casser le modulo 12
    int hour_minute = (START_HOUR_IN_MINUTE- NUMBER_MINUTE_IN_HOUR) - minute_number;

    //Fin du calcul du nombre d'heure, on rajoute l'heure qu'on a enlever avant
    int hours = (hour_minute / NUMBER_MINUTE_IN_HOUR) % MAX_CADRAN_HOUR 
     + (NUMBER_MINUTE_IN_HOUR /NUMBER_MINUTE_IN_HOUR);

    //Calcul des minutes
    minute = (NUMBER_MINUTE_IN_HOUR - ((minute_number)%60))%60;

    cout << "Pour un angle de " << angle << " nous avons " << hours << " heures et " << minute << " minute" << endl;
}
