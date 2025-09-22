#include <iostream>
#include "Point2D.hpp"
#include "Point3D.hpp"
#include "Circle.hpp"
#include "Rectangle.hpp"
#include "Triangle.hpp"
#include "Trajectory.hpp"

using namespace std;

int main() {
    // Initialisation du générateur aléatoire
    srand(static_cast<unsigned int>(time(nullptr)));

    cout << "=== TESTS POINT2D ===" << endl;
    Point2D p2d1;
    Point2D p2d2(5.0f, 10.0f);
    cout << "Point2D 1: "; p2d1.print(); cout << endl;
    cout << "Point2D 2: "; p2d2.print(); cout << endl;
    cout << "Distance: " << p2d1.distanceTo(p2d2) << endl << endl;

    cout << "=== TESTS POINT3D ===" << endl;
    Point3D p3d1;
    Point3D p3d2(1.0f, 2.0f, 3.0f);
    cout << "Point3D 1: "; p3d1.print(); cout << endl;
    cout << "Point3D 2: "; p3d2.print(); cout << endl;
    cout << "Distance: " << p3d1.distanceTo(p3d2) << endl << endl;

    cout << "=== TESTS SHAPES ===" << endl;
    Circle circle(Point2D(0, 0), 5.0f, "red");
    circle.print();
    circle.draw();
    cout << endl;

    Rectangle rect(Point2D(0, 0), Point2D(10, 5), "blue");
    rect.print();
    rect.draw();
    cout << endl;

    Triangle triangle(Point2D(0, 0), Point2D(4, 0), Point2D(0, 3), "green");
    triangle.print();
    triangle.draw();
    cout << endl;

    cout << "=== TESTS TRAJECTORY ===" << endl;
    Trajectory trajectory(5);
    trajectory.print();
    cout << "Total distance: " << trajectory.getTotalDistance() << endl;

    return 0;
}