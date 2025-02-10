/*
Kamal Raj Timilsena
CSC 1180 - Programming in C++

Program 3 - Wooden Baseball game

This program will calculate the scores based on the dice rolled.

Algorithm:
Step 1 - Take the two dice value inputs (order doesn't matter). Validate the inputs (report an error for values less than 1 or greater than 6).
Step 2 - Use conditionals to determine if the values result in a play. The order doesn't matter.
Step 3 - Keep a count for hits (single, double, triple, walk, and home run).
Step 4 - End the game if the user plays three outs (double play, sacrifice play, fly out, pop out, ground out, strike out).
Step 5 - If the inning ends, show the hits and walks.
*/

#include <iostream>
using namespace std;

int main() {

    // Declare variables for dice
    int dice1 = 0, dice2 = 0;

    // Declare variable for play type, hit, out and walk count
    string play;
    int hit = 0;
    int out = 0;
    int walk = 0;

    do {
        cout << "Enter the first die's value: ";
        cin >> dice1;

        cout << "Enter the second die's value: ";
        cin >> dice2;


        // Determine the play based on dice values
        if ((dice1 == 1 && dice2 == 1) || (dice1 == 6 && dice2 == 6)) 
        {
            play = "Home Run";
            hit++;

        } 
        else if ((dice1 == 1 && dice2 == 2) || (dice1 == 2 && dice2 == 1) || (dice1 == 5 && dice2 == 5)) 
        {
            play = "Double";
            hit++;
        } 

        else if ((dice1 == 3 && dice2 == 4) || (dice1 == 4 && dice2 == 3)) 
        {
            play = "Triple";
            hit++;
        } 

        else if ((dice1 == 1 && dice2 == 6) || (dice1 == 6 && dice2 == 1) || (dice1 == 2 && dice2 == 5) || (dice1 == 5 && dice2 == 2)) 
        {
            play = "Single";
            hit++;
        } 

        else if ((dice1 == 1 && dice2 == 4) || (dice1 == 4 && dice2 == 1) || (dice1 == 3 && dice2 == 3) || (dice1 == 4 && dice2 == 4)) 
        {
            play = "Walk";
            walk++;
        } 

        else if ((dice1 == 1 && dice2 == 3) || (dice1 == 3 && dice2 == 1) || (dice1 == 3 && dice2 == 6) || (dice1 == 6 && dice2 == 3)) 
        {
            play = "Fly Out";
            out++;
        } 

        else if ((dice1 == 1 && dice2 == 5) || (dice1 == 5 && dice2 == 1) || (dice1 == 4 && dice2 == 5) || (dice1 == 5 && dice2 == 4)) 
        {
            play = "Pop Out";
            out++;
        } 

        else if (dice1 == 2 && dice2 == 2) 
        {
            play = "Double Play";
            out++;
        } 

        else if ((dice1 == 2 && dice2 == 3) || (dice1 == 3 && dice2 == 2) || (dice1 == 3 && dice2 == 5) || (dice1 == 5 && dice2 == 3)) 
        {
            play = "Ground Out";
            out++;
        } 

        else if ((dice1 == 2 && dice2 == 4) || (dice1 == 4 && dice2 == 2) || (dice1 == 4 && dice2 == 6) || (dice1 == 6 && dice2 == 4) || (dice1 == 2 && dice2 == 6) || (dice1 == 6 && dice2 == 2) ) 
        {
            play = "Strike Out";
            out++;
        } 

        else if ((dice1 == 5 && dice2 == 6) || (dice1 == 6 && dice2 == 5) ) 
        {
            play = "Sacrifice Play";
            out++;
        } 

        else 
        {
        // Validate dice values
            play = "Not a play. A normal six-sided die has the following values for its six sides: 1, 2, 3, 4, 5, or 6.";
        }

        // displaying the results
        cout << "Resulting play: " << play << endl;
        cout<<endl;

    } while (out < 3);

    // End of the inning
    cout << "End of the inning." << endl;
    cout << "Hits: " << hit << endl;
    cout << "Walks: " << walk << endl;

    return 0;
}