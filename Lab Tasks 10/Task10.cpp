#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream file("data_records.txt");
    
    if (!file.is_open()) {
        cerr << "Failed to open file." << endl;
        return 1;
    }

    int offset = 9 * 2; 

    file.seekg(offset, ios::beg);

    string record;
    getline(file, record);
    
    cout << "Third record: " << record << endl;

    file.close();
    return 0;
}
