#include "Point3D.hpp"
#include <iostream>
#include <cmath>    // pour sqrt, pow
#include <cstdlib>  // pour rand()
#include <ctime>    // pour srand()

using namespace std;

// Constructeur par défaut : valeurs aléatoires entre 0 et 100
Point3D::Point3D() {
    static bool initialized = false;
    if (!initialized) {
        srand(static_cast<unsigned int>(time(nullptr)));
        initialized = true;
    }
    x = static_cast<float>(rand() % 101); // 0 à 100 inclus
    y = static_cast<float>(rand() % 101);
    z = static_cast<float>(rand() % 101);
}

// Constructeur avec paramètres
Point3D::Point3D(const float& newx, const float& newy, const float& newz) {
    x = newx;
    y = newy;
    z = newz;
}

// Setters
void Point3D::setXYZ(const float& newx, const float& newy, const float& newz) {
    x = newx;
    y = newy;
    z = newz;
}
void Point3D::setX(const float& newx) { x = newx; }
void Point3D::setY(const float& newy) { y = newy; }
void Point3D::setZ(const float& newz) { z = newz; }

// Getters
float Point3D::getX() { return x; }
float Point3D::getY() { return y; }
float Point3D::getZ() { return z; }

// Méthode print
void Point3D::print() {
    cout << "(" << x << ", " << y << ", " << z << ")" << endl;
}

// Distance entre deux points
float Point3D::distanceTo(const Point3D& otherPoint3D) {
    float dx = x - otherPoint3D.x;
    float dy = y - otherPoint3D.y;
    float dz = z - otherPoint3D.z;
    return sqrt(dx * dx + dy * dy + dz * dz);
}
