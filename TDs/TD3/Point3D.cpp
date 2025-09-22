#include "Point3D.hpp"

// Constructeur par défaut
Point3D::Point3D() : Point2D() {
    z = static_cast<float>(rand() % 101);
}

// Constructeur avec coordonnées spécifiques
Point3D::Point3D(const float& newx, const float& newy, const float& newz)
    : Point2D(newx, newy), z(newz) {
}

// Setters
void Point3D::setXYZ(const float& newx, const float& newy, const float& newz) {
    setXY(newx, newy);
    z = newz;
}

void Point3D::setZ(const float& newz) {
    z = newz;
}

// Getter
float Point3D::getZ() const {
    return z;
}

// Affichage des coordonnées 3D
void Point3D::print() const {
    std::cout << "(" << getX() << ", " << getY() << ", " << z << ")";
}

// Calcul de la distance entre deux points 3D
float Point3D::distanceTo(const Point3D& otherPoint3D) const {
    float dx = getX() - otherPoint3D.getX();
    float dy = getY() - otherPoint3D.getY();
    float dz = z - otherPoint3D.z;
    return std::sqrt(dx * dx + dy * dy + dz * dz);
}