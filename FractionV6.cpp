/*
CSC 1180 - Problem for 4/21
Create a class called Fraction
-add - DONE
-subtract - DONE
-multiply - DONE
-divide DONE
-show decimal equivalent - DONE
-reduce fraction to lowest form - DONE
-int - denominator, int - numerator - DONE

This version of Fraction omits the use of friends, to maintain sound
object-oriented programming principles, such as encapsulation and information
hiding.

publicReduce was an option to add to call reduce that was in private.  An
alternative solution could be to move reduce into the public section.  The
problem is that beyond calculations, reduce doesn't really serve much of a
purpose to the client of a class.
*/
#include<iostream>
using namespace std;

/*
friends - C++ thing
have access to non-public sections of your class. (public, private, protected)
(protected comes into play with inheritance, so hold that thought)
friend functions
friend classes

OOP - encapsulation, information hiding, show data as programmer wants it seen

where written?
in the class: friend function prototype (functions)
friend class X (classes)

coupling - degree to which one class/function knows the business of another class (private/protected)
cohesion - degree of reliance on just calling objects to do what is requested

loose coupling, strong cohesion

used for efficiency concerns?

*/

/*

More than one way to do things
-overloaded operators w/ friends
-overloaded operators w/o friends (safer, maintains OOPL concepts - encapsulation, information hiding)

*/

class Fraction{
public: //methods (some exceptions)
//constructor to initialize an object
//name of class and arguments in parentheses
//no return type
   Fraction(int n=0, int d=1){
      setNumerator(n);
      setDenominator(d);
   }
   
   //setters
   void setNumerator(int n){
      numerator = n;
     
      if(numerator < 0){//prevent negative values
         numerator = 0;
      }
   }
   
   void setDenominator(int d){
      denominator = d;
   
      if(denominator<1){//prevent negative values as well as 0
         denominator = 1;
      }
   }
   
   //getters
   int getNumerator(){
      return numerator;
   }
   
   int getDenominator(){
      return denominator;
   }
  

   double decimalEquivalent(){
      return (double)getNumerator()/getDenominator();
   
   }

   void print(){
      cout<<getNumerator()<<"/"<<getDenominator()<<endl;
   
   }
   
   /*
   
   no friends - so we don't break OOP ideals (information hiding, encapsulation)
   
   friend Fraction operator+(const Fraction&, const Fraction&);
   //c = a + b
   friend Fraction operator-(const Fraction&, const Fraction&);
   //c = a - b
   friend Fraction operator*(const Fraction&, const Fraction&);
   //c = a * b
   friend Fraction operator/(const Fraction&, const Fraction&);
   //c = a/b
   */
   void publicReduce(){
      reduce();
   }


private: 

   void reduce(){
   
   //assumption:  numerator is smaller than the denominator
      int gcd;
      for(int i = 1; i<=getNumerator(); i++){
         if(((getNumerator()%i)==0)&&((getDenominator()%i)==0)){
         //if index currently divides into both numerator and denominator
            gcd = i;
         }
      }
   
      setNumerator(getNumerator()/gcd);
      setDenominator(getDenominator()/gcd);
   
   
   }
   
   int numerator, denominator;

//data (some exceptions - methods - don't bring usefulness to class' client
};

Fraction operator+(Fraction f1, Fraction f2){ //pass-by-value; none of the "extra stuff"
//a/b + c/d = (ad + bc)/bd
   Fraction result;
   //step-by-step
   int tempNumerator1, tempNumerator2, tempDenominator;
   tempNumerator1 = f1.getNumerator() * f2.getDenominator(); //ad
   tempNumerator2 = f1.getDenominator() * f2.getNumerator(); //bc
   tempDenominator = f1.getDenominator() * f2.getDenominator(); //bd
   result.setNumerator(tempNumerator1 + tempNumerator2);
   result.setDenominator(tempDenominator);
   result.publicReduce();
   return result;

}

Fraction operator-(Fraction f1, Fraction f2){
//a/b - c/d = (ad - bc)/bd
   int tempNumerator1, tempNumerator2, tempDenominator;
   Fraction result;
   tempNumerator1 = f1.getNumerator() * f2.getDenominator(); //ad
   tempNumerator2 = f1.getDenominator() * f2.getNumerator(); //bc
   tempDenominator = f1.getDenominator() * f2.getDenominator(); //bd
   result.setNumerator(tempNumerator1 - tempNumerator2);
   result.setDenominator(tempDenominator);
   result.publicReduce(); //reduce the fraction - problematic later...
   return result;

}

Fraction operator*(Fraction f1, Fraction f2){

//n1/d1 * n2/d2 = (n1 * n2)/(d1 * d2)
   Fraction result;
   int tempNumerator, tempDenominator;
   tempNumerator = f1.getNumerator() * f2.getNumerator(); //multiplying top parts
   tempDenominator = f1.getDenominator()*f2.getDenominator(); //multiplying denominators
   result.setNumerator(tempNumerator);
   result.setDenominator(tempDenominator);
   result.publicReduce();
   return result;

}


Fraction operator/(Fraction f1, Fraction f2){
//n1/d1 / n2/d2 = n1/d1 * d2/n2 = (n1*d2)/(d1*n2)
   Fraction result;
   int tempNumerator, tempDenominator;
   tempNumerator = f1.getNumerator() * f2.getDenominator(); //n1*d2
   tempDenominator = f1.getDenominator() * f2.getNumerator(); //n2*d1
   result.setNumerator(tempNumerator);
   result.setDenominator(tempDenominator);
   result.publicReduce();
   return result;

}


int main(){

   Fraction f1(1, 8), f2(1, 4);
   Fraction f3;
   f3 = f1/f2;
   f3.print();

   return 0;
}

