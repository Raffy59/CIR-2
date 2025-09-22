#include "Point2D.hpp"

// Constructeur par défaut - valeurs aléatoires entre 0 et 100
Point2D::Point2D() {
    x = static_cast<float>(rand() % 101);
    y = static_cast<float>(rand() % 101);
}

// Constructeur avec coordonnées spécifiques
Point2D::Point2D(const float& newx, const float& newy) : x(newx), y(newy) {}

// Setters
void Point2D::setXY(const float& newx, const float& newy) {
    x = newx;
    y = newy;
}

void Point2D::setX(const float& newx) {
    x = newx;
}

void Point2D::setY(const float& newy) {
    y = newy;
}

// Getters
float Point2D::getX() const {
    return x;
}

float Point2D::getY() const {
    return y;
}

// Affichage des coordonnées
void Point2D::print() const {
    std::cout << "(" << x << ", " << y << ")";
}

// Calcul de la distance entre deux points
float Point2D::distanceTo(const Point2D& otherPoint) const {
    float dx = x - otherPoint.x;
    float dy = y - otherPoint.y;
    return std::sqrt(dx * dx + dy * dy);
}

