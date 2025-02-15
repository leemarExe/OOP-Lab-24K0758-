#include <iostream>
#include <string>

using namespace std;

class Car {
private:
    string brand;
    string model;
    float price;
    bool availability;
    float* revenue;
    int carId;

public:
    Car() {
        brand = "Unknown";
        model = "Generic";
        price = 0.0;
        availability = true;
        revenue = new float(0.0);
    }

    Car(string b, string m, float p, bool a, int id) {
        brand = b;
        model = m;
        price = p;
        availability = a;
        revenue = new float(0.0);
        carId = id;
    }
    
    Car(const Car &other) {
        brand = other.brand;
        model = other.model;
        price = other.price;
        availability = other.availability;
        revenue = other.revenue;
        carId = other.carId;
        cout << "Copy constructor called: Car copied successfully.\n";
    }

    ~Car() {
        cout << "Destructor called: " << brand << " " << model << " is being deleted.\n";
        delete revenue;
    }

    void updateDetails(string b, string m, float p, int id) {
        brand = b;
        model = m;
        price = p;
        carId = id;
    }

    bool checkAvailability() {
        return availability;
    }

    void rentCar(int days) {
        float rentPrice;
        if(availability) {
            cout<<"Car ID: "<< carId << endl;
            cout <<brand << "-" << model <<" rented successfully for " << days << " days.\n";
            rentPrice = price * days;
            cout<<"Renting Cost: " << rentPrice << endl;
            *revenue += rentPrice;
            availability = false;
        } else {
            cout << "Car already rented out.\n";
        }
    }
    
    void displayDetails() const {
        cout<<"Car ID: "<< carId << endl;
        cout << "Car Brand: " << brand << endl;
        cout << "Car Model: " << model << endl;
        cout << "Price: $" << price << endl;
        if(availability){
            cout<<"Car Available for rent.\n";
        }
        else{
            cout<<"Car already rented out\n";
        }
    }
    void checkRevenue() const{
        cout <<"Total revenue so far: $" << *revenue << endl;
        cout<<endl;
    }
};

int main() {
    Car car1("Toyota", "Corolla", 5000.0, true, 100);
    Car car2("Honda", "Civic", 6000.0, true, 101);
    
    car1.displayDetails();
    
    car1.updateDetails("Toyota", "Corolla", 5500.0, 100);
    car1.checkAvailability();
    car1.rentCar(6);
    car1.checkRevenue();
    
    car2.displayDetails();
    car2.checkAvailability();
    car2.rentCar(20);
    car2.checkRevenue();




    return 0;
}
