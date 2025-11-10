#include <iostream>
#include "Chiffrement.hpp"

int main() {
    Chiffrement_Cesar cesar(5);
    Chiffrement* chiff = &cesar;

    std::cout << "=== Chiffrement César ===" << std::endl;
    std::cout << "Entrez un mot en MAJUSCULES : ";
    std::cin >> *chiff;
    std::cout << "Texte chiffré : " << chiff->texte_ << std::endl;
    std::cout << "Texte déchiffré : " << *chiff << std::endl;

    std::cout << "\n=== Chiffrement Vigenere ===" << std::endl;
    Chiffrement_Vigenere vigenere("AB");
    Chiffrement* chiff2 = &vigenere;
    std::cout << "Entrez un mot en MAJUSCULES : ";
    std::cin >> *chiff2;
    std::cout << "Texte chiffré : " << chiff2->texte_ << std::endl;
    std::cout << "Texte déchiffré : " << *chiff2 << std::endl;

    return 0;
}

