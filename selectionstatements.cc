/*
CSC 1180, Section 2 - 1/22/25
Assignment 1 - due tonight
Assignment 2 - 
Quiz 1 - Friday, Coverage : throught today
Today: Selction STatements

Friday: input, output, calculations, assignment,....
relational operators
== > >=
!= < <=

C++ Format = single selection statement
if (condition){
all code to run if this condition is true
}
if (x>10){

} -> if x is greater than 10

Double Selection Statement
if (condition) j{
statements to do if conditions met
}
else{
if condition isn't met run these statements
}

if you have an if, you don't necessarily need to have an else
if (GPA > sth) {
print the honor
}
else is not necessary here

if/else -> stacked 
if (){
.
.
.
}
else{
 if (){
 .
 .
 .
 }
}


if (){
}
if (){}
else{}
if (){}

#include<iostream>
using namespace std;

int main(){
    // take in a number (int)
    // if greater than 60, print passed, otherwise print fail
    int score; //variable for input

    cout<<"Enter a score: ";

    cin>>score;

    //double-selection statement: if, followed by else

    if (score>=60){
        cout<<"Passed"<<endl;
    }

    else{
        cout<<"Failed"<<endl;
    }

    if (score>=80){ //reconize the achievement - A or B
        cout<<"Good job"<<endl;
    }
    return 0;
}
#include<iostream>
using namespace std;

int main() {
    // final grade report
    // print the letter grade that goes with the score
    double score;
    cout<<"Enter score: ";
    cin>>score; //input for score from user

    //check to see if there's A, B, C, D, or F

    cout<<"Grade: ";

    //stacking one if on top of another

    if (score>=90){
        cout<<"A"<<endl;
    }
    if (score>= 80){
        cout<<"B"<<endl;
    }
    if (score>=70){
        cout<<"C"<<endl;
    }
    if (score>=60){
        cout<<"D"<<endl;
    }
    else {
        cout<<"F"<<endl;
    }
    return 0;
}

prints out all the grades if the grade is higher because of which i wouldn't recommend using stacking if statements
#include<iostream>
using namespace std;

int main() {
    // nested if statements
    double score;
    cout<<"score: ";
    cin>>score;

    if (score>90){
        cout<<"A"<<endl;
        else{
        if (score > 80){
            cout<<"B"<<endl;
            else{
            if (score > 70){
                cout<<"C"<<endl;
                else{
                if (score > 60){
                    cout <<"D"<<endl;
                    else{
                        cout<<"F"<<endl;
                    }
                }
                }
            }
            }
        }
        }
    }

    return 0;
}


Logical Connectives
AND - && Both sides have to be true
OR - || one side needs to be true
NOT = ! logical opposite


p q p&&q p||q !p
T T T    T    F
T F F    T    F
F T F    T    T
F F F    T    T

Tommorw is (1/24) Quiz
I/0
arithmetic/shortcuts
relational operators -> rules, order of precedence, trekay ties

5 questions
3 Short questions
2 coding snippets
write lines of code in C++
do only what needs to be done 
-no complete programs 
-priting prompts -> out
straighforward no bs type question

will be online, 1/2 hour to complete

if (num % 2 == 0){  remainder is zero 'even'
cout<<"yes"<<endl;
}
else{
cout<<"no"<<endl;
}

if (num % 5 == 0){
cout<<"evenly divisible by 5"<<endl;
}

if (Num % 13 == 0){
cout<<"it is divisible by thirteen"<<endl;
}
*/
// if - 1ast conditon
// elif - python => else if condition
// else

// exapmple of multiple selection
#include<iostream>
using namespace std;


int main() {
    double score;

    cout<<"score: ";
    cin>>score;
    if (score >= 89.5){
        cout<<"A"<<endl;
    }
    else if (score >= 79.5){
        cout<<"B"<<endl;
    }
    else if (score >= 69.5){
        cout<<"C"<<endl;
    }
    else if (score >= 59.5){
        cout<<"D"<<endl;
    }
    else {
        cout<<"F"<<endl;
    }
    return 0;
}