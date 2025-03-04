#include<iostream>
#include<string>
using namespace std;

class Student{
    string id, name;
    int* examScores;
    public:
    Student(string i, string n){
        id = i;
        name = n;
        examScores = new int[5];
    }
    Student(Student &s){
        id = s.id;
        name = s.name;

        examScores = new int[5];
        for(int i = 0 ; i < 5 ; i++){
            examScores[i] = s.examScores[i];
        }
    }
    void setExamScores(){
        for(int i = 0 ; i < 5 ; i++){
            int score;
            cout<<"Enter Exam Score " << i + 1<< ": \n";
            cin>>score;
            examScores[i] = score;
        }
    }
    void displayScores(){
        for(int i = 0 ; i < 5 ; i++){
            cout<<"Exam Score "<<i + 1 << ": \n" << examScores[i]<< endl;
        }
    }

};





int main(){
    Student rameel("1001","Rameel");
    rameel.setExamScores();
    cout<<"Rameel's Exam Scores: \n";
    rameel.displayScores();
    
    Student ahmed = rameel;
    cout<<"Ahmed's Exam Scores: \n";
    ahmed.displayScores();
    
    rameel.setExamScores();
    cout<<"Ahmed's Exam Scores after updating Rameel's scores: \n";
    ahmed.displayScores();





    return 0;
}