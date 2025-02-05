/*
Today 
- Enumerated types (the role they play in assignment 4)
-File I/O
    - output
    - then, input from a file

- Exam 1 discussion
    - "Rules of Engagement" / instructions
    - Types of questions

Enumerated Types -> for assignment 4 
    - Single
    - Double
    - Triple
    - Home Run
    - Walk
    - Fly out
    - Pop out
    - Strike out
    - Double play
    - Sac Fly
    - Ground Out
    - not play
    enum needs to address all of these values

Create a program that prints out the numbers 1-100, one per line, in a file called numbers.txt.

instructions for exam1 feb 7
    - instructions - read
    - canvas 80 minutes 12:30 - 1:50 (1 attempt at this)
    - scratch paper

short answer questions (5) - similar style to the quiz
Brief Coding Questions (4)
    - write whatever needed to solve the problem
    - no #include, no printing of prompts

Tracing 
Long Coding Questions
    - write like you would a normal program full program

Make sure you can log into the lab machines
- uvawise email login/ canvas login
*/
#include<iostream> //any possible cin, cout
#include<fstream> // file I/O
using namespace std;

int main() {
    /*
    how to write a file:
    1. declare an ofstream variable
    2. open the file with the ofstream variable
    2.1. if the file doesn't exitst, it'll be created
    2.2. if the file does exist, it'll be overwritten
    3. output to the file
    4. closing the file
    */

   ofstream numberOutput; //ofstream variable - step 1

   numberOutput.open("numbers.txt"); //step 2 - what file?

    //write 1 - 100 to the file
   for (int value = 1; value <= 100; value++){

        //remember user output: cout<<value<<endl;
        numberOutput<<value<<endl; //output to the file (step 3)

   }

   numberOutput.close(); //step 4 - prevent data corruption

   cout<<"Program completed."<<endl;
    return 0;
}