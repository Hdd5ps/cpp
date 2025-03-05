//DO NOT MODIFY THIS FILE
#include "assignment6.h"
using namespace std;

   
int main(){

   PlayResult play; //deciphering the roll
   GeneratedPlayType playOutcome; //determine if hit, walk, out
   int outs = 0, walks = 0, hits = 0; //keeping track of the same stats as before
   
   //needed to print end-of-inning stats for avg, on-base pct, slugging pct
   int atBats = 0, totalBaseCount = 0; 
   double battingAverage, onBase, slugging; 
   int playerNumber = 0; //needed to print out Players 1-9.
   char promptUser = 'y';
   
   initialize();//call the set the seed for the random number generator

   while((outs < 3)&&(promptUser=='y')){
      atBats++;//add an at-bat; we'll take it back, depending on the play
      play = roll(playOutcome); //the way this function works has changed slightly
      cout<<endl<<"Result - Player "<<playerNumber+1<<": ";
      printPlayResult(play);
      
      //so we get back the play, which we printed above, as well as the type of
      //play.  Time to adjust certain things...
      switch(playOutcome){
      //update the appropriate stat
         case BB:
            walks++;
            atBats--; //walks aren't counted as an at-bat.
            break;
         case HIT:
            hits++;
            totalBases(play, totalBaseCount); 
            //added; based on the type of hit, add the number of bases that goes
            //with that hit
            break;
         case OUT:
            outs++;
            break;
         default: //not counted as an at-bat if a Sacrifice Fly
            outs++;//add an out, but take back an at-bat
            atBats--;
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
   cout<<endl;  
   cout<<"End of the inning."<<endl;
   cout<<"Walks: "<<walks<<endl;
   cout<<"Hits: "<<hits<<endl;
   cout<<endl;
  
//reporting new stats, since Assignment 5:
//tell the compiler that this should print out as a decimal value
   cout<<fixed;
//tell the compiler that this should print out to 3 decimal places
   cout.precision(3); //sticky setting - will last until another cout.precision call
   //determine team batting average
   teamBattingAverage(hits, atBats, battingAverage);
   //print the result to the screen:
   cout<<"Team Batting Average: "<<battingAverage<<endl;
   //determine the team's on-base percentage:
   teamOnBasePct(hits, walks, atBats, onBase);
   //print the on-base percentage calculated to the screen
   cout<<"Team On-Base Percentage: "<<onBase<<endl;
   //determine the team's slugging percentage:
   slugging = teamSluggingPercentage(atBats, totalBaseCount);
   //print the team's slugging percentage to the screen
   cout<<"Team Slugging Percentage: "<<slugging<<endl;

//finished
   return 0;
}