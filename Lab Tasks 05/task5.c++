#include<iostream>
#include<string>
using namespace std;

class Hospital;
class Doctor{
    string name, specialization;
    float experience;
    Hospital* hospital_assigned_To;
    public:
    Doctor(){
        hospital_assigned_To = nullptr;
    }
    Doctor(string n, string s, float exp){
        name = n;
        specialization = s;
        experience = exp;
        hospital_assigned_To = nullptr;
    }
    string getName() const{
        return name;
    }
    string getSpecialization() const{
        return specialization;
    }
    float getExp() const{
        return experience;
    }
    void setHospital(Hospital &h);
};
class Hospital{
    string hospital_name;
    Doctor** assigned_doctors;
    int doctorCount;
    int maxDoctors;
    public:
    Hospital(){}
    Hospital(int maxD, string name){
        hospital_name = name;
        maxDoctors = maxD;
        assigned_doctors = new Doctor*[maxD];
        doctorCount = 0;
    }
    ~Hospital(){
        delete[] assigned_doctors;
    }
    void addDoctor(Doctor* d){
        if(doctorCount < maxDoctors){
            assigned_doctors[doctorCount] = d;
            doctorCount += 1;
        }
        else{
            cout<<"The hospital has already employed the maximum amount of Doctors.\n";
        }
    }
        void hospital_info(){
            cout<<"Hospital Name: "<<hospital_name <<endl;
            if(doctorCount == 0){
                cout<<"No doctors employeed yet.\n";
                return;
            }
            cout<<"Doctors Currently employed: \n";
            for(int i = 0; i < doctorCount ; i++){
                cout<<"Name: "<<assigned_doctors[i]->getName()<<endl;
                cout<<"Specialization: "<<assigned_doctors[i]->getSpecialization()<<endl;
                cout<<"Experience: "<<assigned_doctors[i]->getExp()<<endl;
        }
    }
    void removeDoctor(Doctor* d) {
        for (int i = 0; i < doctorCount; i++) {
            if (assigned_doctors[i] == d) {
                for (int j = i; j < doctorCount - 1; j++) {
                    assigned_doctors[j] = assigned_doctors[j + 1]; 
                }
                doctorCount -= 1;
                cout << d->getName() << " has been removed from " << hospital_name << endl;
                return;
            }
        }
    }
};

void Doctor :: setHospital(Hospital &h){
    hospital_assigned_To = &h;
}

int main(){
    Hospital myhospital(15, "Aga Khan");
    Doctor d1("Dr.Rameel Sohail","General Physician",5.5);
    Doctor d2("Dr.Ahmed Khan","Orthopedic Surgeon",8.5);
    myhospital.addDoctor(&d1);
    myhospital.addDoctor(&d2);
    d1.setHospital(myhospital);
    d2.setHospital(myhospital);
    myhospital.hospital_info();
    Hospital myhospital2(15, "John Hopkins");
    myhospital2.addDoctor(&d1);
    myhospital.removeDoctor(&d1);
    d1.setHospital(myhospital2);
    myhospital.hospital_info();
    myhospital2.hospital_info();

    return 0;
}
