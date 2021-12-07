/* 
Nom: Delay
Prenom: Benoit
Date : 24/09/2021
Cours: Labo3
Projet: Labo3
Description: Transformer des secondes en semaine, jour, heure, minute, seconde  
*/
#include <iostream>

using namespace std;

const int NUMBER_OF_SECOND_IN_MIN = 60;
const int NUMBER_OF_MINUTE_IN_HOUR = 60;
const int NUMBER_OF_HOUR_IN_DAY = 24;
const int NUMBER_OF_DAY_IN_WEEKS = 7;

int main()
{
    //Recupere le nombre de seconde a convertir
    int number_second_to_convert;
    cout << "Veuillez indiquez le nombre de seconde a convertir" << endl;
    cin >> number_second_to_convert;

    //Recupere le nombre de minute et le reste de seconde
    int number_minute = number_second_to_convert / NUMBER_OF_SECOND_IN_MIN;
    int seconds = number_second_to_convert % NUMBER_OF_SECOND_IN_MIN;

    //Recupere le nombre d'heure ainsi que le reste de minute
    int number_hour = number_minute / NUMBER_OF_MINUTE_IN_HOUR;
    int minutes = number_minute % NUMBER_OF_MINUTE_IN_HOUR;

    //Recupere le nombre de jour ainsi que le reste d'heure
    int number_days = number_hour / NUMBER_OF_HOUR_IN_DAY;
    int hours = number_hour & NUMBER_OF_HOUR_IN_DAY;

    //Recupere le nombre de semaine et le reste de jour
    int weeks = number_days / NUMBER_OF_DAY_IN_WEEKS;
    int days = number_days % NUMBER_OF_DAY_IN_WEEKS;

    //Affiche le resultat
    cout << number_second_to_convert << " s = " << weeks << " semaines, " 
    << days << " jours, " 
    << hours << " heures, " 
    << minutes << " minutes, " 
    << seconds << " secondes"<< endl; 

}