#include <iostream>
#include <string>
using namespace std;

class AlarmSystem {
    string securityLevel;
public:
    AlarmSystem(string SL) {
        securityLevel = SL;
    }
    string getSecurityLevel() const {
        return securityLevel;
    }
};

class SmartHome {
    AlarmSystem alarm;
public:
    SmartHome(string sL) : alarm(sL) {} 

    void displayDetails() const {
        cout << "Smart Home Details:\n";
        cout << "Alarm System Security Level: " << alarm.getSecurityLevel() << endl;
    }
};

int main() {
    SmartHome home1("High");
    SmartHome home2("Medium");

    home1.displayDetails();
    home2.displayDetails();

    return 0;
}
