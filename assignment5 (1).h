#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

#ifndef ASSIGNMENT5_H
#define ASSIGNMENT5_H

enum PlayResult{NONE, WALK, SINGLE, DOUBLE, TRIPLE, HOME_RUN, FLY_OUT,
SAC_FLY, GROUND_OUT, STRIKE_OUT, POP_OUT, DOUBLE_PLAY};

enum GeneratedPlayType{NOT, BB, HIT, OUT};

void initialize(){
   srand(time(0));
}

bool isValid(int number){
//checking the bounds for the given number
   if (number<1){//one is the lower bound on a six-sided die
      return false;//if less than 1, invalid
   }
   else if(number>6){//six is the upper bound on a six-sided die
      return false;//if greater than 6, invalid
   }
   return true;//otherwise, within range
}

PlayResult getPlay(int d1, int d2){
//assuming d1 is smaller/equal to d2
   PlayResult play = NONE;
   //check to make sure both d1 and d2 are in bounds...
   if((!isValid(d1))||(!isValid(d2))){
      return play;
   }
         
   switch(d1){
      case 1: //first die is a 1
         switch(d2){
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
      case 2: //first die is a 2
         switch(d2){
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
      case 3: //first die is a 3
         switch(d2){
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
      case 4: //first die is a 4
         switch(d2){
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
      case 5: //first die is a 5
         switch(d2){
            case 5:
               play = DOUBLE;
               break;
            case 6:
               play = SAC_FLY;
               break;
         }
         break;
      case 6: //first die is a 6
         switch(d2){
            case 6:
               play = HOME_RUN;
               break;
         }
         break;
   }
         
   return play;
}

void printPlayResult(PlayResult p){
   switch(p){
      case WALK:
         cout<<"Walk"<<endl;
         break;
      case SINGLE:
         cout<<"Single"<<endl;
         break;
      case DOUBLE:
         cout<<"Double"<<endl;
         break;
      case TRIPLE:
         cout<<"Triple"<<endl;
         break;
      case HOME_RUN:
         cout<<"Home Run"<<endl;
         break;
      case FLY_OUT:
         cout<<"Fly Out"<<endl;
         break;
      case POP_OUT:
         cout<<"Pop Out"<<endl;
         break;
      case GROUND_OUT:
         cout<<"Ground Out"<<endl;
         break;
      case STRIKE_OUT:
         cout<<"Strike Out"<<endl;
         break;
      case DOUBLE_PLAY:
         cout<<"Double Play"<<endl;
         break;
      case SAC_FLY:
         cout<<"Sacrifice Fly"<<endl;
         break;
      default:
         cout<<"No play"<<endl;
         break;
   }
}

PlayResult roll(){
   int die1, die2, swapValue;
   int upper = 6, lower = 1; //range, just looking at upper and lower values
   int range = upper - lower + 1; //range = upper-lower + 1
   PlayResult play;
   die1 = rand()%range; //generate random number
   die1 += lower; //add lower bound; repeat for die2
   die2 = rand()%range;
   die2 += lower;

   if(die1 > die2){ //put lower value first
      swapValue = die1;
      die1 = die2;
      die2 = swapValue;
   }

//determine the play
   play = getPlay(die1, die2);
   return play; //send back the resulting play to main()

}

GeneratedPlayType scorePlay(PlayResult play){
//determine hit, walk, or out
   GeneratedPlayType gpt = NOT;
   switch(play){
      case SINGLE:
      case DOUBLE:
      case TRIPLE:
      case HOME_RUN: gpt = HIT;
         break;
      case FLY_OUT:
      case POP_OUT:
      case STRIKE_OUT:
      case DOUBLE_PLAY:
      case GROUND_OUT:
      case SAC_FLY: gpt = OUT;
         break;
      case WALK: gpt = BB;
         break;
      default: //nothing to do here, just turn off warnings
         break;
   }
   
   return gpt;

}

#endif