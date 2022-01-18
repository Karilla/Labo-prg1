//
// Created by bdela on 13/01/2022.
//

#ifndef LABO_31_SUINT_H
#define LABO_31_SUINT_H


#include <iostream>
#include <cctype>
#include "Uint.h"
class Sint {

    /**
     * Classe amie
     */
    friend class Uint;

    /**
     * @brief Operateur d'egalité entre 2 SInt
     * @param lhs Sint de droite
     * @param rhs Sint de gauche
     * @return resultat de la comparaison
     */
    friend bool operator==(const Sint &lhs, const Sint &rhs);

    /**
     * @brief Operateur de difference entre 2 Sint
     * @param lhs Sint de droite
     * @param rhs Sint de gauche
     * @return resultat de la comparaison
     */
    friend bool operator!=(const Sint &lhs, const Sint &rhs);

    /**
     * @brief Operateur plus petti ou egal
     * @param lhs Sint de gauche
     * @param rhs Sint de droite
     * @return resultat de l'operation
     */
    friend bool operator<=(const Sint &lhs, const Sint &rhs);

    /**
     * @brief Operateur plus grand ou egal
     * @param lhs Sint de gauche
     * @param rhs Sint de droites
     * @return Resultat de l'operation
     */
    friend bool operator>=(const Sint &lhs, const Sint &rhs);

    /**
     * @brief Operateur plus petit que
     * @param lhs Sint de gauche
     * @param rhs Sint de droite
     * @return resultat de l'operation
     */
    friend bool operator<(const Sint &lhs, const Sint &rhs);

    /**
     * @brief Operateur plus grand que
     * @param lhs Sint de gauche
     * @param rhs Sint de droite
     * @return Resultat de la comparaison
     */
    friend bool operator>(const Sint &lhs, const Sint &rhs);

    /**
     * @brief Operateur d'affichage
     * @param lhs flux de sortie
     * @param rhs Uint a afficher
     * @return flux de sortie modifié
     */
    friend std::ostream &operator<<(std::ostream &lhs, const Sint &rhs);

    /**
     * @brief Operateur de multiplication entre 2 Sint
     * @param lhs Sint de gauche
     * @param rhs Sint de droite
     * @return Resultat de l'operation
     */
    friend Sint operator*(Sint lhs, const Sint &rhs);

    /**
     * @brief Operation de multiplication entre un Sint et un int
     * @param lhs Sint de gauche
     * @param scalaire int de droite
     * @return Resultat de l'operation
     */
    friend Sint operator*(Sint lhs, const int scalaire);

    /**
     * @brief Operateur de division entre 2 SInt
     * @param lhs Sint de gauche
     * @param rhs Sint de droite
     * @return Resultat de l'operation
     */
    friend Sint operator/(Sint lhs, const Sint &rhs);

    /**
     * @brief Operateur de modulo entre 2 Sint
     * @param lhs Sint de gauche
     * @param rhs Sint de droite
     * @return Resultat de l'operation
     */
    friend Sint operator%(Sint lhs, const Sint &rhs);

    /**
     * @brief Operateur d'addition entre 2 Sint
     * @param lhs Sint de gauche
     * @param rhs Sint de droite
     * @return Resultat de l'operation
     */
    friend Sint operator+(Sint lhs, const Sint &rhs);

    /**
     * @brief Operateur de soustraction entre 2 Sint
     * @param lhs Sint de gauche
     * @param rhs Sint de droite
     * @return Resultat de l'operastion
     */
    friend Sint operator-(Sint lhs, const Sint &rhs);

public:

    /**
     * Constructeur vide par defeaut
     */
    Sint() = default;

    /**
     * @brief Constructeur avec un string
     * @param nb string a parser
     */
    Sint(std::string nb);

    /**
     * @brief Constructeur avec un int
     * @param nb int a parser
     */
    Sint(int nb);

    /**
     * Constructeur avec un Uint
     * @param nb Uint a parser
     */
    Sint(Uint nb) {sign = false; number = nb;}

    /**
     * @brief Operarteur de cast Sint -> Uint
     * @return Uint de retour
     */
    explicit operator Uint() const { return number;}

    /**
     * @brief Operateur de multiplication avec un autre Sint
     * @param rhs Sint de gauche
     * @return Resultat de l0operation
     */
    Sint &operator*=(const Sint &rhs);

    /**
     * @brief Operation de divisione avec un autre Sint
     * @param rhs Sint de droite
     * @return Resultat de l'operation
     */
    Sint &operator/=(const Sint &rhs);

    /**
     * @brief Operateur de modulo avec un autre Sint
     * @param rhs Sint de droite
     * @return Resultat de l'operation
     */
    Sint &operator%=(const Sint &rhs);

    /**
     * @brief Operation de l'addition avec una utre SInt
     * @param rhs Sint de droite
     * @return Resultat de l'operation
     */
    Sint &operator+=(const Sint &rhs);

    /**
     * @brief Operateur de soustraction avec un autre Sint
     * @param rhs Sint de droite
     * @return Resultat de l'operation
     */
    Sint &operator-=(const Sint &rhs);

    /**
     * @brief Methode qui genere un nombre de n digit
     * @param nbDigits nomre de digit a generer
     * @return Sint genrer
     */
    static Sint rand(int nbDigits);

    /**
     * @brief Methode de comparaisonm de 2 Sint
     * @param u1 Sint 1
     * @param u2 Sint 2
     * @return retourne -1 si plus grand 0 si egale 1 si plus grand
     */
    static int comp(const Sint &u1, const Sint &u2);

    /**
     * @brief Methode qui gere pour qu'il n'y ait pas de zero negatif
     */
    void handleZero();

private:
    /**
     *  Uint qui gere le nombre
     */
    Uint number;

    /**
     * Bit de signe
     */
    bool sign;
};


#endif //LABO_31_SUINT_H
