#include<iostream>
#include<string>
using namespace std;

class Person{
    protected:
    string name;
    int age;
    public:
    Person(string n, int a){
        name = n;
        age = a;
    }
    virtual void displayDetails(){
        cout<<"Name: " << name << endl;
        cout<<"Age: " << age << endl;
    }
};
class Teacher : public Person{
    protected:
    string subject;
    public:
    Teacher(string n, int a, string sub) : Person(n, a), subject(sub){}
    void displayDetails() override{
        Person::displayDetails();
        cout<<"Subject: " << subject << endl;
    }
};
class Researcher : public Teacher{
    protected:
    string researchArea;
    public:
    Researcher(string n, int a, string sub, string rArea) : Teacher(n, a ,sub), researchArea(rArea){}
    void displayDetails() override{
        Teacher::displayDetails();
        cout<<"Research Area: " << researchArea << endl;
    }
};
class Professor : public Researcher{
    int publications;
    public:
    Professor(string n, int a, string sub, string rArea, int pub) : Researcher(n, a ,sub, rArea), publications(pub){}
    void displayDetails() override{
        Researcher::displayDetails();
        cout<<"Total Publications: " << publications << endl;
    }
};

int main(){
    string name, subject, researchArea;
    int age, publications;

    cout<<"Enter the Professor's Name: \n";
    getline(cin, name);

    cout<<"Enter the Professor's Age: \n";
    cin>>age;
    cin.ignore();

    cout<<"What subject does the Professor teach? \n";
    getline(cin, subject);

    cout<<"What is the Professor's research Area? \n";
    getline(cin, researchArea);

    cout<<"Enter the Professor's total number of Publications: \n";
    cin>>publications;

    Professor p(name, age, subject, researchArea, publications);
    p.displayDetails();


    return 0;
}