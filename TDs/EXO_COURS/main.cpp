#include <iostream>
#include <string>

class Quadrupede {
public:
    Quadrupede(const std::string& in_nom) : nom(in_nom) {
        std::cout << "Naissance d'un quadrupede" << std::endl;
    }
    virtual ~Quadrupede() {
        std::cout << "Mort d'un quadrupede" << std::endl;
    }

    virtual void speak() = 0; // méthode pure virtuelle

    const std::string& getNom() const {
        return nom;
    }

    void setNom(const std::string& nom) {
        this->nom = nom;
    }

protected:
    std::string nom;
};

class Chien : public Quadrupede {
public:
    Chien(const std::string& in_nom) : Quadrupede(in_nom) {
        std::cout << "Naissance d'un chien." << std::endl;
    }
    ~Chien() override {
        std::cout << "Mort d'un chien." << std::endl;
    }
    void speak() override {
        std::cout << nom << " dit : Ouaf ouaf et pis ouaf" << std::endl;
    }
};

class Chat : public Quadrupede {
public:
    Chat(const std::string& in_nom) : Quadrupede(in_nom) {
        std::cout << "Naissance d'un chat." << std::endl;
    }
    ~Chat() override {
        std::cout << "Mort d'un chat." << std::endl;
    }
    void speak() override {
        std::cout << nom << " dit : Miaou et pis c'est tout." << std::endl;
    }
    void ou_suis_je() {
        std::cout << nom << " miaule a la maison." << std::endl;
    }
};

int main() {
    constexpr size_t nb_quadrupede = 4;
    Quadrupede* tableau_de_quadrupede[nb_quadrupede];

    // Création des animaux
    tableau_de_quadrupede[0] = new Chat("Felix");
    tableau_de_quadrupede[1] = new Chien("Albert");
    tableau_de_quadrupede[2] = new Chat("Simba");
    tableau_de_quadrupede[3] = new Chien("Stein");

    // Appel polymorphe
    for (size_t iquad = 0; iquad < nb_quadrupede; ++iquad) {
        tableau_de_quadrupede[iquad]->speak();
    }

    // Libération mémoire
    for (size_t iquad = 0; iquad < nb_quadrupede; ++iquad) {
        delete tableau_de_quadrupede[iquad];
    }

    return 0;
}
