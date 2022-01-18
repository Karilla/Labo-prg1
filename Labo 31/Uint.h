//
// Created by bdela on 14/12/2021.
//

#ifndef LABO_31_UINT_H
#define LABO_31_UINT_H

#include <cstdint>
#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <limits>
#include <random>
#include <functional>

class Uint {

    /**
     * Declare la classe amie Sint
     */
    friend class Sint;

    /**
     * @brief Compare si lhs plus petite que rhs
     * @param lhs Uint de gauche
     * @param rhs Uint de droite
     * @return retourne la valeur de la comparaison
     */
    friend bool operator<(const Uint &lhs, const Uint &rhs);

    /**
     * @brief Compare si lhs egale rhs
     * @param lhs Uint de gauche
     * @param rhs Uint de droite
     * @return valeur de la comparaison
     */
    friend bool operator==(const Uint &lhs, const Uint &rhs);

    /**
     * @brief Compare si les 2 membres ne sont pas egale
     * @param lhs Uint de gauche
     * @param rhs Uint de droite
     * @return valeur de comparaison
     */
    friend bool operator!=(const Uint &lhs, const Uint &rhs);

    /**
     * @brief Compare si lhs est plus grand que rhs
     * @param lhs Uint de gauche
     * @param rhs Uint de droite
     * @return valeur de la comparaison
     */
    friend bool operator>(const Uint &lhs, const Uint &rhs);

    /**
     * @brief Compare si lhs est plus grande ou egale que rhs
     * @param lhs Uint de gauche
     * @param rhs Uint de droite
     * @return valeur de la comparaison
     */
    friend bool operator>=(const Uint &lhs, const Uint &rhs);

    /**
     * @brief Comppare si lhs est plus petit ou egale que rhs
     * @param lhs Uint de gauche
     * @param rhs Uint de droite
     * @return valeur de la comparaison
     */
    friend bool operator<=(const Uint &lhs, const Uint &rhs);

    /**
     * @brief operateur d'addition simple entre 2 Uint
     * @param lhs Uint de gauche
     * @param rhs Uint de droite
     * @return Uint du resultat de l'operation
     */
    friend Uint operator+(Uint lhs, const Uint &rhs);

    /**
     * @brief operateur de soustraction simple entre 2 Uint
     * @param lhs Uint de gauche
     * @param rhs Uint de droite
     * @return Uint du resultat de l'operation
     */
    friend Uint operator-(Uint lhs, const Uint &rhs);

    /**
     * @brief Operateur simple de multiplication entre 2 uint
     * @param lhs Uint de gauche
     * @param rhs Uint de droite
     * @return resultat de l'operation
     */
    friend Uint operator*(Uint lhs, const Uint &rhs);

    /**
     * @brief Operateur simple de multiplication
     * entre un Uint et un int
     * @param lhs Uint de gauche
     * @param scalaire int de droite
     * @return Uint du resultat de l'operation
     */
    friend Uint operator*(Uint lhs, const int scalaire);

    /**
     * @brief Operateur d'affichage de l'uint
     * @param lhs Flux de gauche de sortie
     * @param rhs Uint de droite a afficher
     * @return flux de sortie modifié
     */
    friend std::ostream &operator<<(std::ostream &lhs, const Uint &rhs);

    /**
     * @brief Pour lire depuis un flux d'entree un Uint
     * @param lhs Flux d'entrée
     * @param rhs Uint lu
     * @return flux d'entrée modifié
     */
    friend std::istream &operator>>(std::istream &lhs, Uint &rhs);

public:
    /**
     * @brief Constructeur qui prend en parametre un uint64_t
     * @param number nombre pour initialiser l'Uint
     */
    Uint(uint64_t number);

    /**
     * @brief Constructeur qui prend en parametre un string
     * @param number string qui sera parsé en Uint
     */
    Uint(std::string number);

    /**
     * @brief Constructeur vide par defaut
     */
    Uint() = default;

    /**
     * @brief Operateur de division simple entre un int et un uint
     * @param rhs Int de droite
     * @return Uint du resultat de l'operation
     */
    Uint operator/(int rhs) const;

    /**
     * @brief Operateur de division entre 2 Uint
     * @param rhs Uint de droite
     * @return Uint du resultat de l'operation
     */
    Uint operator/(const Uint &rhs) const;

    /**
     * @brief Operateur modulo entre un uint32_t et un Uint
     * @param rhs uint32_t de droite
     * @return Uint de resultat de l'operation
     */
    Uint operator%(uint32_t rhs) const;

    /**
     * @brief Operateur de modulo entre 2 Uint
     * @param rhs Uint de droite
     * @return Uint de resultat de l'operation
     */
    Uint operator%(const Uint &rhs) const;

    /**
     * @brief Post incremente
     * @return Uint de retour
     */
    Uint &operator++();

    /**
     * @brief Operateur de cast en uint64_t
     * @return uint64_t de retour
     */
    explicit operator uint64_t();

    /**
     * @brief Pre incremente
     * @return Uint de retour
     */
    Uint operator++(int);

    /**
     * @brief Post decremente
     * @return Uint de retour
     */
    Uint &operator--();

    /**
     * Pre Decremente
     * @return Uint de retour
     */
    Uint operator--(int);

    /**
     * @brief Operateur d'addition avec un autre Uint
     * @param number Uint de droite
     * @return Uint de resultat
     */
    Uint &operator+=(const Uint &number);

    /**
     * @brief Operateur de soustraction avec un autre Uint
     * @param number Uint de droite
     * @return Uint de resultat
     */
    Uint &operator-=(const Uint &number);

    /**
     * @brief Operateur de multiplication avec un autre Uint
     * @param rhs Uint de droite
     * @return Uint de resultat
     */
    Uint &operator*=(const Uint &rhs);

    /**
     * @brief Operateur d'affectation depuis un int
     * @param rhs int a affecter
     * @return Uint affecté
     */
    Uint& operator=(const int rhs);

    /**
     * @brief Operateur d'affecation avec un string
     * @param rhs string a affecté
     * @return Uint affecté
     */
    Uint& operator=(const std::string rhs);

    /**
     * @brief Operateur de divisiom avec un autre int
     * @param rhs int de droite
     * @return Uint de resultat
     */
    Uint& operator/=(int rhs);

    /**
     * @brief Operateur de division avec un autre Uint
     * @param rhs Uint de droite
     * @return Uint de resultat
     */
    Uint& operator/=(const Uint &rhs);

    /**
     * @brief Operateur de modulo avec un autre Uint
     * @param rhs Uint de droite
     * @return Uint de resultat
     */
    Uint& operator%=(const Uint &rhs);

    /**
     * @brief Operateur de divisiona avec un uint32_t
     * @param rhs uint32_t de droite
     * @return Uint de resultat
     */
    Uint &operator%=(uint32_t rhs);

    /**
     * @brief retourne le nombre de digit du Uint
     * @return nombre de digit du Uint
     */
    size_t getSize();

    /**
     * @brief Compare 2 uint entre eux
     * @param u1 Uint 1
     * @param u2 Uint 2
     * @return 1 si plus grand 0 si egale - 1 si plus petit
     */
    static int comp(Uint u1, Uint u2);

    /**
     * @brief Genere un Uint de taille pasés en parametre
     * @param nbDigits taille du Uint a generer
     * @return Uint generer
     */
    static Uint rand(int nbDigits);


private:

    /**
     *  Vecteur qui stocke les digit
     */
    std::vector<uint64_t> vectorNumber;

    /**
     * @brief Fonction qui retourne le quotient et renvoie le reste de la division
     * @param dividende Uint a divisier
     * @param divisieur Uint diviseur
     * @param reste Uint qui va stocker le reste
     * @return uint quotient de la division
     */
    Uint divRem(const Uint &dividende, const Uint &divisieur, Uint& reste);

    /**
     * @brief Fonction qui va supprimer les 0 inutile
     */
    void refactor();

};

#endif //LABO_29_UINT_H
