#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <vector>
#include "assignment6.h"
#include "assignment7.h" //reusing files again?  Hmmm...
using namespace std;

#ifndef ASSIGNMENT10_H
#define ASSIGNMENT10_H

class Player
{
public:
   // Constructor with one argument, default argument; name of the player
   // the default argument is the empty string ""
   // Calls the setters
   Player(string name = "")
   {
      setName(name);
      setAtBats(0);
      setSingles(0);
      setDoubles(0);
      setTriples(0);
      setHomers(0);
      setWalks(0);
      setSacflies(0);
   }

   // define getters and setters
   // setters
   void setName(string n)
   {
      name = n;
   }

   void setAtBats(int ab)
   {
      atBats = ab;

      if (atBats < 0)
      {
         atBats = 0;
      }
   }

   void setWalks(int w)
   {
      walks = w;

      if (walks < 0)
      {
         walks = 0;
      }
   }

   void setSacflies(int sf)
   {
      sacflies = sf;

      if (sacflies < 0)
      {
         sacflies = 0;
      }
   }

   void setSingles(int s)
   {
      singles = s;

      if (singles < 0)
      {
         singles = 0;
      }
   }

   void setDoubles(int d)
   {
      doubles = d;

      if (doubles < 0)
      {
         doubles = 0;
      }
   }

   void setTriples(int t)
   {
      triples = t;

      if (triples < 0)
      {
         triples = 0;
      }
   }

   void setHomers(int h)
   {
      homers = h;

      if (homers < 0)
      {
         homers = 0;
      }
   }

   // getters
   string getName()
   {
      return name;
   }

   int getAtBats()
   {
      return atBats;
   }

   int getWalks()
   {
      return walks;
   }

   int getSacflies()
   {
      return sacflies;
   }

   int getSingles()
   {
      return singles;
   }

   int getDoubles()
   {
      return doubles;
   }

   int getTriples()
   {
      return triples;
   }

   int getHomers()
   {
      return homers;
   }

   // the ofstream argument passed in refers to the file being printed to.
   void print(ofstream &outFile)
   {
      // print the name of the player>>
      outFile << setw(20) << left << name;
      // print the stats
      outFile << setw(5) << atBats;
      outFile << setw(5) << singles;
      outFile << setw(5) << doubles;
      outFile << setw(5) << triples;
      outFile << setw(5) << homers;
      outFile << setw(5) << walks;
      outFile << setw(5) << sacflies;
      // print the batting average
      outFile << setw(8) << fixed << setprecision(3) << battingAverage();
      // print the on base percentage
      outFile << setw(8) << fixed << setprecision(3) << onBasePercentage();
      // print the slugging percentage
      outFile << setw(8) << fixed << setprecision(3) << sluggingPercentage();
   }

private:
   // methods are in private because they really only help with the print
   // at this point in time.

   // calculates batting average the same as before, just the methodology
   // will be different.
   double battingAverage()
   {
      // if the player has no at bats, return 0.0
      if (atBats == 0)
         return 0.0;
      // otherwise, return the average
      return (double)(singles + doubles + triples + homers) / atBats;
   }

   // calculates obp, just the methodology is different
   double onBasePercentage()
   {
      // if the player has no at bats, return 0.0
      if (atBats + walks == 0)
         return 0.0;
      // otherwise, return the average
      return (double)(singles + doubles + triples + homers + walks) / (atBats + walks);
   }

   // same story with slugging percentage
   double sluggingPercentage()
   {
      // if the player has no at bats, return 0.0
      if (atBats == 0)
         return 0.0;
      // otherwise, return the average
      return (double)(singles + (2 * doubles) + (3 * triples) + (4 * homers)) / atBats;
   }

   string name;                           // player's name
   int atBats, walks, sacflies;           // stats to keep up with
   int singles, doubles, triples, homers; // different types of scored hits
};

// reads names from roster.txt and stores them to objects in the vector.
void initialize(vector<Player> &lineup, const int LINEUP_SIZE)
{
   srand(time(0)); // seed the random number generator
   // open the file
   ifstream inFile("roster.txt");
   // loop through the vector, getting names from the file
   for (int i = 0; i < LINEUP_SIZE; i++)
   {
      string name;
      getline(inFile, name);
      // create a new player object with the name
      Player p(name);
      // push it into the vector
      lineup.push_back(p);
   }
   inFile.close();
}

// prints out all of the batters' results, formatted like previous assignments,
// to a file called a10results.txt
void printPlayerStats(vector<Player> lineup)
{
   // open the file
   ofstream outFile("a10results.txt");
   // print the header
   outFile << setw(20) << left << "Player"
           << setw(5) << "ab"
           << setw(5) << "1b"
           << setw(5) << "2b"
           << setw(5) << "3b"
           << setw(5) << "hr"
           << setw(5) << "bb"
           << setw(5) << "sf"
           << setw(8) << "avg"
           << setw(8) << "obp"
           << setw(8) << "slug" << endl;
   // loop through the vector, printing each player's stats
   for (int i = 0; i < lineup.size(); i++)
   {
      lineup[i].print(outFile);
      outFile << endl;
   }
   outFile.close();
}

// similar to previous versions of playBall, the argument this time being
// a vector of players.  As with previous versions
void playBall(vector<Player> &lineup)
{
   const int LINEUP_SIZE = lineup.size();
   int currentBatter = 0; // Track the current batter across innings

   PlayResult play;
   GeneratedPlayType playOutcome;

   // Loop through the innings
   for (int inning = 0; inning < 9; inning++)
   {
      int outs = 0;
      int inningHits = 0;
      int inningWalks = 0;
      cout << "Inning " << inning + 1 << ": " << endl;

      // Continue until 3 outs are recorded
      while (outs < 3)
      {
         // Get the play result
         PlayResult play = roll(playOutcome);
         cout << "Up to bat: " << lineup[currentBatter].getName() << "\n";
         cout << "Play: ";
         printPlayResult(play);
         cout << endl;

         // Update the player's stats based on the play result
         switch (play)
         {
         case WALK:
            lineup[currentBatter].setWalks(lineup[currentBatter].getWalks() + 1);
            inningWalks++;
            break;
         case SAC_FLY:
            lineup[currentBatter].setSacflies(lineup[currentBatter].getSacflies() + 1);
            outs++;
            break;
         case SINGLE:
            lineup[currentBatter].setSingles(lineup[currentBatter].getSingles() + 1);
            lineup[currentBatter].setAtBats(lineup[currentBatter].getAtBats() + 1);
            inningHits++;
            break;
         case DOUBLE:
            lineup[currentBatter].setDoubles(lineup[currentBatter].getDoubles() + 1);
            lineup[currentBatter].setAtBats(lineup[currentBatter].getAtBats() + 1);
            inningHits++;
            break;
         case TRIPLE:
            lineup[currentBatter].setTriples(lineup[currentBatter].getTriples() + 1);
            lineup[currentBatter].setAtBats(lineup[currentBatter].getAtBats() + 1);
            inningHits++;
            break;
         case HOME_RUN:
            lineup[currentBatter].setHomers(lineup[currentBatter].getHomers() + 1);
            lineup[currentBatter].setAtBats(lineup[currentBatter].getAtBats() + 1);
            inningHits++;
            break;
         case FLY_OUT:
         case GROUND_OUT:
         case STRIKE_OUT:
         case POP_OUT:
         case DOUBLE_PLAY:
            lineup[currentBatter].setAtBats(lineup[currentBatter].getAtBats() + 1);
            outs++;
            break;
         default:
            break;
         }

         // Move to the next batter
         currentBatter = (currentBatter + 1) % LINEUP_SIZE;
      }

      cout << "End of Inning.\n";
      cout << "Walks: " << inningWalks << endl;
      cout << "Hits: " << inningHits << endl;
      cout << endl;

      char choice;
      cout << "\nContinue? (y/n): ";
      cin >> choice;
      if (choice == 'n' || choice == 'N')
      {
         break;
      }
      cout << endl;
   }

   // Print the player stats to a file
   printPlayerStats(lineup);
}

#endif