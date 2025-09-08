#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Fonction pour trier une colonne avec un tri à bulles
void trier_colonne(int** tab, int n, int col) {
    int i, j, tmp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (tab[j][col] > tab[j + 1][col]) {
                tmp = tab[j][col];
                tab[j][col] = tab[j + 1][col];
                tab[j + 1][col] = tmp;
            }
        }
    }
}

int main() {
    int n, m;
    int i, j;

    printf("Entrez le nombre de lignes (n) : ");
    scanf("%d", &n);
    printf("Entrez le nombre de colonnes (m) : ");
    scanf("%d", &m);

    // Allocation dynamique du tableau 2D
    int** tab = malloc(n * sizeof(int*));
    if (tab == NULL) {
        printf("Erreur d'allocation mémoire.\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        tab[i] = malloc(m * sizeof(int));
        if (tab[i] == NULL) {
            printf("Erreur d'allocation mémoire.\n");
            return 1;
        }
    }

    srand(time(NULL));

    // Remplir le tableau avec des valeurs aléatoires entre 0 et 99
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            tab[i][j] = rand() % 100;
        }
    }

    // Afficher le tableau avant tri
    printf("\nTableau avant tri :\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%3d ", tab[i][j]);
        }
        printf("\n");
    }

    // Trier chaque colonne
    for (j = 0; j < m; j++) {
        trier_colonne(tab, n, j);
    }

    // Afficher le tableau après tri
    printf("\nTableau apres tri colonne par colonne :\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%3d ", tab[i][j]);
        }
        printf("\n");
    }

    // Libération mémoire
    for (i = 0; i < n; i++) {
        free(tab[i]);
    }
    free(tab);

    return 0;
}
