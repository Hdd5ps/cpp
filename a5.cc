//DO NOT MODIFY THIS FILE

#include "assignment5.h"
using namespace std;

   
int main(){

   PlayResult play; //deciphering the roll
   GeneratedPlayType playOutcome; //determine if hit, walk, out
   int outs = 0, walks = 0, hits = 0; //keeping track of the same stats as before
   int playerNumber = 0; //needed to print out Players 1-9.
   char promptUser = 'y';

   while((outs < 3)&&(promptUser=='y')){
      play = roll();
      cout<<endl<<"Result - Player "<<playerNumber+1<<": ";
      printPlayResult(play);
      
      //add one to either hit, walk, or out variable
      switch(scorePlay(play)){
      //update the appropriate stat
         case BB:
            walks++;
            break;
         case HIT:
            hits++;
            break;
         case OUT:
            outs++;
            break;
         default: //to turn off warning issues from compiler
            break;
      }
     
     //increment then mod by 9 to cycle back to the top when
     //on the last player 
      playerNumber++;
      playerNumber %= 9;
      
      //prompt the user to continue (or not)
      cout<<"Continue (y/n)? ";
      cin>>promptUser;      
   }

//print stats after inning ends   
   cout<<"End of the inning."<<endl;
   cout<<"Walks: "<<walks<<endl;
   cout<<"Hits: "<<hits<<endl;



   return 0;
}