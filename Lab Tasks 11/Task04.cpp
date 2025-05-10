#include<iostream>
#include<string>
#include<exception>
using namespace std;


class DatabaseException : public exception{
    string msg;
    public:
    DatabaseException(){
        msg = "A database error occured.\n";
    }
    const char* what() const noexcept override{
        return msg.c_str();
    }
};

class ConnectionFailedException : public DatabaseException{};
class QueryTimeoutException : public DatabaseException{};

template<typename T>
class DatabaseConnector{
    T* val;
    public:
    DatabaseConnector(T* val) : val(val){}
    void print(){
        if(*val <= 10){
            throw ConnectionFailedException();
        }
        else if(*val > 10){
            throw QueryTimeoutException();
        }
        else{
            cout << "Value: " << *val << endl;
        }
    }
};


int main(){
    int* ptr1;
    int a = 9;
    ptr1 = &a;

    int* ptr2;
    int b = 11;
    ptr2 = &b;


    DatabaseConnector<int> dc1(ptr1);
    try{
        cout << "Attempting to connect to invalid_db..." << endl;
        dc1.print();
    }
    catch(const ConnectionFailedException& e){
        cout << "Caught ConnectionFailedException - what(): " << e.what();
    }
    
    DatabaseConnector<int> dc2(ptr2);
    try{
        cout << "Attempting to connect to slow_db..." << endl;
        dc2.print();
    }
    catch(const QueryTimeoutException& e){
        cout << "Caught QueryTimeoutException - what(): " << e.what();
    }

}
