#include <iostream>
#include "Animaux.hpp"

int main() {
    Animaux singe;
    std::cout << "Espèce par défaut : " << singe.getEspeces() << std::endl;

    singe.setEspeces("humain");
    std::cout << "Nouvelle espèce : " << singe.getEspeces() << std::endl;

    Mamifere humain(2, 32, 206, "humain", 2);
    std::cout << "Mamifère : " << humain.getEspeces()
              << " - Œufs : " << humain.getOeuf() << std::endl;


    humain.setEspeces("singe");
    std::cout << "Mamifère : " << humain.getEspeces()
              << " - Œufs : " << humain.getOeuf() << std::endl;

    return 0;
}

