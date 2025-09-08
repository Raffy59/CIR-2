#include <stdio.h>

// Factorielle avec une boucle for
long long fact_for(int n) {
    long long resultat = 1;
    for (int i = 1; i <= n; i++) {
        resultat *= i;
    }
    return resultat;
}

// Factorielle avec une boucle while
long long fact_while(int n) {
    long long resultat = 1;
    int i = 1;
    while (i <= n) {
        resultat *= i;
        i++;
    }
    return resultat;
}

// Factorielle en récursif
long long fact_rec(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    else {
        return n * fact_rec(n - 1);
    }
}

int main() {
    int n;

    printf("Entrez un entier n : ");
    scanf("%d", &n);

    if (n < 0) {
        printf("La factorielle n'est pas definie pour les entiers negatifs.\n");
    }
    else {
        printf("Factorielle de %d avec for     : %lld\n", n, fact_for(n));
        printf("Factorielle de %d avec while   : %lld\n", n, fact_while(n));
        printf("Factorielle de %d en recursif  : %lld\n", n, fact_rec(n));
    }

    return 0;
}
