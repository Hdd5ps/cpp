/*
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

int main()
{
    Fraction f1(1, 2), f2(1, 4);
    f1.addition(f2);
    f1.print();
    cout << "Decimal equivalent: " << f1.decimalEquivalent() << endl;
    cout << "------------------------" << endl;

    f1.subtraction(f2);
    f1.print();
    cout << "Decimal equivalent: " << f1.decimalEquivalent() << endl;
    cout << "------------------------" << endl;

    Fraction f3(2, 3);
    f1.multiplication(f3);
    f1.print();
    cout << "Decimal equivalent: " << f1.decimalEquivalent() << endl;
    cout << "------------------------" << endl;

    f1.division(f3);
    f1.print();
    cout << "Decimal equivalent: " << f1.decimalEquivalent() << endl;
    cout << "------------------------" << endl;

    return 0;
}