#include<iostream>
#include<exception>
using namespace std;


class InvalidTemperatureException : public exception{
    string msg;
    public:
    InvalidTemperatureException(string m) : msg(m){}
    string what(){
        return msg.c_str();
    }
};

template<typename T>
double convertToFarhenheit(T celcius){
    if(celcius < -273.15){
        throw InvalidTemperatureException("The temp is less than absolute zero\n");
    }
    return (celcius * 1.8) + 32;
}





int main(){
    try{
    float temp = convertToFarhenheit(-300);
    cout << temp;
    }
    catch(InvalidTemperatureException& e){
        cout << "Caught InvalidTemperatureException - what(): " << e.what() << endl;
    }
}