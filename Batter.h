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
   Batter(string fn, string ln, string tn, bool allStar, bool active, bool hallOfFame, int atBats = 0, int hits = 0, int doubles = 0, int triples = 0, int homers = 0, int walks = 0, int hitByPitch = 0, int sacrificeFlies = 0)
   {
      //call the parent constructor to set the inherited values
      BaseballPlayer(fn, ln, tn, allStar, active, hallOfFame);
      setAtBats(atBats);
      setHits(hits);
      setDoubles(doubles);
      setTriples(triples);
      setHomeRuns(homers);
      setWalks(walks);
      setHitsByPitch(hitByPitch);
      setSacrificeFlies(sacrificeFlies);
   }
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

   void divideByZeroException();

protected: //in case we want to do further expansion...
   int atBats, hits, doubles, triples, homers;
   int walks, hitByPitch, sacrificeFlies;

}; /** END OF INTERFACE; WRITE IMPLEMENTATION BELOW **/

void Batter::divideByZeroException()
{
   throw("Error: Division by zero in batting average calculation.");
}

void Batter::setAtBats(int ab)
{
   atBats = ab;
}

void Batter::setHits(int h)
{
   hits = h;
}

void Batter::setDoubles(int d)
{
   doubles = d;
}

void Batter::setTriples(int t)
{
   triples = t;
}

void Batter::setHomeRuns(int hr)
{
   homers = hr;
}

void Batter::setWalks(int w)
{
   walks = w;
}

void Batter::setHitsByPitch(int hbp)
{
   hitByPitch = hbp;
}

void Batter::setSacrificeFlies(int sf)
{
   sacrificeFlies = sf;
}

int Batter::getAtBats()
{
   return atBats;
}

int Batter::getHits()
{
   return hits;
}

int Batter::getDoubles()
{
   return doubles;
}

int Batter::getTriples()
{
   return triples;
}

int Batter::getHomeRuns()
{
   return homers;
}

int Batter::getWalks()
{
   return walks;
}

int Batter::getHitsByPitch()
{
   return hitByPitch;
}

int Batter::getSacrificeFlies()
{
   return sacrificeFlies;
}

double Batter::battingAverage()
{
   if (atBats == 0)
   {
      divideByZeroException();
      return 0.0;
   }
   return (double)(hits) / (atBats);
}

double Batter::onBasePercentage()
{
   if (hits + walks + hitByPitch + sacrificeFlies == 0)
   {
      divideByZeroException();
      return 0.0;
   }
   return (double)(hits + walks + hitByPitch) / (hits + walks + hitByPitch + sacrificeFlies);
}

double Batter::sluggingPercentage()
{
   if (atBats == 0)
   {
      divideByZeroException();
      return 0.0;
   }
   return (double)(hits + (2 * doubles) + (3 * triples) + (4 * homers)) / (atBats);
}


double Batter::onBasePlusSluggingPercentage()
{
   return onBasePercentage() + sluggingPercentage();
}





//This is a function external to the class (just like with BaseballPlayer)
ostream& operator<<(ostream& os, Batter bp){
   BaseballPlayer b = (BaseballPlayer)bp; //cast to BaseballPlayer
   os << b; //call the overloaded operator<< for BaseballPlayer
   os << "At Bats: " << setw(8) << bp.getAtBats() << endl;
   os << "Hits: " << setw(8) << bp.getHits() << endl;
   os << "Doubles: " << setw(8) << bp.getDoubles() << endl;
   os << "Triples: " << setw(8) << bp.getTriples() << endl;
   os << "Home Runs: " << setw(8) << bp.getHomeRuns() << endl;
   os << "Walks: " << setw(8) << bp.getWalks() << endl;
   os << "Hits by Pitch: " << setw(8) << bp.getHitsByPitch() << endl;
   os << "Sacrifice Flies: " << setw(8) << bp.getSacrificeFlies() << endl;
   os << "Batting Average: " << setw(8) << setprecision(3) << fixed << bp.battingAverage() << endl;
   os << "On Base Percentage: " << setw(8) << setprecision(3) << fixed << bp.onBasePercentage() << endl;
   os << "Slugging Percentage: " << setw(8) << setprecision(3) << fixed << bp.sluggingPercentage() << endl;
   os << "On Base Plus Slugging Percentage: " << setw(8) << setprecision(3) << fixed << bp.onBasePlusSluggingPercentage() << endl;
}
//makes life easier by just using cout with the << to print out the object.
//see example output for order of output for batter.
//also: print out stats to the thousands place for any of the calculations (three decimal places).
#endif