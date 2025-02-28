/*
Recursion => function that calls itself to solve an easier, related problem

Part 1: base case -> "stopping point"
Part 2: recursive step -> "call to itself with a simpler argument"


Pros:
 - elegant -> fewer lines of code; innovative solution
    - decomposing the arguments so as to eventually reach the base case
 - program stack -> any time a function is called, it's added to the program stack; encounter longer waittimes (as opposed to an iterative solution)

For eg:
Sum of a series -> from 1 to n
                1 + 2 + 3 + .. + n - 1 + n

int sum(int numbers){
    if (number == 1){  // base case / stopping point
        return 1;
    }
    return numbers + sum(number - 1); -> recursive step (function calls itself) -> reduction of the original arguments
}

somewhere in main
cout<<sum(4)<<endl;

| sum(1) -> ret 1
| sum(2) -> ret 2 + sum(1) = 3
| sum (3) -> ret 3 + sum(2) = 6
| sum (4) -> ret 4 + sum(3) = 10
|main + variables; sum(4) = 10

printed to the screen - 10
int factorial(int n)
{
    if (n == 1){
        return 1;
    }

    return n * factorial(n - 1);
}

int main() {


    int number;

    cout<<"Enter a number: ";
    cin>>number;
    int factor = factorial(number);
    cout<<"The factorial of your number is: "<<factor<<endl;

    return 0;
}
// solution
// Enter a number: 4
// The factorial of your number is: 24
*/
#include<iostream>
using namespace std;

// runtime = 2^n
// 10th number of sequece = 2^10 fun from calls 1024
// 20th number of sequemce = 2**20 function calls million
int fibonacci(int n){
    if (n==1){
        return 1;
    }

    if (n==2){
        return 1;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

int main()
{
    int number;

    cout<<"Enter a number: ";
    cin>>number;
    int fibonnaci = fibonacci(number);
    cout<<"The fibonacci upto your number is: "<<fibonnaci<<endl;

    return 0;
    return 0;
}
// stack would look like this
// | fib(1) = 1; fib(2) = 1
// |fib(3) = fib(2) + fib(1) = 2
// | fib(4) = fib(3) + fib(2) = fib(2) + fib(1) + fib(2) = 3
// |fib(5) = fib(4) + fib(3) = fib(2) + fib(1) + fib(2) + fib(2) + fib(1) = 5
// | fib(6) = fib(5) + fib(4) = fib(2) + fib(1) + fib(2) + fib(2) + fib(1) + fib(2) + fib(1) + fib(2) = 8
// | fib (7) = fib(6) + fib (5) = fib(2) + fib(1) + fib(2) + fib(2) + fib (1) +fib(2) + fib(1) + fib(2) + fib(2) + fib(1) + fib(2) + fib(2) + fib(1) = 13
// | main -> fib (7)

// Enter a number: 7
// The fibonacci upto your number is: 13