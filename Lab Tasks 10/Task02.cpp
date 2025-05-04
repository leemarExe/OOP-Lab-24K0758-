#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    ifstream my("vehicles.txt");

    if (!my.is_open()) {
        cerr << "Error: Could not open file 'vehicles.txt'" << endl;
        return -1;
    }

    string line;
    while (getline(my, line)) {
        if (line.empty() || (line[0] == '/' && line[1] == '/'))
            continue;

        istringstream ss(line);
        string type, id, name, year, extraData, certification;
        getline(ss, type, ',');
        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, year, ',');
        getline(ss, extraData, ',');
        getline(ss, certification, ',');
        cout << "Type: " << type << endl;
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Year: " << year << endl;
        cout << "ExtraData: " << extraData << endl;
        cout << "Certification: " << certification << endl;
        cout <<"-------------------------------------\n";
        
    }

    my.close();
    return 0;
}
