#ifndef COURSE_H
#define COURSE_H
#include <string>
using namespace std;

class Course {
protected:
    string courseCode;
    int credits;

public:
    Course(string code, int cred) : courseCode(code), credits(cred) {}
    virtual void calculateGrade() = 0;
    virtual void displayInfo() = 0;
    virtual ~Course() {}
};

#endif
