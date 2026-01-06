#include <iostream>
#include <vector>

void monotone(const std::vector<int>& T, int& deb, int& lon) {
    int n = T.size();

    int debCourant = 0;
    int longCourant = 1;

    deb = 0;
    lon = 1;

    int i = 0;

    while (i < n - 1) {
        if (T[i] < T[i + 1]) {
            longCourant++;
        } else {
            debCourant = i + 1;
            longCourant = 1;
        }

        if (longCourant > lon) {
            lon = longCourant;
            deb = debCourant;
        }

        i++;
    }
}

int main() {
    std::vector<int> T = {3,4,5,1,2,3,4,5,10,1};

    int deb, lon;
    monotone(T, deb, lon);

    std::cout << "Début : " << deb << std::endl;
    std::cout << "Longueur : " << lon << std::endl;

    return 0;
}
