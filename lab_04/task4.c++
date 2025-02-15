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

public:
    Car() {
        brand = "Unknown";
        model = "Generic";
        price = 0.0;
        availability = true;
        revenue = new float(0.0);
    }

    Car(string b, string m, float p, bool a) {
        brand = b;
        model = m;
        price = p;
        availability = a;
        revenue = new float(0.0);
    }
    
    Car(const Car &other) {
        brand = other.brand;
        model = other.model;
        price = other.price;
        availability = other.availability;
        revenue = other.revenue;
        cout << "Copy constructor called: Car copied successfully.\n";
    }

    ~Car() {
        cout << "Destructor called: " << brand << " " << model << " is being deleted.\n";
        delete revenue;
    }

    void updateDetails(string b, string m, float p) {
        brand = b;
        model = m;
        price = p;
    }

    bool checkAvailability() {
        return availability;
    }

    void rentCar(int days) {
        float rentPrice;
        if(availability) {
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
    Car originalCar("Toyota", "Corolla", 5000.0, true);
    
    cout << "Original Car Details:\n";
    originalCar.displayDetails();

    Car copiedCar(originalCar);
    
    cout << "\nCopied Car Details (Before Changes):\n";
    copiedCar.displayDetails();

    cout << "\nUpdating Original Car Details...\n";
    originalCar.updateDetails("Honda", "Civic", 6000.0);

    cout << "\nOriginal Car Details (After Changes):\n";
    originalCar.displayDetails();

    cout << "\nCopied Car Details: \n";
    copiedCar.displayDetails();

    originalCar.rentCar(15);
    originalCar.checkRevenue();
    copiedCar.rentCar(10);
    copiedCar.checkRevenue();

    return 0;
}
