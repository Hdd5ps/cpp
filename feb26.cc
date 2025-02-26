/*
New assignment - due 3/5 Exam 2 - 3/4 (lab time)
Today: looking back at overloading reference parameters?
reference parameteres -> if not today, will be in tomorrow's lab.


// function templates - function calls that have same logic, 
// you're just dealing with a different type

// function called - compiler creates a "version" of that
// function
// function template: have a placeholder for the type

#include<iostream>

using namespace std;


template<class T>
    T max(T num1, T num2, T num3){
    //  T - placeholder for a type (the same type)
    // max(int, int, int)
    // max(double, double, double)
    // max(char, char, char)

    T temp;
    // look at first two values...

    if (num1 > num2){
        temp = num1;
    }
    else{
        temp = num2;
    }

    if (temp > num3){
        return temp;
    }
    else{
        return num3;
    }
}

int main(){

    //variable declarations for the various versions of max:
       double double_input1, double_input2, double_input3, double_result;
       int int_input1, int_input2, int_input3, int_result;
       char char_input1, char_input2, char_input3, char_result;
    
    //utilizing the overloaded function, with three double arguments:
       cout<<"Enter three decimal values: ";
       cin>>double_input1>>double_input2>>double_input3;
       double_result = max(double_input1, double_input2, double_input3);
       cout<<"Largest value: "<<double_result<<endl;
    
    //utilizing the overloaded function, with three int arguments:
       cout<<"Enter three integer values: ";
       cin>>int_input1>>int_input2>>int_input3;
       int_result = max(int_input1, int_input2, int_input3);
       cout<<"Largest value: "<<int_result<<endl;
    
    //utilizing the overloaded function with three char arguments (greatest ASCII value):
       cout<<"Enter three character values: ";
       cin>>char_input1>>char_input2>>char_input3;
       char_result = max(char_input1, char_input2, char_input3);
       cout<<"Largest valued character: "<<char_result<<endl;
    

    
       return 0;
    }


Enter three decimal values: 2 3 3
Largest value: 3
Enter three integer values: 2 3 4
Largest value: 4
Enter three character values: a b c
Largest valued character: c

#include<iostream>
using namespace std;

// scope - visibility of a name
// -global scope (global variables)
// -block scope (for int i = 0; ...), then i
// -function prototype scope - names to the arguments
// auto/static - how long does the name last in memory?
// auto: default, what've used the whole time
// static: explicit declaration needed; historical reasons for having?

int min(int num1, int num2){
    int timesRun = 0; // auto variable; resets each time.
    cout<<timesRun<<endl;
    timesRun++;

    if(num1<num2){
        return num1;
    }
    else {
        return num2;
    }
}

double min(double num1, double num2){
    static int timesRun = 0; // auto variable; resets each time.
    // once program starts running, space is set in memory for
    // timesRun, and it will remain until the program terminates.
    cout<<timesRun<<endl;
    timesRun++;

    if(num1<num2){
        return num1;
    }
    else {
        return num2;
    }
}

int main(){
    int int_result;
    double double_result;
    int loopCounter = 0;
    // test for continuance
    while(loopCounter<10){
        double_result = min(2.4, 5.1);
        int_result = min(6, 1);
        loopCounter++;
    }

    return 0;
}


0 double static
0 int auto
1 double static
0 int auto
2 double static
0 int auto
3 double static
0 int auto
4 double static
0 int auto
5 double static
0 int auto
6 double static
0 int auto
7 double static
0 int auto
8 double static
0 int auto
9 double static
0 int auto
*/

