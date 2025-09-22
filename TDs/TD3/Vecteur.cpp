#include "Vecteur.hpp"
#include <stdexcept>

// Constructeur par défaut - vecteur nul 3D
Vecteur::Vecteur() : x(0.0f), y(0.0f), z(0.0f), is3D(true) {}

// Constructeur 2D
Vecteur::Vecteur(float x, float y) : x(x), y(y), z(0.0f), is3D(false) {}

// Constructeur 3D
Vecteur::Vecteur(float x, float y, float z) : x(x), y(y), z(z), is3D(true) {}

// Constructeur à partir de deux points 2D
Vecteur::Vecteur(const Point2D& start, const Point2D& end)
    : x(end.getX() - start.getX()),
    y(end.getY() - start.getY()),
    z(0.0f),
    is3D(false) {
}

// Constructeur à partir de deux points 3D
Vecteur::Vecteur(const Point3D& start, const Point3D& end)
    : x(end.getX() - start.getX()),
    y(end.getY() - start.getY()),
    z(end.getZ() - start.getZ()),
    is3D(true) {
}

// Getters
float Vecteur::getX() const { return x; }
float Vecteur::getY() const { return y; }
float Vecteur::getZ() const { return z; }
bool Vecteur::getIs3D() const { return is3D; }

// Setters
void Vecteur::setX(float newX) { x = newX; }
void Vecteur::setY(float newY) { y = newY; }
void Vecteur::setZ(float newZ) {
    z = newZ;
    if (z != 0.0f) is3D = true;
}

// Somme de deux vecteurs
Vecteur Vecteur::operator+(const Vecteur& other) const {
    if (is3D && other.is3D) {
        return Vecteur(x + other.x, y + other.y, z + other.z);
    }
    else if (!is3D && !other.is3D) {
        return Vecteur(x + other.x, y + other.y);
    }
    else {
        // Si les dimensions sont différentes, on convertit en 3D
        float otherZ = other.is3D ? other.z : 0.0f;
        return Vecteur(x + other.x, y + other.y, z + otherZ);
    }
}

// Produit par un scalaire
Vecteur Vecteur::operator*(float scalar) const {
    if (is3D) {
        return Vecteur(x * scalar, y * scalar, z * scalar);
    }
    else {
        return Vecteur(x * scalar, y * scalar);
    }
}

// Égalité entre vecteurs
bool Vecteur::operator==(const Vecteur& other) const {
    const float epsilon = 1e-6f; // Tolérance pour les comparaisons de flottants

    if (is3D != other.is3D) {
        return false; // Dimensions différentes
    }

    if (is3D) {
        return (std::abs(x - other.x) < epsilon) &&
            (std::abs(y - other.y) < epsilon) &&
            (std::abs(z - other.z) < epsilon);
    }
    else {
        return (std::abs(x - other.x) < epsilon) &&
            (std::abs(y - other.y) < epsilon);
    }
}

// Norme du vecteur
float Vecteur::norme() const {
    if (is3D) {
        return std::sqrt(x * x + y * y + z * z);
    }
    else {
        return std::sqrt(x * x + y * y);
    }
}

// Vecteur normalisé
Vecteur Vecteur::normaliser() const {
    float n = norme();
    if (n < 1e-6f) { // Éviter la division par zéro
        return *this;
    }

    if (is3D) {
        return Vecteur(x / n, y / n, z / n);
    }
    else {
        return Vecteur(x / n, y / n);
    }
}

// Affichage du vecteur
void Vecteur::print() const {
    if (is3D) {
        std::cout << "Vecteur3D(" << x << ", " << y << ", " << z << ")";
    }
    else {
        std::cout << "Vecteur2D(" << x << ", " << y << ")";
    }
}

// Produit scalaire
float Vecteur::dot(const Vecteur& other) const {
    if (is3D && other.is3D) {
        return x * other.x + y * other.y + z * other.z;
    }
    else {
        // Pour les vecteurs 2D ou mixtes, on ignore la composante z
        return x * other.x + y * other.y;
    }
}

// Produit vectoriel (uniquement pour les vecteurs 3D)
Vecteur Vecteur::cross(const Vecteur& other) const {
    if (!is3D || !other.is3D) {
        throw std::runtime_error("Le produit vectoriel n'est défini que pour les vecteurs 3D");
    }

    return Vecteur(
        y * other.z - z * other.y,
        z * other.x - x * other.z,
        x * other.y - y * other.x
    );
}