#include <iostream>
#include "user.h"
#include "request.h"
#include "admin.h"
#include "communication.h"
#include "dashboard.h"

void showMenu() {
    std::cout << "Welcome to Community Hero\n";
    std::cout << "1. Register\n";
    std::cout << "2. Login\n";
    std::cout << "3. Submit Request\n";
    std::cout << "4. Manage Requests (Admin)\n";
    std::cout << "5. Send Message\n";
    std::cout << "6. View Messages\n";
    std::cout << "7. View Dashboard\n";
    std::cout << "8. Exit\n";
    std::cout << "Choose an option: ";
}

int main() {
    int choice;
    while (true) {
        showMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                submitRequest();
                break;
            case 4:
                manageRequests();
                break;
            case 5:
                sendMessage();
                break;
            case 6:
                viewMessages();
                break;
            case 7:
                showDashboard();
                break;
            case 8:
                std::cout << "Goodbye!\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    }
    return 0;
}
