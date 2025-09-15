#include "Trajectory.hpp"
#include <iostream>
using namespace std;

void Trajectory::print() {
    for (size_t i = 0; i < numberOfPoints; ++i) {
        cout << "Point " << i << ": ";
        points[i].print();
    }
}

Point3D& Trajectory::getPoint(const int& n) {
    if (n < 0 || n >= static_cast<int>(numberOfPoints)) {
        cerr << "Erreur : indice hors limites !" << endl;
        exit(1);
    }
    return points[n];
}

float Trajectory::getTotalDistance() {
    float total = 0.0f;
    for (size_t i = 1; i < numberOfPoints; ++i) {
        total += points[i - 1].distanceTo(points[i]);
    }
    return total;
}
