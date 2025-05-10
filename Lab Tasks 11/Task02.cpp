#include<iostream>
#include<exception>
using namespace std;

class QueueOverflowException : public exception{
    private:
    string msg;
    public:
    QueueOverflowException(){
        msg = "Max Capacity reached. Cannot enqueue anymore items...\n";
    }
    string what(){
        return msg;
    }
};

class QueueUnderflowException : public exception{
    private:
    string msg;
    public:
    QueueUnderflowException(){
        msg = "There are no items to dequeue...\n";
    }
    string what(){
        return msg;
    }
};


template<typename T>
class Queue{
    private:
    int capacity;
    int current;
    T* data;
    public:
    Queue(int c) : capacity(c){
        data = new T[capacity];
        current = 0;
    }
    void enqueue(T val){
        if(current < capacity){
            data[current] = val;
            current += 1;
            cout << val << " added\n";
            }
        else{
            throw QueueOverflowException();
        }
    }
    void dequeue(){
        if(current > 0){
            for(int i = 0 ; i < current - 1 ; i++){
                data[i] = data[i + 1];
            }
            current -= 1;
            cout << "Item removed.\n";
        }
        else{
            throw QueueUnderflowException();
        }
    }
};



int main(){
    Queue<int> Q(2);
    try{
        Q.enqueue(1);
        Q.enqueue(2);
        cout<<"Attempting to enqueue in a full QUEUE"<<endl;
        Q.enqueue(3);
    }catch(QueueOverflowException& e){
        cout<<"Caught Overflow Exception "<<e.what()<<endl;
    }
    try{
        Q.dequeue();
        Q.dequeue();
        cout<<"Attempting to dequeue From a empty QUEUE"<<endl;
        Q.dequeue();
    }catch(QueueUnderflowException &e){
        cout<<"Caught Underflow Exception "<<e.what()<<endl;
    }
    return 0;


}