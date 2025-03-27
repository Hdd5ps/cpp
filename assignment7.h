#include <iostream>
#include <fstream>
#include "assignment6.h"
// hmmm, with the inclusion of assignment6.h file, it looks like you might be
// about to - dare I say it - reuse something(s) from the file.
using namespace std;

#ifndef ASSIGNMENT7_H
#define ASSIGNMENT7_H

// needed to determine the play type to increment.
enum Statistics
{
    ATBATS = 0,
    SINGLES = 1,
    DOUBLES = 2,
    TRIPLES = 3,
    HOMERS = 4,
    WALKS = 5,
    SACFLIES = 6
};

// initializes the array, as well as sets up the seed for the
// random number generator
void initialize(int battersLine[], const int SIZE)
{
    srand(time(0));
    for (int i = 0; i < SIZE; i++)
    {
        battersLine[i] = 0;
    }
}
// first argument is the array; second is the size of the array

void updateStatLine(PlayResult p, int battersLine[])
{
    switch (p)
    {
    case SINGLE:
        battersLine[SINGLES] = battersLine[SINGLES] + 1;
        battersLine[ATBATS] = battersLine[ATBATS] + 1;
        break;
    case DOUBLE:
        battersLine[ATBATS] = battersLine[ATBATS] + 1;
        battersLine[DOUBLES] = battersLine[DOUBLES] + 1;
        break;
    case TRIPLE:
        battersLine[TRIPLES] = battersLine[TRIPLES] + 1;
        battersLine[ATBATS] = battersLine[ATBATS] + 1;
        break;
    case HOME_RUN:
        battersLine[ATBATS] = battersLine[ATBATS] + 1;
        battersLine[HOMERS] = battersLine[HOMERS] + 1;
        break;
    case WALK:
        battersLine[WALKS] = battersLine[WALKS] + 1;
        break;
    default:
        battersLine[SACFLIES] = battersLine[SACFLIES] + 1;
        break;
    }
}
// based on the first argument, update the player's stats where needed.

double battingAverage(const int stats[])
{
    if (stats[ATBATS] == 0)
    {
        return 0.0; // Prevent division by zero
    }
    else
    {
        double batAvg = (double)(stats[SINGLES] + stats[DOUBLES] + stats[TRIPLES] + stats[HOMERS]) / (double)stats[ATBATS];
        return batAvg;
    }
}
// calculates the total number of hits divided by the total number of at-bats

double onBasePercentage(const int stats[])
{
    if (stats[ATBATS] + stats[WALKS] == 0)
    {
        return 0.0; // Prevent division by zero
    }
    else
    {
        double obBase = (double)(stats[SINGLES] + stats[DOUBLES] + stats[TRIPLES] + stats[HOMERS] + stats[WALKS]) / (double)(stats[ATBATS] + stats[WALKS]);
        return obBase;
    }
}
// calculates (hits+walks)/(at-bats + walks)

double sluggingPercentage(const int stats[])
{
    if (stats[ATBATS] == 0)
    {
        return 0.0; // Prevent division by zero
    }
    else
    {
        double slug = (double)(stats[SINGLES] + (2 * stats[DOUBLES]) + (3 * stats[TRIPLES]) + (4 * stats[HOMERS])) / (double)stats[ATBATS];
        return slug;
    }
}
// calculates slugging percentage:
//(singles + (2*doubles) + (3*triples) + (4*homers))/at-Bats

void printStatsToFile(const int stats[], const int size)
{
    ofstream outfile;
    outfile.open("a7stats.txt");
    outfile << "At Bats: " << stats[ATBATS] << endl;
    outfile << "Singles: " << stats[SINGLES] << endl;
    outfile << "Doubles: " << stats[DOUBLES] << endl;
    outfile << "Triples: " << stats[TRIPLES] << endl;
    outfile << "Home Runs: " << stats[HOMERS] << endl;
    outfile << "Walks: " << stats[WALKS] << endl;
    outfile << "Sacrifice Flies: " << stats[SACFLIES] << endl;
    outfile << "Batting Average: " << battingAverage(stats) << endl;
    outfile << "On Base Percentage: " << onBasePercentage(stats) << endl;
    outfile << "Slugging Percentage: " << sluggingPercentage(stats) << endl;
    outfile.close();
}
// prints all of the stats to the file a7stats.txt.
// you should probably check out the description file for all
// that you'll need to include.

void playBall(int stats[], const int size)
{
    PlayResult play;
    GeneratedPlayType playOutcome; // determine if hit, walk, out
    for (int i = 0; i < 10; i++)
    {
        play = roll(playOutcome);
        cout << "Play: ";
        printPlayResult(play);
        updateStatLine(play, stats);
    }
}
// takes in the array of stats, as well as the size of that array.
// prints the resulting plays to the screen.
// once done, it looks for the function necessary to print stats to a file...

#endif