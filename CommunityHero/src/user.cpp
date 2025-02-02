#include <iostream>
#include <fstream>
#include <string>
#include "user.h"

void registerUser() {
    std::string username, password;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;

    std::ofstream file("data/users.txt", std::ios::app);
    file << username << " " << password << std::endl;
    file.close();

    std::cout << "Registration successful!\n";
}

void loginUser() {
    std::string username, password, storedUsername, storedPassword;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;

    std::ifstream file("data/users.txt");
    bool loginSuccess = false;
    while (file >> storedUsername >> storedPassword) {
        if (username == storedUsername && password == storedPassword) {
            loginSuccess = true;
            break;
        }
    }
    file.close();

    if (loginSuccess) {
        std::cout << "Login successful!\n";
    } else {
        std::cout << "Invalid username or password.\n";
    }
}
