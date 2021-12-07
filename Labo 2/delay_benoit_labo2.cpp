/*
Nom: Delay
Prenom: Benoit
Date: 22/09/2021
Cours: Prog1 Labo 2
Projet: Labo 2
*/


#include <iostream>
#include <string>

const int CURRENT_YEAR = 2021;

int main()
{
    const int CURRENT_YEAR = 2021;
    std::cout << "Indiquez votre prenom : ";
    std::string prenom;
    getline(std::cin,prenom);
    std::cout<< "Indiquez votre age ";
    int age;
    std::cin >> age;
    std::cout<<"Vous vous appellez "<< prenom
            << " vous avez " << age 
            << "ans et vous etes ne en " << CURRENT_YEAR - age << std::endl;

}