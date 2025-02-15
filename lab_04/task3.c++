#include <iostream>
#include <string>

using namespace std;

class Car {
private:
    string brand;
    string model;
    float price;
    bool availability;

public:
    Car() {
        brand = "Unknown";
        model = "Generic";
        price = 0.0;
        availability = true;
    }

    Car(string b, string m, float p, bool a) {
        brand = b;
        model = m;
        price = p;
        availability = a;
    }

    Car(const Car &other) {
        brand = other.brand;
        model = other.model;
        price = other.price;
        availability = other.availability;
        cout << "Copy constructor called: Car copied successfully.\n";
    }

    ~Car() {
        cout << "Destructor called: " << brand << " " << model << " is being deleted.\n";
    }

    void updateDetails(string b, string m, float p) {
        brand = b;
        model = m;
        price = p;
    }

    bool checkAvailability() {
        return availability;
    }

    void rentCar() {
        if (availability) {
            cout << "Car rented successfully!\n";
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

    return 0;
}
