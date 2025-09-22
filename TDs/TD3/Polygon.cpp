#include "Polygon.hpp"
#include <stdexcept>
#include <cmath>

// Constructeur par défaut
Polygon::Polygon() {}

// Constructeur avec liste de points
Polygon::Polygon(const std::vector<Point2D>& points) : vertices(points) {}

// Ajouter un sommet avec un objet Point2D
void Polygon::addVertex(const Point2D& point) {
    vertices.push_back(point);
}

// Ajouter un sommet avec des coordonnées
void Polygon::addVertex(float x, float y) {
    vertices.push_back(Point2D(x, y));
}

// Nombre de sommets
size_t Polygon::getVertexCount() const {
    return vertices.size();
}

// Obtenir un sommet spécifique
Point2D Polygon::getVertex(size_t index) const {
    if (index >= vertices.size()) {
        throw std::out_of_range("Index de sommet invalide");
    }
    return vertices[index];
}

// Obtenir tous les sommets
const std::vector<Point2D>& Polygon::getVertices() const {
    return vertices;
}

// Calcul de l'aire avec la formule de l'énoncé
float Polygon::calculateArea() const {
    if (vertices.size() < 3) {
        return 0.0f; // Un polygone doit avoir au moins 3 sommets
    }

    float area = 0.0f;
    size_t n = vertices.size();

    // Appliquer la formule: 1/2 * Σ(x_i * y_{i+1} - x_{i+1} * y_i)
    for (size_t i = 0; i < n; i++) {
        size_t next = (i + 1) % n; // Le dernier point se connecte au premier
        area += vertices[i].getX() * vertices[next].getY() -
            vertices[next].getX() * vertices[i].getY();
    }

    return std::abs(area) / 2.0f; // Valeur absolue et division par 2
}

// Affichage du polygone
void Polygon::print() const {
    std::cout << "Polygone avec " << vertices.size() << " sommets:" << std::endl;
    for (size_t i = 0; i < vertices.size(); i++) {
        std::cout << "  Sommet " << i << ": ";
        vertices[i].print();
        std::cout << std::endl;
    }
    if (vertices.size() >= 3) {
        std::cout << "  Aire: " << calculateArea() << std::endl;
    }
}

// Vérifier si le polygone est valide
bool Polygon::isValid() const {
    return vertices.size() >= 3;
}
