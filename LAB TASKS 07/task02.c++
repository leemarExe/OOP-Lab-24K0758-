#include <iostream>
#include <string>
using namespace std;

class Product {
protected:
    string productID, productName;
    double price;
    int stockQuantity;

public:
    Product(string id, string name, double p, int s = 0)
        : productID(id), productName(name), price(p), stockQuantity(s) {}

    virtual double applyDiscount() const {
        return price;
    }

    virtual double calculateTotalPrice(int quantity) const {
        return applyDiscount() * quantity;
    }

    virtual void displayProductInfo() const {
        cout << "Product ID: " << productID << endl;
        cout << "Product Name: " << productName << endl;
        cout << "Price: $" << price << endl;
        cout << "Quantity: " << stockQuantity << " units" << endl;
    }

    friend ostream& operator<<(ostream& out, const Product& p) {
        p.displayProductInfo();
        return out;
    }

    Product operator+(const Product& other) {
        return Product(
            productID + "+" + other.productID,
            productName + " & " + other.productName,
            price + other.price,
            stockQuantity + other.stockQuantity
        );
    }
};

class Electronics : public Product {
    string brand;
    int warrantyPeriod;

public:
    Electronics(string id, string name, double p, int s, string b, int warr)
        : Product(id, name, p, s), brand(b), warrantyPeriod(warr) {}

    void displayProductInfo() const override {
        Product::displayProductInfo(); 
        cout << "Brand: " << brand << endl;
        cout << "Warranty Period: " << warrantyPeriod << " years\n";
    }
};

class Clothing : public Product {
    string size, color, fabricMaterial;

public:
    Clothing(string id, string name, double price, int quantity, string size, string color, string fabric)
        : Product(id, name, price, quantity), size(size), color(color), fabricMaterial(fabric) {}

    double applyDiscount() const override {
        return price * 0.9; 
    }

    void displayProductInfo() const override {
        Product::displayProductInfo();
        cout << "Size: " << size << endl;
        cout << "Color: " << color << endl;
        cout << "Fabric: " << fabricMaterial << endl;
    }
};

class FoodItem : public Product {
    string expirationDate;
    int calories;

public:
    FoodItem(string id, string name, double price, int quantity, string expiry, int cal)
        : Product(id, name, price, quantity), expirationDate(expiry), calories(cal) {}

    double calculateTotalPrice(int quantity) const override {
        double discount = quantity >= 10 ? 0.85 : 1.0;
        return price * discount * quantity;
    }

    void displayProductInfo() const override {
        Product::displayProductInfo();
        cout << "Expires: " << expirationDate << endl;
        cout << "Calories: " << calories << " kcal" << endl;
    }
};

class Book : public Product {
    string author, genre;

public:
    Book(string id, string name, double price, int quantity, string auth, string gen)
        : Product(id, name, price, quantity), author(auth), genre(gen) {}

    void displayProductInfo() const override {
        Product::displayProductInfo();
        cout << "Author: " << author << endl;
        cout << "Genre: " << genre << endl;
    }
};

int main() {
    Electronics e("E100", "Smartphone", 999.99, 5, "Samsung", 2);
    Clothing c("C200", "T-Shirt", 29.99, 15, "M", "Blue", "Cotton");
    FoodItem f("F300", "Pasta Pack", 2.5, 30, "2025-06-01", 400);
    Book b("B400", "C++ Programming", 49.99, 20, "Bjarne Stroustrup", "Programming");

    cout << "--- Electronics ---\n" << e << endl;
    cout << "--- Clothing (with 10% discount) ---\n" << c << endl;
    cout << "Total Price for 2: $" << c.calculateTotalPrice(2) << endl;

    cout << "--- Food Item (bulk discount if >=10) ---\n" << f << endl;
    cout << "Total Price for 12: $" << f.calculateTotalPrice(12) << endl;

    cout << "--- Book ---\n" << b << endl;

    cout << "--- Combined Product (Clothing + Book) ---\n";
    Product combo = c + b;
    cout << combo;

    return 0;
}
