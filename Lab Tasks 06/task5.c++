#include<iostream>
#include<string>
using namespace std;

class Device{
    protected:
    int deviceID;
    bool status;
    public:
    Device(int id, bool s) : deviceID(id), status(s){}

    virtual void displayDetails(){
        cout << "Device ID: " << deviceID << endl;
        if(status){
            cout << "Device is Active.\n";
        }
        else{
            cout << "Device is InActive.\n";
        }
    }
};

class SmartPhone : protected Device{
    protected:
    float screenSize;
    public:
    SmartPhone(int id, bool s, float SZ) : Device(id, s), screenSize(SZ){}
    void displayDetails() override{
        Device :: displayDetails();
        cout << "Screen Size: " << screenSize << endl;
    }
};
class SmartWatch : protected SmartPhone{
    protected:
    bool heartRateMonitor;
    public:
    SmartWatch(int id, bool s, float SZ, bool HRM) : SmartPhone(id, s, SZ), heartRateMonitor(HRM){}
    void displayDetails() override{
        SmartPhone :: displayDetails();
        if(heartRateMonitor){
        cout << "Heart Rate Monitor is Active.\n";
    }
        else{
        cout << "Heart Rate Monitor is InActive.\n";
        }
    }
};
class SmartWearable : protected SmartWatch{
    protected:
    int stepCounter;
    public:
    SmartWearable(int id, bool s, float SZ, bool HRM, int SC) : SmartWatch(id, s, SZ, HRM), stepCounter(SC){}
    void displayDetails() override{
        SmartWatch :: displayDetails();
        cout << "Steps Today: " << stepCounter << endl;
    }
};

int main(){
    SmartWearable s(1002, true, 6.5, true, 1200);
    s.displayDetails();


    return 0;
}