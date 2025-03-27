#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#ifndef ASSIGNMENT6_H
#define ASSIGNMENT6_H

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

// Initialize random number generator
void initialize()
{
    srand(time(0));
}

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
        cout << "Walk\n" << endl;
        break;
    case SINGLE:
        cout << "Single\n" << endl;
        break;
    case DOUBLE:
        cout << "Double\n" << endl;
        break;
    case TRIPLE:
        cout << "Triple\n" << endl;
        break;
    case HOME_RUN:
        cout << "Home Run\n" << endl;
        break;
    case FLY_OUT:
        cout << "Fly Out\n" << endl;
        break;
    case POP_OUT:
        cout << "Pop Out\n" << endl;
        break;
    case GROUND_OUT:
        cout << "Ground Out\n" << endl;
        break;
    case STRIKE_OUT:
        cout << "Strike Out\n" << endl;
        break;
    case DOUBLE_PLAY:
        cout << "Double Play\n" << endl;
        break;
    default:
        cout << "Sacrifice Fly\n" << endl;
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
    scorePlay(play);
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

// Calculation for team batting average
void teamBattingAverage(int hits, int atbats, double &battingAverage)
{
    battingAverage = (double)hits / (double)atbats;
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

#endif