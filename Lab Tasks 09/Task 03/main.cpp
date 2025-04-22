#include "LectureCourse.h"
#include "LabCourse.h"

int main() {
    Course* c1 = new LectureCourse("CS201", 3);
    Course* c2 = new LabCourse("CS201L", 1);

    c1->displayInfo();
    c1->calculateGrade();

    c2->displayInfo();
    c2->calculateGrade();

    delete c1;
    delete c2;
    return 0;
}
