#include <iostream>
#include <fstream>
#include <string>
#include "request.h"

void submitRequest() {
    std::string username, requestDetails;
    std::cout << "Enter your username: ";
    std::cin >> username;
    std::cin.ignore(); // To ignore the newline character left in the buffer
    std::cout << "Enter request details: ";
    std::getline(std::cin, requestDetails);

    std::ofstream file("data/requests.txt", std::ios::app);
    file << username << ": " << requestDetails << std::endl;
    file.close();

    std::cout << "Request submitted successfully!\n";
}

void viewRequests() {
    std::ifstream file("data/requests.txt");
    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }
    file.close();
}
