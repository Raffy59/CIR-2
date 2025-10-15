#include "Fraction.hpp"
#include <numeric> // std::gcd

// Constructeur
Fraction::Fraction(int num, int den) : num(num), den(den) {
    if (den == 0) {
        std::cerr << "Erreur: dénominateur nul !" << std::endl;
        this->den = 1;
    }
    simplifier();
}

// Simplification de la fraction
void Fraction::simplifier() {
    int g = std::gcd(num, den);
    if (g != 0) {
        num /= g;
        den /= g;
    }
    if (den < 0) { // convention : dénominateur toujours positif
        num = -num;
        den = -den;
    }
}

// Affichage
void Fraction::print() const {
    std::cout << num << "/" << den << std::endl;
}

// Affectation
Fraction& Fraction::operator=(const Fraction& other) {
    if (this != &other) {
        this->num = other.num;
        this->den = other.den;
    }
    return *this;
}

// ------------------- Opérateurs arithmétiques -------------------
Fraction Fraction::operator+(const Fraction& other) const {
    return Fraction(num*other.den + den*other.num, den*other.den);
}

Fraction Fraction::operator-(const Fraction& other) const {
    return Fraction(num*other.den - den*other.num, den*other.den);
}

Fraction Fraction::operator*(const Fraction& other) const {
    return Fraction(num*other.num, den*other.den);
}

Fraction Fraction::operator/(const Fraction& other) const {
    return Fraction(num*other.den, den*other.num);
}

// ------------------- Comparaisons -------------------
bool Fraction::operator==(const Fraction& other) const {
    return num == other.num && den == other.den;
}

bool Fraction::operator<(const Fraction& other) const {
    return (num * other.den) < (other.num * den);
}

// ------------------- Opérateurs de flux -------------------
std::ostream& operator<<(std::ostream& os, const Fraction& f) {
    os << f.num << "/" << f.den;
    return os;
}

std::istream& operator>>(std::istream& is, Fraction& f) {
    char slash;
    is >> f.num >> slash >> f.den;
    if (f.den == 0) {
        std::cerr << "Erreur: dénominateur nul !" << std::endl;
        f.den = 1;
    }
    f.simplifier();
    return is;
}

