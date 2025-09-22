#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "Point2D.hpp"
#include <string>

class Shape {
protected:
    std::string color;

public:
    Shape(const std::string& color = "black");
    virtual ~Shape() = default;

    // Méthodes virtuelles pures
    virtual float area() const = 0;
    virtual float perimeter() const = 0;
    virtual void draw() const = 0;
    virtual void print() const = 0;

    // Getter et setter
    std::string getColor() const;
    void setColor(const std::string& newColor);
};

#endif