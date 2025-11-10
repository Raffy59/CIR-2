#include "Animaux.hpp"

// Constructeurs de Animaux
Animaux::Animaux() : pattes(10), dents(20), os(200), especes("singe") {}

Animaux::Animaux(int pattes, int dents, int os, std::string especes)
    : pattes(pattes), dents(dents), os(os), especes(especes) {}

void Animaux::setEspeces(std::string especes) {
    this->especes = especes;
}

std::string Animaux::getEspeces() const {
    return especes;
}

// Constructeurs de Mamifere
Mamifere::Mamifere() : Animaux(), oeuf(0) {}

Mamifere::Mamifere(int pattes, int dents, int os, std::string especes, int oeuf)
    : Animaux(pattes, dents, os, especes), oeuf(oeuf) {}

int Mamifere::getOeuf() const {
    return oeuf;
}

void Mamifere::setOeuf(int oeuf) {
    this->oeuf = oeuf;
}


