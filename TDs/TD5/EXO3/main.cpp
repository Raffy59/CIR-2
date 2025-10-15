#include <iostream>
#include <vector>
#include <algorithm>  // pour std::distance, std::min
using namespace std;

template<typename Iter>
typename Iter::value_type
partial_dot(Iter first1, Iter last1, Iter first2, Iter last2) {
    using T = typename Iter::value_type;
    T sum = T(); // initialise à 0 du bon type (int, double, etc.)

    // avance en parallèle dans les deux séquences
    for (; first1 != last1 && first2 != last2; ++first1, ++first2)
        sum += (*first1) * (*first2);

    return sum;
}

int main() {
    vector<int> A = {1, 2, 3, 4};
    vector<int> B = {10, 20, 30, 40};

    int result = partial_dot(A.begin(), A.end(), B.begin(), B.end());
    cout << "Produit scalaire = " << result << endl;

    // exemple avec vecteurs de tailles différentes
    vector<double> C = {1.5, 2.5, 3.5};
    vector<double> D = {2.0, 4.0};
    cout << "Produit scalaire partiel = "
         << partial_dot(C.begin(), C.end(), D.begin(), D.end()) << endl;

    return 0;
}

