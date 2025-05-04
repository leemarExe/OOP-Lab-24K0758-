#include<iostream>
#include<fstream>
#include<string>
using namespace std;


int main(){
    ofstream outFile("config.txt");
    string content = "AAAAABBBBBCCCCC";
    outFile.write("AAAAABBBBBCCCCC", sizeof("AAAAABBBBBCCCCC"));
    outFile.close();

    ifstream inFile("config.txt");
    string line;
    getline(inFile, line);
    cout << "File Before Updation: " << line << endl;
    inFile.close();

    fstream file("config.txt", ios::in | ios::out);
    if(!file){
        cout<<"Error: Could not perform operation on file..."<<endl;
        return -1;
    }

    file.seekp(5);
    file.write("XXXXX", 5);
    file.close();
    
    ifstream inFile2("config.txt");
    getline(inFile2, line);
    cout << "File After Updation: " << line << endl;

    inFile2.close();

}