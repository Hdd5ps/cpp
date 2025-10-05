#include <iostream>
#include "customerType.h"
#include "waitingCustomerQueueType.h"
#include "serverType.h"
#include "serverListType.h"
#include "queueType.h"

using namespace std;

void setSimulationParameters(int& sTime, int& numOfServers, int& transTime, int& tBetweenCArrival);

void startTransaction(customerType customer, serverListType& serverList, int serverID, int transactionTime, int& totalWait, int& numCustomersServed);

void runSimulation(int simulationTime, int numberOfServers, int transactionTime, int timeBetweenArrivals, waitingCustomerQueueType& waitingCustomerQueue, serverListType& serverList);

int main()
{
    int simulationTime;
    int numberOfServers;
    int transactionTime;
    int timeBetweenArrivals;

    setSimulationParameters(simulationTime, numberOfServers, transactionTime, timeBetweenArrivals);

    waitingCustomerQueueType waitingCustomerQueue;
    serverListType serverList(numberOfServers);

    runSimulation(simulationTime, numberOfServers, transactionTime, timeBetweenArrivals, waitingCustomerQueue, serverList);
    return 0;
}

void setSimulationParameters(int& sTime, int& numOfServers, int& transTime, int& tBetweenCArrival)
{
    cout << "Enter the simulation time: ";
    cin >> sTime;
    cout << endl;

    cout << "Enter the number of servers: ";
    cin >> numOfServers;
    cout << endl;

    cout << "Enter the transaction time: ";
    cin >> transTime;
    cout << endl;

    cout << "Enter the time between customer arrivals: ";
    cin >> tBetweenCArrival;
    cout << endl;
}

void startTransaction(customerType customer, serverListType& serverList, int serverID, int transactionTime, int& totalWait, int& numCustomersServed)
{
    totalWait += customer.getWaitingTime();
    serverList.setServerBusy(serverID, customer, transactionTime);
    ++numCustomersServed;
}

void runSimulation(int simulationTime, int numberOfServers, int transactionTime, int timeBetweenArrivals, waitingCustomerQueueType& waitingCustomerQueue, serverListType& serverList)
{
    int totalWait = 0;
    int numCustomersArrived = 0;
    int numCustomersServed = 0;
    int customerNumber = 0;

    for (int clock = 1; clock <= simulationTime; ++clock)
    {
        if (timeBetweenArrivals > 0 && clock % timeBetweenArrivals == 0)
        {
            ++customerNumber;
            customerType newCustomer(customerNumber, clock, 0, transactionTime);
            ++numCustomersArrived;

            int freeServerID = serverList.getFreeServerID();
            if (freeServerID != -1)
            {
                startTransaction(newCustomer, serverList, freeServerID, transactionTime, totalWait, numCustomersServed);
            }
            else
            {
                waitingCustomerQueue.addQueue(newCustomer);
            }
        }

        serverList.updateServers(cout);

        while (!waitingCustomerQueue.isEmptyQueue())
        {
            int freeServerID = serverList.getFreeServerID();
            if (freeServerID == -1)
            {
                break;
            }

            customerType nextCustomer = waitingCustomerQueue.front();
            waitingCustomerQueue.deleteQueue();
            startTransaction(nextCustomer, serverList, freeServerID, transactionTime, totalWait, numCustomersServed);
        }

        if (!waitingCustomerQueue.isEmptyQueue())
        {
            waitingCustomerQueue.updateWaitingQueue();
        }
    }

    int numCustomersLeftInQueue = static_cast<int>(waitingCustomerQueue.size());
    cout << "\nSimulation summary:\n";
    cout << "Total customers arrived: " << numCustomersArrived << '\n';
    cout << "Total customers served: " << numCustomersServed << '\n';
    cout << "Customers left in queue: " << numCustomersLeftInQueue << '\n';
    cout << "Average wait time: "
         << (numCustomersServed > 0 ? static_cast<double>(totalWait) / numCustomersServed : 0.0)
         << '\n';
}