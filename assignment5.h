//You will need to remember to adjust the name of this file prior to
//turning it in.

//Do remember that the overall purpose of utilizing .h files is to promote
//reusability in the code that you write.  If you write it in this file,
//you need only reference this file to get whatever function/enumerated type
//that you have created here.

#include<iostream>   //cin, cout, endl
#include<cstdlib>    //rand(), srand() calls
#include<ctime>      //time(0) to generate truly random numbers, as previously
                     //discussed in class.

using namespace std;

//side-note: when the above libraries are included here, you don't necessarily
//have to include them in other files of the program.

#ifndef ASSIGNMENT5_H 
//once the header file is included, it checks to see if a unique value (in
//this case ASSIGNMENT5_H has been defined.  If it's not defined, it defines
//it using the #define line below.
//when the file is used again in the same application elsewhere, none of its
//contents are redefined (which avoids some headaches and choice words for
//your compiler).
#define ASSIGNMENT5_H
//if the file's contents have not previously been defined, they are done so
//here, following the above #define

//Need two enumerated types.
//Remember that multiple enumerated types cannot share the same value name.
enum PlayResult { HOME_RUN, DOUBLE, TRIPLE, SINGLE, WALK, FLY_OUT, POP_OUT, DOUBLE_PLAY, GROUND_OUT, STRIKE_OUT, SACRIFICE_FLY, INVALID};
enum GeneratedPlayType { HIT, BB, OUT};

//functions:

void initialize(){
    srand(time(0));
}
//takes no arguments.  Its only purpose is to set the seed for the random
//number generator.

bool isValid(int arg){
    if (arg < 1){
        return false;
    }
    else if (arg > 6){
        return false;
    }
    else{
        return true;
    }
}
//takes in a single integer argument.  If it's within the proper range of the
//value of a six-sided die, it returns true.  If not, it returns false.

PlayResult getPlay(int dice1, int dice2){
    isValid(dice1);
    isValid(dice2);

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
        // Single
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
        cout << "Invalid play detected." << endl;
        return INVALID;
    }
}
//takes in two integer values that represent the rolling of two dice and
//determines the correct play.  It prints out the play via a call to 
//printPlay, and returns the determined play result.  You should probably
//make a call to the function that determines if a value "rolled" is
//valid.

void printPlayResult(PlayResult i)
{
    switch (i) {
        case HOME_RUN:
            cout << "Home Run" << endl;
            break;

        case DOUBLE:
            cout << "Double" << endl;
            break;

        case TRIPLE:
            cout << "Triple" << endl;
            break;

        case SINGLE:
            cout << "Single" << endl;
            break;

        case WALK:
            cout << "Walk" << endl;
            break;

        case FLY_OUT:
            cout << "Fly Out" << endl;
            break;

        case POP_OUT:
            cout << "Pop Out" << endl;
            break;

        case DOUBLE_PLAY:
            cout << "Double Play" << endl;
            break;

        case GROUND_OUT:
            cout << "Ground Out" << endl;
            break;

        case STRIKE_OUT:
            cout << "Strike Out" << endl;
            break;

        case SACRIFICE_FLY:
            cout << "Sacrifice Fly" << endl;
            break;

        default :
            cout << "Invalid play" << endl;
            break;
    }
}
//prints out the text that corresponds to the PlayResult value passed in.

PlayResult roll()
{
    // Initialize the random number generator
    initialize();

    // Generate the first random number between 1 and 6
    int rolledValue1 = rand() % 6 + 1;

    // Generate the second random number between 1 and 6
    int rolledValue2 = rand() % 6 + 1;

    // Ensure the two numbers are different
    while (rolledValue1 == rolledValue2) {
        rolledValue2 = rand() % 6 + 1;
    }

    return getPlay(rolledValue1, rolledValue2);
}
//simulates the rolling of two dice and makes a call to getPlay and returns
//the value returned by getPlay

GeneratedPlayType scorePlay(PlayResult i){
    switch (i){
        case HOME_RUN:
        case DOUBLE:
        case TRIPLE:
        case SINGLE:
            return HIT;
            break;

        case WALK:
            return BB;
            break;

        case FLY_OUT:
        case POP_OUT:
        case DOUBLE_PLAY:
        case GROUND_OUT:
        case STRIKE_OUT:
        case SACRIFICE_FLY:
            return OUT;
            break;

        default:
            break;
    }
}
//given the value of the PlayResult argument passed in, it returns the
//appropriate value necessary for tallying hits, walks, and outs.
//anything with the word out in it is an out, as is sac fly and double play.
//the word walk means a walk
//anything else is considered a hit.

#endif
//signifies the end of the #ifndef from above.