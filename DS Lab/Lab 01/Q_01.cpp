#include <iostream>
using namespace std;

class BankAccount {
    double balance;

public:
    BankAccount() {
        balance = 0.0;
    }

    BankAccount(const BankAccount& bankAccount) {
        this->balance = bankAccount.balance;
    }

    BankAccount(double balance) {
        this->balance = balance;
    }

    double getBalance() {
        return balance;
    }

    void deposit(double amount) {
        if(amount <= 0) {
            cout << "\nInvalid Amount entered for depositing!! \n";
            return;
        }

        balance += amount;
        cout << "\nDeposited successfully! \n";
    }

    void withdraw(double amount) {
        if(amount <= 0) {
            cout << "\nInvalid Amount entered for withdrawal!! \n";
            return;
        }

        if(amount > balance) {
            cout << "\nInsufficient Balance to withdraw!! \n";
            return;
        }

        balance -= amount;
        cout << "\n\nWithdrawal successful!";
    }
};

int main() {
    
    BankAccount account1;
    cout << "Balance of Account1: " << account1.getBalance();

    BankAccount account2(1000);
    cout << "\nBalance of Account2: " << account2.getBalance();

    BankAccount account3 = account2;

    account3.withdraw(200);

    cout << "\n\nBalance of Account3: " << account3.getBalance();
    cout << "\nBalance of Account2: " << account2.getBalance();

    return 0;
}
