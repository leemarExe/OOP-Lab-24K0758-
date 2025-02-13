#include <iostream>
#include <string>

using namespace std;

class Car
{
private:
    string brand, model;
    double fuelCapacity, currentFuel;

public:
    Car(string b, string m, double cap)
    {
        brand = b;
        model = m;
        fuelCapacity = cap;
        currentFuel = cap;
    }

    void drive(double distance)
    {
        double fuelNeeded = distance * 0.1;
        if (fuelNeeded > currentFuel)
        {
            cout << "Not enough fuel to drive " << distance << " km.\n";
        }
        else
        {
            currentFuel -= fuelNeeded;
            cout << "Drove " << distance << " km. Fuel left: " << currentFuel << "L\n";
        }
        if (currentFuel < 25)
        {
            cout << "Warning: Low fuel!\n";
        }
    }

    void refuel(double amount)
    {
        if (amount + currentFuel > fuelCapacity)
        {
            currentFuel = fuelCapacity;
            cout << "Tank full!\n";
        }
        else
        {
            currentFuel += amount;
            cout << "Added " << amount << "L. Fuel now: " << currentFuel << "L\n";
        }
    }

    void status()
    {
        cout << brand << " " << model << " - Fuel: " << currentFuel << "-" << fuelCapacity << "L\n";
    }
};

int main()
{
    string b, m;
    double cap, dist, fuel;
    int choice;

    cout << "Enter car brand: ";
    getline(cin, b);
    cout << "Enter car model: ";
    getline(cin, m);
    cout << "Enter fuel capacity: ";
    cin >> cap;

    Car car(b, m, cap);

    do
    {
        cout << "\n1. Drive\n2. Refuel\n3. Check Status\n4. Exit\nChoose: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter distance to drive (km): ";
            cin >> dist;
            car.drive(dist);
            break;
        case 2:
            cout << "Enter fuel amount to refuel (L): ";
            cin >> fuel;
            car.refuel(fuel);
            break;
        case 3:
            car.status();
            break;
        case 4:
            cout << "Goodbye!\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}
