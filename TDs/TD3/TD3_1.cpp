#include <iostream>
using namespace std;

// Classe de base A
class A {
public:
    // Constructeur par d�faut - initialise x � 0
    A() {
        x = 0;
        cout << "1";
    }

    // Constructeur avec param�tre - initialise x avec la valeur donn�e
    A(int px) {
        x = px;
        cout << "2";
    }

    // Constructeur de copie - copie la valeur x d'un autre objet A
    A(const A& pa) {
        x = pa.x;
        cout << "3";
    }

protected:
    int x;  // Attribut prot�g�
};

// Classe B qui contient un objet A
class B {
public:
    // Constructeur avec param�tre par d�faut - utilise la liste d'initialisation
    B(const A& pa = A()) : a(pa) {
        cout << "4";
    }

    // Constructeur avec deux param�tres - assignation dans le corps
    B(const A& pa, int py) {
        a = pa;
        y = py;
        cout << "5";
    }

protected:
    A a;    // Composition: B contient un objet A
    int y;  // Attribut entier
};

// Classe C qui h�rite de B
class C : public B {
public:
    // Constructeur par d�faut - initialise z
    C(int pz = 1) {
        z = pz;
        cout << "6";
    }

    // Constructeur avec objet A - utilise la liste d'initialisation pour B
    C(A pa) : B(pa) {
        z = 0;
        cout << "7";
    }

    // Constructeur avec objet B - initialise B par copie et a avec valeur 1
    C(const B& pb) : B(pb), a(1) {
        z = 0;
        cout << "8";
    }

protected:
    A a;    // Composition: C contient aussi un objet A
    int z;  // Attribut entier
};

// Fonction principale de test
int main() {
    cout << "-- Tests de la classe A --\n";

    A a0;           // Constructeur par d�faut: affiche "1"
    cout << endl;

    A a1(3);        // Constructeur avec param�tre: affiche "2"
    cout << endl;

    A a2(a1);       // Constructeur de copie: affiche "3"
    cout << endl;

    A a3 = a2;      // Constructeur de copie: affiche "3"
    cout << endl;

    a3 = a1;        // Op�rateur d'assignation (d�faut): aucun affichage
    cout << endl;

    cout << "-- Tests de la classe B --\n";

    B b0(a0, 3);    // A() temporaire + constructeur B: "1" + "5"
    cout << endl;

    B b1(a1);       // Constructeur B avec param�tre: "4"
    cout << endl;

    B b2;           // Constructeur par d�faut: A() + "4" = "1" + "4"
    cout << endl;

    cout << "-- Tests de la classe C --\n";

    C c0;           // B() + constructeur C: "1" + "4" + "6"
    cout << endl;

    C c1(a1);       // B(a1) + constructeur C: "4" + "7"
    cout << endl;

    C c2(b2);       // B(b2) + A(1) + constructeur C: "3" + "2" + "8"
    cout << endl;

    return 0;
}