#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "Shape.hpp"

class Triangle : public Shape {
private:
    Point2D point1;
    Point2D point2;
    Point2D point3;

public:
    Triangle(const Point2D& p1 = Point2D(),
        const Point2D& p2 = Point2D(1, 0),
        const Point2D& p3 = Point2D(0, 1),
        const std::string& color = "black");

    // Méthodes implémentées
    float area() const override;
    float perimeter() const override;
    void draw() const override;
    void print() const override;

    // Getters et setters
    Point2D getPoint1() const;
    Point2D getPoint2() const;
    Point2D getPoint3() const;
    void setPoint1(const Point2D& p);
    void setPoint2(const Point2D& p);
    void setPoint3(const Point2D& p);
};

#endif