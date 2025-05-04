#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ofstream out("large_log.txt");
    if(!out){
        cout<<"Error: Could not open file..." << endl;
        return -1;
    }
    out << "This is the first part of log\n";
    out << "This is the second part of log\n";
    out << "And this is the third part";
    out.close();

    ifstream in("large_log.txt");
    char temp[11];
    temp[10] = '\0';
    in.read(temp, 10);
    cout << "First 10 characters: " << temp << endl;
    streampos pos1 = in.tellg();
    cout <<"Position just after the first read: " << pos1 << endl;

    in.read(temp, 10);
    cout << "Next 10 characters: " << temp << endl;
    streampos pos2 = in.tellg();
    cout << "Position just after second read: " << pos2 << endl;

    in.close();

    return 0;

    

}