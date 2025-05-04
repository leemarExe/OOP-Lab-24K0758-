#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct InventoryItem {
    int itemID;
    char itemName[20];
};

int main() {
    InventoryItem item1;
    item1.itemID = 101;
    strncpy(item1.itemName, "Random Item", sizeof(item1.itemName));
    item1.itemName[sizeof(item1.itemName) - 1] = '\0';

    ofstream outFile("inventory.dat", ios::binary);
    if (!outFile) {
        cerr << "Error opening file for writing!" << endl;
        return -1;
    }
    outFile.write(reinterpret_cast<char*>(&item1), sizeof(item1));
    outFile.close();

    InventoryItem item2;
    ifstream inFile("inventory.dat", ios::binary);
    if (!inFile) {
        cerr << "Error opening file for reading!" << endl;
        return 1;
    }
    inFile.read(reinterpret_cast<char*>(&item2), sizeof(item2));
    inFile.close();

    cout << "Loaded Item ID: " << item2.itemID << endl;
    cout << "Loaded Item Name: " << item2.itemName << endl;

    return 0;
}
