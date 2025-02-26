#include<iostream>
using namespace std;

/*
CSC 1180 02 - Programming in C++
February 24, 2025 - Lecture 14
Demonstration of function overloading

Utilizing a function called max, taking in three arguments, returning the
largest of the three arguments
*/

int max(int num1, int num2, int num3){
   int temp;//for the greater between num1 and num2
   //verifying which version of max is called:
   cout<<"Called: max with three integers."<<endl;
   if(num1 > num2){
      temp = num1;
   }
   else{
      temp = num2;
   }
   if(temp>num3){//for the greater between num1/num2 and num3
      return temp;
   }
   else{
      return num3;
   }
}

double max(double num1, double num2, double num3){

   double temp;//for the greater between the first two doubles
   //verifying which version of max is called:
   
   cout<<"Called: max with three doubles."<<endl;
   
   if(num1 > num2){
      temp = num1;
   }
   else{
      temp = num2;
   }
   if(temp>num3){//for the greater between num1/num2 and num3
      return temp;
   }
   else{
      return num3;
   }
}

char max(char char1, char char2, char char3){

   char temp;//for greater ASCII value between characters
   cout<<"Called: max with three characters."<<endl;
   
   if(char1 > char2){
      temp = char1;
   }
   else{
      temp = char2;
   }
   if(temp>char3){//for the character greater between char1/char2 and char3
      return temp;
   }
   else{
      return char3;
   }

}

double max(double num1, double num2){
//looking for the greater between the two arguments passed in...
   cout<<"Called: max with two doubles."<<endl;
   if(num1 > num2){
      return num1;
   }
   return num2;
}

int max(int num1, int num2){
//looking for the greater between the two arguments passed in...
   cout<<"Called: max with two integers."<<endl;
   if(num1 > num2){
      return num1;
   }

   return num2;
}

/*
Output:

 Enter three decimal values: 4.59 -12.06 2.24
 Called: max with three doubles.
 Largest value: 4.59
 Enter three integer values: 4 85 61
 Called: max with three integers.
 Largest value: 85
 Enter three character values: ! / a
 Called: max with three characters.
 Largest valued character: a
 Enter two double values: 4.59 4.59
 Called: max with two doubles.
 Larger value: 4.59
 Enter two integer values: -5 -1
 Called: max with two integers.
 Larger value: -1

*/

/*
Having written the following functions above, they are at your disposal in main.
This is how the compiler will see them (roughly):

max(int, int, int)
max(double, double, double)
max(char, char, char)
max(double, double)
max(int, int)

by the definition of overloading, all five of the above are overloaded functions.
They all share the same name, but have different arguments:
1st - 3 integer arguments
2nd - 3 double arguments
3rd - 3 character arguments
4th - 2 double arguments
5th - 2 integer arguments
*/

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

//utilizing the overloaded function with two double arguments:
   cout<<"Enter two double values: ";
   cin>>double_input1>>double_input2;
   double_result = max(double_input1, double_input2);
   cout<<"Larger value: "<<double_result<<endl;
   
//utilizing the overloaded function with two integer arguments:
   cout<<"Enter two integer values: ";
   cin>>int_input1>>int_input2;
   int_result = max(int_input1, int_input2);
   cout<<"Larger value: "<<int_result<<endl;





   return 0;
}