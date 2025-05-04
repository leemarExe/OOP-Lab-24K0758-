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

        if(type == "AutonomousCar"){
            size_t colonPos = extraData.find(':');
            if (colonPos != string::npos) {
                float SW = stof(extraData.substr(colonPos + 1));
                cout << "AutonomousCar ID: " << id << endl;
                cout << "SW Version: " << SW << endl;
            }
            else{
                cout << "Colon(:) not found" << endl;
            }
        }
        else if(type == "ElectricVehicle"){
            size_t colonPos = extraData.find(':');
            if (colonPos != string::npos) {
                int battery = stoi(extraData.substr(colonPos + 1));
                cout << "ElectricVehicle ID: " << id << endl;
                cout << "Battery: " << battery << " kWh" << endl;
            }
            else{
                cout << "Colon(:) not found" << endl;
            }
        }
    }

    my.close();
    return 0;
}
