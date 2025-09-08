#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_TAILLE 50
#define MAX_ERREURS 10

int main() {
    char mot[MAX_TAILLE];
    char trouve[MAX_TAILLE];
    char lettre;
    int erreurs = 0;
    int longueur, i;
    int gagne = 0;

    // Saisie du mot par le joueur 1
    printf("Joueur 1, entrez le mot a deviner : ");
    scanf("%s", mot);

    longueur = strlen(mot);

    // Initialiser l'affichage avec des '_'
    for (i = 0; i < longueur; i++) {
        trouve[i] = '_';
    }
    trouve[longueur] = '\0';

    printf("\n\n=== Jeu du Pendu ===\n");
    printf("Le mot a deviner contient %d lettres.\n", longueur);

    // Boucle de jeu
    while (erreurs < MAX_ERREURS && !gagne) {
        printf("\nMot actuel : %s\n", trouve);
        printf("Tentatives restantes : %d\n", MAX_ERREURS - erreurs);
        printf("Proposez une lettre : ");
        scanf(" %c", &lettre);

        lettre = toupper(lettre); // normaliser en majuscule
        int trouve_lettre = 0;

        // Vérifier si la lettre est dans le mot
        for (i = 0; i < longueur; i++) {
            if (toupper(mot[i]) == lettre) {
                trouve[i] = mot[i]; // révéler la lettre
                trouve_lettre = 1;
            }
        }

        if (!trouve_lettre) {
            erreurs++;
            printf("La lettre %c n'est pas dans le mot !\n", lettre);
        }

        // Vérifier si le mot est trouvé
        if (strcmp(mot, trouve) == 0) {
            gagne = 1;
        }
    }

    // Fin du jeu
    if (gagne) {
        printf("\nBravo ! Vous avez trouvé le mot : %s\n", mot);
    }
    else {
        printf("\nPerdu ! Le mot etait : %s\n", mot);
    }

    return 0;
}
