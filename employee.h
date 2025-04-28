#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include<iostream>
#include<string>
#include "person.h"

// inheritance: public, private, or protected inheritance. What's the difference?
// you might cover in Data Structures
// if inheritance in this class - go with public inheritance

class Employee : public Person {
    // means Employee has access to Person's methods and dat

    public:
    Employee(string f = "", string l = "",string i = "", string o = "", string d = "") : Person(f, l, i)
    {
        setOfficeLocation(o);
        setDepartment(d);
    }

    // setters
    void setOfficeLocation(string o) {
        officeLocation = o;
    }
    
    void setDepartment(string d) {
        department = d;
    }

    // getters
    string getOfficeLocation() {
        return officeLocation;
    }
    string getDepartment() {
        return department;
    }

    // method to display employee information
    void displayEmployeeInfo() {
        Person::printPersonInfo(); // call base class method prints out first name, last name, id number
        cout << "Office Location: " << getOfficeLocation() << endl;
        cout << "Department: " << getDepartment() << endl;
    }

    protected: // expand this class 
    string officeLocation, department;


};

#endif