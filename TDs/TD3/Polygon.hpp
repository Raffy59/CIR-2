#ifndef POLYGON_HPP
#define POLYGON_HPP

#include "Point2D.hpp"
#include <vector>
#include <iostream>

class Polygon {
private:
    std::vector<Point2D> vertices; // Sommets du polygone

public:
    // Constructeurs
    Polygon(); // Polygone vide
    Polygon(const std::vector<Point2D>& points); // Polygone avec sommets

    // Méthodes d'ajout de points
    void addVertex(const Point2D& point);
    void addVertex(float x, float y);

    // Méthodes d'accès
    size_t getVertexCount() const;
    Point2D getVertex(size_t index) const;
    const std::vector<Point2D>& getVertices() const;

    // Calcul de l'aire avec la formule donnée
    float calculateArea() const;

    // Affichage
    void print() const;

    // Opérateur d'égalité ← AJOUTER CETTE LIGNE
    bool operator==(const Point2D& other) const;

    // Méthodes utilitaires
    bool isValid() const; // Vérifie si le polygone est valide (au moins 3 sommets)
    void closePolygon(); // Ferme le polygone en ajoutant le premier point à la fin si nécessaire
};

#endif