#include<iostream>
using namespace std;

//working with default arguments for all values
//note:  once you start using default arguments in function definitions,
//you cannot stop.

double volume(double length = 1, double width = 1, double height = 1){
   return length*width*height;
}

/*
output:

 Calling volume without parameters added
 Result: 1
 
 Enter the length: 5.5
 Calling volume with first parameter (length) specified.
 Result: 5.5
 
 Enter the length: 5.5
 Enter the width: 2.1
 Calling volume with first two parameters specified.
 Result: 11.55
 
 Enter the length: 50
 Enter the width: 2
 Enter the height: 12
 Calling volume with all parameters specified.
 Result: 1200
 
 */
 
 /*
 with the way volume is written, there are possibly four different
 prototypes/headers for the compiler to match up with:
 
 volume()
 volume(double)
 volume(double, double)
 volume(double, double, double)
 
 */

int main(){
   double input1, input2, input3, result;
//showing the four possible function calls

//this first one: go with length = 1, width = 1, height = 1,
//the default arguments
   cout<<"Calling volume without parameters added"<<endl;
   result = volume();
   cout<<"Result: "<<result<<endl<<endl;
   
   //calling with one argument
   cout<<"Enter the length: ";
   cin>>input1;
   cout<<"Calling volume with first parameter (length) specified."<<endl;
   result = volume(input1); //width and height are each 1.
   cout<<"Result: "<<result<<endl;
   
   //calling with two arguments
   cout<<endl<<"Enter the length: ";
   cin>>input1;
   cout<<"Enter the width: ";
   cin>>input2;
   cout<<"Calling volume with first two parameters specified."<<endl;
   result = volume(input1, input2); //height is 1.
   cout<<"Result: "<<result<<endl;
   
   //calling with three arguments
   cout<<endl<<"Enter the length: ";
   cin>>input1;
   cout<<"Enter the width: ";
   cin>>input2;
   cout<<"Enter the height: ";
   cin>>input3;
   cout<<"Calling volume with all parameters specified."<<endl;
   result = volume(input1, input2, input3);
   cout<<"Result: "<<result<<endl;
   
   

   return 0;
}