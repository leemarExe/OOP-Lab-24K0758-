#include<iostream>
#include<fstream>
using namespace std;


int main(){
    ofstream file("sensor_log.txt");
    if(!file){
        cout<<"Error: Could not open file 'sensor_log.txt'"<<endl;
        return -1;
    }
    
    file<<"Sensor 1: 25.5 C\n";
    streampos pos1 = file.tellp();
    cout<<"Position after First line: " << pos1 << endl;
    file<<"Sensor 2: 98.1 %RH\n";
    streampos pos2 = file.tellp();
    cout<<"Position after Second line: " << pos2 << endl;
    

    file.close();
    return 0;
}