#ifndef TRAJECTORY_HPP
#define TRAJECTORY_HPP

#include "Point3D.hpp"

class Trajectory {
private:
    Point3D* points;
    size_t numberOfPoints;

public:
    // Constructeur avec allocation dynamique
    Trajectory(size_t size);

    // Destructeur
    ~Trajectory();

    // Méthodes
    void print() const;
    Point3D& getPoint(size_t n);
    const Point3D& getPoint(size_t n) const;
    float getTotalDistance() const;
    size_t getNumberOfPoints() const;

    // Empêcher la copie pour simplifier
    Trajectory(const Trajectory&) = delete;
    Trajectory& operator=(const Trajectory&) = delete;
};

#endif