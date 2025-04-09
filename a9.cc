#include "assignment9.h"
using namespace std;

int main(){
   const int LINEUP_SIZE = 9; 
   //the size of the array corresponds to the number of batters
   Player *lineup = new Player[LINEUP_SIZE];
   //dynamically-allocated memory with a pointer
   //initialize is called in a similar way to the previous assignments
   initialize(lineup, LINEUP_SIZE);
   //play the game/generate the plays
   playBall(lineup);
   //write the results to the file a9results.txt
   printPlayerStats(lineup, LINEUP_SIZE);
   //lastly, in memory management, it's important to free up the memory
   //if it won't be used again...
   delete[] lineup;
}