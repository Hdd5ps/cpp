#include <iostream>
#include <fstream>
#include <string>
#include "communication.h"

void sendMessage() {
    std::string sender, recipient, message;
    std::cout << "Enter your username: ";
    std::cin >> sender;
    std::cout << "Enter recipient username: ";
    std::cin >> recipient;
    std::cin.ignore(); // To ignore the newline character left in the buffer
    std::cout << "Enter your message: ";
    std::getline(std::cin, message);

    std::ofstream file("data/messages.txt", std::ios::app);
    file << sender << " to " << recipient << ": " << message << std::endl;
    file.close();

    std::cout << "Message sent successfully!\n";
}

void viewMessages() {
    std::ifstream file("data/messages.txt");
    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }
    file.close();
}
