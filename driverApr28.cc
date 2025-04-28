/*
*/
#include <iostream>
#include <string>
#include "person.h" // creates issues.
#include "employee.h"
using namespace std;

int main(){
    Person p1;
    Person p2("Oscar","The Grouch", "25");
    p1.printPersonInfo();
    p2.printPersonInfo();
    cout << endl;

    Employee e1;
    Employee e2("Elmo", "Monster", "1234", "123 Sesame St.", "Muppet Studies");
    e1.displayEmployeeInfo();
    e2.displayEmployeeInfo();
}