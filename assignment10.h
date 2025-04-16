#include<string>
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include<vector>
#include "assignment6.h"
#include "assignment7.h" //reusing files again?  Hmmm...
using namespace std;

#ifndef ASSIGNMENT10_H
#define ASSIGNMENT10_H


class Player{
public:
   //Constructor with one argument, default argument; name of the player
   //the default argument is the empty string ""
   //Calls the setters
      
   //define getters and setters

   //the ofstream argument passed in refers to the file being printed to.
   void print(ofstream&);



private:

   //methods are in private because they really only help with the print
   //at this point in time.

   //calculates batting average the same as before, just the methodology
   //will be different.
   double battingAverage();
   
   //calculates obp, just the methodology is different
   double onBasePercentage();

   //same story with slugging percentage 
   double sluggingPercentage(){
      
   string name; //player's name
   int atBats, walks, sacflies; //stats to keep up with
   int singles, doubles, triples, homers; //different types of scored hits
};


   
//reads names from roster.txt and stores them to objects in the vector.
void initialize(vector<Player>&, const int);
   

//prints out all of the batters' results, formatted like previous assignments,
//to a file called a10results.txt   
void printPlayerStats(vector<Player>);

//similar to previous versions of playBall, the argument this time being
//a vector of players.  As with previous versions
void playBall(vector<Player>&);

#endif