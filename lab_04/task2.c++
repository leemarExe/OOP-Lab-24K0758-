#include<iostream>
#include<string>
using namespace std;

class Car{
private:
    string brand;
    string model;
    float price;
    bool availability;
public:
    Car(){}
    Car(string b, string m, float p, bool a){
        brand = b;
        model = m;
        price = p;
        availability = a;
    }
    void updateDetails(string b, string m, float p, bool a){
        brand = b;
        model = m;
        price = p;
        availability = a;
    }
    bool checkAvailability(){
        return availability;
    }
    void rentCar(int d){
        float discountedPrice;
        if(availability){
            if(d > 5){
                discountedPrice = price * 0.95;
                cout <<"You get a 5% discount\n";
                cout<<"Final Price: "<< discountedPrice << endl;
            }
            if(d > 10){
                discountedPrice = price * 0.9;
                cout <<"You get a 10% discount\n";
                cout<<"Final Price: "<< discountedPrice << endl;
            }
            cout<<"Car rented succesfully!\n";
            availability = false;
        }
        else{
            cout<<"Car already rented out.\n";
        }
    }
    void displayDetails(){
        cout<<"Car Brand: " << brand << endl;
        cout<<"Car Model: " << model << endl;
        cout<<"Price: " << price << endl;
        if(availability){
            cout<<"Car Available for rent.\n";
        }
        else{
            cout<<"Car already rented out\n";
        }
    }


};


int main(){
    Car myCar("Toyota" ,"Corolla", 5000.0, true);
    myCar.displayDetails();
    
    cout << "\nProcessing rental request...\n";
    myCar.rentCar(7);
    myCar.displayDetails();
    
    
    cout<<"\nUpdating Details...\n";
    myCar.updateDetails("Toyota", "Corolla", 5000.0, true);
    myCar.displayDetails();
    if(myCar.checkAvailability()){
        cout<<"\nCar available for rent.\n";
    }
    else{
        cout<<"\nCar available for rent.\n";
    }
    cout << "\nTrying to rent again...\n";
    myCar.rentCar(11);
    
    return 0;
    
}