#ifndef H_SERVERTYPE
#define H_SERVERTYPE

#include <iostream>
#include <string>
#include "customerType.h"

using namespace std;

class serverType
{
    public:
        serverType();
        //Default constructor
        //Sets the values of the instance variables to their //default values.
        //Postcondition: currentCustomer is initialized by its
        //default constructor; status = "free"; and
        //the transaction time is initialized to 0.
    
        bool isFree() const;
        //Function to determine if the server is free.
        //Postcondition: Returns true if the server is free,
        //otherwise returns false.
        
        void setBusy();
        //Function to set the status of the server to busy.
        //Postcondition: status = "busy"

        void setFree () ;
        //Function to set the status of the server to "free".
        //Postcondition: status = "free";

        void setTransactionTime (int t);
        //Function to set the transaction time according to //the parameter t.
        //Postcondition: transactionTime = t;

        void setTransactionTime();
        //Function to set the transaction time according to //the transaction time of the current customer.
        //Postcondition:
        // transactionTime = currentCustomer.transactionTime;

        int getRemainingTransactionTime() const;
        //Function to return the remaining transaction time.
        //Postcondition: The value of transactionTime is returned.

        void decreaseTransactionTime ();
        //Function to decrease the transactionTime by 1 unit.
        //Postcondition: transactionTime--;

        void setCurrentCustomer (customerType Customer);
        //Function to set the info of the current customer //according to the parameter cCustomer.
        //Postcondition: currentCustomer = cCustomer;

        int getCurrentCustomerNumber () const;
        //Function to return the customer number of the current //customer.
        //Postcondition: The value of customerNumber of the //
        //current customer is returned.

        int getCurrentCustomerArrivalTime () const;
        //Function to return the arrival time of the current //customer.
        ////Postcondition: The value of arrivalTime of the current customer is returned.

        int getCurrentCustomerWaitingTime() const;
        //Function to return the current waiting time of the //current customer.
        //Postcondition: The value of transactionTime is returned.

        int getCurrentCustomerTransactionTime() const;
        //Function to return the transaction time of the //current customer.
        //Postcondition: The value of transactionTime of the //current customer is returned.

    private:
        customerType currentCustomer;
        string status;
        int transactionTime;
};

serverType:: serverType ()
{
    status = "free";
    transactionTime = 0;
}

bool serverType:: isFree () const
{
    return (status == "free");
}

void serverType:: setBusy ()
{
    status = "busy";
}
void serverType:: setFree ()
{
    status = "free";
}

void serverType:: setTransactionTime (int t)
{
    transactionTime = t;
}

void serverType:: setTransactionTime ()
{
    int time;
    time = currentCustomer.getTransactionTime () ;
    transactionTime = time;
}

void serverType:: decreaseTransactionTime ()
{
    transactionTime--;
}

int serverType::getRemainingTransactionTime() const
{
    return transactionTime;
}

void serverType:: setCurrentCustomer (customerType cCustomer)
{
    currentCustomer = cCustomer;
}

int serverType:: getCurrentCustomerNumber () const
{
    return currentCustomer.getCustomerNumber();
}

int serverType:: getCurrentCustomerArrivalTime () const
{
    return currentCustomer.getArrivalTime();
}

int serverType:: getCurrentCustomerWaitingTime() const
{
    return currentCustomer.getWaitingTime();
}

int serverType:: getCurrentCustomerTransactionTime() const
{
    return currentCustomer.getTransactionTime();
}

#endif