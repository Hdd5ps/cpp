/* 
multi-line comment
*/

// in-line comment

/*
Variables

Python: declare variables in python?
x=10;
bob = "cold";
x = 3.14159

C++: declare variables:
1st part - a type
2nd part - variable name

rules for names:
1. cannot start with a number
2. cannot be a number (i.e. int 7 = 5;)
3. cannot be a keyword (in jgrasp -> pop up in purple text)
4. can start with an underscore: int _num = 7;
5. use camel-case: myThirdPick
6. use underscores: my_third_pick
7. can utilize numbers in about anywhere else: pick3
8. everything is case-sensitive in c++: Pick3, pick3 are two different things
9. declare multiple variables on the same line
10. declare values for variables as you're defining them
11. special characters a possibility, besides underscore...
--!pick3 --> reads as "not pick3"

type:
integers, strings, booleans, float, double, character

how we represent/denote different types:
integers - int
strings - string
booleans - bool
floats (decimal) - float
double (decimal) - double
character - char
--it's any symbol contained withing single quotes
---'a', 'Z', '1' -> all correspond to an ASCII code

declare variables:
int x, y; - separate every variable name with a comma
-don't use variable names that aren't meaningful
--same as:
int x;
int y;
double latitude = 32.1234;
double longitude = 32.1234;
could also write as:
double latitude = 32.1234, longitude = 32.1234

syntax: remember every line ends with a ; in C++

extensions : cpp and cc

*/

#include<iostream> // means we need the library that takes in input and prints out output
using namespace std; // avoid writing std:: in front of any commands (iostream)

int main(){ //main -> makes the program go

//print - use the command cout, followed by <<, then content
//endl - print a carriage return/end the line
// take in input - cin, followed by >>.
// NOTE: write endl, it only goes with cout. if included on cin, you'll get an error

    int price, quantity, total;


    cout<<"Hello world!"<<endl; //if you don't have use namespace std, use std::cout and std::endl

    // cout<<"Please enter the price: ";
    // cin>>price;
    // cout<<"Please enter the quantity:";
    // cin>>quantity;

    // cout<<"The total price is : "<<price*quantity<<endl;

    // another way to do it
    cout<<"Please enter the price and quantity: ";
    cin>>price>>quantity; //take in multiple items with cin
    //cin skips white space to get to the next value
    total = price*quantity;
    cout<<"The total price is: "<<total<<endl;

    return 0; //old-style "flag" that everything executed okay
}

// int latitude = 32.1234; //let's revisit this error: collect2: error: Id returned 1 exit status
/*
Python - interpreted language; doesn't need a compiler
-program that runs your program

C++ - compiled language
the language - we know how to write in to communicate to the machine
when compile: it takes code, makes sure it's syntactically correct
if compilation was successful, it will create .exe file on Windows
-executable


*/