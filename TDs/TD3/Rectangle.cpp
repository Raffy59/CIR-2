#include "Rectangle.hpp"
#include <iostream>
#include <cmath>

Rectangle::Rectangle(const Point2D& topLeft, const Point2D& bottomRight,
    const std::string& color)
    : Shape(color), topLeft(topLeft), bottomRight(bottomRight) {
}

float Rectangle::area() const {
    return getWidth() * getHeight();
}

float Rectangle::perimeter() const {
    return 2 * (getWidth() + getHeight());
}

void Rectangle::draw() const {
    std::cout << "Drawing Rectangle from ";
    topLeft.print();
    std::cout << " to ";
    bottomRight.print();
    std::cout << " with color " << color << std::endl;
}

void Rectangle::print() const {
    std::cout << "Rectangle: TopLeft = ";
    topLeft.print();
    std::cout << ", BottomRight = ";
    bottomRight.print();
    std::cout << ", Width = " << getWidth() << ", Height = " << getHeight()
        << ", Color = " << color << ", Area = " << area()
        << ", Perimeter = " << perimeter() << std::endl;
}

Point2D Rectangle::getTopLeft() const {
    return topLeft;
}

Point2D Rectangle::getBottomRight() const {
    return bottomRight;
}

void Rectangle::setTopLeft(const Point2D& newTopLeft) {
    topLeft = newTopLeft;
}

void Rectangle::setBottomRight(const Point2D& newBottomRight) {
    bottomRight = newBottomRight;
}

float Rectangle::getWidth() const {
    return std::abs(bottomRight.getX() - topLeft.getX());
}

float Rectangle::getHeight() const {
    return std::abs(bottomRight.getY() - topLeft.getY());
}