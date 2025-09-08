#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100  // Taille maximale du tableau

// Fonction pour trier un tableau (tri à bulles)
void trier(int tab[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (tab[j] > tab[j + 1]) {
                temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n, i;
    int tab[MAX];

    printf("Entrez la taille du tableau (<= %d) : ", MAX);
    scanf("%d", &n);

    if (n <= 0 || n > MAX) {
        printf("Taille invalide.\n");
        return 1;
    }

    // Initialiser le générateur de nombres aléatoires
    srand(time(NULL));

    // Remplir le tableau avec des valeurs aléatoires entre 0 et 99
    for (i = 0; i < n; i++) {
        tab[i] = rand() % 100;
    }

    // Affichage avant tri
    printf("\nTableau avant tri :\n");
    for (i = 0; i < n; i++) {
        printf("%d ", tab[i]);
    }

    // Trier
    trier(tab, n);

    // Affichage après tri
    printf("\n\nTableau trie en ordre croissant :\n");
    for (i = 0; i < n; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");

    return 0;
}
