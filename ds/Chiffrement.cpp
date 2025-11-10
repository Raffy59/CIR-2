#include <iostream>
#include "Chiffrement.hpp"

Chiffrement::Chiffrement() : texte_("Neuille") {}
Chiffrement::Chiffrement(std::string texte) : texte_(texte) {}

Chiffrement_Cesar::Chiffrement_Cesar(const int &nb_decal) : nb_decal_(nb_decal) {}
Chiffrement_Vigenere::Chiffrement_Vigenere(const std::string &password) : password_(password) {}

std::ostream& operator<<(std::ostream& out, const Chiffrement &chf) {
    out << chf.dechiffrement(chf.texte_);
    return out;
}

std::istream& operator>>(std::istream& in, Chiffrement &chf) {
    std::string texte;
    in >> texte;
    chf.texte_ = chf.chiffrement(texte);
    return in;
}

int decalage(const int& lettre,const int& nb_decal){
    return ( ( (lettre - 'A' + nb_decal) % 26 + 26 ) % 26 ) + 'A';
}

int decalage_inverse(const int& lettre,const int& nb_decal){
    return ( ( (lettre - 'A' - nb_decal) % 26 + 26 ) % 26 ) + 'A';
}

std::string Chiffrement_Cesar::chiffrement(const std::string &_txt_) const {
    std::string resultat;
    for (char c : _txt_) {
        resultat += (c == ' ') ? ' ' : decalage(c, nb_decal_);
    }
    return resultat;
}

std::string Chiffrement_Cesar::dechiffrement(const std::string &_txt_) const {
    std::string resultat;
    for (char c : _txt_) {
        resultat += (c == ' ') ? ' ' : decalage_inverse(c, nb_decal_);
    }
    return resultat;
}

std::string Chiffrement_Vigenere::chiffrement(const std::string& _txt_) const {
    std::string t;
    for (long unsigned i = 0; i < _txt_.length(); i++) {
        if (_txt_[i] == ' ') {
            t += ' ';
        } else {
            int decal = password_[i % password_.length()] - 'A';
            t += decalage(_txt_[i], decal);
        }
    }
    return t;
}

std::string Chiffrement_Vigenere::dechiffrement(const std::string& _txt_) const {
    std::string t;
    for (long unsigned i = 0; i < _txt_.length(); i++) {
        if (_txt_[i] == ' ') {
            t += ' ';
        } else {
            int decal = password_[i % password_.length()] - 'A';
            t += decalage_inverse(_txt_[i], decal);
        }
    }
    return t;
}

