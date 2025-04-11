#include <iostream>
using namespace std;

class Account {
private:
    string accountNumber;
    double balance;

public:
    Account(string accNum, double bal) : accountNumber(accNum), balance(bal) {}

    friend class Manager;
    friend void transferFunds(Account& from, Account& to, double amount);
};

class Manager {
public:
    void displayAccountDetails(const Account& acc) {
        cout << "Account Number: " << acc.accountNumber << "\nBalance: $" << acc.balance << endl;
    }

    void deposit(Account& acc, double amount) {
        acc.balance += amount;
    }

    void withdraw(Account& acc, double amount) {
        if (acc.balance >= amount) {
            acc.balance -= amount;
        } else {
            cout << "Insufficient funds!" << endl;
        }
    }
};

void transferFunds(Account& from, Account& to, double amount) {
    if (from.balance >= amount) {
        from.balance -= amount;
        to.balance += amount;
        cout << "Transfer successful!" << endl;
    } else {
        cout << "Transfer failed: Insufficient funds!" << endl;
    }
}

int main() {
    Account acc1("A1001", 1000.0);
    Account acc2("A1002", 500.0);
    
    Manager mgr;
    
    mgr.displayAccountDetails(acc1);
    mgr.displayAccountDetails(acc2);

    mgr.deposit(acc1, 200.0);
    mgr.withdraw(acc2, 100.0);

    transferFunds(acc1, acc2, 300.0);

    mgr.displayAccountDetails(acc1);
    mgr.displayAccountDetails(acc2);

    return 0;
}
