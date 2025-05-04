#include <iostream>
#include <fstream>
#include <string>
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

        cout << line << endl; 
    }

    my.close();
    return 0;
}
