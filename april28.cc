/*
Inheritance - Today
Inheritance is a fundamental concept in object-oriented programming that allows a class to inherit properties and behaviors (methods) from another class. This promotes code reusability and establishes a hierarchical relationship between classes.
In C++, inheritance is implemented using the `class` keyword, and the derived class can access the members of the base class based on the access specifiers (public, protected, private).
-> why #ifndef, #define, #endif are crucial?
Wednesday- bring questions about topic in exams
Friday - no class; project workday
Expect a page addressing FAQs, re:final, final course average

Inheritance by midweek.
"is a relationship" - a derived class is a specialized(more date, more methods) version of the base class.
-> class A is a base class, class B is a derived class
-> class B is a subclass of class A
-> class A is a superclass of class B
-> class B is a child class of class A
-> class A is a parent class of class B
-> class B is a descendant of class A
-> class A is an ancestor of class B
-> class B is a more specific version of class A

Person - class
string name -> first name, last name
string idNumber

student - subclass of person employee - subclass of person
student - class                             employee - class
currentCourses - array of strings           officeLocation - string
course history - array of strings           department - string
credit hours - int                          salary - double
GPA - double                                printEmployeeInfo() - method
printStudentInfo() - method

staff class - subclass of employee faculty class - subclass of employee
staff - class                                               faculty - class
schedule - array of strings ?fulltime or part time?         office hours - array of strings
tenure track - bool

*/
#ifndef APRIL28_CC
#define APRIL28_CC

#include <iostream>
#include <string>
using namespace std;

// leave ifndef, define out for now

class Person
{
public: // methods
    Person(string fn = "", string ln = "", string id = "")
    {
        setFirstName(fn); // setters first name
        setLastName(ln); // setters last name
        setIdNumber(id); // setters id number
    }

    // getters and setters:

    void setFirstName(string fn) // used and tested via constructor
    {
        firstName = fn;
    }

    string getFirstName() const
    {
        return firstName;
    }

    void setLastName(string ln)
    {
        lastName = ln;
    }

    string getLastName() const
    {
        return lastName;
    }

    void setIdNumber(string id)
    {
        idNumber = id;
    }

    string getIdNumber() const
    {
        return idNumber;
    }

    // print method
    void printPersonInfo() const
    {
        cout << "Name: " << getFirstName() << " " << getLastName() << endl;
        cout << "ID Number: " << getIdNumber() << endl;
    }

protected: // data members
    string firstName;
    string lastName;
    string idNumber;
};

#endif // APRIL28_CC