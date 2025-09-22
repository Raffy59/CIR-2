#include "Trajectory.hpp"
#include <iostream>

Trajectory::Trajectory(size_t size) : numberOfPoints(size) {
    points = new Point3D[numberOfPoints];
}

Trajectory::~Trajectory() {
    delete[] points;
}

void Trajectory::print() const {
    std::cout << "Trajectory with " << numberOfPoints << " points:" << std::endl;
    for (size_t i = 0; i < numberOfPoints; ++i) {
        std::cout << "Point " << i << ": ";
        points[i].print();
        std::cout << std::endl;
    }
}

Point3D& Trajectory::getPoint(size_t n) {
    if (n >= numberOfPoints) {
        throw std::out_of_range("Index out of bounds");
    }
    return points[n];
}

const Point3D& Trajectory::getPoint(size_t n) const {
    if (n >= numberOfPoints) {
        throw std::out_of_range("Index out of bounds");
    }
    return points[n];
}

float Trajectory::getTotalDistance() const {
    float total = 0.0f;
    for (size_t i = 1; i < numberOfPoints; ++i) {
        total += points[i - 1].distanceTo(points[i]);
    }
    return total;
}

size_t Trajectory::getNumberOfPoints() const {
    return numberOfPoints;
}