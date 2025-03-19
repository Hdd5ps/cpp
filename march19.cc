/*
New Programming Assignment; due 3/26 - Taking care of business day

Practice with Arrays
2D Arrays:

type arrayName[row_size][column-size];
- behaviour is about the same

int intArray[3][3] = {{0, 1, 2}, {1, 2, 3}, {2, 3, 4}};

char charArray[4][3] = {{0, 1, 2}, {1, 2, 3}, {2, 3, 4}, {3, 4, 5}};

array range: 0 - (size - 1)

Functions: 2D Arrays: 2nd dimension needs to be specified

nD Arrays: define sizes for
*/

#include <iostream>
#include <iomanip>
using namespace std;

// pass-by-value
// creates a copy

// pass-by-referene
// calling card typically the &
// passing along the memory location
// passing an entire array in - pass- by- reference
// array name - has address of the first value in array

void print(int array[], int);
void input(int array[], int);

int main()
{
    const int SIZE = 5; // if changing the size of the array, you only need to alter SIZE
    // int numberArray[SIZE];
    // Contents of numberArray
    // 0: 0
    // 1: 0
    // 2: 1431654688
    // 3: 21845
    // 4: -11728

    int numberArray[SIZE] = {0};
    // Contents of numberArray
    // 0: 0
    // 1: 0
    // 2: 0
    // 3: 0
    // 4: 0

    cout << "Contents of numberArray" << endl;
    // need a loop to go through the array

    // function print
    cout<<"Memory address: "<<numberArray<<endl;
    print(numberArray, SIZE);
    cout << endl
         << endl
         << "Input values for the array: ";
    // take in input
    input(numberArray, SIZE);

    // function - print
    print(numberArray, SIZE);

    return 0;
}

// pass arrays - pass by reference
// avoid accidental changes - put a const before the argument
// array is same as pass by reference unless you use a const
void print(const int array[], int SIZE)
{
    // print out the address of the array
    cout<<"Memory address: "<<array<<endl;

    for (int i = 0; i < SIZE; i++)
    {
        // printing the index as well as the value at the index 2/ numberArray[i]
        cout << i << ": " << array[i] << endl;
    }
}

void input(int array[], int SIZE)
{
    for (int i = 0; i < SIZE; i++)
    {
        cin>>array[i]>>endl;
    }
}
// remember: pass-by-reference
// but = I *do* want to change the contents