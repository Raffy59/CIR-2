#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "Shape.hpp"

class Rectangle : public Shape {
private:
    Point2D topLeft;
    Point2D bottomRight;

public:
    Rectangle(const Point2D& topLeft = Point2D(),
        const Point2D& bottomRight = Point2D(1, 1),
        const std::string& color = "black");

    // Méthodes implémentées
    float area() const override;
    float perimeter() const override;
    void draw() const override;
    void print() const override;

    // Getters et setters
    Point2D getTopLeft() const;
    Point2D getBottomRight() const;
    void setTopLeft(const Point2D& newTopLeft);
    void setBottomRight(const Point2D& newBottomRight);
    float getWidth() const;
    float getHeight() const;
};

#endif