#include<iostream>
using namespace std;

int iterativeFibonacci(int sequenceNumber){
   int current = 1, previous = 1, older = 1;
   //current = current number just calculated in sequence
   //previous = the number just previous to the current
   //older = the number that was two numbers away from the current
   //in the fibonacci sequence.
   
   //if the user enters 1 or 2, we have the first two numbers of
   //the sequence already; we will not enter the loop.
   for (int i = 3; i<=sequenceNumber; i++){
      current = previous + older; //sum of previous 2 numbers in sequence.
      older = previous; //n-2 is assigned as n-1
   //move the previous value to take up the position 
   //of the first number to add
      previous = current;
   //get ready for next pass through the loop; move the
   //the value of current into previous
   }
   return current;
}

int recursiveFibonacci(int sequenceNumber){
//elegant - fewer lines of code, no variables to declare
   if(sequenceNumber == 1){ 
   //takes care of both base cases - looking for the first two numbers 
   //in sequence
      return 1;
   }
   if(sequenceNumber == 2){
      return 1;
   }
//recursive step:
   return recursiveFibonacci(sequenceNumber - 1) + recursiveFibonacci(sequenceNumber - 2);
//calling the same function twice to get the last two numbers in the sequence
//and add them together.
}

int main(){
   int input; //user input for the sequence number argument
   cout<<"Enter an integer value: ";
   cin>>input;
   cout<<endl<<"Iterative result: "<<iterativeFibonacci(input)<<endl;
   cout<<"Recursive result: "<<recursiveFibonacci(input)<<endl;
//you won't see a big change in performance until around maybe
//the 35th or 40th number in the sequence
   return 0;
}