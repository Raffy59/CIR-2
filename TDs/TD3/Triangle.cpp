#include "Triangle.hpp"
#include <iostream>
#include <cmath>

Triangle::Triangle(const Point2D& p1, const Point2D& p2, const Point2D& p3,
    const std::string& color)
    : Shape(color), point1(p1), point2(p2), point3(p3) {
}

float Triangle::area() const {
    // Formule de Héron
    float a = point1.distanceTo(point2);
    float b = point2.distanceTo(point3);
    float c = point3.distanceTo(point1);
    float s = (a + b + c) / 2.0f;
    return std::sqrt(s * (s - a) * (s - b) * (s - c));
}

float Triangle::perimeter() const {
    return point1.distanceTo(point2) +
        point2.distanceTo(point3) +
        point3.distanceTo(point1);
}

void Triangle::draw() const {
    std::cout << "Drawing Triangle with points: ";
    point1.print(); std::cout << ", ";
    point2.print(); std::cout << ", ";
    point3.print();
    std::cout << " and color " << color << std::endl;
}

void Triangle::print() const {
    std::cout << "Triangle: Points = (";
    point1.print(); std::cout << ", ";
    point2.print(); std::cout << ", ";
    point3.print();
    std::cout << "), Color = " << color << ", Area = " << area()
        << ", Perimeter = " << perimeter() << std::endl;
}

Point2D Triangle::getPoint1() const {
    return point1;
}

Point2D Triangle::getPoint2() const {
    return point2;
}

Point2D Triangle::getPoint3() const {
    return point3;
}

void Triangle::setPoint1(const Point2D& p) {
    point1 = p;
}

void Triangle::setPoint2(const Point2D& p) {
    point2 = p;
}

void Triangle::setPoint3(const Point2D& p) {
    point3 = p;
}