#include<iostream>
#include<string>
using namespace std;

class Account{
    protected:
    int accNumber;
    float balance;
    public:
    Account(int acc, float b){
        accNumber = acc;
        balance = b;
    }
    virtual void displayDetails(){
        cout<<"Account Number: " << accNumber << endl;
        cout<<"Account Balance: $" << balance << endl;
    }
};

class SavingsAccount : protected Account{
    float interestRate;
    public:
    SavingsAccount(int acc, float balance, float IR) : Account(acc, balance), interestRate(IR){}
    void displayDetails() override{
        Account :: displayDetails();
        cout <<"Interest Rate: " << interestRate <<"%" << endl;
    }
};

class CheckingAccount : protected Account{
    float overdraftLimit;
    public:
    CheckingAccount(int acc, float balance, float OL) : Account(acc, balance), overdraftLimit(OL){}
    void displayDetails() override{
        Account :: displayDetails();
        cout <<"Overdraft Limit: $" << overdraftLimit << endl;
    }
};


int main(){
    SavingsAccount s(301910, 56000.98, 3.3);
    s.displayDetails();

    CheckingAccount c(17797, 45000.67, 50000.00);
    c.displayDetails();


    return 0;
}