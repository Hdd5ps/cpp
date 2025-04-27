//CSC 1180 - Spring 2025, Programming Assignment 11
//Driver File - a11Driver.cc
//You might want to try other players and see if and how things pan out.

//you'll notice the third .h file isn't included here; this is because it's utilized by each
//of the two .h files listed below.
#include "Batter.h"
#include "Pitcher.h"
using namespace std;

int main(){
   BaseballPlayer bp;
   Batter b1;
   Pitcher p1;
   bp.setFirstName("Richard");
   bp.setLastName("Fitts");
   bp.setTeamName("Red Sox");
   bp.setAllStar(true);
   //your baseball player class should be able to pick up on the descrepancy that this
   //player is considered both active and a hall-of-famer.  The best thing to do is to
   //handle this exception, and set active and hall-of-famer to both be false.
   bp.setActive(true);
   bp.setHallOfFame(true);
   
   //creating object Frank Thomas, with inherited items from the BaseballPlayer class:
   Batter frankThomas("Frank", "Thomas", "White Sox", true, false, true, 8199, 2468,
   495, 12, 521, 1667, 87, 121);
   
   //creating the object Tim Hudson, with inherited items from the BaseballPlayer class:
   Pitcher timHudson("Tim", "Hudson", "Giants", true, true, true, 
   1213, 3126.67, 2957, 917, 2080, 222, 133);
   
   //next two lines of code override what << does; you'll need to address this in each
   //class 
   cout<<endl<<endl<<frankThomas<<endl;

   cout<<endl<<endl<<timHudson<<endl;
   
   cout<<endl<<endl<<bp<<endl;

}