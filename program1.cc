/*
Kamal Raj Timilsena
jan 18 2025
Programming Assignment 1

this program will do the basic mathematical calculations such as addition, subtraction, multiplication and division

Algorithm:
1. Take in a pair of numbers ot a time declare variables as doubles
2. Do the addition and multiplication
3. Cast as integer and do the subtraction and Division
*/
#include<iostream>
using namespace std;

int main(){
    double num1, num2, add, sub, mul, div; //declare variables

    //addition
    cout<<"Addition - Please Input Two Doubles:"; //input statement
    cin>>num1>> num2;
    add = num1 + num2;
    cout<<"Addition Result: "<<add<<endl;

    //subtraction
    cout<<"Subtraction - Please Input Two Integers:";
    cin>>num1>> num2;
    sub = num1 - num2;
    cout<<"Subtraction Result: "<<(int)sub<<endl;

    //multiplication
    cout<<"Multiplication - Please Input Two Doubles:";
    cin>>num1>> num2;
    mul = num1 * num2;
    cout<<"Multiplication Result: "<<mul<<endl;

    //division
    cout<<"Division - Please Input Two Integers:";
    cin>>num1>> num2;
    div = num1 / num2;
    cout<<"Division Result: "<<(int)div<<endl;

    cout<<"Program Complete"<<endl;
    return 0;
}