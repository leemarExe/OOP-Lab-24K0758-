#include <iostream>
using namespace std;

class Patient
{
protected:
    string name;
    string id;

public:
    Patient(string n, string i) : name(n), id(i)
    {
    }
    virtual void displayTreatment() = 0;
    virtual void calculateCost() = 0;
};

class Inpatient : public Patient
{
public:
    Inpatient(string n, string i) : Patient(n, i)
    {
    }
    void displayTreatment()
    {
        cout << "In patient: " << name << "\nID: " << id << endl;
    }
    void calculateCost()
    {
        cout << "Cost: $13000" << endl;
    }
};

class Outpatient : public Patient
{
public:
    Outpatient(string n, string i) : Patient(n, i)
    {
    }
    void displayTreatment()
    {
        cout << "Out patient: " << name << "\nID: " << id << endl;
    }
    void calculateCost()
    {
        cout << "Cost: $2300" << endl;
    }
};

int main()
{
    Inpatient ip("Rameel", "A001");
    Outpatient op("Sohail", "X001");

    Patient *p1 = &ip;
    Patient *p2 = &op;

    p1->displayTreatment();
    p1->calculateCost();
    p2->displayTreatment();
    p2->calculateCost();
}