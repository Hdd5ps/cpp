#ifndef H_SERVERlISTTYPE
#define H_SERVERlISTTYPE

#include <iostream>
#include "customerType.h"
#include "serverType.h"

using namespace std;

class serverListType
{
    public:
        serverListType(int num = 1);
        //Constructor to initialize a list of servers
        //Postcondition: numOfServers = num
       // A list of servers, specified by num, is created and each server is initialized to "free".
        
        ~serverListType () ;
        //Destructor
        //Postcondition: The list of servers is destroyed.

        int getFreeServerID() const;
        //Function to search the list of servers.
        //Postcondition: If a free server is found, returns its ID; otherwise, returns -1.

        int getNumberOfBusyServers () const;
        //Function to return the number of busy servers.
        //Postcondition: The number of busy servers is returned.

        void setServerBusy(int serverID, customerType cCustomer, int tTime);
        //Function to set a server as busy.
        //Postcondition: The server specified by serverID is
        //set to "busy", to serve the customer
        //specified by cCustomer, and the transaction time is set according to
        //the parameter tTime.

        void setServerBusy(int serverID, customerType Customer);
        //Function to set a server as busy.
        //Postcondition: The server specified by serverID is set
        //to "busy", to serve the customer
        //specified by Customer. 

        void updateServers (ostream& outFile);
        //Function to update the status of a server.
        //Postcondition: The transaction time of each busy
        //server is decremented by one unit. If the transaction time of a busy server
        //is reduced to zero, the server is set to "free". Moreover, if the actual parameter
        // corresponding to outFile is cout, a message indicating which customer has been served
        //  is printed on the screen, together with the customer's departing time. Otherwise, the 
        // output is sent to a file specified by the user.
  
    private:
        int numOfServers;
        serverType *servers;
};

serverListType:: serverListType (int num)
{
    numOfServers = num;
    servers = new serverType[num];
}
serverListType::~serverListType()
{
    delete[] servers;
}


int serverListType::getFreeServerID() const
{
    int serverID = -1;
    for (int i = 0; i < numOfServers; i++)
        if (servers[i].isFree())
        {
            serverID = i;
            break;
        }
        return serverID;
}   

int serverListType::getNumberOfBusyServers() const
{
    int busyServers = 0;
    for (int i = 0; i < numOfServers; i++)
        if (!servers[i].isFree())
            busyServers++;
    return busyServers;
}

void serverListType::setServerBusy(int serverID,
customerType cCustomer, int tTime)
{
    servers[serverID].setBusy();
    servers[serverID].setTransactionTime(tTime);
    servers[serverID].setCurrentCustomer(cCustomer);
}

void serverListType::setServerBusy(int serverID, customerType Customer)
{
    int time;
    time = Customer.getTransactionTime();
    servers[serverID].setBusy();
    servers[serverID].setTransactionTime(time);
    servers[serverID].setCurrentCustomer(Customer);
}

void serverListType::updateServers (ostream& outFile)
{
    for (int i = 0; i < numOfServers; i++)
    {
        if (!servers[i].isFree())
        {
            servers[i].decreaseTransactionTime();
            if (servers[i].getRemainingTransactionTime() == 0)
            {
                outFile << "From server number " << (i + 1)
                        << " customer number "
                        << servers[i].getCurrentCustomerNumber()
                        << " departed at time unit "
                        << servers[i].getCurrentCustomerArrivalTime()
                        + servers[i].getCurrentCustomerWaitingTime()
                        + servers[i].getCurrentCustomerTransactionTime()
                        << endl;
                servers[i].setFree();
            }
        }
    }
}

#endif