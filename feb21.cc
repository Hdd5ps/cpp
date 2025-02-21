/*
csc 1180 - 2/21/25
Todat: reference parameters
function overloading

recall references:
    define like a regular variable
    difference: notation (&)
    int ref; - variable declaration
    
    int& ref - reference declaration
    int &ref
    
    - immediate assignment necessary
    & -> looking at addresses

int x = 10; // somewhere in the memory a block at #9120 with a value of x resides
int &xRef = &x;  // xref is referencing the same location (space) and value of x that was previously created
only use &xRef upon declaring &xRef

Reference Parameters
int function(int a, int b){ //Limiting ?
    .                         - at most -1 item returned in a function          
    .
    .
    return ...; 
}

Reference parameters allow for more than 1 values to be returned
1 value max still returned via traditional return 

reference parameter definition?
    - same way as references
    
void swap(double& value1, double& value2){ // void is not an indicator of reference parameters
    double temp;
    temp = value1;
    value1 = value2;
    value2 = temp;
}

int swapAndMax(double& value1, double& value2)
{
    .
    .
    .
    return maximumValue;
}

int main(){
    double number1, number2;
    .
    .
    .
    // defined values for number1 & number2;
    swap (number1, number2);
    // any changes made to value1 and value2 are kept after completion of the function

    //number1 = 9.5
    //number2 = -1.5  // direct access to the memory location (references)

    call swap

    cout on number1 & number2, 
    values will be flipped
}
#include<iostream>
using namespace std;


//parameter passing
//pass-by-value
//whatever gets passed in for value1 and value2 - a copy of each value is passed in
//tip-off: there are no ampersands (&) in the arguments
void swap(double value1, double value2)
{
    double temp;
    cout<<"value1: "<< value1<< " value2: " << value2<< endl;
    temp = value1;
    value1 = value2;
    value2 = temp;
    cout<<"value1: "<< value1<< " value2: " << value2<<endl;;

    return;
}

int main()
{
    double decimal1 = 9.5, decimal2 = -1.5;
    swap(decimal1, decimal2);
    cout<<"decimal1: "<<decimal1<<" decimal2: "<< decimal2 << endl;
    return 0;
}


value1: 9.5 value2: -1.5
value1: -1.5 value2: 9.5
decimal1: 9.5 decimal2: -1.5
[1] + Done                       "/usr/bin/gdb" --interpreter=mi --tty=${DbgTerm} 0<"/tmp/Microsoft-MIEngine-In-emb5j3ht.i4o" 1>"/tmp/Microsoft-MIEngine-Out-mvka121x.c0x"

we see the swap takes place inside the function but once we leave the function it's gonna print 9.5 again without swapping it
#include<iostream>
using namespace std;

// parameter passing
// pass-by-reference; tip-off: &
// value1 and value get the addresses for decimal1 and decimal2
// access to change what's in value2 and value2 
// it enables you to affect the variables

void swap(double& value1, double& value2)
{
    double temp;
    cout<<"value1: "<< value1<< " value2: " << value2<< endl;
    temp = value1;
    value1 = value2;
    value2 = temp;
    cout<<"value1: "<< value1<< " value2: " << value2<<endl;;

    return;
}

int main()
{
    double decimal1 = 9.5, decimal2 = -1.5;
    swap(decimal1, decimal2);
    cout<<"decimal1: "<<decimal1<<" decimal2: "<< decimal2 << endl;
    return 0;
}

// value1: 9.5 value2: -1.5
// value1: -1.5 value2: 9.5
// decimal1: -1.5 decimal2: 9.5

#include<iostream>
using namespace std;

// parameter passing
// pass-by-reference; tip-off: &
// value1 and value get the addresses for decimal1 and decimal2
// access to change what's in value2 and value2 
// it enables you to affect the variables


double swapAndMax(double& value1, double& value2)
{
    double temp, result;
    temp = value1;
    value1 = value2;
    value2 = temp;

    if (value1> value2)
    {
        result = value1;
    }
    else{
        result = value2;
    }

    return result;
}

int main()
{
    double decimal1 = 9.5, decimal2 = -1.5;
    double result = swapAndMax(decimal1, decimal2);
    cout<<"decimal1: "<<decimal1<<" decimal2: "<< decimal2 << endl;
    cout<<"larger value: "<< result <<endl;
    return 0;
}

// decimal1: -1.5 decimal2: 9.5
// larger value: 9.5


Overloading Functions:
    textbook definition: functions w/same name, but different signatures

    int fun(int x, int y) - signature is fun(int x, int y) ; [note:- return type is not the signature]

    functions do share the same name, but the arguments differ
        -type       your compiler sees
        -number     fun(int, int);
        -order

    int fun(int a, int b); -> fun(int, int);(same as above)

    number of arguments=>
    int fun(int x, int y); -> compilers will look at as function with two arguments only i.e fun(int,int)
    int fun(int w, int x, int y); fun(int, int, int)

    type of arguments=>
    double fun(double x, double y); fun(double, double)
    double fun(double w, double x, double y); fun (double, double, double)

    order of arguments=>
    double fun(int x, double y)-> fun(int, double)
    double fun(double y, int y)-> fun(double, int)

    with function overloading -> same name but different arguments

    Quiz 
    - reference parameters
    - pass-by-value v pass-by-reference
    - providing a good definition for function
    overloading
    -any content covered since 1st test
        -file I/O
        - I/O manipulation
        - predefined functions
        - user-defined functions

    Monday: Overloading Functions -> example(s) with code
        (Overloading Function Names)
    */


