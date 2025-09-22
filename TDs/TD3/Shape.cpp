#include "Shape.hpp"

Shape::Shape(const std::string& color) : color(color) {}

std::string Shape::getColor() const {
    return color;
}

void Shape::setColor(const std::string& newColor) {
    color = newColor;
}