#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "Shape.hpp"

class Circle : public Shape {
private:
    Point2D center;
    float radius;

public:
    Circle(const Point2D& center = Point2D(), float radius = 1.0f,
        const std::string& color = "black");

    // Méthodes implémentées
    float area() const override;
    float perimeter() const override;
    void draw() const override;
    void print() const override;

    // Getters et setters
    Point2D getCenter() const;
    float getRadius() const;
    void setCenter(const Point2D& newCenter);
    void setRadius(float newRadius);
};

#endif