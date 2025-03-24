
#include "assignment7.h"
using namespace std;

int main(){

   const int SIZE = 7; //convention for const is all-caps
   int battersLine[SIZE]; //set array's size to that of SIZE
   //better programming practice:  take a second argument
   //that represents the size of the array.  If you change the
   //size of the array later, you only have to make one change
   //on one line - the declaration line.
   initialize(battersLine, SIZE); //sets up the array, as well as srand() call
   playBall(battersLine, SIZE); //the function doing the "heavy lifting"
   printStatsToFile(battersLine, SIZE); //prints the stats recorded to a file called a7results.txt

}