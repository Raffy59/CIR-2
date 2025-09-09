#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c;
    double delta, x1, x2;

    // Saisie des coefficients
    printf("Entrez a, b et c : ");
    scanf_s("%lf %lf %lf", &a, &b, &c);

    if (a == 0) {
        printf("Ce n'est pas une équation du second degré.\n");
    }
    else {
        delta = b * b - 4 * a * c;

        if (delta > 0) {
            x1 = (-b - sqrt(delta)) / (2 * a);
            x2 = (-b + sqrt(delta)) / (2 * a);
            printf("Deux racines réelles distinctes : x1 = %.2lf, x2 = %.2lf\n", x1, x2);
        }
        else if (delta == 0) {
            x1 = -b / (2 * a);
            printf("Une racine réelle double : x = %.2lf\n", x1);
        }
        else {
            double re = -b / (2 * a);
            double im = sqrt(-delta) / (2 * a);
            printf("Deux racines complexes : x1 = %.2lf - %.2lfi, x2 = %.2lf + %.2lfi\n",
                re, im, re, im);
        }
    }

    return 0;
}
