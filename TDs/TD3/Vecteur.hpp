#ifndef VECTEUR_HPP
#define VECTEUR_HPP

#include "Point2D.hpp"
#include "Point3D.hpp"
#include <iostream>
#include <cmath>

class Vecteur {
private:
    float x, y, z;
    bool is3D; // Pour distinguer les vecteurs 2D et 3D

public:
    // Constructeurs
    Vecteur(); // Vecteur nul 3D
    Vecteur(float x, float y); // Vecteur 2D
    Vecteur(float x, float y, float z); // Vecteur 3D

    // Constructeurs à partir de points
    Vecteur(const Point2D& start, const Point2D& end); // Vecteur 2D entre deux points
    Vecteur(const Point3D& start, const Point3D& end); // Vecteur 3D entre deux points

    // Getters
    float getX() const;
    float getY() const;
    float getZ() const;
    bool getIs3D() const;

    // Setters
    void setX(float newX);
    void setY(float newY);
    void setZ(float newZ);

    // Opérations vectorielles
    Vecteur operator+(const Vecteur& other) const; // Somme de deux vecteurs
    Vecteur operator*(float scalar) const; // Produit par un scalaire
    bool operator==(const Vecteur& other) const; // Égalité entre vecteurs

    // Méthodes utilitaires
    float norme() const; // Norme du vecteur
    Vecteur normaliser() const; // Vecteur normalisé
    void print() const; // Affichage du vecteur

    // Produit scalaire
    float dot(const Vecteur& other) const;

    // Produit vectoriel (uniquement pour les vecteurs 3D)
    Vecteur cross(const Vecteur& other) const;
};

#endif