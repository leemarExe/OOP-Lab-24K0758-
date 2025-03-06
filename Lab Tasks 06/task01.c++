#include <iostream>
#include <string>

using namespace std;


class Employee {
protected:
    string name;
    float salary;

public:
    Employee(string n, float s) {
        name = n;
        salary = s;
    }

    virtual void displayDetails() {
        cout << "Employee Name: " << name << endl;
        cout << "Salary: $" << salary << endl;
    }
};

class Manager : public Employee {
    float bonus;
public:
    Manager(string n, float s, float b) : Employee(n, s){
        bonus = b;
    }

    void displayDetails() override {
        cout << "Manager Name: " << name << endl;
        cout << "Salary: $" << salary << endl;
        cout << "Bonus: $" << bonus << endl;
    }
};

int main() {
    string name;
    float salary, bonus;

    cout << "Enter Manager Name: ";
    getline(cin, name);
    cout << "Enter Salary: ";
    cin >> salary;
    cout << "Enter Bonus: ";
    cin >> bonus;


    Manager mgr(name, salary, bonus);

    cout << "Manager Details:\n";
    mgr.displayDetails();

    return 0;
}

