#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "assignment6.h"
#include "assignment7.h"
// hmmm...reusing an old file again here?
using namespace std;

#ifndef ASSIGNMENT9_H
#define ASSIGNMENT9_H

struct Player
{                // each player...
   string name;  //...has a name (from roster.txt)
   int atBats;   // at-bats
   int singles;  // singles
   int doubles;  // doubles
   int triples;  // triples
   int homers;   // home runs
   int walks;    // walks
   int sacflies; // sacflies
};

// needed for srand() call and initializing all lineup names and
// all values set to zero.
// names of the batters come from roster.txt
void initialize(Player *lineup, const int LINEUP_SIZE)
{
   // initialize the random number generator
   srand(time(0));
   // open the file roster.txt
   ifstream inFile("roster.txt");

   // loop through the array of players, assigning names and
   // initializing all values to zero
   for (int i = 0; i < LINEUP_SIZE; i++)
   {
      getline(inFile, lineup[i].name);
      lineup[i].atBats = 0;
      lineup[i].singles = 0;
      lineup[i].doubles = 0;
      lineup[i].triples = 0;
      lineup[i].homers = 0;
      lineup[i].walks = 0;
      lineup[i].sacflies = 0;
   }
   inFile.close();
}

// same calculation as before, just collecting the information in
// a different way.
double battingAverage(Player p)
{
   // If the player has no at-bats, return 0.0
   if (p.atBats == 0)
   {
      return 0.0;
   }
   // Correct calculation of batting average
   double avg = (double)(p.singles + p.doubles + p.triples + p.homers) / (double)p.atBats;
   return avg;
}

// same story for on-base as batting average
double onBasePercentage(Player p)
{
   // If the player has no at-bats or walks, return 0.0
   if (p.atBats + p.walks == 0)
   {
      return 0.0;
   }
   // Correct calculation of on-base percentage
   double obp = (double)(p.singles + p.doubles + p.triples + p.homers + p.walks) / (double)(p.atBats + p.walks);
   return obp;
}

// same story for slugging percentage
double sluggingPercentage(Player p)
{
   // If the player has no at-bats, return 0.0
   if (p.atBats == 0)
   {
      return 0.0;
   }
   // Correct calculation of slugging percentage
   double slg = (double)(p.singles + (2 * p.doubles) + (3 * p.triples) + (4 * p.homers)) / (double)p.atBats;
   return slg;
}

// print out the player's stats to a file specified through the
// ostream argument.
// called by printPlayerStats
void printPlayer(Player p, ofstream &outFile)
{
   // print the player's name
   outFile << setw(20) << left << p.name;
   // print the player's stats
   outFile << setw(5) << p.atBats
           << setw(5) << p.singles
           << setw(5) << p.doubles
           << setw(5) << p.triples
           << setw(5) << p.homers
           << setw(5) << p.walks
           << setw(5) << p.sacflies;
   // print the player's batting average, on-base percentage, and slugging percentage
   outFile << setw(8) << battingAverage(p)
           << setw(8) << onBasePercentage(p)
           << setw(8) << sluggingPercentage(p) << endl;
}

// prints the header of each column, as well as each player's stats
// relies on printPlayerStats for a good bit of its functionality.
// writes to the file a9results.txt
void printPlayerStats(const Player *lineup, const int LINEUP_SIZE)
{
   // open the file a9results.txt
   ofstream outFile("a9results.txt");
   // print out the header
   // Set formatting for the output file
   outFile << fixed << setprecision(3);

   // Print the headers
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

   // use printPlayer to print out each player's stats
   for (int i = 0; i < LINEUP_SIZE; i++)
   {
      printPlayer(lineup[i], outFile);
   }
   // close the file
   outFile.close();
}

// after a batter has their plate appearance, update their stats,
// based on the PlayResult; the third argument corresponds to
// a batter in the lineup
void updateStatLine(PlayResult p, Player *pl, const int index)
{
   // Update the player's stats based on the PlayResult
   switch (p)
   {
   case SINGLE:
      pl[index].singles++;
      pl[index].atBats++; // Singles count as an at-bat
      break;
   case DOUBLE:
      pl[index].doubles++;
      pl[index].atBats++; // Doubles count as an at-bat
      break;
   case TRIPLE:
      pl[index].triples++;
      pl[index].atBats++; // Triples count as an at-bat
      break;
   case HOME_RUN:
      pl[index].homers++;
      pl[index].atBats++; // Home runs count as an at-bat
      break;
   case WALK:
      pl[index].walks++; // Walks do not count as an at-bat
      break;
   case SAC_FLY:
      pl[index].sacflies++; // Sacrifice flies do not count as an at-bat
      break;
   case FLY_OUT:
   case GROUND_OUT:
   case STRIKE_OUT:
   case POP_OUT:
   case DOUBLE_PLAY:
      pl[index].atBats++; // Outs count as an at-bat
      break;
   default:
      break;
   }
}

// playBall is the main function of the program.  It simulates a
// similar functionality to playBall from the previous assignment's
// playBall.  The major difference here is the use of the pointer for
// the array of batters.
void playBall(Player *lineup)
{
   // Define the size of the lineup
   const int LINEUP_SIZE = 9;

   // Initialize the play result
   PlayResult play;
   // Initialize the play outcome
   GeneratedPlayType playOutcome;

   // Loop through the nine innings
   for (int inning = 0; inning < 9; inning++)
   {
      // Initialize the number of outs
      int outs = 0;

      cout << "Inning " << inning + 1 << ": " << endl;

      // Loop through the batters in a circular manner
      int batter = 0;
      while (outs < 3)
      {
         // Roll the dice to determine the play
         PlayResult play = roll(playOutcome); // Use roll() from assignment6.h

         cout << "Up to bat: " << lineup[batter].name << "\n";
         cout << "Play: ";
         printPlayResult(play); // Use printPlayResult() from assignment6.h

         updateStatLine(play, lineup, batter);
         // Update the batter's stats

         // Check if the play is an out
         if (play == FLY_OUT || play == SAC_FLY || play == GROUND_OUT || play == STRIKE_OUT || play == POP_OUT || play == DOUBLE_PLAY)
         {
            outs++;
         }


         // Move to the next batter
         batter = (batter + 1) % LINEUP_SIZE;
      }

      // Calculate total hits and walks for the inning
      int totalHits = 0;
      int totalWalks = 0;
      for (int i = 0; i < LINEUP_SIZE; i++)
      {
         totalHits += lineup[i].singles + lineup[i].doubles + lineup[i].triples + lineup[i].homers;
         totalWalks += lineup[i].walks;
      }

      // Display inning summary
      cout << "End of inning.\n";
      cout << "Walks: " << totalWalks << endl;
      cout << "Hits: " << totalHits << endl;
      cout << endl
           << endl;

      // Prompt the user to continue or not
      char choice;
      cout << "Continue? (y/n): ";
      cin >> choice;
      cout << endl;

      if (choice == 'n' || choice == 'N')
      {
         return; // Exit the game
      }
   }
}

#endif