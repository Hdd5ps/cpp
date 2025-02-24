/*
Overloading functions:
    same function name, but different arguments

    what compilor is looking is type, no. and order
    for match to a fucntion call by looking only @ the arguments' types



int max(int num1, int num2)
{
//max of 2 numbers
}

int max(int num1, int num2, int num2)
{
//max of 3 numbers
}

looking for a matching function

max(int, int)
max(int, int, int)


int max(int num5, int num6)
-> max(int, int) // already done before so will not work

why use? The name is succient.

max -> 2 -> other than int
max -> 3 -> other than int

- enumareted types possible
- user - defined data types

Default Arguments

if an arg isn't specified, it's replaced with a default value,
- once you start using default arguments on function, you cannot stop

double volume(double l = 1.0 (1st default arg. all must have default argument), double w = 1.0, double h = 1.0)
{
    return l*w*h;
}

possible calls: 
    double x = volume(); -> 1 * 1 * 1
    double y = volume(10); -> 10 * 1 * 1
    double z = volume(10,5)l -> 10 * 5 * 1
    double a = volume(10,5,2) -> 10 * 5 * 2

double volume (double x, double y, double z){
    //whatever
}

b = volume (10, 5, 2);
- error: possibility of vol w/3 args defined

function template:-
int max (int x, int y, int z){
    //steps in here to find max of 3
}

(1, 1, 1.5) will go with doubles 

double max(double x, double y, double z){
    //find max of 3 args
}


char max(char x, char 4, char z){
    // find max of 3 args
}

better way to do fhms?
*/