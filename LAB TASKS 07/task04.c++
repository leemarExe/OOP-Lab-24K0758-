#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name, contactNumber, address;
    int age;

public:
    Person(string n, int a, string c, string addr = "") : name(n), age(a), contactNumber(c), address(addr) {}

    virtual void displayInfo() const {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Contact: " << contactNumber << endl;
        cout << "Address: " << address << endl;
    }

    virtual void updateInfo(string n, int a, string c, string addr = "") {
        name = n;
        age = a;
        contactNumber = c;
        address = addr;
    }
};

class Patient : public Person {
    string patientID, medicalHistory, doctorAssigned;

public:
    Patient(string n, int a, string c, string addr, string id, string hist, string doc) : Person(n, a, c, addr), patientID(id), medicalHistory(hist), doctorAssigned(doc) {}

    void displayInfo() const override {
        Person::displayInfo();
        cout << "Patient ID: " << patientID << endl;
        cout << "Medical History: " << medicalHistory << endl;
        cout << "Doctor Assigned: " << doctorAssigned << endl;
    }
};

class Doctor : public Person {
    string specialization;
    double consultationFee;
    string patientsList[5];
    int patientCount;

public:
    Doctor(string n, int a, string c, string addr, string spec, double fee, string plist[], int count) : Person(n, a, c, addr), specialization(spec), consultationFee(fee), patientCount(count) {
        for (int i = 0; i < count && i < 5; ++i) {
            patientsList[i] = plist[i];
        }
    }

    void displayInfo() const override {
        Person::displayInfo();
        cout << "Specialization: " << specialization << endl;
        cout << "Consultation Fee: $" << consultationFee << endl;
        cout << "Patients List: ";
        for (int i = 0; i < patientCount; ++i) {
            cout << patientsList[i] << " ";
        }
        cout << endl;
    }
};

class Nurse : public Person {
    string assignedWard, shiftTimings;

public:
    Nurse(string n, int a, string c, string addr, string ward, string shift) : Person(n, a, c, addr), assignedWard(ward), shiftTimings(shift) {}

    void displayInfo() const override {
        Person::displayInfo();
        cout << "Assigned Ward: " << assignedWard << endl;
        cout << "Shift Timings: " << shiftTimings << endl;
    }
};

class Administrator : public Person {
    string department;
    double salary;

public:
    Administrator(string n, int a, string c, string addr, string dept, double sal) : Person(n, a, c, addr), department(dept), salary(sal) {}

    void updateInfo(string n, int a, string c, string addr, string dept, double sal) {
        Person::updateInfo(n, a, c, addr);
        department = dept;
        salary = sal;
    }

    void displayInfo() const override {
        Person::displayInfo();
        cout << "Department: " << department << endl;
        cout << "Salary: $" << salary << endl;
    }
};

int main() {
    Patient p("Ali", 30, "0345123456", "Lahore", "P001", "Diabetes", "Dr. Ahmed");

    string plist[2] = { "P001", "P002" };
    Doctor d("Dr. Ahmed", 45, "0333765432", "Lahore", "Cardiology", 1500, plist, 2);

    Nurse n("Fatima", 28, "0300123456", "Lahore", "Ward A", "Day Shift");
    Administrator a("Zeeshan", 40, "0312345678", "Lahore", "HR", 75000);

    p.displayInfo();
    cout << endl;
    d.displayInfo();
    cout << endl;
    n.displayInfo();
    cout << endl;
    a.displayInfo();

    return 0;
}
