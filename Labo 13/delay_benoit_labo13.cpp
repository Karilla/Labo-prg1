/*
Nom: Delay
Prenom: Benoit
Date: 19/10/2021
Projet: Labo 13
*/
#include <iostream>
#include <random>
#include <functional>
#include <time.h>
#include <cmath>

using namespace std;

//Signature des fonctions
void ex_3_32(void);
void ex_3_33(void);


int main()
{
    ex_3_32();
    ex_3_33();
}

//Entree:-
//Sortie:-
//But: Ecrire un programme qui trouve pi par approximation
void ex_3_32(void)
{
    //Cree les fonctions de generation de double et de int
    auto genCoord = std::bind(std::uniform_real_distribution<double>(0,1), std::mt19937(time(NULL))); // germe: 1234
    auto genNumberArrow = std::bind(std::uniform_int_distribution<int>(1,1000000), std::mt19937(time(NULL))); // un autre germe

    //Recupere un nombre aleatoire de fleche
    int numberArrow = genNumberArrow();
    int numberIn = 0;

    //Pour chaque fleche lancee
    for(int i = 0 ;i < numberArrow; i++)
    {
        //Recuperer les coordoonee d'impact des fleches
        double x = genCoord();
        double y = genCoord();

        //Calcule si oui ou non la fleche est dans le cercle
        double hypothenuse = hypot(x, y);

        //Si la fleche est bien dans le cercle
        if(not(hypothenuse > 1))
        {
            //L'ajoute au nombre de fleche qui ont touche leur cible
            numberIn++;
        }
    }
    
    //Calcul la surface du cercle (qui vaut pi car r = 1) en fonction du nombre de fleche qui ont touche le cerlce
    double circleSurface = ((2 * 2) * numberIn) / (double)numberArrow;

    //Affiche le resultat
    cout << "Pour " << numberArrow << " fleches lancee nous avons pi = " << circleSurface << endl;
}

//Entree:-
//Sortie:-
//But: Mettre en pratique le programme de monty hall a l'aide de simulation numerique
void ex_3_33(void)
{
    //Prepare les generateur de fonction aleatoire
    auto numberOfGeneration = std::bind(std::uniform_int_distribution<int>(1000,10000), std::mt19937(time(NULL)));
    auto gen_int_3 = std::bind(std::uniform_int_distribution<int>(1,3), std::mt19937(time(NULL)));

    int changeDoor = 0;
    int noChangeDoor = 0;

    //Recupere un nombre de partie aleatoire
    int nbOfGeneration = numberOfGeneration();

    //Pour chaque partie
    for(int i = 0; i < nbOfGeneration; i++)
    {
        //Choisi aleatoirement la porte gagnante
        int win_door = gen_int_3();

        //Le joueur choisi une porte au hasard
        int player_door = gen_int_3();

        //Si le joueur ne change pas de choix apres que le presentateur lui ouvre une fausse porte
        if (win_door == player_door)
        {
            //Incremente le compteur du non changement de porte
            noChangeDoor++;
        }
        //Si le joueur change de choix apres que le presentateur lui ouvre une fausse porte
        else
        {
            //Incremente le compteur du changement de porte
            changeDoor++;
        }
    }

    //Affiche les resultats
    cout <<"Si l'utilisateur change de porte il a " << ((double)changeDoor / nbOfGeneration) * 100.0 
    << "% alors que si il change pas il a que " << ((double)noChangeDoor / nbOfGeneration) * 100.0 <<
    "% de reussite" << endl;
}