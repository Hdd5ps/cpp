#include "assignment10.h"
using namespace std;

int main(){

   //working with vectors for the line up this time
   //the angle brackets denote the type that the vector
   //holds, of type Player, in this instance.
   vector<Player> lineup;
   //similar functionality to previous assignments' initialize
   //function
   initialize(lineup, 9);
   //does the "heavy lifting" by running the game.
   playBall(lineup);
   //print out the players' stats 
   printPlayerStats(lineup);

   return 0;
}