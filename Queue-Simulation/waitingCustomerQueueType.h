#ifndef WAITINGCUSTOMERQUEUETYPE_H
#define WAITINGCUSTOMERQUEUETYPE_H
#include <iostream>
#include "customerType.h"
#include "queueType.h"
#include "serverType.h"
#include "serverListType.h"

using namespace std;

class waitingCustomerQueueType: public queueType<customerType>
{
    public:
        waitingCustomerQueueType(int size = 100);
        // constructor
        // postcondition: the queue is initialized according to the parameter size
        // the value of size is passed to the constructor of queueType

        void updateWaitingQueue();
        // function to increment the waiting time of each customer in the queue by one time unit
    private:
};

waitingCustomerQueueType::waitingCustomerQueueType(int size) : queueType<customerType>(size)
{
    // constructor
    // postcondition: the queue is initialized according to the parameter size
    // the value of size is passed to the constructor of queueType
}

void waitingCustomerQueueType::updateWaitingQueue()
{
    customerType cust;
    cust.setwaitingTime(-1);
    int wTime = 0;
    addQueue(cust);
    while (wTime != -1)
    {
        cust = front();
        deleteQueue();
        wTime = cust.getWaitingTime();
        if (wTime == -1)
            break;
        cust.incrementWaitingTime();
        addQueue(cust);
    }   
}

#endif