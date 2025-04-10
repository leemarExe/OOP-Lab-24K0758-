#include<iostream>
#include<string>
using namespace std;

class Device{
    protected:
    string deviceId;
    string name;
    bool status;
    string location;

    public:
    Device(string ID, string name, string loc = "") : deviceId(ID), name(name), status(false), location(loc){}

    virtual void turnON(){
        status = true;
    }
    virtual void turnOFF(){
        status = false;
    }

    virtual void getStatus() const{
        if(status){
            cout <<"The device is ON.\n";
        }
        else{
            cout <<"The device is OFF.\n";
        }
    }

    virtual void displayInfo() const{
        cout << "Device ID: " << deviceId << endl;
        cout << "Device Name: " << name << endl;
        cout << "Device Location: " << location << endl;
    }
};

class Light : public Device{
    int brightnessLevel;
    string colorMode;
    
    public:
    Light(string ID, string name, string loc, int BL, string mode) : Device(ID, name, loc), brightnessLevel(BL), colorMode(mode){}

    void displayInfo() const override{
        Device :: displayInfo();
        cout << "Brightness Level: " << brightnessLevel << endl;
        cout << "Color Mode: " << colorMode << endl;
    }
};

class Thermostat : public Device{
    float temp, targetTemp;
    string mode;
    
    public:
    Thermostat(string ID, string name, string loc, float temp, float targetTemp, string mode) : Device(ID, name, loc), temp(temp), targetTemp(targetTemp), mode(mode){}

    void displayInfo() const override{
        Device :: displayInfo();
        cout << "Current Temperature: " << temp << endl;
        cout << "Target Temperature: " << targetTemp << endl;
        cout << "Mode: " << mode << endl;
    }

    void getStatus() const{
        cout << "Current Temperature: " << temp << endl;
    }
};

class SecurityCamera : public Device{
    string resolution;
    bool recordingStatus, nightVisionEnabled;
    
    public:
    SecurityCamera(string ID, string name, string loc, string r): Device(ID, name, loc), resolution(r), recordingStatus(false), nightVisionEnabled(false){}

    void displayInfo() const override{
        Device :: displayInfo();
        cout << "Resolution: " << resolution << endl;
        if(recordingStatus){
            cout <<"The device is recording.\n";
        }
        else{
            cout <<"The device is not recording.\n";
        }
        if(nightVisionEnabled){
            cout <<"Night Vision enabled.\n";
        }
        else{
            cout <<"Night Vision disabled.\n";
        }
    }

    void turnON() override{
        recordingStatus = true;
    }

    void NightVisionEnabling(){
        nightVisionEnabled = true;
    }
};

class smartPlug : public Device{
    float powerConsumption;
    int timerSetting;
    
    public:
    smartPlug(string ID, string name, string loc, float PC, int TS): Device(ID, name, loc), powerConsumption(PC), timerSetting(TS){}

    void displayInfo() const override{
        Device :: displayInfo();
        cout << "Power Consumption: " << powerConsumption << " W/hr\n";
        cout << "Timer Setting: " << timerSetting << endl;
        
    }

    void turnOFF() override {
        status = false;
        std::cout << name << " turned off. Power consumed: " << powerConsumption << "W\n";
    }
};

int main(){

    Light livingRoomLight("L101", "Living Room Light", "Living Room", 75, "Warm White");
    livingRoomLight.turnON();
    livingRoomLight.displayInfo();
    livingRoomLight.getStatus();
    cout << "-------------------------\n";


    Thermostat homeThermostat("T202", "Home Thermostat", "Hallway", 22.5, 24.0, "Cooling");
    homeThermostat.turnON();
    homeThermostat.displayInfo();
    homeThermostat.getStatus();
    cout << "-------------------------\n";


    SecurityCamera frontDoorCamera("C303", "Front Door Cam", "Entrance", "1080p");
    frontDoorCamera.turnON();
    frontDoorCamera.NightVisionEnabling();
    frontDoorCamera.displayInfo();
    frontDoorCamera.getStatus();
    cout << "-------------------------\n";


    smartPlug coffeePlug("S404", "Coffee Plug", "Kitchen", 150.0, 30);
    coffeePlug.turnON();
    coffeePlug.displayInfo();
    coffeePlug.turnOFF();
    coffeePlug.getStatus();
    cout << "-------------------------\n";


    return 0;
}