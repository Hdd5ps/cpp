#include "BaseballPlayer.h"
//we need BaseballPlayer, since we're inheriting from it some of the information.
using namespace std;

#ifndef BATTER_H
#define BATTER_H

/** START OF INTERFACE FOR BATTER; DO NOT MODIFY UNLESS GIVEN THE OPTION TO DO SO **/
class Batter : public BaseballPlayer{

public:

   //note:  you are allowed to modify this prototype if you feel it necessary.  This is 
   //the only thing in the interface you're allowed to modify.
   //why?  think:  I can't have a declaration of Batter b; - the information must be completely
   //filled in for any object of a class
   Batter(string, string, string, bool, bool, bool, int, int, int, int, int, int, int, int);
   /*
   order of arguments:
   first name
   last name
   team name
   has been an all-star
   is active
   is a hall-of-famer
   at-bats
   hits
   doubles
   triples
   home runs
   walks
   hits-by-pitch
   sacrifice flies (factors into obp)
   
   
   */

//setter prototypes; do not modify:
   void setAtBats(int);
   void setHits(int);
   void setDoubles(int);
   void setTriples(int);
   void setHomeRuns(int);
   void setWalks(int);
   void setHitsByPitch(int);
   void setSacrificeFlies(int);

//getter rototypes; do not modify:
   int getAtBats();
   int getHits();
   int getDoubles();
   int getTriples();
   int getHomeRuns();
   int getWalks();
   int getHitsByPitch();
   int getSacrificeFlies();

//calculations; remember to throw exceptions where relevant:
   double battingAverage(); 
   //likelihood of a batter getting a hit to get on base
   //hits/atbats
   double onBasePercentage(); 
   //likelihood of a batter getting on base via hit, walk, or hit-by-pitch
   //(hits + walks + hbp)/(hits+walks+hbp+sac flies)
   double sluggingPercentage(); 
   //more or less - are they a power hitter?
   //calculation:  (singles + (2*doubles) + (3*triples) + (4*home runs))/atBats
   double onBasePlusSluggingPercentage(); 
   //combines how well a batter can get on base, hit for average, and power
   //calculation:  add onBase percentage and slugging percentage together

protected: //in case we want to do further expansion...
   int atBats, hits, doubles, triples, homers;
   int walks, hitByPitch, sacrificeFlies;

}; /** END OF INTERFACE; WRITE IMPLEMENTATION BELOW **/

//This is a function external to the class (just like with BaseballPlayer)
ostream& operator<<(ostream&, Batter);
//makes life easier by just using cout with the << to print out the object.
//see example output for order of output for batter.
//also: print out stats to the thousands place for any of the calculations (three decimal places).
#endif