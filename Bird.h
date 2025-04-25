#ifndef BIRD_H
#define BIRD_H

#include "Animal.h"

class Bird : public Animal
{
private:
    double wingspan;
    bool flies;

public:
    Bird(string c, string n, string b, double w, bool f) : Animal(c, n, b), wingspan(w), flies(f)
    {
        // setters
        setColor(c);
        setName(n);
        setBreed(b);
        wingspan = w;
        flies = f;
    }
    void chirp()
    {
        cout << "chirp chirp" << endl;
    }
    void soar()
    {
        cout << "chirp chirp\nchirp chirp" << endl;
    }
    void introduceMyself()
    {
        Animal::introduceMyself();
        cout << "I am a bird." << endl;
        cout << "My breed is " << getBreed() << "." << endl;
        cout << "My wingspan is " << wingspan << " inches." << endl;
        if (flies)
        {
            cout << "Yes; I can fly." << endl;
        }
        else
        {
            cout << "No; I cannot fly." << endl;
        }
    }

    void eat()
    {
        Animal::eat();
        chirp();
    }
    void sleep()
    {
        Animal::sleep();
        soar();
    }
};

#endif
