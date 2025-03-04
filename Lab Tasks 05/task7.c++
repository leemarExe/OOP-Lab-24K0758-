#include<iostream>
#include<string>
using namespace std;

class Product{
    string name, id;
    int quantity;
    public:
    Product(){}
    Product(string n, string i, int q){
        name = n;
        id = i;
        quantity = q;
    }
    string getName() const{
        return name;
    }
    string getId() const{
        return id;
    }
    int getQuantity() const{
        return quantity;
    }
    void display() const {
        cout << "ID: " << id << ", Name: " << name << ", Quantity: " << quantity << endl;
    }
};
class Warehouse{
    Product* inventory;
    int productCount;
    int maxProducts;
    public:
    Warehouse(int mp){
        productCount = 0;
        maxProducts = mp;
        inventory = new Product[mp];
    }
    ~Warehouse(){
        delete[] inventory;
    }
    void addProduct(string id, string name, float quantity){
        if(productCount < maxProducts){
            inventory[productCount] = Product(name, id, quantity);
            productCount += 1;
        }
        else{
            cout<<"The Inventory is full!\n";
        }
    }
    void searchById(string id){
        for(int i = 0 ; i < productCount ; i++){
            if(inventory[i].getId() == id){
               inventory[i].display();
                return;
            }
        }
        cout<<"Product ID: " <<  id << " not found in the Inventory.\n";
    }
    void sortProducts(){
        for(int i = 0 ; i < productCount - 1; i++){
            for(int j = i + 1 ; j < productCount ; j++){
                if(inventory[i].getName() > inventory[i + 1].getName()){
                    swap(inventory[i], inventory[i+1]);
                }
            }
        }
    }
    void displayAllProducts() {
        if (productCount == 0) {
            cout << "No products in inventory.\n";
            return;
        }
        for (int i = 0; i < productCount; i++) {
            inventory[i].display();
        }
    }

};

int main(){
    Warehouse warehouse(10);

    warehouse.addProduct("101", "Laptop", 5);
    warehouse.addProduct("102", "Chair", 20);
    warehouse.addProduct("103", "Apple", 50);

    cout << "\nProducts before sorting:\n";
    warehouse.displayAllProducts();

    warehouse.sortProducts();
    
    cout << "Products after sorting:\n";
    warehouse.displayAllProducts();

    cout << "Searching for product with ID 102:\n";
    warehouse.searchById("102");
    return 0;
}