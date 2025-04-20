#include <iostream>
#include <fstream>
#include <iomanip>
#include "assignment6.h"
using namespace std;

#ifndef ASSIGNMENT7_H
#define ASSIGNMENT7_H

// needed to determine the play type to increment.
enum Statistics
{
   ATBATS,
   SINGLES,
   DOUBLES,
   TRIPLES,
   HOMERS,
   WALKS,
   SACFLIES
};

// calls the older initialize, but also sets all of the values of the array
// we're using to keep track of stats
void initialize(int array[], const int size)
{
   initialize(); // calling assignment6's initialize
   for (int i = 0; i < size; i++)
   {
      array[i] = 0;
   }
}

void updateStatLine(PlayResult p, int a[])
{
   switch (p)
   {
      // update the appropriate counters based on the play received.
   case SAC_FLY:
      a[(int)SACFLIES]++;
      break;
   case WALK:
      a[(int)WALKS]++;
      break;
   case SINGLE:
      a[(int)SINGLES]++;
      a[(int)ATBATS]++;
      break;
   case DOUBLE:
      a[(int)DOUBLES]++;
      a[(int)ATBATS]++;
      break;
   case TRIPLE:
      a[(int)TRIPLES]++;
      a[(int)ATBATS]++;
      break;
   case HOME_RUN:
      a[(int)HOMERS]++;
      a[(int)ATBATS]++;
      break;
   default:
      a[(int)ATBATS]++;
      break;
   }
   return;
}

double battingAverage(const int array[])
{
   int hits = 0;
   /*for(Statistics s = SINGLES; s<=HOMERS; (Statistics)(((int)s)++){
      hits += array[(int)s];
   }
   */
   hits += array[(int)SINGLES];
   hits += array[(int)DOUBLES];
   hits += array[(int)TRIPLES];
   hits += array[(int)HOMERS];
   return (double)hits / array[(int)ATBATS];
}

double onBasePercentage(const int array[])
{
   int sum = 0;
   sum += array[(int)SINGLES];
   sum += array[(int)DOUBLES];
   sum += array[(int)TRIPLES];
   sum += array[(int)HOMERS];
   sum += array[(int)WALKS];

   return (double)sum / (array[(int)ATBATS] + array[(int)WALKS]);
}

double sluggingPercentage(const int array[])
{
   int sum = 0;
   sum += array[(int)SINGLES];
   sum += (2 * array[(int)DOUBLES]);
   sum += (3 * array[(int)TRIPLES]);
   sum += (4 * array[(int)HOMERS]);
   return (double)sum / array[(int)ATBATS];
}

void printStatsToFile(const int array[], const int size)
{
   ofstream outFile;
   outFile.open("stats.txt");
   outFile << "At-Bats: " << array[(int)ATBATS] << endl;
   outFile << "Singles: " << array[(int)SINGLES] << endl;
   outFile << "Doubles: " << array[(int)DOUBLES] << endl;
   outFile << "Triples: " << array[(int)TRIPLES] << endl;
   outFile << "Home Runs: " << array[(int)HOMERS] << endl;
   outFile << "Walks: " << array[(int)WALKS] << endl;
   outFile << "Sacrifice Flies: " << array[(int)SACFLIES] << endl;
   outFile << setprecision(3);
   outFile << "Batting Average: " << battingAverage(array) << endl;
   outFile << setprecision(3);
   outFile << "On-Base Percentage: " << onBasePercentage(array) << endl;
   outFile << setprecision(3);
   outFile << "Slugging Percentage: " << sluggingPercentage(array) << endl;
   outFile.close();
   return;
}

void playBall(int array[], const int size)
{
   PlayResult result = NONE;
   GeneratedPlayType playOutcome;
   for (int i = 0; i < 10; i++)
   {
      cout << "Play: ";
      result = roll(playOutcome);
      printPlayResult(result);
      cout << endl;
      updateStatLine(result, array);
   }
   printStatsToFile(array, size);
   return;
}

#endif