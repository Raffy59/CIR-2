#include "Point3D.hpp"
#include <cstddef>

class Trajectory {
private:
    Point3D* points;
    size_t numberOfPoints;

public:
    // Constructeur dynamique
    Trajectory(size_t n) : numberOfPoints(n) {
        points = new Point3D[n]; // allocation dynamique
    }

    // Destructeur
    ~Trajectory() {
        delete[] points;
    }

    void print();
    Point3D& getPoint(const int& n);
    float getTotalDistance();
};
