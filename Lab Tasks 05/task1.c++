#include<iostream>
#include<string>
using namespace std;

class Apartment{
    string id;
    string address;
    string* ownerName;
    public:
    Apartment(string i, string add, string oN){
        id = i;
        address = add;
        ownerName = new string(oN);
    }
    Apartment(Apartment &a){
        id = a.id;
        address = a.address;
        ownerName = a.ownerName;
    }
    ~Apartment(){
        delete ownerName;
    }
    void display() const {
        cout <<"Apartment ID: "<<id << endl;
        cout <<"Address: " << address<< endl;
        cout <<"Owner: " << *ownerName << endl;
    }

};


int main(){
    Apartment apt1("1001","123 Street","rameel ");
    apt1.display();
    
    Apartment apt2 = apt1;
    apt2.display();


    return 0;
}