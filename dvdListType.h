// author: d.s malik
#include <string>
#include "unorderedLinkedList.h"
#include "dvdType.h"

using namespace std;

class dvdListType:public unorderedLinkedList<dvdType>
{
    public:
        bool dvdSearch(string title) const;
        // function to search the list ot see whether a particular title is in the list

        bool isDVDAvailable(string title) const;
        // function to determine whether a copy of a particular DVD is in th store.

        void dvdCheckOut(string title);
        // function to check out a DVD, that is rent a DVD

        void dvdCheckIn(string title);
        // function to check in a DVD returned by a customer

        bool dvdCheckTitle(string title) const;
        // function to determine whether a particular DVD is in the store.

        void dvdUpdateInStock(string title, int num);
        // function to update teh number of copies of a DVD

        void dvdSetCopiesInStock(string title, int num);
        // function to reset the number of copies of a DVD.

        void dvdPrintTitle() const;
        // function to print the titles of all the DVDs in the store

    private:
        void searchDVDList(string title, bool& found, nodeType<dvdType>* &current) const;
        // this function searches the DVD list for a particular DVD specified by the parameter.
    
};

void dvdListType::searchDVDList(string title, bool& found, nodeType<dvdType>* &current) const
{
    found = false; // set found to false

    current = this->first; // set current to point to the first node in the list

    while (current != nullptr && !found) // search the list
        if (current->info.dvdCheckTitle(title)) // the item is found
            found = true;
        else
            current = current->link; // advance current to the next node
}

bool dvdListType::isDVDAvailable(string title) const
{
    bool found;
    nodeType<dvdType> *location;

    searchDVDList(title, found, location);

    if (found)
        found = (location->info.getNoOfCopiesInStock() > 0);
    else
        found = false;
    return found;
}

void dvdListType::dvdCheckIn(string title)
{
    bool found = false;
    nodeType<dvdType> *location;

    searchDVDList(title, found, location); // search the list

    if (found)
        location->info.checkIn();
    else
        cout << "The store does not carry " << title << endl;
}

void dvdListType::dvdCheckOut(string title)
{
    bool found = false;
    nodeType<dvdType> *location;

    searchDVDList(title, found, location); // search the list

    if (found)
        location->info.checkOut();
    else
        cout << "The store does not carry " << title << endl;
}

bool dvdListType::dvdCheckTitle(string title) const
{
    bool found = false;
    nodeType<dvdType> *location;

    searchDVDList(title, found, location); // search the list
    return found;
}

void dvdListType::dvdUpdateInStock(string title, int num)
{
    bool found = false;
    nodeType<dvdType> *location;

    searchDVDList(title, found, location); // search the list

    if (found)
        location->info.dvdUpdateInStock(num);
    else
        cout << "The store does not carry " << title << endl;
}

void dvdListType::dvdSetCopiesInStock(string title, int num)
{
    bool found = false;
    nodeType<dvdType> *location;

    searchDVDList(title, found, location);

    if (found)
        location->info.dvdSetCopiesInStock(num);
    else
        cout << "The store does not carry " << title << endl;
}

bool dvdListType::dvdSearch(string title) const
{
    bool found = false;
    nodeType<dvdType> *location;

    searchDVDList(title, found, location);

    return found;
}

void dvdListType::dvdPrintTitle() const
{
    nodeType<dvdType>* current;
    current = this->first;
    
    while (current!=nullptr)
    {
        current->info.dvdPrintTitle();
        current = current->link;
    }
}