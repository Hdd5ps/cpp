/*
CSC 1180 - January 29, 2025
- Assignment 2 due tonight
- Assignment 3 posted, due 2/5/25
- Today and Tomorrow: Loops

Next Thursday (2/6) -> Exam 1

3 types of statements (structurally)
i. sequence I/O, calculattions, assignment
ii. selection conditional statement if, else, switch, case
iii. repetition loops - while, for, do while 
do while gurantees one pass throught the loop

Steps to set up a loop
1. define/initiate a loop control variable
2. condition -> loop variable utilized ?
3. update the loop control variable

logically, 2 different types of loops
- count controlled (we know how many times loop will run)
- sentinal controlled (don't know # of times loop will run, but do know the condition to terminate)

Take in integers -1 signals the stopping point of taking in input for sentinal controlled loop.

cin>>userInput;

while (userInput!=-1){
....
cin>>userInput;
}

for loops 
- python -> use range, list/array assigned to variable, iterate through a string)
    for x in range(start, end, step) stop one away from end

C++: 
    for (value/variable declarations; condition; update){
    }

    for ( ; ; ;)
    C++ expects 3 parts to a for loop

count controlled loops
for (int i = 0; i < 50; i++){

cout<<i<<endl; compiliation error for loop: block of code ; leave a block of code -> any declared variables within the block do not exist
}

int i;
for ( i = 0; i < 50; i++){

}
i will still be available after the block of code

you can write a loop using any kind of loop

int i = 0;
while (i<50){
....
i++
}

for loop is tailor made for count controlled loops
while loop is tailor made for sentinal control loops

for (char c = 'y'; c=='y'; cin>>c){
}

for (char c = 'y'; c == 'y'; ){
cin>>c;
}

do while -> guaranteed one pass through the loop

do{ step 3 done in the loop
.
.
.
}(condition); step 2

int userInput;

do{
cin>>userInput;
...
} while(userInput != -1);

int userInput = 5;
do{
if (userInput % 2 == 1){
cout<<"odd"<<endl;
}
else{
cout<<"even"<<endl;
}
cin>>userInput;
} while(userInput != -1)


sentinel controlled loop
int userInput;
cin>>userInput;
if(userInput != -1){
    do{
    if (userInput )}
    cout<<"odd"<<endl;
    }
    else{
    cout<<"even"<<endl;
    }
    cin>>userInput;
    }while(userInput i != -1);

Three types of loops (syntactically)

while - > step1, step2, step3 in the loop
 test for continuing the loop

 for -> for (step1; step2; step3){
 be careful variables here
 }

 do-while -> step1, step23, step2
    - guaranteed one pass
}
*/

#include<iostream>
using namespace std;

int main(){
    for (char c = 'y'; c == 'y'; ){
    cin>>c;
    }
    return 0;
}