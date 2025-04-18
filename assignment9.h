#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "assignment6.h"
#include "assignment7.h"
using namespace std;

#ifndef ASSIGNMENT9_H
#define ASSIGNMENT9_H

struct Player
{
   string name;  // Player's name
   int atBats;   // At-bats
   int singles;  // Singles
   int doubles;  // Doubles
   int triples;  // Triples
   int homers;   // Home runs
   int walks;    // Walks
   int sacflies; // Sacrifice flies
};

// Initialize the lineup from roster.txt
void initialize(Player *lineup, const int LINEUP_SIZE)
{
   srand(time(0)); // Seed the random number generator
   ifstream inFile("roster.txt");

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

// Calculate batting average
double battingAverage(Player p)
{
   if (p.atBats == 0)
      return 0.0;
   return (double)(p.singles + p.doubles + p.triples + p.homers) / p.atBats;
}

// Calculate on-base percentage
double onBasePercentage(Player p)
{
   if (p.atBats + p.walks == 0)
      return 0.0;
   return (double)(p.singles + p.doubles + p.triples + p.homers + p.walks) / (p.atBats + p.walks);
}

// Calculate slugging percentage
double sluggingPercentage(Player p)
{
   if (p.atBats == 0)
      return 0.0;
   return (double)(p.singles + (2 * p.doubles) + (3 * p.triples) + (4 * p.homers)) / p.atBats;
}

// Print player stats to a file
void printPlayer(Player p, ofstream &outFile)
{
   outFile << setw(20) << left << p.name
           << setw(5) << p.atBats
           << setw(5) << p.singles
           << setw(5) << p.doubles
           << setw(5) << p.triples
           << setw(5) << p.homers
           << setw(5) << p.walks
           << setw(5) << p.sacflies
           << setw(8) << battingAverage(p)
           << setw(8) << onBasePercentage(p)
           << setw(8) << sluggingPercentage(p) << endl;
}

// Print all player stats to a9results.txt
void printPlayerStats(const Player *lineup, const int LINEUP_SIZE)
{
   ofstream outFile("a9results.txt");
   outFile << fixed << setprecision(3);
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

   for (int i = 0; i < LINEUP_SIZE; i++)
   {
      printPlayer(lineup[i], outFile);
   }
   outFile.close();
}

// Update player stats based on the play result
void updateStatLine(PlayResult p, Player *pl, const int index)
{
   switch (p)
   {
   case SINGLE:
      pl[index].singles++;
      pl[index].atBats++;
      break;
   case DOUBLE:
      pl[index].doubles++;
      pl[index].atBats++;
      break;
   case TRIPLE:
      pl[index].triples++;
      pl[index].atBats++;
      break;
   case HOME_RUN:
      pl[index].homers++;
      pl[index].atBats++;
      break;
   case WALK:
      pl[index].walks++;
      break;
   case SAC_FLY:
      pl[index].sacflies++;
      break;
   case FLY_OUT:
   case GROUND_OUT:
   case STRIKE_OUT:
   case POP_OUT:
   case DOUBLE_PLAY:
      pl[index].atBats++;
      break;
   default:
      break;
   }
}

// Simulate a nine-inning game
void playBall(Player *lineup)
{
   const int LINEUP_SIZE = 9;

   // Initialize the play result
   PlayResult play;
   GeneratedPlayType playOutcome;

   for (int inning = 0; inning < 9; inning++)
   {
      int outs = 0;
      int inningHits = 0;
      int inningWalks = 0;

      cout << "Inning " << inning + 1 << ": " << endl;

      int batter = 0;
      while (outs < 3)
      {
         PlayResult play = roll(playOutcome); // Simulate the play
         cout << "Up to bat: " << lineup[batter].name << "\n";
         cout << "Play: ";
         printPlayResult(play);

         updateStatLine(play, lineup, batter);

         if (play == SINGLE || play == DOUBLE || play == TRIPLE || play == HOME_RUN)
         {
            inningHits++;
         }
         else if (play == WALK)
         {
            inningWalks++;
         }
         else if (play == FLY_OUT || play == SAC_FLY || play == GROUND_OUT || play == STRIKE_OUT || play == POP_OUT || play == DOUBLE_PLAY)
         {
            outs++;
         }

         batter = (batter + 1) % LINEUP_SIZE;
      }

      cout << "End of inning " << inning + 1 << ".\n";
      cout << "Walks: " << inningWalks << endl;
      cout << "Hits: " << inningHits << endl;

      char choice;
      cout << "Continue? (y/n): ";
      cin >> choice;
      if (choice == 'n' || choice == 'N')
      {
         break;
      }
   }

   printPlayerStats(lineup, LINEUP_SIZE);
}

#endif