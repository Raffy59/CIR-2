#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

//----------------------------------------------------
// Fonction utilitaire pour simplifier une fraction
//----------------------------------------------------
int pgcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return abs(a);
}

void simplifier(int &num, int &den) {
    int g = pgcd(num, den);
    if (g != 0) {
        num /= g;
        den /= g;
    }
    if (den < 0) { num = -num; den = -den; } // normaliser
}

//----------------------------------------------------
// Conversion fraction -> valeur réelle
//----------------------------------------------------
double valeur(int num, int den) {
    return static_cast<double>(num) / den;
}

//----------------------------------------------------
// Addition de deux fractions
//----------------------------------------------------
pair<int,int> addition(pair<int,int> a, pair<int,int> b) {
    int n = a.first * b.second + b.first * a.second;
    int d = a.second * b.second;
    simplifier(n, d);
    return {n, d};
}

//----------------------------------------------------
// Affichage d'une fraction
//----------------------------------------------------
void afficher(const pair<int,int> &f) {
    cout << f.first << "/" << f.second;
}

//----------------------------------------------------
// Programme principal
//----------------------------------------------------
int main() {
    ifstream fichier("fractions.txt");
    if (!fichier) {
        cerr << "Erreur : impossible d'ouvrir le fichier 'fractions.txt'.\n";
        return 1;
    }

    vector<pair<int,int>> fractions;
    int n, d;

    // Lecture dans le vecteur
    while (fichier >> n >> d) {
        if (d == 0) d = 1; // éviter division par zéro
        simplifier(n, d);
        fractions.push_back({n, d});
    }
    fichier.close();

    //----------------------------------------------------
    // 1️⃣ Trier par valeur croissante
    //----------------------------------------------------
    sort(fractions.begin(), fractions.end(),
         [](auto &a, auto &b){ return valeur(a.first, a.second) < valeur(b.first, b.second); });

    cout << "Fractions triees :\n";
    for (auto &f : fractions) { afficher(f); cout << " "; }
    cout << "\n\n";

    //----------------------------------------------------
    // 2️⃣ Somme totale
    //----------------------------------------------------
    pair<int,int> somme = accumulate(fractions.begin(), fractions.end(), make_pair(0,1),
        [](pair<int,int> acc, pair<int,int> f){ return addition(acc, f); });

    cout << "Somme totale = "; afficher(somme); cout << "\n\n";

    //----------------------------------------------------
    // 3️⃣ Supprimer les doublons
    //----------------------------------------------------
    fractions.erase(unique(fractions.begin(), fractions.end(),
        [](auto &a, auto &b){ return valeur(a.first, a.second) == valeur(b.first, b.second); }),
        fractions.end());

    //----------------------------------------------------
    // 4️⃣ Supprimer les négatives
    //----------------------------------------------------
    fractions.erase(remove_if(fractions.begin(), fractions.end(),
        [](auto &f){ return valeur(f.first, f.second) < 0; }),
        fractions.end());

    //----------------------------------------------------
    // 5️⃣ Trouver min et max
    //----------------------------------------------------
    auto minF = *min_element(fractions.begin(), fractions.end(),
        [](auto &a, auto &b){ return valeur(a.first, a.second) < valeur(b.first, b.second); });

    auto maxF = *max_element(fractions.begin(), fractions.end(),
        [](auto &a, auto &b){ return valeur(a.first, a.second) < valeur(b.first, b.second); });

    //----------------------------------------------------
    // 6️⃣ Affichage final
    //----------------------------------------------------
    cout << "Apres suppression doublons et negatives :\n";
    for (auto &f : fractions) { afficher(f); cout << " "; }
    cout << "\n\n";

    cout << "Valeur minimale : "; afficher(minF); cout << "\n";
    cout << "Valeur maximale : "; afficher(maxF); cout << "\n";

    return 0;
}

