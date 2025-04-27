#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#ifndef BASEBALL_PLAYER_H
#define BASEBALL_PLAYER_H

// inheritance - parent class is BaseballPlayer

// Do not modify the interface, except where it is noted that it could be beneficial to do so...

/** START OF INTERFACE/NO MODIFICATIONS (EXCEPT WHERE NOTED) **/
class BaseballPlayer
{

public:
   // Constructor - takes in first name, last name, team name as strings
   // other arguments that follow: all-star, active, and hall of fame, which are all booleans.
   // Note:  a player cannot be active and in the Hall of Fame.

   /* ** NOTE:  the constructor may be of use to you to modify a little bit, while maintaining its
   being a prototype here. ** */
   BaseballPlayer(string first, string last, string team, bool all, bool act, bool hof)
   {
      setFirstName(first);
      setLastName(last);
      setTeamName(team);
      setAllStar(all);
      setActive(act);
      setHallOfFame(hof);
   }
   // order of arguments:  first name, last name, team name, if they've been an all-star,
   // if they're active, if they're a hall-of-famer

   // if you take a further look at the driver, you'll notice something interesting about how the
   // constructor is called...

   // setters - no changes needed to the interface here.
   void setFirstName(string first)
   {
      firstName = first;
   }
   void setLastName(string last)
   {
      lastName = last;
   }
   void setTeamName(string team)
   {
      teamName = team;
   }
   void setAllStar(bool all)
   {
      allStar = all;
   }
   void setActive(bool act)
   {
      active = act;
      // if a player is active, they cannot be in the Hall of Fame.
      if (active == true)
      {
         hallOfFame = false;
      }
   }
   void setHallOfFame(bool hof)
   {
      hallOfFame = hof;
      // if a player is in the Hall of Fame, they cannot be active.
      if (hof == true)
      {
         active = false;
      }
   }

   // getters - note:  not all say get; no changes needed to the interface here, either.

   string getFirstName()
   {
      return firstName;
   }
   string getLastName()
   {
      return lastName;
   }
   string getTeamName()
   {
      return teamName;
   }
   bool isAnAllStar()
   {
      return allStar;
   }
   bool isActive()
   {
      return active;
   }
   bool isHallOfFamer()
   {
      return hallOfFame;
   }

   // the data you'll need.  Do not modify what's here.
protected:
   string firstName, lastName, teamName;
   bool allStar, active, hallOfFame;

}; /** END OF THE CLASS INTERFACE **/

// Start writing implementations for each of your methods for BaseballPlayer here

// ostream& as the return type for operator<< - allows the chaining of multiple items with
// stream insertion operators (you'd see the same thing with >>, too.
// basically, it allows something like: cout<<"Baseball Player"<<endl<<bp<<endl;
// to actually happen

ostream &operator<<(ostream &, BaseballPlayer);
// this is a function that is external to the BaseballPlayer class.
// arguments:  os - where in the output stream you presently are; this will change, as
// you add stuff you want to print out from BaseballPlayer.
// see sample output for an idea of the order.
#endif