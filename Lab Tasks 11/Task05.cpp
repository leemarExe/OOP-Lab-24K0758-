#include<iostream>
#include<string>
#include<exception>
using namespace std;

class NegativeStockException : public  exception{};
class OverCapacityException : public  exception{};

template<typename T>
class InventoryItem{
    T* stock;
    static int maxCapacity;
    public:
    InventoryItem(){
        stock = nullptr;
    }
    void setStock(T* t){
        if(*t < 0){
            throw NegativeStockException();
        }
        else if(*t >100){
            throw OverCapacityException();
        }
        else{
            stock = t;
        }
    }
};

template<typename T>
int InventoryItem<T> :: maxCapacity = 100;


int main(){
    int* ptr1;
    int a = -5;
    ptr1 = &a;

    int* ptr2;
    int b = 120;
    ptr2 = &b;

    InventoryItem<int> II1;
    try{
        cout << "Attempting to set stock to -5..." << endl;
        II1.setStock(ptr1);
    }
    catch(const NegativeStockException& e){
        cout << "Caught NegativeStockException - what(): " << e.what() << endl;
    }

    InventoryItem<int> II2;
    try{
        cout << "Attempting to set stock to 120 (max 100)..." << endl;
        II2.setStock(ptr2);
    }
    catch(const OverCapacityException& e){
        cout << "Caught OverCapacityException - what(): " << e.what() << endl;
    }

}