#include<iostream>
#include"Fraction.hpp"

Fraction::Fraction(): num(0),den(1){std::cout<<"Construceur par défaut crée"<<std::endl;}
Fraction::Fraction(int num,int den):num(num),den(den){std::cout<<"Construceur par valeur crée"<<std::endl;}
Fraction::Fraction(Fraction& C){
   this->den=C.den;
   this->num=C.num;
}

// Fraction::~Fraction(){
//     delete this;
// }

void Fraction::setnum(int value){
    this->num = value;
}

int Fraction::getnum(){
    return this->num;
}


void Fraction::setden(int value){
    this->den = value;
}

int Fraction::getden(){
    return this->den;
}

Fraction Fraction::operator*(const Fraction &other) const {
    Fraction resultat;
    resultat.num = this->num* other.num;
    resultat.den = this->den* other.den;
    return resultat;
}


void Fraction::print(){
    std::cout<<this->num << "/" << this->den <<"en mode bidon"<< std::endl;
}


std::ostream& operator<<(std::ostream& flux,const Fraction& fraction){
    flux << fraction.num << "/" << fraction.den <<"en mode smart"<< std::endl;
    return flux;
}

Fraction::operator double(){
    return (float)this->num / (float)this->den;
}
