#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>
using namespace std;

class Animal
{
private:
    // common attributes
    string color;
    string name;
    string breed;

public:
    Animal(string c, string n, string b) : color(c), name(n), breed(b)
    {
        // setters
        setColor(c);
        setName(n);
        setBreed(b);
    }

    // setters
    void setColor(string c)
    {
        color = c;
    }
    void setName(string n)
    {
        name = n;
    }
    void setBreed(string b)
    {
        breed = b;
    }

    // getters
    string getColor()
    {
        return color;
    }  
    string getName()
    {
        return name;
    }
    string getBreed()
    {
        return breed;
    }

    // common methods
    void eat()
    {
        cout << "Omnomnomnom...nomnomnom...nomnomnom" << endl;
    }
    void sleep()
    {
        cout << "zzzzzzzzzzzzzzzzzzzz" << endl;
    }
    void introduceMyself()
    {
        cout << "Hello, my name is " << getName() << "." << endl;
        cout << "My color is " << getColor() << "." << endl;
    }
};

#endif
