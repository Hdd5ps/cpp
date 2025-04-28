#ifndef PERSON_H
#define PERSON_H

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