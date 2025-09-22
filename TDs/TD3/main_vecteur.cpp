#include <iostream>
#include "Vecteur.hpp"
#include "Point2D.hpp"
#include "Point3D.hpp"

using namespace std;

void testVecteur() {
    cout << "=== TESTS DE LA CLASSE VECTEUR ===" << endl << endl;

    // Test des constructeurs de base
    cout << "1. Constructeurs de base:" << endl;
    Vecteur v1; // Vecteur nul 3D
    cout << "Vecteur nul: "; v1.print(); cout << endl;

    Vecteur v2(2.0f, 3.0f); // Vecteur 2D
    cout << "Vecteur 2D: "; v2.print(); cout << endl;

    Vecteur v3(1.0f, 2.0f, 3.0f); // Vecteur 3D
    cout << "Vecteur 3D: "; v3.print(); cout << endl << endl;

    // Test des constructeurs à partir de points
    cout << "2. Constructeurs à partir de points:" << endl;
    Point2D p2d1(0.0f, 0.0f);
    Point2D p2d2(3.0f, 4.0f);
    Vecteur v4(p2d1, p2d2);
    cout << "Vecteur 2D entre points: "; v4.print(); cout << endl;
    cout << "Norme: " << v4.norme() << " (devrait être 5.0)" << endl;

    Point3D p3d1(0.0f, 0.0f, 0.0f);
    Point3D p3d2(1.0f, 2.0f, 2.0f);
    Vecteur v5(p3d1, p3d2);
    cout << "Vecteur 3D entre points: "; v5.print(); cout << endl;
    cout << "Norme: " << v5.norme() << " (devrait être 3.0)" << endl << endl;

    // Test de la somme de vecteurs
    cout << "3. Somme de vecteurs:" << endl;
    Vecteur v6(1.0f, 2.0f);
    Vecteur v7(3.0f, 4.0f);
    Vecteur somme2D = v6 + v7;
    cout << "Somme 2D: "; v6.print(); cout << " + "; v7.print();
    cout << " = "; somme2D.print(); cout << endl;

    Vecteur v8(1.0f, 2.0f, 3.0f);
    Vecteur v9(4.0f, 5.0f, 6.0f);
    Vecteur somme3D = v8 + v9;
    cout << "Somme 3D: "; v8.print(); cout << " + "; v9.print();
    cout << " = "; somme3D.print(); cout << endl << endl;

    // Test du produit par un scalaire
    cout << "4. Produit par un scalaire:" << endl;
    Vecteur v10(2.0f, 3.0f);
    Vecteur produit2D = v10 * 2.5f;
    cout << "Produit 2D: "; v10.print(); cout << " * 2.5 = ";
    produit2D.print(); cout << endl;

    Vecteur v11(1.0f, 2.0f, 3.0f);
    Vecteur produit3D = v11 * 3.0f;
    cout << "Produit 3D: "; v11.print(); cout << " * 3.0 = ";
    produit3D.print(); cout << endl << endl;

    // Test de l'égalité
    cout << "5. Test d'égalité:" << endl;
    Vecteur v12(2.0f, 3.0f);
    Vecteur v13(2.0f, 3.0f);
    Vecteur v14(2.0f, 3.0f, 0.0f); // 3D mais z=0
    Vecteur v15(2.1f, 3.0f); // Légèrement différent

    cout << "v12 == v13: " << (v12 == v13) << " (devrait être vrai)" << endl;
    cout << "v12 == v14: " << (v12 == v14) << " (devrait être faux - dimensions différentes)" << endl;
    cout << "v12 == v15: " << (v12 == v15) << " (devrait être faux)" << endl << endl;

    // Test de normalisation
    cout << "6. Normalisation:" << endl;
    Vecteur v16(3.0f, 4.0f); // Norme = 5
    Vecteur normalise2D = v16.normaliser();
    cout << "Vecteur 2D: "; v16.print(); cout << " -> Normalisé: ";
    normalise2D.print(); cout << " (Norme: " << normalise2D.norme() << ")" << endl;

    Vecteur v17(2.0f, 3.0f, 6.0f); // Norme = 7
    Vecteur normalise3D = v17.normaliser();
    cout << "Vecteur 3D: "; v17.print(); cout << " -> Normalisé: ";
    normalise3D.print(); cout << " (Norme: " << normalise3D.norme() << ")" << endl << endl;

    // Test produit scalaire
    cout << "7. Produit scalaire:" << endl;
    Vecteur v18(1.0f, 2.0f);
    Vecteur v19(3.0f, 4.0f);
    cout << "Produit scalaire 2D: " << v18.dot(v19) << " (devrait être 11)" << endl;

    Vecteur v20(1.0f, 2.0f, 3.0f);
    Vecteur v21(4.0f, 5.0f, 6.0f);
    cout << "Produit scalaire 3D: " << v20.dot(v21) << " (devrait être 32)" << endl;
}

int main() {
    testVecteur();
    return 0;
}