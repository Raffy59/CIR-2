#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <functional> // pour std::hash
using namespace std;

//---------------------------------------------------------
// Fonction : hacher le mot de passe (utilise std::hash)
//---------------------------------------------------------
string hashPassword(const string& password) {
    hash<string> h;
    return to_string(h(password)); // simple hash → pas un vrai chiffrement
}

//---------------------------------------------------------
// Charger les utilisateurs depuis un fichier
//---------------------------------------------------------
void chargerUtilisateurs(map<string, string>& users, const string& fichier) {
    ifstream fin(fichier);
    if (!fin) {
        cerr << "⚠️  Fichier " << fichier << " introuvable. Il sera créé.\n";
        return;
    }

    string ligne;
    while (getline(fin, ligne)) {
        size_t pos = ligne.find('=');
        if (pos != string::npos) {
            string username = ligne.substr(0, pos);
            string passwordHash = ligne.substr(pos + 1);
            users[username] = passwordHash;
        }
    }
    fin.close();
}

//---------------------------------------------------------
// Sauvegarder les utilisateurs dans un fichier
//---------------------------------------------------------
void sauvegarderUtilisateurs(const map<string, string>& users, const string& fichier) {
    ofstream fout(fichier);
    for (auto& [user, hash] : users)
        fout << user << "=" << hash << endl;
    fout.close();
}

//---------------------------------------------------------
// Créer un nouvel utilisateur
//---------------------------------------------------------
void creerUtilisateur(map<string, string>& users, const string& fichier) {
    string username, pass1, pass2;

    cout << "=== Création d'un nouvel utilisateur ===\n";
    cout << "Nom d'utilisateur : ";
    getline(cin, username);

    if (users.find(username) != users.end()) {
        cout << "⚠️  L'utilisateur existe déjà.\n";
        return;
    }

    cout << "Mot de passe : ";
    getline(cin, pass1);
    cout << "Confirmez le mot de passe : ";
    getline(cin, pass2);

    if (pass1 != pass2) {
        cout << "❌ Les mots de passe ne correspondent pas.\n";
        return;
    }

    users[username] = hashPassword(pass1);
    sauvegarderUtilisateurs(users, fichier);

    cout << "✅ Utilisateur " << username << " créé avec succès !\n";
}

//---------------------------------------------------------
// Authentification d'un utilisateur (3 tentatives max.)
//---------------------------------------------------------
void loginUtilisateur(const map<string, string>& users) {
    string username, password;
    int essais = 3;

    cout << "=== Connexion ===\n";

    while (essais > 0) {
        cout << "Nom d'utilisateur : ";
        getline(cin, username);
        cout << "Mot de passe : ";
        getline(cin, password);

        auto it = users.find(username);
        if (it != users.end() && it->second == hashPassword(password)) {
            cout << "✅ Authentification réussie ! Bienvenue, " << username << " 👋\n";
            return;
        } else {
            essais--;
            cout << "❌ Identifiant ou mot de passe incorrect. ";
            if (essais > 0)
                cout << "Tentatives restantes : " << essais << "\n";
        }
    }
    cout << "⛔ Trop de tentatives échouées. Programme terminé.\n";
}

//---------------------------------------------------------
// Programme principal
//---------------------------------------------------------
int main(int argc, char* argv[]) {
    const string fichier = "utilisateurs.txt";
    map<string, string> utilisateurs;
    chargerUtilisateurs(utilisateurs, fichier);

    if (argc < 2) {
        cout << "Usage : " << argv[0] << " [create|login]\n";
        return 1;
    }

    string mode = argv[1];
    if (mode == "create") {
        creerUtilisateur(utilisateurs, fichier);
    } else if (mode == "login") {
        loginUtilisateur(utilisateurs);
    } else {
        cout << "Argument inconnu. Utilisez 'create' ou 'login'.\n";
    }

    return 0;
}

