/*
assignment 4 due 2/12
assignment 5 post on 2/12/ due 2/19

exams will be graded by the end of the week
quiz next week; topics and date tba

how do we get truly random numbers?
- Extra steps (and add a library to use)

srand(time(0)); #sec/msec since 1/1/1970
int seed = time(0);
srand(seed);

what we know;
 rand() -> start with the same seed value

 today
    srand(time(0)) -> clock (time is always changing) -> difference in time each time program runs
cstdlib for srand and ctime for time

-need to call srand(time(0)) pme time in your program, one of the first lines in main.

up to now: predefined functions. - python

def whatever (arg1, arg2, arg3):
    //lines of code for functions

user - defined functions

returnType name (args(type name)) #each arg is separated by comman

protoype/main/function definition

prototype -> 1st line of code
    -signals to compiler: "look for my definition later"
    - use function in main/other functions

prototype: 
    returnType functionName (type, type, type);

1. prototype - order of prototypes does not matter
2. main
3. function definition

1. function definition      -order of functions does matter
2. main     -if f calling s, then s needs to be defined before f

definition -> same as of prototype, but w/ each argument you have type and argument name

.h files
    - separate from .cpp/.cc/cxx files
    - function definitions, etc.
    - provide for reuse
        - over time, any bugs are eliminated

main -> is a function itself; it is the driver of the program
    because it has return type name (could have arguments -> for command line)

    - not do much processing within main
    - delegating responsibilities via function calls 
    - pressure is off of main -> figure out where a bug/problem occurs

return Type (beginning of the function definition declaration)

int
bool
double
float
char
string
(user-defined types/classes)
void -> does not return a value (usually using this to print something)

return type not void -> function (Ada)
void return type -> procedure (Ada)

for example:

#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

// prototype, main, function definition route
int roll(); //prototype

int main(){
    int result;
    srand(time(0)); //generate truly random numbers based on time
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            result = roll(); //function call instead of lines of code to generate lines of code
            cout<<result<<" ";
        }
        cout<<endl;
    }
    return 0;
}

int roll(){
    int rolledValue;
//variables for upper and lower
    int upper = 6, lower = 1;
//determine range
    int range = upper - lower + 1;
//call rand() % range
    rolledValue = rand()%range;
// add the lower bound
    rolledValue += lower;

    return rolledValue;
}

// function definition + main route
// order does matter (declarations and usage)

int roll(){
int rolledValue;
int upper = 6, lower = 1;
...
..}

*/
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(){
    int result; //resulting role
    int upper = 6, lower = 1, range;
    srand(time(0)); //generate truly random numbers based on time
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            //determine range
            range = upper - lower + 1;

            //call rand, mod by range
            result = rand() % range;

            //add the lower bound
            result += lower;

            cout<<result<<" ";
        }
        cout<<endl;
            
    }
    return 0;
}
