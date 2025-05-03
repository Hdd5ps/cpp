#include "BaseballPlayer.h"
#include <sstream>
// we're going to need BaseballPlayer.h since we'll inherit from BaseballPlayer for Pitcher
using namespace std;

#ifndef PITCHER_H
#define PITCHER_H

class Pitcher : public BaseballPlayer
{
   /** NOTE:  BEGINNING OF CLASS INTERFACE; DON'T MODIFY UNLESS YOU SEE A PLACE THAT SUGGESTS OTHERWISE **/

public:
   // note:  you are allowed to modify this prototype if you feel it necessary.  This is
   // the only thing in the interface you're allowed to modify.
   // why?  think:  I can't have a declaration of Pitcher p; - the information must be completely
   // filled in for any object of a class

   Pitcher(string fn, string ln, string tn, bool allStar, bool active, bool hof, int eR, double iP, int hits, int walks, int sK, int w, int l) : BaseballPlayer(fn, ln, tn, allStar, active, hof)
   {
      setEarnedRuns(eR);
      setInningsPitched(iP);
      setHits(hits);
      setWalks(walks);
      setStrikeouts(sK);
      setWins(w);
      setLosses(l);
   }

   Pitcher() : BaseballPlayer()
   {
      // default constructor
      setEarnedRuns(0);
      setInningsPitched(0.0);
      setHits(0);
      setWalks(0);
      setStrikeouts(0);
      setWins(0);
      setLosses(0);
   }
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

   // setters - do not modify
   void setEarnedRuns(int);
   void setInningsPitched(double);
   void setHits(int);
   void setWalks(int);
   void setStrikeouts(int);
   void setWins(int);
   void setLosses(int);

   // getters - do not modify
   int getEarnedRuns();
   double getInningsPitched();
   int getHits();
   int getWalks();
   int getStrikeouts();
   int getWins();
   int getLosses();

   // calculations - do not modify - make sure to catch the appropriate exceptions
   double earnedRunAverage();
   // calculation to project how many runs a pitcher would give up for every 9 innings
   // calculation:  (earned runs/innings pitched)*9
   double whip();
   // calculation to determine how much "trouble" a pitcher will get into during each inning,
   // based on the number of hits and walks surrendered.
   // calculation:  (walks + hits)/innings pitched
   double strikeoutsPerNineInnings();
   // calculation to determine how many strikeouts a pitcher would be projected to have
   // over the span of nine innings
   // calculation: (strikeouts/innings pitched) * 9
   string ratioStrikeoutsToWalks();
   // kind of a calculation that can be used to see how well the pitcher is in control (to
   // some extent, anyway).
   // calculation:  strikeouts/walks
   double winningPercentage();
   // apparently some like to see if a pitcher is good by just their record and/or winning
   // percentage.  the problem with this line of thinking is if there's no run support from
   // the offense, and the pitcher is having a stellar game, this won't reflect that.
   // see:  Jacob deGrom with the Mets, back before he signed with the Rangers.  He won
   // a Cy Young award (deemed best pitcher) in spite of the fact how lethargic his team was when
   // it came to scoring runs to help him out.

protected: // data needed; do not modify
   int earnedRuns, hits, walks, strikeouts, wins, losses;
   double inningsPitched;

   // note on inningsPitched - you might see it written in an alternative decimal form:
   // Example:  125.0 - 125 innings pitched
   // 125.1 - actually translates to 125.33 innings pitched (or 125 and a third innings pitched)
   // 125.2 - actually translates to 125.67 innings pitched (or 125 and two thirds of an inning pitched)
}; /* NOTE:  END OF INTERFACE FOR CLASS PITCHER; BEING WRITING METHOD IMPLEMENTATIONS BELOW */

int gcd(int, int);
void Pitcher::setEarnedRuns(int eR)
{
   earnedRuns = eR;
}

void Pitcher::setInningsPitched(double iP)
{
   inningsPitched = iP;
}

void Pitcher::setHits(int h)
{
   hits = h;
}

void Pitcher::setWalks(int w)
{
   walks = w;
}

void Pitcher::setStrikeouts(int sK)
{
   strikeouts = sK;
}

void Pitcher::setWins(int w)
{
   wins = w;
}

void Pitcher::setLosses(int l)
{
   losses = l;
}

int Pitcher::getEarnedRuns()
{
   return earnedRuns;
}

double Pitcher::getInningsPitched()
{
   return inningsPitched;
}

int Pitcher::getHits()
{
   return hits;
}

int Pitcher::getWalks()
{
   return walks;
}

int Pitcher::getStrikeouts()
{
   return strikeouts;
}

int Pitcher::getWins()
{
   return wins;
}

int Pitcher::getLosses()
{
   return losses;
}

double Pitcher::earnedRunAverage()
{
   if (inningsPitched == 0)
   {
      BaseballPlayer::divideByZeroException();
      return 0.0;
   }
   return (double)(earnedRuns / inningsPitched) * 9;
}

double Pitcher::whip()
{
   if (inningsPitched == 0)
   {
      BaseballPlayer::divideByZeroException();
      return 0.0;
   }
   return (double)(walks + hits) / inningsPitched;
}

double Pitcher::strikeoutsPerNineInnings()
{
   if (inningsPitched == 0)
   {
      BaseballPlayer::divideByZeroException();
      return 0.0;
   }
   return (double)(strikeouts / inningsPitched) * 9;
}

string Pitcher::ratioStrikeoutsToWalks()
{
   std::ostringstream oss;
   if (walks == 0)
   {
      BaseballPlayer::divideByZeroException();
      return "0:0";
   }
   if (strikeouts == 0)
   {
      BaseballPlayer::divideByZeroException();
      return "0:1";
   }
   int g = gcd(strikeouts, walks);
   double strikeoutsReduced = (double)strikeouts / g;
   double walksReduced = (double)walks / g;
   double ratio = (double)strikeouts / walks;
   oss << (int)strikeoutsReduced << ":" << (int)walksReduced << " (";
   oss << fixed << setprecision(3) << ratio << " strikeouts per walk)" << endl;
   return oss.str();
}

double Pitcher::winningPercentage()
{
   if (wins + losses == 0)
   {
      BaseballPlayer::divideByZeroException();
      return 0.0;
   }
   return (double)(wins) / (wins + losses);
}

// determining greatest common divisor for ratios - recursive solution; not a part of the class
int gcd(int x, int y)
{
   if (y == 0)
   {
      return x;
   }
   return gcd(y, x % y);
}

// same rationale as with BaseballPlayer and Batter; we want to be able to use cout.
// see sample output for order of output
// note: finding gcd might be useful to reduce ratios that are not in their smallest form.
// for instance, instead of saying the ratio is 6:3, you would use gcd to reduce to 2:1.
ostream &operator<<(ostream &os, Pitcher p)
{
   BaseballPlayer b = (BaseballPlayer)p; // cast to BaseballPlayer
   os << b;
   os << left << setw(35) << "Record: " << p.getWins() << "-" << p.getLosses() << endl;
   os << left << setw(35) << "Winning Percentage: " << p.winningPercentage() << endl;
   os << left << setw(35) << "Earned Runs: " << p.getEarnedRuns() << endl;
   os << left << setw(35) << "Hits: " << p.getHits() << endl;
   os << left << setw(35) << "Walks: " << p.getWalks() << endl;
   os << left << setw(35) << "Strikeouts: " << p.getStrikeouts() << endl;
   os << left << setw(35) << "Innings Pitched: " << fixed << setprecision(2) << p.getInningsPitched() << endl;
   os << left << setw(35) << "Earned Run Average: " << fixed << setprecision(2) << p.earnedRunAverage() << endl;
   os << left << setw(35) << "whip: " << fixed << setprecision(2) << p.whip() << endl;
   os << left << setw(35) << "Strikeouts per nine innings: " << fixed << setprecision(2) << p.strikeoutsPerNineInnings() << endl;
   os << left << setw(35) << "Ratio of Strikeouts to Walks: " << p.ratioStrikeoutsToWalks();

   return os;
}

#endif
