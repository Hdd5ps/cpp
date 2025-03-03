#include<iostream>
using namespace std;

/*
Recursion - a solution that takes an argument and reduces it to an
easier, related problem.
Part 1: base case - stopping point for recursion
Part 2: recursive step - call the function again with some adjustment
to the argument so you can eventually reach the base case.

*/

//summation by repetition
int sumRepetition(int value){
   int sum = 0;
   for(int i = 1; i<=value; i++){
      sum+=i;
   }
   return sum;
}

//summation by recursion
int sumRecursion(int value){
   if (value == 1){//base case
      return 1;
   }
   return value + sumRecursion(value - 1);//recursive step
}

//factorial by repetition
int factorialRepetition(int value){
   int product = 1;
   for(int i = 1; i<=value; i++){
      product *= i;
   }
   return product;
}

//factorial by recursion
int factorialRecursion(int value){
   if(value == 1){//base case
      return value;
   }
   return value * factorialRecursion(value - 1); //recursive step
}

int main(){
   int choice, input;
   //choice - for the menu below
   //input - user input for the argument of whichever call
   cout<<"1) Sum by Repetition Statements"<<endl;
   cout<<"2) Sum by Recursion"<<endl;
   cout<<"3) Factorial by Repetition Statements"<<endl;
   cout<<"4) Factorial by Recursion"<<endl;
   cout<<"Your selection: ";
   cin>>choice;
   cout<<"Enter a value: ";
   cin>>input;
   switch(choice){
      case 1: //call iterative sum, print result
         cout<<sumRepetition(input)<<endl;
         break;
      case 2: //call recursive sum, print result
         cout<<sumRecursion(input)<<endl;
         break;
      case 3: //call factorial via loops, print result
         cout<<factorialRepetition(input)<<endl;
         break;
      case 4: //call favorial via recursion, print result
         cout<<factorialRecursion(input)<<endl;
         break;
      default: //covers the case where the user enters an invalid input.
         cout<<"Not a valid option"<<endl;
   }

   return 0;
}