/*
CSC 1180 - 2/3/25
Reminders: Assignment due Wednesday night
    - Next Assignment out on Wednesday
    - Exam 1 - Thursday (2/6)
    - coverage ; throught 1/31 lecture

Assignment -> prompting user for 2 numbers
            - print out the corresponding play
            
-reverse?
-several conditions
writing meaningful, self-documenting code

Enumerated type
type of integer (can't explicittly add/ops b/t enumerated type and an int)

enum                                Enumerated Type Name        { };
^                                               ^                ^
compiliter -> creating a new type | the name of the type | the value that the enumerated type could be

- "magic numbers"
    - student iniformation system,
        encounter a 4 -> gpa (exception to the rule (decimal))
                        -> classification
                        -> class time
                        -> month for d.o.b

Classification - freshman, sophomore, junior, senior, non-degree - earning

enum Classification  {FRESHMAN, SOPHOMORE, JUNIOR, SENIOR, NONDEGREE};
                                                                        ^
- anything that is a constant is in all caps,                        all caps list -> aids in readability
- immediately demystifies the classification in the code/ no longer confusing
- finite series of values
    Classification -> 5

if (classificatin == 4)

int main(){
Classificatin studentClassification; //optional to assign
}

switch statements
    -integer -> +- 2 billion
    -boolean -> 0, 1
    -characters -> ASCII code -> 0 to 255 ( '0' -> code 40, '9' -> code 49, 'a' -> code 65, 'A' -> code 97)

    string s1, s2;
    s1 > s2 -> does s1 comes alphabetically after s2 ? 

switch (studentClassification){
case FRESHMAN:
.
.
.
    break;
case SOPHOMORE:
.
.
.
    brea;
default: //nondegree
    break;
}


enum Month {JAN, FEB, MAR, APR, MAY, JUN, JULY, AUG, SEP, OCT, NOV, DEC};
swithc (dobMonth){
case JAN:
.
.
.
    break;
case FEB:
.
.
.
    break;
}
.
.
default:
break;

can do arithmetic enumTypeint X
                    ^
                    cast as an int
                    ^
                    (int)enumType + int

standar i/o:
cout<<num1;
cin>>num1>>endl;

File I/O
outfile<<num1;
infile>>num1>>endl;

step 1 : use a new library i.e #include<fstrea> -> read from or write to a file

ofstream variables -> output
ifstream variables -> input

open an output file:
1. ofstream variableName; -> declare variable type
2. variableName.open("filename"); -> whatever.dat.names.type
                        ^
                        includes file extension
3. variableName << value1 <<value2;
4. close the file -> variableName.close();

1. 2. loop 3. 4. prevents data corruption if 4. process done after getting done with the loop

writing to a file
got to step 2 -> if file does not exist, it will be created
                -> if file does exist, it will be overwritten

looking for output file? in same folder as the program 

file input
1. create a file input variable
2. have the variable be tied to a particular file
3. read from the file 
4. close the file

Does the file exist? if not, program will terminate abruptly.
read
-> eof -> sentinal control loop
-> read until failure -> loop

ifstream infile; step 1
infile.open("data.txt"); step 2
int input;
^
infile >> input;                            while(inflie>>input){
while(!infile.eof()){ sentinal controlled   .// read until failure
//do whatever here                          .
infile>> input;                             .}
}
infile.close

*/