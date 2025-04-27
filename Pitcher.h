#include "BaseballPlayer.h"
//we're going to need BaseballPlayer.h since we'll inherit from BaseballPlayer for Pitcher
using namespace std;

#ifndef PITCHER_H
#define PITCHER_H

class Pitcher : public BaseballPlayer{
/** NOTE:  BEGINNING OF CLASS INTERFACE; DON'T MODIFY UNLESS YOU SEE A PLACE THAT SUGGESTS OTHERWISE **/

public:
   //note:  you are allowed to modify this prototype if you feel it necessary.  This is 
   //the only thing in the interface you're allowed to modify.
   //why?  think:  I can't have a declaration of Pitcher p; - the information must be completely
   //filled in for any object of a class

   Pitcher(string, string, string, bool, bool, bool, int, double, int, int, int, int, int);
   /*
   order of arguments:
   first name
   last name
   team name
   has been an all-star
   is active
   is a hall-of-famer
   earned runs
   innings pitched
   hits
   walks
   strikeouts
   wins
   losses
   */

//setters - do not modify
   void setEarnedRuns(int);
   void setInningsPitched(double);
   void setHits(int);
   void setWalks(int);
   void setStrikeouts(int);
   void setWins(int);
   void setLosses(int);

//getters - do not modify
   int getEarnedRuns();   
   double getInningsPitched();   
   int getHits();   
   int getWalks();   
   int getStrikeouts();
   int getWins();
   int getLosses();
   
//calculations - do not modify - make sure to catch the appropriate exceptions
   double earnedRunAverage();
   //calculation to project how many runs a pitcher would give up for every 9 innings
   //calculation:  (earned runs/innings pitched)*9
   double whip();
   //calculation to determine how much "trouble" a pitcher will get into during each inning,
   //based on the number of hits and walks surrendered.
   //calculation:  (walks + hits)/innings pitched
   double strikeoutsPerNineInnings();
   //calculation to determine how many strikeouts a pitcher would be projected to have
   //over the span of nine innings
   //calculation: (strikeouts/innings pitched) * 9
   double ratioStrikeoutsToWalks();
   //kind of a calculation that can be used to see how well the pitcher is in control (to
   //some extent, anyway).
   //calculation:  strikeouts/walks
   double winningPercentage();
   //apparently some like to see if a pitcher is good by just their record and/or winning
   //percentage.  the problem with this line of thinking is if there's no run support from 
   //the offense, and the pitcher is having a stellar game, this won't reflect that.
   //see:  Jacob deGrom with the Mets, back before he signed with the Rangers.  He won
   //a Cy Young award (deemed best pitcher) in spite of the fact how lethargic his team was when
   //it came to scoring runs to help him out.
   
 protected: //data needed; do not modify
   int earnedRuns, hits, walks, strikeouts, wins, losses;
   double inningsPitched;
   
   //note on inningsPitched - you might see it written in an alternative decimal form:
   //Example:  125.0 - 125 innings pitched
   //125.1 - actually translates to 125.33 innings pitched (or 125 and a third innings pitched)
   //125.2 - actually translates to 125.67 innings pitched (or 125 and two thirds of an inning pitched)
}; /* NOTE:  END OF INTERFACE FOR CLASS PITCHER; BEING WRITING METHOD IMPLEMENTATIONS BELOW */


//determining greatest common divisor for ratios - recursive solution; not a part of the class
int gcd(int x, int y){
   if (y==0){
      return x;
   }
   return gcd(y, x%y);
}

//same rationale as with BaseballPlayer and Batter; we want to be able to use cout.
//see sample output for order of output
//note: finding gcd might be useful to reduce ratios that are not in their smallest form.
//for instance, instead of saying the ratio is 6:3, you would use gcd to reduce to 2:1.
ostream& operator<<(ostream&, Pitcher);

#endif
