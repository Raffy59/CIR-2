#ifndef FRACTION_HPP
#define FRACTION_HPP

#include <iostream>
#include <compare>  // pour l’opérateur spaceship (C++20)

class Fraction {
private:
    int num; // numérateur
    int den; // dénominateur

    void simplifier(); // pour réduire la fraction

public:
    // Constructeurs
    Fraction(int num=0, int den=1);

    // Affichage
    void print() const;

    // Getters
    int getNum() const { return num; }
    int getDen() const { return den; }

    // --------- Opérateurs ---------
    // Affectation
    Fraction& operator=(const Fraction& other);

    // Arithmétiques
    Fraction operator+(const Fraction& other) const;
    Fraction operator-(const Fraction& other) const;
    Fraction operator*(const Fraction& other) const;
    Fraction operator/(const Fraction& other) const;

    // Comparaison classique
    bool operator==(const Fraction& other) const;
    bool operator<(const Fraction& other) const;

    // Flux
    friend std::ostream& operator<<(std::ostream& os, const Fraction& f);
    friend std::istream& operator>>(std::istream& is, Fraction& f);
};

#endif

