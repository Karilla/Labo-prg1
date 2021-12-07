#include <iostream>
#include <iomanip>

using namespace std;

void ex3_19(void);
void ex3_20(void);

const double RULE_70 = 70.0;
const double DOUBLE = 2;
const double PERCENT = 100;

const int NB_WHITESPACE = 3;
const int START_NUMBER = 20;
const int NB_COLUMN = 3;
const int NB_ROW = 7;
const int NEXT_NUMBER = 1;
const int MODULO_THREE = 3;

int main()
{
    ex3_19();
    ex3_20();   
}   

//Entree: -
//Sortie: -
//But: Ecrire un programme qui calcul le nombre d'année poure doubler un capital x avec un taux y
void ex3_19(void)
{
    //Recupere le capital de depart et le taux d'interet
    int startCapital;
    double taux;
    cout << "Veuillez entrer votre capital de depart ainsi que le taux" << endl;
    cin >> startCapital >> taux;

    //Calcul le nombre d'annee avec la regle de 70
    int numberYear = int(RULE_70 / (taux));

    //Affiche le resultat en nombre d'année
    cout << "Nombre d'année necessaire sans boucle = " << numberYear << endl;

    //Reset le compteur et le capital de depart pour la partie avec boucle
    numberYear = 0;
    double actualCapital = startCapital;

    //Tant que le capital n'est pas doublé
    while(actualCapital  <= (DOUBLE * startCapital))
    {
        //Calcul du nouveau capital apres les taux
        actualCapital += (taux/PERCENT * actualCapital);
        
        //Une annee est passee (le temps file a une vitesse dit donc)
        numberYear++;
    }
    //Affiche le nombre d'annee trouvee avec une boucle
    cout << "Nombre d'année necessaire avec boucle = " << numberYear << endl;
}

//Entree:
//Sortie:
//But: Ecrire un programme qui compte de 20 a 0 avec une fois une boucle while et une boucle for
void ex3_20(void)
{
    //Insere la valeur de depart
    int currentNumber = START_NUMBER;
    cout << "Affichage avec boucle while";
    //Compteur jusqu'a 0
    while(currentNumber >= 0)
    {
        //Defini le nombre de caractere par ligne
        cout << setw(NB_WHITESPACE);
        
        //Tous les 3 chiffres insere un saut de ligne
        if((currentNumber + NEXT_NUMBER) % MODULO_THREE == 0)
        {
            cout<<endl;
        }
        //Affiche un espace entre chaque chiffre
        cout << currentNumber << " ";

        //Decremente le compteur
        currentNumber--;
    }

    //Remets a 20 le compteur
    currentNumber = START_NUMBER;
    cout<<endl;
    cout << "Affichage avec boule for"<< endl;

    //Pour chaque ligne
    for(int i = 0; i < NB_ROW; i++)
    {
        //Pour chaque colonne
        for(int j = 0; j < NB_COLUMN; j++)
        {
            //Indique le nombre de caractere
            cout << setw(NB_WHITESPACE);

            //Affiche le nombre avec un espace
            cout << currentNumber << " ";

            //Decrement le compteur
            currentNumber--;
        }

        //A chaque fin de ligne place un saut de ligne
        cout<<endl;
    }
}