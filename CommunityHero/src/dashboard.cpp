#include <iostream>
#include <fstream>
#include <string>
#include "dashboard.h"

void showDashboard() {
    std::cout << "Dashboard Overview:\n";

    // Display number of users
    std::ifstream userFile("data/users.txt");
    int userCount = 0;
    std::string line;
    while (std::getline(userFile, line)) {
        userCount++;
    }
    userFile.close();
    std::cout << "Total Users: " << userCount << std::endl;

    // Display number of requests
    std::ifstream requestFile("data/requests.txt");
    int requestCount = 0;
    while (std::getline(requestFile, line)) {
        requestCount++;
    }
    requestFile.close();
    std::cout << "Total Requests: " << requestCount << std::endl;

    // Display number of messages
    std::ifstream messageFile("data/messages.txt");
    int messageCount = 0;
    while (std::getline(messageFile, line)) {
        messageCount++;
    }
    messageFile.close();
    std::cout << "Total Messages: " << messageCount << std::endl;
}
