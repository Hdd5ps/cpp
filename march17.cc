/*
- Arrays
    Assignment7 goes out Wednesday (array-based)
    Exams graded, not everyone has taken
    if you want to know score, monday is not the based day

Array is a contiguous spaces in memory, all of the same type
declare:
    type name[may/not need to fill in the size/no. of items] = {values that go into the array; comma separated};
    static -> can't change size once set

    int array[] = {1, 2, 3, 4, 5}; // size is 5

    another route
    int array[10]; <- another way to declare an array
    const int SIZE = 10;
    int array[SIZE];

    int array[SIZE] = {1, 2, 3, 4, 5};
          1 2 3 4 5 declared for size 10, but only 5. What happens? the rest of the array will be filled with int or whatever datatype is declared in 0.
    array -------------------
          0 1 2 3 4 5 6 7 8 9
          ___________________
          indexes/indices

int array[5] = {1, 2, 3, 4, 5, 6}
 What will happen?
    - first 5 assigned [F]
    - error size != size of list [T]

int values[5];

type name[size];

x[index] -> literal integer => 0, 1, 2, 3.....
         -> int arithmetic -> *, /, %, +, -

cell of the array
cell numbers: (0) - (size-1)        -1 X runtime error as index, no cell numbered -> goinng outside the bounds of the cells will do this

assign one int variable to the other:
     int x;
     int y;
     .
     .
     .
     x = y;

arrays:
    thougt: int x[5], int y[5];
            .
            .
            .
        x = y;// wrong way [array name on its own is address for the 1st location in the array]

    for (int i = 0; i < 5; i++){
    x[i] = y[i]; // copy the content from one array to other
    }


    const int SIZE = 10;
    int intArray[SIZE];

    // putting an array into a function
    - multidimentional arrays -> all but the first dimension must be specified
    - single - dimensional array -> don't have to specify the size


void init (int intArray[5]){
    for (int i = 0; i < 5; i++){
    intArray[i] = i;
    }
}
// if we want to use dimensional arrays we need to use const to avoid any micalculations

const int SIZE = 10;
void init (int intArray[SIZE]){
    for (int i = 0; i < SIZE; i++){
    intArray[i] = i;
    }
}

pass-by-value and pass-by-reference
if I pass single value from an array
x(intArray[4]) // variable declared int example

x could be pass-by-value or pass-by-reference

look at x's signature (&) -> pass by reference

void init (int x[], int size){
    for (int i = 0; i < size; i++){
        x[i] = i;
    }
}       // conventional thinking: pass by value (no &)

init(intArray, size){ 
// no changes kept
}

// passing an entire array into a function -> passing the array name -> location of where the array starts i.e. changes are gonna be kept


if passing an item an item from an array
- pass by value?
- pass by reference?

if passing an array
    - pass by reference

x(f[i]){
    int x (int& a){
    
    }
}
- looks same as passing by variable

void print(int a[], int size){
// prit contents
a[1] = 5; // prevent changing the value using constant
}

void print(const int a[], int size){
    // print constants
    a[i] = 5; => compiler picks this  and say up attemsts to read only
}

next time: code/2D arrays
#include<iostream>
using namespace std;

int main() {
    int values[5];

    cout<<values<<endl;
    // 0x7fffffffd120
    
    int x;
    cout<<x<<endl;
    // 21845
    
    int value[5] = {0};
    cout<<value<<endl;
    // 0x7fffffffd120

    cout<<value[1]<<endl;
    // 0
    return 0;
}
*/
#include <iostream>
#include <iomanip>
#include <array>
using namespace std;

int main() {
    array<int, 5> n; // n is an array of 5 int values

    // initialize elements of array n to 0
    
}
