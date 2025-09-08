#include <stdio.h>

int main() {
    // --- Premier programme ---
    int x1 = 14, y1 = 13;
    if (x1 > y1) {
        if (x1 < 20) {
            x1 -= 10;
        }
        else {
            x1 += 10;
        }
    }
    printf("Premier programme : %d\n", x1);

    // --- Deuxieme programme ---
    int x2 = 4, y2 = 3;
    x2 = x2 + y2;
    y2 = x2 - y2;
    printf("Deuxieme programme : %d\n", y2);

    // --- Troisieme programme ---
    int x3 = 0, y3 = 100;
    int compteur = 0;
    while (x3 * x3 <= y3) {
        x3 += 1;
        compteur++;
    }
    printf("Troisieme programme : x += 1 execute %d fois\n", compteur);

    return 0;
}
