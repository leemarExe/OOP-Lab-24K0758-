#include<iostream>
using namespace std;


class Menuitem{
	protected:
		string dishname;
		double price;
	public:
		Menuitem(string n, double p) : dishname(n),price(p){
		}
		virtual void showDetails()=0;
		virtual void prepare()=0;
};


class Appetizer: public Menuitem{
	public:
		Appetizer(string n, double p) : Menuitem(n ,p){
		}
		void showDetails(){
			cout<<"Appetizer: " << dishname << "\nPrice: " << price << endl;
		}
		void prepare(){
			cout<<"Appetizer: " << dishname << " is bieng prepared" << endl;
		}
};


class Maincourse: public Menuitem{
	public:
		Maincourse(string n,double p) : Menuitem(n ,p){
		}
		void showDetails(){
			cout<<"Main Course: " << dishname << "\nPrice: " << price << endl;
		}
		void prepare(){
			cout<<"Main Course: " << dishname << " is bieng prepared" << endl;
		}
};


int main(){

Appetizer a("Hummus and Bread",1200.00);
Maincourse m("Pizza",2000.00);

Menuitem* d1 = &a;
Menuitem* d2 = &m;


d1->showDetails();
d1->prepare();
d2->showDetails();
d2->prepare();

}