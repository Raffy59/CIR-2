#ifndef ANIMAUX_HPP
#define ANIMAUX_HPP

#include <iostream>
#include <string>

class Animaux {
protected:
    int pattes;
    int dents;
    int os;
    std::string especes;

public:
    Animaux();
    Animaux(int pattes, int dents, int os, std::string especes);

    std::string getEspeces() const;
    void setEspeces(std::string especes);
};

class Mamifere : public Animaux {
private:
    int oeuf;

public:
    Mamifere();
    Mamifere(int pattes, int dents, int os, std::string especes, int oeuf);

    int getOeuf() const;
    void setOeuf(int oeuf);
};

#endif

