#ifndef H_CUSTOMERTYPE
#define H_CUSTOMERTYPE
#include<iostream>
using namespace std;

class customerType
{
    public:
        customerType (int customerNN = 0, int arrvTime = 0, int wTime = 0,int tTime = 0);
        //Constructor to initialize the instance variables //according to the parameters
        //If no value is specified in the object declaration, //the default values are assigned.
        //Postcondition: customerNumber = cN;
        //
        //arrivalTime = arrvTime;
        //
        //waitingTime = wTime;
        //
        //transactionTime = tTime

        void setCustomerInfo(int customerN = 0, int inTime = 0, int wTime = 0, int tTime = 0) ;
        //Function to initialize the instance variables.
        //Instance variables are set according to the parameters.
        //Postcondition: customerNumber = customerN;
        //arrivalTime = arrvTime;
        //waitingTime = wTime;
        //transactionTime = tTime;

        int getWaitingTime() const;
        //Function to return the waiting time of a customer.
        //Postcondition: The value of waitingTime is returned.
        
        void setwaitingTime (int time);
        //Function to set the waiting time of a customer.
        //Postcondition: waitingTime = time;
        
        void incrementWaitingTime ();
        //Function to increment the waiting time by one time unit.
        //Postcondition: waitingTime++;

        int getArrivalTime() const;
        //Function to return the arrival time of a customer.
        //Postcondition: The value of arrivalTime is returned.

        int getTransactionTime() const;
        //Function to return the transaction time of a customer.
        //Postcondition: The value of transactionTime is returned.

        int getCustomerNumber () const;
        //Function to return the customer number.
        //Postcondition: The value of customerNumber is returned.
    private:
        int customerNumber; 
        int arrivalTime; 
        int waitingTime; 
        int transactionTime;
};

void customerType::setCustomerInfo(int customerN, int arrvTime, int wTime, int tTime)
{
    customerNumber = customerN;
    arrivalTime = arrvTime;
    waitingTime = wTime;
    transactionTime = tTime;
}

customerType::customerType(int customerN, int arrvTime, int wTime, int tTime)
{
    setCustomerInfo (customerN, arrvTime, wTime, tTime);
}

int customerType::getWaitingTime() const
{
    return waitingTime;
}

void customerType::incrementWaitingTime()
{
    waitingTime++;
}

void customerType::setwaitingTime(int time)
{
    waitingTime = time;
}

int customerType::getArrivalTime() const
{
    return arrivalTime;
}

int customerType::getTransactionTime() const
{
    return transactionTime;
}

int customerType::getCustomerNumber() const
{
    return customerNumber;
}

#endif