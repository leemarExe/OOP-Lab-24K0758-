#include <iostream>
#include <string>
using namespace std;

class Employee;
class Project {
    string projectTitle;
    string deadline;
    Employee* employees_assigned[10];
    int employeeCount;

public:
    Project(string t, string d) {
        projectTitle = t;
        deadline = d;
        employeeCount = 0;
    }

    void assignEmployee(Employee* e);

    void displayEmployees() const;

    string getTitle() const {
        return projectTitle;
    }

    string getDeadline() const {
        return deadline;
    }
};

class Employee {
    string name, designation;
    Project* projects_assigned[3];
    int projectCount;

public:
    Employee(string n, string d) {
        name = n;
        designation = d;
        projectCount = 0;
    }

    void assignProject(Project* p);
    
    string getName() const {
        return name;
    }

    string getDesignation() const {
        return designation;
    }

    void displayProjects() const;
};

void Project :: assignEmployee(Employee* e) {
    if (employeeCount < 10) {
        employees_assigned[employeeCount] = e;
        employeeCount += 1;
        cout << e->getName() << " assigned to Project " << projectTitle << endl;
        e->assignProject(this);
    } else {
        cout << "Maximum amount of employees are already assigned to the project.\n";
    }
}

void Project :: displayEmployees() const {
    if (employeeCount == 0) {
        cout << "No employees assigned to current project.\n";
        return;
    }
    cout << "Employees assigned to Project " << projectTitle << ":" << endl;
    for (int i = 0; i < employeeCount; i++) {
        cout << "Employee Name: " << employees_assigned[i]->getName() << endl;
        cout << "Employee Designation: " << employees_assigned[i]->getDesignation() << endl;
    }
}

void Employee::assignProject(Project* p) {
    if (projectCount < 3) {
        projects_assigned[projectCount] = p;
        projectCount += 1;
    } else {
        cout << name << " is already working on 3 projects.\n";
    }
}

void Employee :: displayProjects() const {
    if (projectCount == 0) {
        cout << "No projects assigned yet.\n";
        return;
    }
    cout << name << " is assigned to the following Projects: \n";
    for (int i = 0; i < projectCount; i++) {
        cout << "Project Title: " << projects_assigned[i]->getTitle() << endl;
        cout << "Deadline: " << projects_assigned[i]->getDeadline() << endl;
    }
}

int main() {
    Employee emp1("Ali", "Software Engineer");
    Employee emp2("Bilal", "Data Scientist");
    Employee emp3("Rameel", "Project Manager");

    Project proj1("AI Development", "2025-06-30");
    Project proj2("Blockchain Research", "2025-09-15");

    proj1.assignEmployee(&emp1);
    proj1.assignEmployee(&emp2);

    proj2.assignEmployee(&emp2);
    proj2.assignEmployee(&emp3);

    cout << "Displaying Employee Projects:\n";
    emp1.displayProjects();
    emp2.displayProjects();
    emp3.displayProjects();

    cout << "Displaying Project Employees:\n";
    proj1.displayEmployees();
    proj2.displayEmployees();

    return 0;
}
