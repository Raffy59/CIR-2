#include<iostream>

class Fraction{
    private:
        int num;
        int den;
    public:
        Fraction();
        Fraction(int num,int den);
        Fraction(Fraction& C);
        // ~Fraction();
        int getnum();
        int getden();
        void setnum(int num);
        void setden(int den);
        Fraction operator*(const Fraction &other) const;
        void print();
        friend std::ostream& operator<<(std::ostream& flux,const Fraction& fraction);
        operator double();
};
