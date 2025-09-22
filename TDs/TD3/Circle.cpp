#include "Circle.hpp"
#include <iostream>

Circle::Circle(const Point2D& center, float radius, const std::string& color)
    : Shape(color), center(center), radius(radius) {
}

float Circle::area() const {
    return 3.14159f * radius * radius;
}

float Circle::perimeter() const {
    return 2 * 3.14159f * radius;
}

void Circle::draw() const {
    std::cout << "Drawing Circle at ";
    center.print();
    std::cout << " with radius " << radius << " and color " << color << std::endl;
}

void Circle::print() const {
    std::cout << "Circle: Center = ";
    center.print();
    std::cout << ", Radius = " << radius << ", Color = " << color
        << ", Area = " << area() << ", Perimeter = " << perimeter() << std::endl;
}

Point2D Circle::getCenter() const {
    return center;
}

float Circle::getRadius() const {
    return radius;
}

void Circle::setCenter(const Point2D& newCenter) {
    center = newCenter;
}

void Circle::setRadius(float newRadius) {
    radius = newRadius;
}