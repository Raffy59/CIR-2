#include <iostream>
#include <string>
#include <cmath>

// Classe de base Shape
class Shape {
public:
    Shape(const std::string& color = "black") : color_(color) { global_count_++; }
    virtual ~Shape() { global_count_--; }

    virtual float get_area() const = 0;
    virtual void print_data() const = 0;

    static int get_global_count() { return global_count_; }

protected:
    std::string color_;
    static int global_count_;
};

int Shape::global_count_ = 0;

// Rectangle
class Rectangle : public Shape {
public:
    Rectangle(float length, float width, const std::string& color = "black")
        : Shape(color), length_(length), width_(width) {
    }

    float get_area() const override { return length_ * width_; }

    void print_data() const override {
        std::cout << "Rectangle [L=" << length_ << ", W=" << width_
            << ", Couleur=" << color_ << "] Aire=" << get_area() << std::endl;
    }

protected:
    float length_;
    float width_;
};

// Square (hérite de Rectangle)
class Square : public Rectangle {
public:
    Square(float length, const std::string& color = "black")
        : Rectangle(length, length, color), length_(length) {
    }

    float get_area() const override { return length_ * length_; }

    void print_data() const override {
        std::cout << "Square [Cote=" << length_
            << ", Couleur=" << color_ << "] Aire=" << get_area() << std::endl;
    }

private:
    float length_;
};
