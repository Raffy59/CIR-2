#ifndef POINT3D_HPP
#define POINT3D_HPP

#include "Point2D.hpp"

class Point3D : public Point2D {
private:
    float z;

public:
    // Constructeurs
    Point3D();
    Point3D(const float& newx, const float& newy, const float& newz);

    // Setters et getters
    void setXYZ(const float& newx, const float& newy, const float& newz);
    void setZ(const float& newz);
    float getZ() const;

    // Méthodes redéfinies
    void print() const override;
    float distanceTo(const Point3D& otherPoint3D) const;
};

#endif