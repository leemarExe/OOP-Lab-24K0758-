#include "LectureCourse.h"
#include <iostream>
using namespace std;

LectureCourse::LectureCourse(string code, int cred) : Course(code, cred) {}

void LectureCourse::calculateGrade() {
    cout << "Lecture course grade calculated based on quizzes, assignments, and exams.\n";
}

void LectureCourse::displayInfo() {
    cout << "Lecture Course: " << courseCode << ", Credits: " << credits << endl;
}
