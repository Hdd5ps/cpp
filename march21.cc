/*

Programming Assignment 7: due 3/26, by 11:55pm
Assignment 8 will go out shortly after, due 4/2, by 11:55pm

Class -> online asynchronous from 3/24 - 4/11
- Show up for Quiz 3 on 3/28 (in - person)
- Show up for labs (in - person)

Never state, but use the arrays the way I have shown; don't use the book's route.

Today: Vectors

Vectors are a sequence container that encapsulates dynamic size arrays.

- store a lot of values just like arrays
- flexible in size (arrays, not)

-> new library:
#include <vector>

declare a vector:

vector<int> v; // v is a vector of integers

vector<datatype> nameOfVector(size); // size is the number of elements in the vector

- can only store values of one type (int, double, char, etc.)

size -> returns number of elements in the vector
resize -> changes the size of the vector
push_back(item) -> adds an element to the end of the vector
pop_back(item) -> removes the last element of the vector
clear -> removes all elements from the vector
empty -> returns true if the vector is empty, false otherwise
at or [] for arrays or .at() for strings -> returns the element at a specific position in the vector
front -> returns the first element in the vector
back -> returns the last element in the vector
swap -> swaps the contents of two vectors
erase -> removes an element from the vector
insert(POS, ITEM) -> inserts an element into the vector at specified position


array vs vector:
- arrays are fixed size, vectors are dynamic
- arrays are not objects, vectors are
- arrays are not passed by value is we pass the entire array, vectors have lots of data
- arrays are not passed by reference if passed individual cells, vectors are
- arrays are not initialized, vectors are
- arrays are not copied, vectors are
- arrays are not assigned, vectors are
- arrays are not compared, vectors are
- arrays are not resized, vectors are



ex. 1:
#include <iostream> // cin, cout, endl
#include <vector> // vector type
using namespace std;

int main(){
//declare a vector of integers
vector<int> intVector; // generic data type (giveaway: <int>)
// the argument for seeting up a vector's size is optional/default
vector<double> doubleVector(10); // generic data type (giveaway: <double>)
cout<<intVector.size()<<endl; // 0
cout<<doubleVector.size()<<endl; // 10



//how to put information into a vector?
for (int i = 0; i < 10; i++){
    intVector.push_back(i); // add items from the back

    // check the size of intVector
    cout<<intVector.size()<<endl; // 1, 2, 3, 4, 5, 6, 7, 8, 9, 10


    if (doubleVector.empty()){
        cout<<"doubleVector is empty"<<endl;
    }
    else{
        cout<<"doubleVector is not empty"<<endl;
    }

    // how is doubleVecotr not empty?

    cout<<"Enter an integer (or -1 to quit): ";
    cin>>input;
    while (input != -1){
        cin>>input;
        intVector.push_back(input);
        cout<<"Size of intVector: "<<intVector.size()<<endl;
        cout<<"Enter an integer (or -1 to quit): ";
        cin>>input;
    }
    for (int i = 0; i < doubleVector.size(); i++){
        cout<<doubleVector[i]<<endl; // 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    }
        // interesting side-effect: all values set to zero
        // if you give vector a size but no values, it will set all values to zero
        // int or double
        // char - null characters
        //vector<char> charVector(10); // 10 null characters
        //vector<string> stringVector(10); // 10 empty strings

    // put something into the doubleVector
    doubleVector.at(0) = 3.14159; // put 3.14159 into the first element of the doubleVector
    cout<<doubleVector.size()<<endl; // 10
}

return 0;
}
*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <stdexcept>
using namespace std;

void outputVector(const vector<int>&); // display the vector
void inputVector(vector<int>&); // input values into the vector

int main(){
    vector<int> integers1(7); // 7-element vector<int>
    vector<int> integers2(10); // 10-element vector<int>

    // print integers1 size and contents
    cout << "Size of vector integers1 is " << integers1.size() << "\nvector after initialization:" << endl;
    outputVector(integers1);

    // print integers2 size and contents
    cout << "\nSize of vector integers2 is " << integers2.size() << "\nvector after initialization:" << endl;
    outputVector(integers2);

    // input and print integers1 and integers2
    cout << "\nEnter 17 integers:" << endl;
    inputVector(integers1);
    inputVector(integers2);

    cout << "\nAfter input, the vectors contain:\n"
         << "integers1:" << endl;
    outputVector(integers1);
    cout << "integers2:" << endl;
    outputVector(integers2);

    // use inequality (!=) operator with vector objects
    cout << "\nEvaluating: integers1 != integers2" << endl;
    if (integers1 != integers2){
        cout << "integers1 and integers2 are not equal" << endl;
    }

    // create vector integers3 using integers1 as an initializer; print size and contents
    vector<int> integers3(integers1); // copy constructor

    cout << "\nSize of vector integers3 is " << integers3.size() << "\nvector after initialization:" << endl;
    outputVector(integers3);

    // use overloaded assignment (=) operator
    cout << "\nAssigning integers2 to integers1:" << endl;
    integers1 = integers2; // assign integers2 to integers1

    cout << "integers1:" << endl;
    outputVector(integers1);
    cout << "integers2:" << endl;
    outputVector(integers2);

    // use equality (==) operator with vector objects
    cout << "\nEvaluating: integers1 == integers2" << endl;
    if (integers1 == integers2){
        cout << "integers1 and integers2 are equal" << endl;
    }

    // use square brackets to use the value at location 5 as an rvalue
    cout << "\nintegers1[5] is " << integers1[5];

    // use square brackets to create lvalue
    cout << "\n\nAssigning 1000 to integers1[5]" << endl;
    integers1[5] = 1000;
    cout << "integers1:" << endl;
    outputVector(integers1);

    // attempt to use out-of-range subscript
    try {
        cout << "\nAttempt to display integers1.at(5)" << endl;
        cout << integers1.at(5) << endl; // ERROR: out of range
    } catch (out_of_range &ex){
        cerr << "An exception occurred: " << ex.what() << endl;
    }

    // changing the size of the vector
    cout<<"\nCurrent integers3 size is: "<<integers3.size()<<endl;
    integers3.push_back(1000); // add 1000 to the end of the vector
    cout<<"New integers3 size is: "<<integers3.size()<<endl;
    cout<<"New integers3 contents are: "<<endl;
    outputVector(integers3);
}

// output vector contents
void outputVector(const vector<int> &array){
    for (int item : array){
        cout << item << " ";
    }
    cout << endl;
}

// input vector contents
void inputVector(vector<int> &array){
    for (int &item : array){
        cin >> item;
    }
}