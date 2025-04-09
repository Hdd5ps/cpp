#include<string>
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include "assignment6.h"
#include "assignment7.h"
//hmmm...reusing an old file again here?
using namespace std;

#ifndef ASSIGNMENT9_H
#define ASSIGNMENT9_H

struct Player{ //each player...
   string name; //...has a name (from roster.txt)
   int atBats; //at-bats
   int singles; //singles
   int doubles; //doubles
   int triples; //triples
   int homers; //home runs
   int walks; //walks
   int sacflies; //sacflies
};


   
//needed for srand() call and initializing all lineup names and
//all values set to zero.
//names of the batters come from roster.txt
void initialize(Player*, const int);

//same calculation as before, just collecting the information in
//a different way.
double battingAverage(Player); 

//same story for on-base as batting average
double onBasePercentage(Player);   

//same story for slugging percentage
double sluggingPercentage(Player);   


//print out the player's stats to a file specified through the
//ostream argument.
//called by printPlayerStats
void printPlayer(Player, ofstream&);

//prints the header of each column, as well as each player's stats
//relies on printPlayerStats for a good bit of its functionality.
//writes to the file a9results.txt
void printPlayerStats(const Player*, const int);

 //after a batter has their plate appearance, update their stats,
 //based on the PlayResult; the third argument corresponds to 
 //a batter in the lineup  
void updateStatLine(PlayResult p, Player *pl, const int index);   

//similar functionality to playBall from the previous assignment's
//playBall.  The major difference here is the use of the pointer for
//the array of batters.      
void playBall(Player*);



#endif