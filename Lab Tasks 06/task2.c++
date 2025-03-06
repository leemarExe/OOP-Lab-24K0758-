#include<iostream>
#include<string>
using namespace std;

class Vehicle{
    protected:
    string brand;
    int speed;
    public:
    Vehicle(string br, int sp){
        brand = br;
        speed = sp;
    }
    virtual void displayDetails(){
        cout<<"Brand Name: " << brand << endl;
        cout<<"Car Speed: " << speed << endl;
    }
};
class Car : public Vehicle{
    int seats;
    public:
    Car(string br, int sp, int sts) : Vehicle(br ,sp){
        seats = sts;
    }

    void displayDetails() override{
        Vehicle::displayDetails();
        cout<<"Seating Capacity: "<<seats << endl;
    }
};
class ElectricCar : public Car{
    int batteryLife;
    public:
    ElectricCar(string br, int sp, int btl, int sts) : Car(br, sp, sts){
        batteryLife = btl;
    }

    void displayDetails() override{
        Car::displayDetails();
        cout<<"Battery Life: "<< batteryLife << endl;
    }
};


int main(){
    string brand;
    int speed, seats, batteryLife;

    cout << "Enter Car Brand: ";
    cin >> brand;
    cout << "Enter Car Speed (km/h): ";
    cin >> speed;
    cout << "Enter Seating Capacity: ";
    cin >> seats;
    cout << "Enter Battery Life (hours): ";
    cin >> batteryLife;


    ElectricCar myCar(brand, speed, seats, batteryLife);

    cout << "Electric Car Details:\n";
    myCar.displayDetails();

    return 0;

}