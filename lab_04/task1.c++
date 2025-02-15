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
    Car(){
        brand = "Unknown";
        model = "Generic";
        price = 0.0;
        availability = true;
    }
    void updateDetails(string b, string m, float p){
        brand = b;
        model = m;
        price = p;
    }
    bool checkAvailability(){
        return availability;
    }
    void rentCar(){
        if(availability){
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
    Car myCar;
    myCar.displayDetails();
    
    cout << "Updating car details...\n";
    myCar.updateDetails("Toyota", "Corolla", 5000.0);
    myCar.displayDetails();

    if(myCar.checkAvailability()){
        cout<<"\nCar available for rent.\n";
    }
    else{
        cout<<"\nCar available for rent.\n";
    }
    
    cout << "\nProcessing rental request...\n";
    myCar.rentCar();
    myCar.displayDetails();
    
    myCar.rentCar();
    
    return 0;
    
}