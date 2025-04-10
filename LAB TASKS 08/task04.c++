#include <iostream>
#include <string>
using namespace std;

class Car {
private:
    string model;
    double price;

public:
    Car(string m, double p) : model(m), price(p) {}

    friend class InventoryManager;
    friend void comparePrice(const Car& car1, const Car& car2);
};

class InventoryManager {
public:
    void updatePrice(Car& car, double newPrice) {
        car.price = newPrice;
    }

    void displayDetails(const Car& car) {
        cout << "Model: " << car.model << ", Price: $" << car.price << endl;
    }
};

void comparePrice(const Car& car1, const Car& car2) {
    if (car1.price > car2.price) {
        cout << car1.model << " is more expensive than " << car2.model << endl;
    } else if (car2.price > car1.price) {
        cout << car2.model << " is more expensive than " << car1.model << endl;
    } else {
        cout << "Both cars have the same price" << endl;
    }
}

int main() {
    Car car1("Toyota Camry", 25000.0);
    Car car2("Honda Accord", 27000.0);

    InventoryManager mgr;
    mgr.displayDetails(car1);
    mgr.displayDetails(car2);

    comparePrice(car1, car2);

    mgr.updatePrice(car1, 26000.0);
    cout << "After price update:" << endl;
    mgr.displayDetails(car1);

    comparePrice(car1, car2);

    return 0;
}