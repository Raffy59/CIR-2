#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>   // pour isalpha, tolower
#include <array>

using namespace std;

int main() {
    string nomFichier;
    cout << "Entrez le nom du fichier à analyser : ";
    cin >> nomFichier;

    ifstream fichier(nomFichier);
    if (!fichier) {
        cerr << "Erreur : impossible d'ouvrir le fichier." << endl;
        return 1;
    }

    int nbLignes = 0;
    int nbMots = 0;
    int nbLettres = 0;
    array<int, 26> occurrences{}; // initialisé à 0

    string ligne;
    while (getline(fichier, ligne)) {
        nbLignes++;

        stringstream ss(ligne);
        string mot;
        while (ss >> mot) {
            nbMots++;

            for (char c : mot) {
                if (isalpha(static_cast<unsigned char>(c))) {
                    nbLettres++;
                    char lower = tolower(static_cast<unsigned char>(c));
                    occurrences[lower - 'a']++;
                }
            }
        }
    }

    fichier.close();

    cout << "Analyse du fichier : " << nomFichier << endl;
    cout << "Nombre de lignes  : " << nbLignes << endl;
    cout << "Nombre de mots    : " << nbMots << endl;
    cout << "Nombre de lettres : " << nbLettres << endl;

    cout << "\nOccurrences de chaque lettre :" << endl;
    for (int i = 0; i < 26; ++i) {
        if (occurrences[i] > 0) { // n'afficher que les lettres présentes
            cout << static_cast<char>('a' + i) << " : " << occurrences[i] << endl;
        }
    }

    return 0;
}
