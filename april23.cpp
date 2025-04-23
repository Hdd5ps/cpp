/*
Exception Handling -> not tied to classes
Inheritance -> tied to classes

P.A. 10 due tonight P.A. 11 due 5/2              Quiz 4 today

x = y / z; what can go wrong?
type error -> x and y are not the same type
z could be zero -> output = nan (not a number)

try/catch:
 try block -> code that might throw an exception/ attempt to do something think about what might go wrong?
 catch block -> code that handles the exception

try {
    // code that might throw an exception
    if (z == 0) {
        // throw std::runtime_error("Division by zero");
        throw(z); // if happens, exit the try block and go to the catch block
    }
    x = y / z;
} catch (int zeroDivisor) {
    // code that handles the exception
    cout << "Attempted to divide by zero: " << zeroDivisor << endl;
    cout << "x will be set to 0" << endl;
    x = 0;
}
try block 
catch block right after the try block
catch block is executed if an exception is thrown in the try block
catch block can be used to handle the exception
catch block can be used to log the exception
catch block can be used to clean up resources
catch block can be used to rethrow the exception

Exception Handling is a way to handle errors in a program

Inheritance is a way to create a new class based on an existing class
Inheritance is a relationship

Student class
    - name
    - id
    - gpa
    - major
    - advisor
    - Major
    - minor
    - Age

Faculty class
    - name
    - id
    - department
    - title
    - office
    - age/ dob

Person class
    - Student#
    - name
    - DOB/ Age
    // methods
*/
