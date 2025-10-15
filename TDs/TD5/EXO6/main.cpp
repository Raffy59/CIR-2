#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

//----------------------------------------------------------
// Fonction pour charger les acronymes depuis un fichier
//----------------------------------------------------------
void chargerAcronymes(map<string, string>& acronyms, const string& nomFichier) {
    ifstream fichier(nomFichier);
    if (!fichier) {
        cerr << "⚠️  Impossible d'ouvrir le fichier " << nomFichier << endl;
        return;
    }

    string ligne;
    while (getline(fichier, ligne)) {
        size_t pos = ligne.find('=');
        if (pos != string::npos) {
            string cle = ligne.substr(0, pos);
            string valeur = ligne.substr(pos + 1);
            acronyms[cle] = valeur;
        }
    }
    fichier.close();
}

//----------------------------------------------------------
// Fonction pour sauvegarder les acronymes dans le fichier
//----------------------------------------------------------
void sauvegarderAcronymes(const map<string, string>& acronyms, const string& nomFichier) {
    ofstream fichier(nomFichier);
    if (!fichier) {
        cerr << "⚠️  Erreur lors de l'enregistrement dans le fichier " << nomFichier << endl;
        return;
    }

    for (auto& [acronyme, definition] : acronyms)
        fichier << acronyme << "=" << definition << endl;

    fichier.close();
}

//----------------------------------------------------------
// Programme principal
//----------------------------------------------------------
int main() {
    map<string, string> acronyms;
    string nomFichier = "acronymes.txt";

    // 1️⃣ Charger la liste initiale
    chargerAcronymes(acronyms, nomFichier);

    cout << "=== Dictionnaire d'acronymes ===\n";
    cout << "(Tapez 'fin' pour quitter)\n\n";

    string acronyme;
    while (true) {
        cout << "Entrez un acronyme : ";
        getline(cin, acronyme);

        if (acronyme == "fin") break;

        auto it = acronyms.find(acronyme);
        if (it != acronyms.end()) {
            cout << "👉 " << acronyme << " = " << it->second << "\n\n";
        } else {
            cout << "❓ Acronyme inconnu. Entrez sa signification : ";
            string definition;
            getline(cin, definition);

            acronyms[acronyme] = definition;
            cout << "✅ Ajouté : " << acronyme << " = " << definition << "\n\n";
        }
    }

    // 2️⃣ Sauvegarder les ajouts dans le fichier
    sauvegarderAcronymes(acronyms, nomFichier);

    cout << "\n📁 Liste sauvegardée dans " << nomFichier << endl;
    cout << "👋 Fin du programme." << endl;
    return 0;
}


