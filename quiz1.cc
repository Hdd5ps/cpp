/*
Kamal Raj Timilsena
Jan 24 2025
Quiz 1

Write a program that prompts the user for character input.Determine if a consonant or vowel
-assume correct input
-assume lower-case only

char input;
cin>>input;
if (input == 'a'){
cout<<"vowel"<<enld;
}
else if (input == 'e'){
cout<<"vowel"<<enld;
}
else if (input == 'i'){
cout<<"vowel"<<enld;
}
else if (input == 'o'){
cout<<"vowel"<<enld;
}
else if (input == 'u'){
cout<<"vowel"<<enld;
}
else{ //"catch all"
cout<<"consonant"<<enld;
}


Switch statements/cases (new material) -> not discussed in python
switch is a multiple selection statement.

char input;
cin>>input;

switch (input){
case 'a':
    cout<<"vowel"<<endl;
    break;
case 'e':
    cout<<"vowel"<<endl;
    break;
case 'i':
    cout<<"vowel"<<endl;
    break;
case 'o':
    cout<<"vowel"<<endl;
    break;
case 'u':
    cout<<"vowel"<<endl;
    break;
defalut:
    cout<<"consonant"<<endl;
    break;
}

switch (expression/condition){ //limitations to use only int, char, boolean because of them being distinct values means they are precise and accurate
case __ ; //do this
    break; //gets you out of the switch statement
case __ ;
    break;
default: ___//"catch all"
    break;
}

why break?
-signals the end of what you want to do with that particular case.
-if you don't have the break -> "cascading switch"
    -go on to next case and go through that case's steps, too.


char input;
cin>>input;
switch (input){
case 'a':
case 'e':
case 'i':
case 'o':
case 'u': 
    cout<<"vowel"<<endl;
    break;
default:
    cout<<"consonant"<<endl;
    break;
}

algorithm
*/
#include<iostream>
using namespace std;

int main(){
    
    return 0;
}