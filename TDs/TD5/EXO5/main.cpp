#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

//----------------------------------------------------
// Fonction : convertir "31 Décembre 2014" → "31/12/2014"
//----------------------------------------------------
string convertirDate(const string& dateStr, const map<int, string>& mois) {
    // On découpe la date en 3 parties : jour, nom_du_mois, année
    stringstream ss(dateStr);
    string jour, nomMois, annee;
    ss >> jour >> nomMois >> annee;

    // Trouver le numéro du mois correspondant
    int numeroMois = 0;
    for (auto& [num, nom] : mois) {
        if (nom == nomMois) {
            numeroMois = num;
            break;
        }
    }

    if (numeroMois == 0) return "Erreur : mois inconnu.";

    // Créer la nouvelle date au format JJ/MM/AAAA
    stringstream result;
    result << jour << "/";
    if (numeroMois < 10) result << "0"; // ajouter un zéro devant
    result << numeroMois << "/" << annee;
    return result.str();
}

//----------------------------------------------------
// Programme principal
//----------------------------------------------------
int main() {
    //----------------------------------------------------
    // 1️⃣ Déclaration et remplissage de la map
    //----------------------------------------------------
    map<int, string> mois = {
        {1, "Janvier"}, {2, "Février"}, {3, "Mars"}, {4, "Avril"},
        {5, "Mai"}, {6, "Juin"}, {7, "Juillet"}, {8, "Août"},
        {9, "Septembre"}, {10, "Octobre"}, {11, "Novembre"}, {12, "Décembre"}
    };

    //----------------------------------------------------
    // 2️⃣ Affichage dans l’ordre alphabétique
    //----------------------------------------------------
    cout << "Liste des mois en ordre alphabetique :\n";

    // Copier les paires dans un vecteur pour pouvoir trier selon le nom du mois
    vector<pair<int, string>> liste(mois.begin(), mois.end());

    sort(liste.begin(), liste.end(),
         [](auto &a, auto &b) { return a.second < b.second; });

    for (auto& [num, nom] : liste)
        cout << num << " → " << nom << endl;

    cout << "\n";

    //----------------------------------------------------
    // 3️⃣ Conversion de date
    //----------------------------------------------------
    string date1 = "31 Décembre 2014";
    string date2 = "15 Février 2025";

    cout << date1 << " → " << convertirDate(date1, mois) << endl;
    cout << date2 << " → " << convertirDate(date2, mois) << endl;

    return 0;
}

