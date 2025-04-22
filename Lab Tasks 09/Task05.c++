#include<iostream>
using namespace std;


class Shipment{
protected:
	string trackingNumber;
	double weight;
	public:
		Shipment(string num,double w) : trackingNumber(num), weight(w){
		}
		void virtual estimatedDeliverlyTime()=0;
		void virtual showDetails()=0;
};
class AirFreight :public Shipment{
public:
	AirFreight(string num, double w) : Shipment(num, w){
	}
	void estimatedDeliverlyTime(){
		cout <<"Estimating aerial delivery time..."<< endl;
	}
	void showDetails(){
		cout << "Tracking Number#: "<< trackingNumber << "\nWeight: " << weight << endl;
	}
		
};
class GroundShipment :public Shipment{
public:
	GroundShipment(string num,double w) : Shipment(num, w){
	}
	void estimatedDeliverlyTime(){
		cout << "Estimating grounded deliverly time..." << endl;
	}
	void showDetails(){
		cout << "Tracking Number#: "<< trackingNumber << "\nWeight: " << weight << endl;
	}
};
int main(){

    Shipment* shipments[2];
    
    shipments[0] = new AirFreight("AF2345", 85.6);
    shipments[1] = new GroundShipment("GS7890", 123.4);
    
    for (int i = 0; i < 2; ++i) {
        shipments[i]->showDetails();
        shipments[i]->estimatedDeliverlyTime();
        cout << endl;
    }
    
    for (int i = 0; i < 2; ++i) {
         delete shipments[i];
    }
    
    return 0;
    
}