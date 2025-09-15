// Author: D.S. Malik
#include <iostream>
#include <string>

using namespace std;

class dvdType
{
    friend ostream& operator<< (ostream&, const dvdType&);
    
    public:
    void setDVDInfo(string title, string star1, string star2, string producer, string director, string productionCo, int setInStock);
    // function to set the details of a DVD

    int getNoOfCopiesInStock() const;
    // function tot check the number of copies in stock.

    void checkOut();
    // function to rent a DVD

    void checkIn();
    // function to check in a DVD.

    void printTitle() const;
    // functio to print the title of movie

    void printInfo() const;
    // function to print the detials of a DVD

    bool checkTitle(string title);
    // function to check whethre the title is the same as teh title of the DVD.

    void updateInStock(int num);
    // function to increment the number of copies in stock by adding the value of the paramenter num.

    void setCopiesInStock(int num);
    // function to set teh number of copies in stock

    string getTitle() const;
    // function to return the title of the DVD

    dvdType(string title = "", string star1 = "", string star2 = "", string producer = "", string director = "", string productionCo = "", int setInStock = 0);
    // constructor

    // overload the relational operator
    bool operator==(const dvdType&) const;
    bool operator!=(const dvdType&) const;

    private:
    string dvdTitle; // variabl eto store the naem of the movie
    string movieStar1; // variable to store the name of the star
    string movieStar2; // variable to store the name of the star
    string movieProducer; // variable to store the name of the producer
    string movieDirector; // variable to store the name of the director
    string movieProductionCo; // variable to store the name of the production company
    int setCopiesInStock; // variable to store the number of copies in stock
};