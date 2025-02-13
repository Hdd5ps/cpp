/*
Kamal Raj Timilsena
CSC 1180 - Programming in C++

Program 4 - Wooden Baseball game

This program will calculate the scores based on the dice rolled.

Algorithm:
Step 1 - Take the two dice value inputs (order doesn't matter). Validate the inputs (report an error for values less than 1 or greater than 6).
Step 2 - Use conditionals to determine if the values result in a play. The order doesn't matter.
Step 3 - Keep a count for hits (single, double, triple, walk, and home run).
Step 4 - End the game if the user plays three outs (double play, sacrifice play, fly out, pop out, ground out, strike out).
Step 5 - If the inning ends, show the hits and walks.
*/

#include <iostream>
#include <fstream>
using namespace std;

enum Play { HOME_RUN, DOUBLE, TRIPLE, SINGLE, WALK, FLY_OUT, POP_OUT, DOUBLE_PLAY, GROUND_OUT, STRIKE_OUT, SACRIFICE_FLY, INVALID };

Play determinePlay(int dice1, int dice2) {
    if ((dice1 == 1 && dice2 == 1) || (dice1 == 6 && dice2 == 6)) {
        // Home Run
        return HOME_RUN;
    } 

    else if ((dice1 == 1 && dice2 == 2) || (dice1 == 2 && dice2 == 1) || (dice1 == 5 && dice2 == 5)) {
        // Double
        return DOUBLE;
    } 

    else if ((dice1 == 3 && dice2 == 4) || (dice1 == 4 && dice2 == 3)) {
        // Triple
        return TRIPLE;
    } 

    else if ((dice1 == 1 && dice2 == 6) || (dice1 == 6 && dice2 == 1) || (dice1 == 2 && dice2 == 5) || (dice1 == 5 && dice2 == 2)) {
        return SINGLE;
    } 

    else if ((dice1 == 1 && dice2 == 4) || (dice1 == 4 && dice2 == 1) || (dice1 == 3 && dice2 == 3) || (dice1 == 4 && dice2 == 4)) {
        // Walk
        return WALK;
    } 

    else if ((dice1 == 1 && dice2 == 3) || (dice1 == 3 && dice2 == 1) || (dice1 == 3 && dice2 == 6) || (dice1 == 6 && dice2 == 3)) {
        // Fly Out
        return FLY_OUT;
    } 
    
    else if ((dice1 == 1 && dice2 == 5) || (dice1 == 5 && dice2 == 1) || (dice1 == 4 && dice2 == 5) || (dice1 == 5 && dice2 == 4)) {
        // Pop Out
        return POP_OUT;
    } 
    
    else if (dice1 == 2 && dice2 == 2) {
        // Double Play
        return DOUBLE_PLAY;
    } 
    
    else if ((dice1 == 2 && dice2 == 3) || (dice1 == 3 && dice2 == 2) || (dice1 == 3 && dice2 == 5) || (dice1 == 5 && dice2 == 3)) {
        // Ground Out
        return GROUND_OUT;
    } 
    
    else if ((dice1 == 2 && dice2 == 4) || (dice1 == 4 && dice2 == 2) || (dice1 == 4 && dice2 == 6) || (dice1 == 6 && dice2 == 4) || (dice1 == 2 && dice2 == 6) || (dice1 == 6 && dice2 == 2)) {
        // Strike Out
        return STRIKE_OUT;
    } 
    
    else if ((dice1 == 5 && dice2 == 6) || (dice1 == 6 && dice2 == 5)) {
        // Sacrifice Fly
        return SACRIFICE_FLY;
    } 
    
    else {
        // Invalid play
        return INVALID;
    }
}

int main() {
    // Declare variables for dice
    int dice1 = 0, dice2 = 0;

    // Declare an ofstream variable
    ofstream playResult("playResults.txt");

    // Declare variables for play type, hit, out and walk count
    int hit = 0;
    int out = 0;
    int walk = 0;
    int batter = 1;

    do {
        cout << "Enter the first die value: ";
        cin >> dice1;

        cout << "Enter the second die value: ";
        cin >> dice2;

        // Validate dice values
        if (dice1 < 1 || dice1 > 6 || dice2 < 1 || dice2 > 6) {
            cout << "Invalid input; please try again." << endl;
            cout << "Each die's possible value should be between 1 and 6 inclusive." << endl;
            cout << endl;
            continue;
        }

        // Determine the play based on dice values
        Play play = determinePlay(dice1, dice2);

        // Display and log the results
        cout << "Batter " << batter << ": ";

        playResult << "Batter " << batter << ": ";

        switch (play) {
            case HOME_RUN:
                cout << "Home Run" << endl;
                playResult << "Home Run" << endl;
                hit++;
                break;

            case DOUBLE:
                cout << "Double" << endl;
                playResult << "Double" << endl;
                hit++;
                break;

            case TRIPLE:
                cout << "Triple" << endl;
                playResult << "Triple" << endl;
                hit++;
                break;

            case SINGLE:
                cout << "Single" << endl;
                playResult << "Single" << endl;
                hit++;
                break;

            case WALK:
                cout << "Walk" << endl;
                playResult << "Walk" << endl;
                walk++;
                break;

            case FLY_OUT:
                cout << "Fly Out" << endl;
                playResult << "Fly Out" << endl;
                out++;
                break;

            case POP_OUT:
                cout << "Pop Out" << endl;
                playResult << "Pop Out" << endl;
                out++;
                break;

            case DOUBLE_PLAY:
                cout << "Double Play" << endl;
                playResult << "Double Play" << endl;
                out++;
                break;

            case GROUND_OUT:
                cout << "Ground Out" << endl;
                playResult << "Ground Out" << endl;
                out++;
                break;

            case STRIKE_OUT:
                cout << "Strike Out" << endl;
                playResult << "Strike Out" << endl;
                out++;
                break;

            case SACRIFICE_FLY:
                cout << "Sacrifice Fly" << endl;
                playResult << "Sacrifice Fly" << endl;
                out++;
                break;

            case INVALID:
                cout << "Invalid play" << endl;
                playResult << "Invalid play" << endl;
                break;
        }

        cout<<endl;
        playResult<<endl;

        batter = (batter % 9) + 1; // Cycle through batters

    } while (out < 3);

    // End of the inning
    cout << "Total walks: " << walk << endl;
    cout << "Total hits: " << hit << endl;

    playResult.close(); // closing the playresult file

    return 0;
}