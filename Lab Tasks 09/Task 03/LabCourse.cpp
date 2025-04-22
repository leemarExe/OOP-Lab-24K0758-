#include "LabCourse.h"
#include <iostream>
using namespace std;

LabCourse::LabCourse(string code, int cred) : Course(code, cred) {}

void LabCourse::calculateGrade() {
    cout << "Lab course grade calculated based on practical work and reports.\n";
}

void LabCourse::displayInfo() {
    cout << "Lab Course: " << courseCode << ", Credits: " << credits << endl;
}
