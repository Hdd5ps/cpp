/*
Python
-Addition +
-Subtraction -
-Multiplication *
-Exponential **
-Division /
-Remainder %
                                    ORDER OF OPERATION
C++                                 Parenthesis
-Addition +                         Exponents
-Subtraction -                      Multiplication
-Multiplication *                   Modulus
-Division /                         Division
-Remainder %                        Addition and Subtraction
-Exponential we don't have that here

ORDER OF OPERATIONS W/PRECEDENCE:
PARENTHESES
MULTIPLICATION DIVISION MODULUS
ADDITION, SUBTRACTION

EX; (7*(9/3))5.0
    Break ties in precedence, go left to right

Assignment operator =
Value to store = (expression) -> calculation, another, variable, constant

int a = 18, b = 5;
cout<<a/b<<endl; what gets printed
3 is printed out since integer is assigned int/int -> int result

casting -> temporarily reassigning to another type
denoted by: (type)
cout<<(double)a/b<<endl; what gets printed
3.6 is printed out

shorthand
+= count = count + 5; count+=5;
-= num = num - 2; num-=2;
*= result = result * 3; result*=3;
/=
%=

increment/decrement operators
++
--
count = count + 1; either count+=1; or count ++; or ++count;

count = count - 1; count -=1; count--; --count;

++before -> ++count 
-increment then use count
++after -> count++
-use then increment count
same for --

int count = 5; int count = 5;
int result = 7*(++count) -> 7 * 6
prints 42

int result = 7(count++) -> 7* 5
prints 35

Relational Operators
greater than >
less than <
greater than or equal to >=
less than or equal to <=
equal to (equivalency) ==
not equal to !=


if statements to facilitate


#include<iostream>
using namespace std;

int main(){
    int a = 18, b = 6;
cout<<(double)(a/b)<<endl;
    return 0;
}
//3 is printed
#include<iostream>
using namespace std;

int main() {
    int sum; //do not initailize
    cout<<sum<<endl;

    return 0;
}
prints 0
*/
