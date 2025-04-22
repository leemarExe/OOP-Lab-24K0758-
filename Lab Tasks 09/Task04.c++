#include<iostream>
using namespace std;

class WeatherSensor {
public:
    WeatherSensor() {}
    virtual void readData() = 0;
    virtual void displayReport() = 0;
};

class Thermometer : public WeatherSensor {
    float temp;
public:
    Thermometer(float t) : WeatherSensor(), temp(t) {}

    void readData() override {
        cout << "Reading data from the thermometer" << endl;
        cout << "Temperature: " << temp << "C" << endl;
    }

    void displayReport() override {
        cout << "Temperature: " << temp << "C" << endl;
    }
};

class Barometer : public WeatherSensor {
    float pressure;
public:
    Barometer(float p) : WeatherSensor(), pressure(p) {}

    void readData() override {
        cout << "Reading data from the barometer" << endl;
        cout << "Pressure: " << pressure << "pa" << endl;
    }

    void displayReport() override {
        cout << "Pressure: " << pressure << "pa" << endl;
    }
};

int main() {
    Barometer b(60.0);
    Thermometer t(67.0);

    WeatherSensor *w1 = &b;
    WeatherSensor *w2 = &t;

    w1->readData();
    w1->displayReport();
    w2->readData();
    w2->displayReport();

    return 0;
}
