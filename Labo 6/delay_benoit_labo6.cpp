/*
Nom: Delay
Prenom: Benoit
Date: 01/10/2021
Labo: Labo 6
But : Écrire un programme permettant à l’utilisateur de calculer la durée d’un trajet.
*/

#include <iostream>

using namespace std;

int main()
{
    const int HOUR_IN_DAY = 24;
    const int MINUTE_IN_HOUR = 60;
    const int ONE_HOUR = 1;

    //Recupere et convertit en minute l'heure de depart
    int start_hour, start_minute, start_total_minute;
    cout << "**Calcul de duree de trajet**" << endl;
    cout << "-----------------------------" << endl;
    cout << "Veuillez indiquez l'heure de depart" << endl;
    cin >> start_hour;
    cout << "Veuillez indiquez les minutes du depart" << endl;
    cin >> start_minute;

    //Convertit en minute
    start_total_minute = (start_hour * MINUTE_IN_HOUR) + start_minute;

    //Recupere et convertit en minute l'heure d'arrivee
    int finish_hour, finish_minute, finish_total_minute;
    cout << "Veuillez indiquez l'heure d'arrivee" << endl;
    cin >> finish_hour;
    cout << "Veuillez indiquez les minutes d'arrivee'" << endl;
    cin >> finish_minute;
    
    //Convertit en minute et ajoute 24h pour eviter de tomber dans le negatif
    finish_hour += HOUR_IN_DAY;
    finish_total_minute = (finish_hour * MINUTE_IN_HOUR) + finish_minute;

    //Recupere la difference en minute en enlevant une heure pour pas caser le modulo
    int hour_minute = (finish_total_minute - MINUTE_IN_HOUR) - start_total_minute;

    //On convertit en heure en rajoutant l'heure qu'on a precedemment enlever
    int hour = (((hour_minute/MINUTE_IN_HOUR ) + ONE_HOUR) % HOUR_IN_DAY);

    //On rajoute 60 minutes pour pas tomber dans le negatif
    finish_minute+= MINUTE_IN_HOUR;
    //On recupere la difference et on la soustrait
    int minute = (finish_minute - start_minute) % MINUTE_IN_HOUR;

    //Affiche la solution
    cout << "Duree : " << hour << " h : " << minute << "min" << endl;
}