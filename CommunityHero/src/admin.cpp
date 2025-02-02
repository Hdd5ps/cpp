#include <iostream>
#include <fstream>
#include <string>
#include "admin.h"

void manageRequests() {
    std::ifstream file("data/requests.txt");
    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }
    file.close();

    std::cout << "Enter the username of the request to mark as resolved: ";
    std::string username;
    std::cin >> username;

    // Logic to mark the request as resolved (e.g., remove from file or mark with a status)
    // This is a simplified example; you can expand it as needed.
    std::cout << "Request from " << username << " marked as resolved.\n";
}
