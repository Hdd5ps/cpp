#include "Bird.h"
#include "Cat.h"
#include "Dog.h"
using namespace std;

/*
For Lab 8, you will need to come up with definitions for
Animal, Bird, Cat, and Dog.  Each will need to be in its own
.h file (so, Animal.h, Bird.h, Cat.h, Dog.h)

*/

int main()
{

   // creating objects of Animal, Bird, Cat, and Dog.
   // note that since Bird, Cat, and Dog are all derived
   // from Animal, you don't have to include it as part of
   // the #include directives.

   /*
   Reminder:  Bird, Cat, and Dog inherit from Animal, which
   means they are more specialized versions of class Animal.  Either
   more data to worry about, more methods to write, a modification
   of methods, etc.
   */

   Animal a("Green", "Malfoy", "Cottonmouth");
   Bird b1("Black and White", "Buster", "Penguin", 10.5, false);
   Bird b2("Gray", "Sisko", "Hawk", 36.71, true);
   Cat c1("Orange", "Tigger", "Tabby", false);
   Cat c2("Orange, Black, and White", "S'mores", "Calico", true);
   Dog d("Tan", "Trooper ", "Golden Retriever");

   // Each animal introduces itself
   a.introduceMyself();
   cout << endl;
   b1.introduceMyself();
   cout << endl;
   b2.introduceMyself();
   cout << endl;
   c1.introduceMyself();
   cout << endl;
   c2.introduceMyself();
   cout << endl;
   d.introduceMyself();
   cout << endl;

   // Each animal eats
   a.eat();
   cout << endl;
   b1.eat();
   cout << endl;
   b2.eat();
   cout << endl;
   c1.eat();
   cout << endl;
   c2.eat();
   cout << endl;
   d.eat();
   cout << endl;

   // Each animal sleeps
   a.sleep();
   cout << endl;
   b1.sleep();
   cout << endl;
   b2.sleep();
   cout << endl;
   c1.sleep();
   cout << endl;
   c2.sleep();
   cout << endl;
   d.sleep();
   cout << endl;

   // Just a quick missive to say we're done
   cout << endl
        << "End program." << endl;

   return 0;
}