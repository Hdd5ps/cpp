#include <iostream>
#include <fstream>
// hmmm, with the inclusion of assignment6.h file, it looks like you might be
// about to - dare I say it - reuse something(s) from the file.
using namespace std;

#ifndef ASSIGNMENT7_H
#define ASSIGNMENT7_H

// Enumeration for play results
enum PlayResult
{
    NONE,
    WALK,
    SINGLE,
    DOUBLE,
    TRIPLE,
    HOME_RUN,
    FLY_OUT,
    SAC_FLY,
    GROUND_OUT,
    STRIKE_OUT,
    POP_OUT,
    DOUBLE_PLAY
};

// Enumeration for generated play types
enum GeneratedPlayType
{
    NOT,
    BB,
    HIT,
    OUT
};

// Check if the function is within bounds
bool isValid(int number)
{
    // Checking the bounds for the given number
    if (number < 1)
    {                 // One is the lower bound on a six-sided die
        return false; // If less than 1, invalid
    }
    else if (number > 6)
    {                 // Six is the upper bound on a six-sided die
        return false; // If greater than 6, invalid
    }
    return true; // Otherwise, within range
}

// Determine the play based on two dice
PlayResult getPlay(int d1, int d2)
{
    // Assuming d1 is smaller/equal to d2
    PlayResult play = NONE;
    // Check to make sure both d1 and d2 are in bounds...
    if ((!isValid(d1)) || (!isValid(d2)))
    {
        return play;
    }

    switch (d1)
    {
    case 1: // First die is a 1
        switch (d2)
        {
        case 1:
            play = HOME_RUN;
            break;
        case 2:
            play = DOUBLE;
            break;
        case 3:
            play = FLY_OUT;
            break;
        case 4:
            play = WALK;
            break;
        case 5:
            play = POP_OUT;
            break;
        case 6:
            play = SINGLE;
            break;
        }
        break;
    case 2: // First die is a 2
        switch (d2)
        {
        case 2:
            play = DOUBLE_PLAY;
            break;
        case 3:
            play = GROUND_OUT;
            break;
        case 4:
            play = STRIKE_OUT;
            break;
        case 5:
            play = SINGLE;
            break;
        case 6:
            play = STRIKE_OUT;
            break;
        }
        break;
    case 3: // First die is a 3
        switch (d2)
        {
        case 3:
            play = WALK;
            break;
        case 4:
            play = TRIPLE;
            break;
        case 5:
            play = GROUND_OUT;
            break;
        case 6:
            play = FLY_OUT;
            break;
        }
        break;
    case 4: // First die is a 4
        switch (d2)
        {
        case 4:
            play = WALK;
            break;
        case 5:
            play = POP_OUT;
            break;
        case 6:
            play = STRIKE_OUT;
            break;
        }
        break;
    case 5: // First die is a 5
        switch (d2)
        {
        case 5:
            play = DOUBLE;
            break;
        case 6:
            play = SAC_FLY;
            break;
        }
        break;
    case 6: // First die is a 6
        switch (d2)
        {
        case 6:
            play = HOME_RUN;
            break;
        }
        break;
    }

    return play;
}

// Print the play result
void printPlayResult(PlayResult p)
{
    switch (p)
    {
    case WALK:
        cout << "Walk" << endl;
        break;
    case SINGLE:
        cout << "Single" << endl;
        break;
    case DOUBLE:
        cout << "Double" << endl;
        break;
    case TRIPLE:
        cout << "Triple" << endl;
        break;
    case HOME_RUN:
        cout << "Home Run" << endl;
        break;
    case FLY_OUT:
        cout << "Fly Out" << endl;
        break;
    case POP_OUT:
        cout << "Pop Out" << endl;
        break;
    case GROUND_OUT:
        cout << "Ground Out" << endl;
        break;
    case STRIKE_OUT:
        cout << "Strike Out" << endl;
        break;
    case DOUBLE_PLAY:
        cout << "Double Play" << endl;
        break;
    case SAC_FLY:
        cout << "Sacrifice Fly" << endl;
        break;
    default:
        cout << "No play" << endl;
        break;
    }
}

GeneratedPlayType scorePlay(PlayResult play);
// Function to roll the dice and determine play
PlayResult roll(GeneratedPlayType &p)
{
    int die1, die2, swapValue;
    int upper = 6, lower = 1;      // Range, just looking at upper and lower values
    int range = upper - lower + 1; // Range = upper-lower + 1
    PlayResult play;
    die1 = rand() % range; // Generate random number
    die1 += lower;         // Add lower bound; repeat for die2
    die2 = rand() % range;
    die2 += lower;

    if (die1 > die2)
    { // Put lower value first
        swapValue = die1;
        die1 = die2;
        die2 = swapValue;
    }

    // Determine the play
    play = getPlay(die1, die2);
    p = scorePlay(play); // Determine play type
    return play;         // Send back the resulting play to main()
}

// Play type determining function (hit, walk, or out)
GeneratedPlayType scorePlay(PlayResult play)
{
    // Determine hit, walk, or out
    GeneratedPlayType gpt = NOT;
    switch (play)
    {
    case SINGLE:
    case DOUBLE:
    case TRIPLE:
    case HOME_RUN:
        gpt = HIT;
        break;
    case FLY_OUT:
    case POP_OUT:
    case STRIKE_OUT:
    case DOUBLE_PLAY:
    case GROUND_OUT:
    case SAC_FLY:
        gpt = OUT;
        break;
    case WALK:
        gpt = BB;
        break;
    default:
        break; // Nothing to do here, just turn off warnings
    }

    return gpt;
}


// Calculation for team on-base percentage
void teamOnBasePct(int hits, int walks, int atbats, double &onbase)
{
    onbase = (double)(hits + walks) / (double)(atbats + walks);
}

// Calculate total bases
void totalBases(PlayResult p, int &total)
{
    switch (p)
    {
    case SINGLE:
    total += 1;
    break;
    case DOUBLE:
    total += 2;
    break;
    case TRIPLE:
        total += 3;
        break;
        case HOME_RUN:
        total += 4;
        break;
        default:
        break; // Nothing to do here, just turn off warnings
    }
}

// Calculate team slugging percentage
double teamSluggingPercentage(int atBats, int totalBaseCount)
{
    double totalBases = (double)totalBaseCount / (double)atBats;
    return totalBases;
}

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

// initializes the array, as well as sets up the seed for the
// random number generator
void initialize(int battersLine[], const int SIZE)
{
    srand(time(0)); // seed the random number generator
    for (int i = 0; i < SIZE; i++)
    {                       // initialize the array to 0
        battersLine[i] = 0; // set each element to 0
    }
}
// first argument is the array; second is the size of the array

void updateStatLine(PlayResult p, int stats[])
{
    // based on the play result, update the player's stats
    switch (p)
    {
        case SINGLE:
        stats[SINGLES]++;
        break;
        case DOUBLE:
        stats[DOUBLES]++;
        break;
        case TRIPLE:
        stats[TRIPLES]++;
        break;
        case HOME_RUN:
        stats[HOMERS]++;
        break;
    case WALK:
        stats[WALKS]++;
        break;
        case SAC_FLY:
        stats[SACFLIES]++;
        break;
        default:
        break; // no update for other plays
    }
}
// based on the first argument, update the player's stats where needed.

// Calculation for team batting average
void teamBattingAverage(int hits, int atbats, double &battingAverage)
{
    battingAverage = (double)hits / (double)atbats;
}
double battingAverage(const int stats[]){
// calculates the batting average:
// hits/at-bats
    return (double)stats[SINGLES] + (double)stats[DOUBLES] + (double)stats[TRIPLES] + (double)stats[HOMERS] / (double)(stats[ATBATS]);
}
// calculates the total number of hits divided by the total number of at-bats

double onBasePercentage(const int stats[]){
// calculates on-base percentage:
// (hits + walks)/(at-bats + walks)
    return (double)(stats[SINGLES] + stats[DOUBLES] + stats[TRIPLES] + stats[HOMERS] + stats[WALKS]) / (double)(stats[ATBATS] + stats[WALKS]);
}
// calculates (hits+walks)/(at-bats + walks)

double sluggingPercentage(const int[]);
// calculates slugging percentage:
//(singles + (2*doubles) + (3*triples) + (4*homers))/at-Bats

void printStatsToFile(const int[], const int);
// prints all of the stats to the file a7stats.txt.
// you should probably check out the description file for all
// that you'll need to include.

void playBall(int array[], const int size);
// takes in the array of stats, as well as the size of that array.
// prints the resulting plays to the screen.
// once done, it looks for the function necessary to print stats to a file...

#endif