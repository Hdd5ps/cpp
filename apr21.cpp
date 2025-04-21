/*

*/

/*

// april 14, 2o25 and april 16
Create a class called Fraction
-add
-subtract
-multiply
-divide
-show decimal equivalent
-reduce fraction  to lowest form
-int - denominator, int- numerator
*/
#include <iostream>
using namespace std;

/*
friends - C++ thing
have access to non-public members of a class. (public, private, protected)
(protected comes into play with inheritance, so hold that thought)
friend functions
friend classes

friend function - a function that is not a member of the class but has access to its private and protected members.
used for efficiency and convenience.

OOP - encapsulation, data hiding, show data as programmer wants to see it
Encapsulation - the bundling of data with the methods that operate on that data.
Data hiding - restricting access to the internal representation of an object.

where written?
in the class: friend function prototype (functions)
friend class X (classes)

coupling - the degree of interdependence between software modules.(degree to which one class/function knows the business of another class/function )
cohesion - the degree to which the elements inside a module belong together.(degree of reliances on just calling objects to do what is requested)

loose coupling, strong cohesion
loose coupling - the degree to which one class/function knows the business of another class/function
strong cohesion - the degree to which the elements inside a module belong together.
*/

/*
Operator Overloading
Operator overloading is a feature in C++ that allows you to redefine the way operators work for user-defined types (classes).
This means you can specify how operators like +, -, *, /, etc., behave when applied to objects of your class.
This is done by defining special member functions or friend functions in your class. For example, you can overload
 the + operator to add two objects of a class together, or the << operator to print an object to an output stream.
*/

/*
-overloaded operators w/ friends
-overloaded operators w/o friends (safer, maintains OOPL concepts - encapsulation)
*/

class Fraction
{
public: // methods (some exceptions)
    // constructor to initialize an object
    // no return type name of class and arguments in parenthese
    Fraction(int n = 0, int d = 1)
    {
        setNumerator(n);
        setDenominator(d);
    }

    // setters
    void setNumerator(int n)
    {
        // set numerator
        numerator = n;
        // check if numerator is negative
        if (numerator < 0)
        {
            numerator = 0;
        }
    }

    void setDenominator(int d)
    {
        // set denominator
        denominator = d;
        // check if denominator is zero and negative
        if (denominator < 1)
        {
            denominator = 1;
        }
    }

    // getters
    int getNumerator()
    {
        // return numerator
        return numerator;
    }
    int getDenominator()
    {
        // return denominator
        return denominator;
    }

    // Expectation: c = a + b
    // Reality: a = a + b - argument f represents b
    // a = the object itself
    void addition(Fraction f)
    {
        // add two fractions
        // n1/d1 + n2/d2 = (n1*d2 + n2*d1)/(d1*d2)

        /*
        setNumerator(getNumerator() * f.getDenominator() + f.getNumerator() * getDenominator());
        setDenominator(getDenominator() * f.getDenominator());
        */

        int tempNumerator1, tempNumerator2, tempDenominator;

        tempNumerator1 = getNumerator() * f.getDenominator();
        // tempNumerator1 = numerator * f.denominator;

        tempNumerator2 = f.getNumerator() * getDenominator();
        // tempNumerator2 = f.numerator * denominator;

        tempDenominator = getDenominator() * f.getDenominator();
        // tempDenominator = denominator * f.denominator;

        setNumerator(tempNumerator1 + tempNumerator2);
        setDenominator(tempDenominator);

        reduce();
    }

    void subtraction(Fraction f)
    {
        // subtract two fractions
        // n1/d1 - n2/d2 = (n1*d2 - n2*d1)/(d1*d2)

        int tempNumerator1, tempNumerator2, tempDenominator;

        tempNumerator1 = getNumerator() * f.getDenominator();
        // an object of fraction has called subtraction, with an argument of f -> object.subtraction(f)

        tempNumerator2 = f.getNumerator() * getDenominator();

        tempDenominator = getDenominator() * f.getDenominator();

        setNumerator(tempNumerator1 - tempNumerator2);
        setDenominator(tempDenominator);

        reduce(); // reduce fraction to lowest form
    }

    void multiplication(Fraction f)
    {
        // multiplication two fractions
        // n1/d1 * n2/d2 = (n1*n2)/(d1*d2)
        int tempNumerator, tempDenominator;

        tempNumerator = getNumerator() * f.getNumerator();

        tempDenominator = getDenominator() * f.getDenominator();

        setNumerator(tempNumerator);
        setDenominator(tempDenominator);

        reduce(); // reduce fraction to lowest form
    }

    void division(Fraction f)
    {
        // division two fractions
        // n1/d1 / n2/d2 = n1/d1 * d2/n2 = (n1*d2)/(d1*n2)
        int tempNumerator, tempDenominator;

        tempNumerator = getNumerator() * f.getDenominator();

        tempDenominator = getDenominator() * f.getNumerator();

        setNumerator(tempNumerator);
        setDenominator(tempDenominator);

        reduce(); // reduce fraction to lowest form
    }

    double decimalEquivalent()
    {
        // show decimal equivalent
        return (double)getNumerator() / getDenominator();
    }

    void print()
    {
        // print fraction
        cout << getNumerator() << "/" << getDenominator() << endl;
    }
    /*
    // // a = the object itself
    // // b = the argument passed to the function
    // // c = the object returned by the function

    // // friend f(Fraction); // friend + function prototype
    // friend Fraction operator+(const Fraction &f);
    // // c = a + b

    // friend Fraction operator-(const Fraction, const Fraction);
    // // c = a - b
    // friend Fraction operator*(const Fraction, const Fraction);
    // // c = a * b
    // friend Fraction operator/(const Fraction, const Fraction);
    // // c = a / b
    */

    void publicReduce()
    {
        // reduce fraction to lowest form
        reduce();
    }

private: // data (some exceptions - methods that don't bring usefulness to class' client)
    void reduce()
    {
        // reduce fraction to lowest form

        // assumption: numerator is smaller than the denominator
        int gcd = 1; // greatest common divisor
        for (int i = 1; i <= getNumerator(); i++)
        {
            if (((getNumerator() % i) == 0) && ((getDenominator() % i) == 0))
            // if index currently divides into both numerator and denominator
            {
                gcd = i;
            }
        }

        setNumerator(getNumerator() / gcd);
        setDenominator(getDenominator() / gcd);
    }

    int numerator, denominator; // data members
};

Fraction operator+(Fraction f1, Fraction f2)
{
    // add two fractions
    // n1/d1 + n2/d2 = (n1*d2 + n2*d1)/(d1*d2)

    Fraction result;
    int tempNumerator1, tempNumerator2, tempDenominator;
    tempNumerator1 = f1.getNumerator() * f2.getDenominator();
    tempNumerator2 = f2.getNumerator() * f1.getDenominator();
    tempDenominator = f1.getDenominator() * f2.getDenominator();
    result.setNumerator(tempNumerator1 + tempNumerator2);
    result.setDenominator(tempDenominator);
    result.publicReduce(); // reduce fraction to lowest form
    return result;   // return the result
}

Fraction operator-(Fraction f1, Fraction f2)
{
    // subtract two fractions
    // n1/d1 - n2/d2 = (n1*d2 - n2*d1)/(d1*d2)

    Fraction result;
    int tempNumerator1, tempNumerator2, tempDenominator;
    tempNumerator1 = f1.getNumerator() * f2.getDenominator();
    tempNumerator2 = f2.getNumerator() * f1.getDenominator();
    tempDenominator = f1.getDenominator() * f2.getDenominator();
    result.setNumerator(tempNumerator1 - tempNumerator2);
    result.setDenominator(tempDenominator);
    result.publicReduce(); // reduce fraction to lowest form
    return result;   // return the result
}

Fraction operator*(Fraction f1, Fraction f2)
{
    // multiply two fractions
    // n1/d1 * n2/d2 = (n1*n2)/(d1*d2)

    Fraction result;
    int tempNumerator, tempDenominator;
    tempNumerator = f1.getNumerator() * f2.getNumerator();
    tempDenominator = f1.getDenominator() * f2.getDenominator();
    result.setNumerator(tempNumerator);
    result.setDenominator(tempDenominator);
    result.publicReduce(); // reduce fraction to lowest form
    return result;   // return the result
}

Fraction operator/(Fraction f1, Fraction f2)
{
    // divide two fractions
    // n1/d1 / n2/d2 = n1/d1 * d2/n2 = (n1*d2)/(d1*n2)

    Fraction result;
    int tempNumerator, tempDenominator;
    tempNumerator = f1.getNumerator() * f2.getDenominator();
    tempDenominator = f1.getDenominator() * f2.getNumerator();
    result.setNumerator(tempNumerator);
    result.setDenominator(tempDenominator);
    result.publicReduce(); // reduce fraction to lowest form
    return result;   // return the result
}

int main()
{
    Fraction f1(1, 8), f2(1, 4);
    Fraction f3;
    f3 = f1 + f2; // f3 = f1.addition(f2);
    f3.print();
    f3 = f3.decimalEquivalent(); // f3 = f1.decimalEquivalent();
    cout << f3 << endl;

    f3 = f1 - f2; // f3 = f1.subtraction(f2);
    f3.print();
    f3 = f3.decimalEquivalent(); // f3 = f1.decimalEquivalent();
    cout << f3 << endl;

    f3 = f1 * f2; // f3 = f1.multiplication(f2);
    f3.print();
    f3 = f3.decimalEquivalent(); // f3 = f1.decimalEquivalent();
    cout << f3 << endl;

    f3 = f1 / f2; // f3 = f1.division(f2);
    f3.print();
    f3 = f3.decimalEquivalent(); // f3 = f1.decimalEquivalent();
    cout << f3 << endl;

    return 0;
}