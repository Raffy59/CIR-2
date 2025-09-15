#include <iostream>
#include "Point3D.hpp"
using namespace std;

int main() {
    // Test constructeur aléatoire
    Point3D p1;
    cout << "Point p1 (aleatoire): ";
    p1.print();

    // Test constructeur avec paramètres
    Point3D p2(10.0f, 20.0f, 30.0f);
    cout << "Point p2 (defini): ";
    p2.print();

    // Test setters
    p1.setXYZ(1.0f, 2.0f, 3.0f);
    cout << "Apres setXYZ, p1 = ";
    p1.print();

    // Test getters
    cout << "p1.x = " << p1.getX() << ", p1.y = " << p1.getY()
        << ", p1.z = " << p1.getZ() << endl;

    // Test distance
    cout << "Distance entre p1 et p2 = " << p1.distanceTo(p2) << endl;

    return 0;
}
