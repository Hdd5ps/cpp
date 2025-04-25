#ifndef DOG_H
#define DOG_H

#include "Animal.h"

class Dog : public Animal
{
public:
    Dog(string c, string n, string b) : Animal(c, n, b)
    {
        // setters
        setColor(c);
        setName(n);
        setBreed(b);
    }
    void bark()
    {
        cout << "*burp*"
             << endl;
    }
    void greet()
    {
        cout << "*whimper*"
             << endl;
    }
    void introduceMyself()
    {
        Animal::introduceMyself();
        cout << "I am a dog." << endl;
        cout << "My breed is: " << getBreed() << "." << endl;
    }

    void eat()
    {
        Animal::eat();
        bark();
    }

    void sleep()
    {
        Animal::sleep();
        greet();
    }
};

#endif
