#include <iostream>
#include "Trajectory.hpp"
using namespace std;

int main() {
    size_t n;
    cout << "Entrez le nombre de points : ";
    cin >> n;

    Trajectory traj(n);

    cout << "Coordonnées de la trajectoire :" << endl;
    traj.print();

    cout << "\nDistance totale de la trajectoire : "
        << traj.getTotalDistance() << endl;

    // Modifier un point
    if (n > 0) {
        traj.getPoint(0).setXYZ(0.0f, 0.0f, 0.0f);
        cout << "\nAprès modification du premier point :" << endl;
        traj.print();
    }

    return 0;
}
