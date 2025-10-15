#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>   // pour ostream_iterator
using namespace std;

int main() {
    vector<int> v = {3, -1, 5, 0, -2, 8, -4, 6};

    //-----------------------------------------------
    // 1️⃣ Déterminer si toutes les valeurs sont positives ou nulles
    //-----------------------------------------------
    bool toutesPositives = all_of(v.begin(), v.end(),
        [](int x){ return x >= 0; });

    cout << "Toutes les valeurs sont positives ou nulles ? "
         << (toutesPositives ? "Oui" : "Non") << endl << endl;

    //-----------------------------------------------
    // 2️⃣ Remplacer toutes les valeurs négatives par 0
    //-----------------------------------------------
    replace_if(v.begin(), v.end(),
        [](int x){ return x < 0; }, 0);

    cout << "Apres remplacement des valeurs negatives par 0 : ";
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << "\n\n";

    //-----------------------------------------------
    // 3️⃣ Afficher toutes les valeurs positives
    //-----------------------------------------------
    cout << "Valeurs positives : ";
    copy_if(v.begin(), v.end(),
        ostream_iterator<int>(cout, " "),
        [](int x){ return x > 0; });
    cout << "\n\n";

    //-----------------------------------------------
    // 4️⃣ Trouver la position du premier et du dernier element negatif
    //-----------------------------------------------
    // (On travaille sur le vecteur original avant remplacement)
    vector<int> original = {3, -1, 5, 0, -2, 8, -4, 6};

    auto firstNeg = find_if(original.begin(), original.end(),
        [](int x){ return x < 0; });

    auto lastNeg = find_if(original.rbegin(), original.rend(),
        [](int x){ return x < 0; });

    if (firstNeg != original.end())
        cout << "Position du premier negatif : "
             << distance(original.begin(), firstNeg) << endl;
    else
        cout << "Aucune valeur negative." << endl;

    if (lastNeg != original.rend())
        cout << "Position du dernier negatif : "
             << (original.size() - 1 - distance(original.rbegin(), lastNeg)) << endl;
    else
        cout << "Aucune valeur negative." << endl;

    return 0;
}

