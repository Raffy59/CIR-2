#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Classe de base
class BankAccount {
protected:
    int number;
    string owner;
    float balance;

public:
    BankAccount(int num, string own, float bal = 0.0f)
        : number(num), owner(own), balance(bal) {
    }

    virtual ~BankAccount() {}

    void deposit(float amount) {
        if (amount > 0) {
            balance += amount;
            cout << owner << " a depose " << fixed << setprecision(2) << amount
                << " EUR. Nouveau solde : " << balance << " EUR\n";
        }
    }

    virtual bool withdrawal(float amount) {
        if (amount > 0 && balance >= amount) {
            balance -= amount;
            cout << owner << " a retire " << fixed << setprecision(2) << amount
                << " EUR. Nouveau solde : " << balance << " EUR\n";
            return true;
        }
        cout << "Retrait refuse pour " << owner << ". Solde insuffisant.\n";
        return false;
    }

    float getBalance() const { return balance; }

    string getOwner() const { return owner; }
};

// Compte courant
class CheckingAccount : public BankAccount {
private:
    float overdraftLimit;

public:
    CheckingAccount(int num, string own, float bal, float limit)
        : BankAccount(num, own, bal), overdraftLimit(limit) {
    }

    bool withdrawal(float amount) override {
        if (amount > 0 && balance + overdraftLimit >= amount) {
            balance -= amount;
            cout << owner << " (compte courant) a retire " << fixed << setprecision(2)
                << amount << " EUR. Nouveau solde : " << balance << " EUR\n";
            return true;
        }
        cout << "Retrait refuse pour " << owner << " (compte courant).\n";
        return false;
    }

    bool transfer(float amount, BankAccount& other) {
        if (withdrawal(amount)) {
            other.deposit(amount);
            cout << "Transfert de " << fixed << setprecision(2) << amount
                << " EUR de " << owner << " vers " << other.getOwner() << " reussi.\n";
            return true;
        }
        cout << "Transfert echoue.\n";
        return false;
    }
};

// Compte epargne
class SavingsAccount : public BankAccount {
private:
    float annualInterestRate; // ex: 0.05 pour 5%

public:
    SavingsAccount(int num, string own, float bal, float rate)
        : BankAccount(num, own, bal), annualInterestRate(rate) {
    }

    void depositAnnualInterest() {
        float interest = balance * annualInterestRate;
        balance += interest;
        cout << owner << " a recu " << fixed << setprecision(2) << interest
            << " EUR d'interets. Nouveau solde : " << balance << " EUR\n";
    }
};

// ======================== MAIN =========================
int main() {
    CheckingAccount compte1(1, "Alice", 500, 200);  // solde 500 EUR, decouvert autorise 200 EUR
    SavingsAccount compte2(2, "Bob", 1000, 0.05f); // solde 1000 EUR, 5% d'interet annuel

    compte1.deposit(200);        // Alice depose 200 EUR
    compte1.withdrawal(800);     // Retrait autorise avec decouvert
    compte1.withdrawal(200);     // Retrait refuse

    compte2.deposit(500);        // Bob depose 500 EUR
    compte2.depositAnnualInterest(); // Applique les interets

    compte1.transfer(100, compte2); // Alice -> Bob

    cout << "Solde final Alice : " << fixed << setprecision(2) << compte1.getBalance() << " EUR\n";
    cout << "Solde final Bob : " << fixed << setprecision(2) << compte2.getBalance() << " EUR\n";

    return 0;
}
