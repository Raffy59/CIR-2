#ifndef CHIFFREMENT_HPP
#define CHIFFREMENT_HPP

#include <iostream>
#include <string>

class Chiffrement {
public:
    Chiffrement();
    Chiffrement(std::string texte);
    virtual ~Chiffrement() = default;

    std::string texte_;

    virtual std::string chiffrement(const std::string &texte_a_chiffrer) const = 0;
    virtual std::string dechiffrement(const std::string &texte_a_dechiffrer) const = 0;

    friend std::ostream& operator<<(std::ostream& out, const Chiffrement &chf);
    friend std::istream& operator>>(std::istream& in, Chiffrement &chf);
};

class Chiffrement_Cesar : public Chiffrement {
private:
    const int nb_decal_;

public:
    Chiffrement_Cesar(const int &nb_decal);
    std::string chiffrement(const std::string &_txt_) const override;
    std::string dechiffrement(const std::string &_txt_) const override;
};

class Chiffrement_Vigenere : public Chiffrement {
private:
    const std::string password_;

public:
    Chiffrement_Vigenere(const std::string &password);
    std::string chiffrement(const std::string &_txt_) const override;
    std::string dechiffrement(const std::string &_txt_) const override;
};

// fonctions utilitaires
int decalage(const int& lettre,const int& nb_decal);
int decalage_inverse(const int& lettre,const int& nb_decal);

#endif

