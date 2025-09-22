#include <iostream>
#include "Polygon.hpp"
#include "Point2D.hpp"

using namespace std;

void testPolygon() {
    cout << "=== TESTS DE LA CLASSE POLYGON ===" << endl << endl;

    // Test 1: Triangle
    cout << "1. Triangle (base=4, hauteur=3):" << endl;
    Polygon triangle;
    triangle.addVertex(0.0f, 0.0f);
    triangle.addVertex(4.0f, 0.0f);
    triangle.addVertex(0.0f, 3.0f);
    triangle.print();
    cout << "Aire attendue: 6.0" << endl << endl;

    // Test 2: Carré
    cout << "2. Carré (côté=5):" << endl;
    Polygon square;
    square.addVertex(0.0f, 0.0f);
    square.addVertex(5.0f, 0.0f);
    square.addVertex(5.0f, 5.0f);
    square.addVertex(0.0f, 5.0f);
    square.print();
    cout << "Aire attendue: 25.0" << endl << endl;

    // Test 3: Rectangle
    cout << "3. Rectangle (largeur=6, hauteur=4):" << endl;
    Polygon rectangle;
    rectangle.addVertex(Point2D(0.0f, 0.0f));
    rectangle.addVertex(Point2D(6.0f, 0.0f));
    rectangle.addVertex(Point2D(6.0f, 4.0f));
    rectangle.addVertex(Point2D(0.0f, 4.0f));
    rectangle.print();
    cout << "Aire attendue: 24.0" << endl << endl;

    // Test 4: Pentagone régulier (test plus complexe)
    cout << "4. Pentagone régulier (approximatif):" << endl;
    Polygon pentagon;
    pentagon.addVertex(0.0f, 1.0f);
    pentagon.addVertex(0.951f, 0.309f);
    pentagon.addVertex(0.588f, -0.809f);
    pentagon.addVertex(-0.588f, -0.809f);
    pentagon.addVertex(-0.951f, 0.309f);
    pentagon.print();
    cout << "Aire approximative attendue: ~2.377" << endl << endl;

    // Test 5: Polygone invalide (2 points seulement)
    cout << "5. Polygone invalide (2 points):" << endl;
    Polygon invalid;
    invalid.addVertex(0.0f, 0.0f);
    invalid.addVertex(1.0f, 1.0f);
    invalid.print();
    cout << "Aire attendue: 0.0" << endl << endl;

    // Test 6: Méthode closePolygon
    cout << "6. Test de fermeture automatique:" << endl;
    Polygon openPolygon;
    openPolygon.addVertex(0.0f, 0.0f);
    openPolygon.addVertex(3.0f, 0.0f);
    openPolygon.addVertex(3.0f, 2.0f);
    openPolygon.addVertex(0.0f, 2.0f);

    cout << "Avant fermeture - Nombre de sommets: " << openPolygon.getVertexCount() << endl;
    openPolygon.closePolygon();
    cout << "Après fermeture - Nombre de sommets: " << openPolygon.getVertexCount() << endl;
    cout << "Aire: " << openPolygon.calculateArea() << " (devrait être 6.0)" << endl;
}

int main() {
    testPolygon();
    return 0;
}