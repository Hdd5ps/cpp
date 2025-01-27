/*
Example problem:

Let the user enter an integer value, then ask what number they're check to see if divisible by...

%2 - even/odd
%3 - divisible by 3?
%4 - divisible by 4?
int main(){
    int userInput, divisor; //userInput - number, divisor - divide by this number.

    cout<<"Enter a number: ";
    cin>>userInput;
    cout<<"What number to check to see if evenly divisible? ";
    cin>>divisor;

    switch(userInput % divisor){
        //check to see if input is evenly divisible
        //divisor = 2; possible results: 0 (evenly divisible), 1 (not divisible)
        //divisor = 3; possible results: 0 (evenly divislbe), 1 or 2 (not)
        //divisor = 7; possible results: 0 (evenly divisible), 1, 2, 3, 4, 5, 6, 7 (not)

        case 0:
        cout<<userInput<<" is evenly divisible by "<<divisor<<endl;
        break; //vital to end one case before starting another
                // unless you're doing so by design....

        default:
        cout<<userInput<<" is not evenly divisible by "<<divisor<<endl;
        break;
    } //end of switch
    return 0;
}

Repetion statements - Loops
Python loops - while, for, (iteration)
C++ - while, for, do..while

Steps needed to set up a loop:
1. define/intialize loop control variable
2. use loop control variable via condition
3. update the loop control variable - not present? infinite loop.
//while looks like if statement
if (Condtion){
}

while:

//example of sentinel control loop. you don't know how many times the loop will run but you know the condition that will terminate the loop.
it is used a bit in reading files
while (condition){
}
    int userInput, divisor; //userInput - number, divisor - divide by this number.

    char answer = 'y'; //step 1 of setting up a loop

    while (answer == 'y'){ // step 2 of setting up a loop testing if the loop is continuing or not

    cout<<"Enter a number: ";
    cin>>userInput;
    cout<<"What number to check to see if evenly divisible? ";
    cin>>divisor;

    if (divisor == 0){
        cout<<"not possible; dividing by 0 leads to an undefined answer. "<<endl;
    }
    else{

    switch(userInput % divisor){
        //check to see if input is evenly divisible
        //divisor = 2; possible results: 0 (evenly divisible), 1 (not divisible)
        //divisor = 3; possible results: 0 (evenly divislbe), 1 or 2 (not)
        //divisor = 7; possible results: 0 (evenly divisible), 1, 2, 3, 4, 5, 6, 7 (not)

        case 0:
        cout<<userInput<<" is evenly divisible by "<<divisor<<endl;
        break; //vital to end one case before starting another
                // unless you're doing so by design....

        default:
        cout<<userInput<<" is not evenly divisible by "<<divisor<<endl;
        break;
    }
    cout<<endl; //adds a space makes output more readable
    cout<<"Do you want to continue checking numbers? (y/n)? ";
    cin>>answer; //marks the third step of the loop

    return 0;
    }
}

 just through x number of integers
  prompt the user to enter a value
  program will print out all results from 1 to that divisor
*/

// logically speaking, two different types of loops:
//count controlled loop - know how many times loop runs (this program)
// sentinel - controlled loop - program ending 
#include<iostream>
using namespace std;

int main(){
    int userInput, divisor; //userInput - number, divisor - divide by this number.
    int count = 1; //setting aup loop control variable - step 1

    cout<<"Enter a number to check divisibility: ";
    cin>>userInput;
    cout<<"What number to check to see if evenly divisible? ";
    cin>>divisor;

    while (count<=divisor){
        
    if (divisor == 0){
        cout<<"not possible; dividing by 0 leads to an undefined answer. "<<endl;
    }
    else{

    switch(userInput % count){// check 1, 2, 3,.., up to divisor
        //check to see if input is evenly divisible
        //divisor = 2; possible results: 0 (evenly divisible), 1 (not divisible)
        //divisor = 3; possible results: 0 (evenly divislbe), 1 or 2 (not)
        //divisor = 7; possible results: 0 (evenly divisible), 1, 2, 3, 4, 5, 6, 7 (not)

        case 0:
        cout<<userInput<<" is evenly divisible by "<<count<<endl;
        break; //vital to end one case before starting another
                // unless you're doing so by design....
                // optionally, cut out extraneous output that user has to parse through

        // default:
        // cout<<userInput<<" is not evenly divisible by "<<count<<endl;
        // break;
    } //end of switch
    }
    count = count + 1;
    }

}