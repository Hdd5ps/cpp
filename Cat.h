#ifndef CAT_H
#define CAT_H

#include "Animal.h"

class Cat : public Animal
{
private:
    bool domesticated;

public:
    Cat(string c, string n, string b, bool d) : Animal(c, n, b), domesticated(d)
    {
        // setters
        setColor(c);
        setName(n);
        setBreed(b);
        domesticated = d;
    }
    void meow()
    {
        cout << "More food, wait staff. Now!" << endl;
    }
    void purr()
    {
        cout << "Don't move, hooman. Your lap is my bed " << endl;
        if (!domesticated)
        {
            cout << "I like it better than out there. It's a lot warmeer and more comfortable." << endl;
        }
    }
    void introduceMyself()
    {
        Animal::introduceMyself();
        cout << "I am a cat." << endl;
        cout << "My breed is " << getBreed() << ". ";
        if (domesticated)
        {
            cout << "I am domesticated." << endl;
        }
        else
        {
            cout << "I am feral." << endl;
        }
    }

    void eat()
    {
        Animal::eat();
        meow();
    }

    void sleep()
    {
        Animal::sleep();
        purr();
    }
};

#endif
