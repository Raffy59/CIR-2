#ifndef POINT2D_HPP
#define POINT2D_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

class Point2D {
protected:
    float x, y;

public:
    // Constructeurs
    Point2D();
    Point2D(const float& newx, const float& newy);

    // Setters et getters
    void setXY(const float& newx, const float& newy);
    void setX(const float& newx);
    void setY(const float& newy);
    float getX() const;
    float getY() const;

    // Méthodes
    virtual void print() const;
    float distanceTo(const Point2D& otherPoint) const;
};

#endif