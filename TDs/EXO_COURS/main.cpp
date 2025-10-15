#include "Fraction.hpp"
#include <iostream>
using namespace std;

int main() {
    Fraction f1(1, 2), f2(1, 3);

    cout << "f1 = " << f1 << endl;
    cout << "f2 = " << f2 << endl;

    // Affectation
    Fraction f3;
    f3 = f1;
    cout << "Affectation f3 = f1 -> f3 = " << f3 << endl;

    // Arithmétiques
    cout << "f1 + f2 = " << (f1 + f2) << endl;
    cout << "f1 - f2 = " << (f1 - f2) << endl;
    cout << "f1 * f2 = " << (f1 * f2) << endl;
    cout << "f1 / f2 = " << (f1 / f2) << endl;

    // Comparaison classique
    if (f1 == f2) cout << "f1 == f2" << endl;
    else cout << "f1 != f2" << endl;

    if (f1 < f2) cout << "f1 < f2" << endl;
    else cout << "f1 >= f2" << endl;

    // Flux >> <<
    Fraction f4;
    cout << "Entrez une fraction (ex: 3/4) : ";
    cin >> f4;
    cout << "Vous avez entré : " << f4 << endl;

    return 0;
}

