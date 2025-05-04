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
        else if(type == "HybridTruck"){
            size_t colonFirstPos = extraData.find(':');
            size_t colonSecondPos = extraData.find(':', colonFirstPos + 1);
            size_t pipePos = extraData.find('|');

            if(colonFirstPos != string::npos && pipePos != string::npos && colonSecondPos != string::npos){
                int cargoVal = stoi(extraData.substr(colonFirstPos + 1, pipePos - 1));
                int batteryValue = stoi(extraData.substr(colonSecondPos + 1));
                cout << "Hybrid Truck ID: " << id << endl;
                cout << "Cargo: " << cargoVal << endl;
                cout << "Battery: " << batteryValue << endl;
            }
        }
        else{
            cout << "Error: Unknown Vehicle Type..." << endl;
        }
    }

    my.close();
    return 0;
}
