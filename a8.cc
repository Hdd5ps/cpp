#include "assignment8.h"
#include <string>
using namespace std;

int main(){

   const int ROW_SIZE = 9; //Nine Batters
   const int COL_SIZE = 7; //Each of the Statistical Categories
   int battingOrder[ROW_SIZE][COL_SIZE];
   string lineup[ROW_SIZE]; //for the names of the nine batters
   initialize(battingOrder, ROW_SIZE, COL_SIZE, lineup); 
   //initialize what you need to here - battingOrder and lineup.
   //playBall has a similar functionality to the last playBall
   //call...and just like Assignment 7, there might be something you
   //could use from a previously-completed .h file.
   playBall(battingOrder, lineup, ROW_SIZE);
   //run through the 9 innings, then print out each batter's stats
   //to the file a8stats.txt
   printStatsToFile(battingOrder, lineup, ROW_SIZE);

}