#include "assignment7.h"
// hmmmm...looks like we're using something from assignment7.h, which,
// by extension means we might be utilizing something from assignment6.h...
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

#ifndef ASSIGNMENT8_H
#define ASSIGNMENT8_H

// four arguments for initialize:
// 1) array of stats for all players in the line-up
// 2 and 3) size of the row and columns
// 4 the last argument is made up of the strings found in roster.txt
void initialize(int battingOrder[][7], const int ROW_SIZE, const int COL_SIZE, string lineup[])
{
    // Initialize the random number generator
    srand(time(0));

    // Open the file for reading
    ifstream infile("roster.txt");

    if (!infile.is_open())
    {
        return;
    }

    // Read the full name (name and surname) of the players from the file into the lineup array
    for (int i = 0; i < ROW_SIZE; i++)
    {
        if (!getline(infile, lineup[i]))
        {
            break;
        }
    }

    // Close the file
    infile.close();

    // Initialize all elements of the battingOrder array to 0
    for (int i = 0; i < ROW_SIZE; i++)
    {
        for (int j = 0; j < COL_SIZE; j++)
        {
            battingOrder[i][j] = 0;
        }
    }
}

// three arguments represent:
// the play "rolled"
// 2D array of stats
// index for the particular batter's information we're updating.
void updateStatLine(PlayResult play, int stats[][7], const int index)
{
    // increment the number of at-bats
    stats[index][ATBATS]++;

    // increment the appropriate statistic based on the play result
    switch (play)
    {
    case SINGLE:
        stats[index][SINGLES]++;
        break;
    case DOUBLE:
        stats[index][DOUBLES]++;
        break;
    case TRIPLE:
        stats[index][TRIPLES]++;
        break;
    case HOME_RUN:
        stats[index][HOMERS]++;
        break;
    case WALK:
        stats[index][WALKS]++;
        stats[index][ATBATS]--;
        break;
    case FLY_OUT:
    case POP_OUT:
    case STRIKE_OUT:
    case DOUBLE_PLAY:
    case GROUND_OUT:
        break;
    default:
        stats[index][SACFLIES]++;
        stats[index][ATBATS]--;
        break;
    }
}

// similar to battingAverage from last program, just now having a
// second dimension, to accommodate 9 batters.

double battingAverage(const int stats[][7], const int batters)
{
    double average = 0.0;
    for (int i = 0; i < batters; i++)
    {
        if (stats[i][ATBATS] == 0)
        {
            average = 0.0; // Prevent division by zero
        }
        else
        {
            average = (double)(stats[i][SINGLES] + stats[i][DOUBLES] + stats[i][TRIPLES] + stats[i][HOMERS]) / (double)stats[i][ATBATS];
        }
    }
    return average;
}

// same story as with batting average
double onBasePercentage(const int stats[][7], const int batters)
{
    double obp = 0.0;
    for (int i = 0; i < batters; i++)
    {
        // Check if the denominator is zero
        if (stats[i][ATBATS] + stats[i][WALKS] == 0)
        {
            obp = 0.0; // Prevent division by zero
        }
        else
        {
            obp = (double)(stats[i][SINGLES] + stats[i][DOUBLES] + stats[i][TRIPLES] + stats[i][HOMERS] + stats[i][WALKS]) /
                  (double)(stats[i][ATBATS] + stats[i][WALKS]);
        }
    }
    return obp;
}

// same story as with batting average
double sluggingPercentage(const int stats[][7], int batters)
{
    double slug = 0.0;
    for (int i = 0; i < batters; i++)
    {
        // Check if the denominator is zero
        if (stats[i][ATBATS] == 0)
        {
            slug = 0.0; // Prevent division by zero
        }
        else
        {
            slug = (double)(stats[i][SINGLES] + stats[i][DOUBLES] * 2 + stats[i][TRIPLES] * 3 + stats[i][HOMERS] * 4) /
                   (double)stats[i][ATBATS];
        }
    }
    return slug;
}

// prints all batters' stats to a file called a8results.txt, complete
// with headers and everything lined up.
// see the assignment 8 description for what this file should look like.
void printStatsToFile(const int battingOrder[][7], string lineup[], const int ROW_SIZE)
{
    ofstream outfile("a8results.txt");

    if (!outfile.is_open())
    {
        return;
    }

    // Set formatting for the output file
    outfile << fixed << setprecision(3);

    // Print the headers
    outfile << setw(20) << left << "Player"
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

    // Print the stats for each player
    for (int i = 0; i < ROW_SIZE; i++)
    {
        outfile << setw(20) << left << lineup[i]; // Print player full name
        for (int j = 0; j < 7; j++)
        {
            outfile << setw(5) << battingOrder[i][j]; // Print stats
        }
        // Print batting average, on-base percentage, and slugging percentage
        outfile << setw(8) << battingAverage(battingOrder, i)
                << setw(8) << onBasePercentage(battingOrder, i)
                << setw(8) << sluggingPercentage(battingOrder, i) << endl;
    }

    // Close the file
    outfile.close();
}

// keep in mind that there are three outs to an inning
// the team will "play" nine innings
// prints each batter's name, as well as the resulting play
// keeps track of the number of hits and walks per inning and prints
// that information out after each inning is complete.
// remember how to cycle back up to the first batter when you're on the
// last one in the line-up
// if you're sitting at two outs and you get a SAC_FLY, change this to a
// FLY_OUT, because this is going to end the inning.
// if you're sitting at two outs and get a DOUBLE_PLAY, change this to a
// GROUNDOUT, because this is going to end the inning.
void playBall(int battingOrder[][7], string lineup[], const int ROW_SIZE)
{

    // initialize the play result
    PlayResult play;

    GeneratedPlayType playOutcome;

    // initialize the number of hits and walks
    int hits = 0;
    int walks = 0;

    // loop through the nine innings
    for (int inning = 0; inning < 9; inning++)
    {
        // initialize the number of outs
        int outs = 0;

        cout << "Inning " << inning + 1 << ": " << endl;
        // loop through each batter in the line-up
        for (int batter = 0; batter < ROW_SIZE; batter++)
        {
            // roll the dice to determine the play
            play = roll(playOutcome);

            cout << "Up to bat: " << lineup[batter] << "\n";
            cout << "Play: ";
            printPlayResult(play);
            // update the batter's stats
            updateStatLine(play, battingOrder, batter);

            // check if the play is a hit, walk, or out
            if (play == WALK)
            {
                walks++;
            }
            else if (play == SINGLE || play == DOUBLE || play == TRIPLE || play == HOME_RUN)
            {
                hits++;
            }
            // check if the play is an out
            if (play == FLY_OUT || play == SAC_FLY || play == GROUND_OUT || play == STRIKE_OUT || play == POP_OUT || play == DOUBLE_PLAY)
            {
                outs++;
            }

            // cycle back to the first batter if at the end of the line-up
            // if the batter is the last one in the line-up, reset to the first batter
            if (batter == ROW_SIZE - 1)
            {
                batter = -1; // reset to the first batter
            }
            // check if the play is a hit, walk, or out
            if (play == SAC_FLY && outs == 2)
            {
                play = FLY_OUT;
            }
            else if (play == DOUBLE_PLAY && outs == 2)
            {
                play = GROUND_OUT;
            }
            // print the play result
            // check if the inning is over
            if (outs == 3)
            {
                cout << "End of Inning.\n"
                     << "Walks: " << walks << "\n"
                     << "Hits: " << hits << "\n"
                     << endl;
                hits = 0;
                walks = 0;

                char cont;
                cout << "Continue ? (y/n): ";
                cin >> cont;
                if (cont == 'n' || cont == 'N')
                {
                    cout << "Exiting the game.\n";
                    return;
                }
                else
                {
                    break; // exit the loop to start the next inning
                }
            }
        }
    }
}
#endif