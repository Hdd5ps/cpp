//SOLOMON, KAMAL, DALLAS                                                                                                                                                                                        

#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <string>
using namespace std;

struct ItemNode {
    string itemName;
    ItemNode* next;
};

// Add a new item to the front of the list                                                                                                                                                                      
void addItem(ItemNode*& head, const string& item) {
    ItemNode* newNode = new ItemNode;
    newNode->itemName = item;
    newNode->next = head;
    head = newNode;

    cout << item << " added to your inventory.\n";
}

// Remove the first matching item                                                                                                                                                                               
bool removeItem(ItemNode*& head, const string& item) {
    if (head == nullptr) {
        return false;
    }

    // If the item is in the first node                                                                                                                                                                         
    if (head->itemName == item) {
        ItemNode* temp = head;
        head = head->next;
        delete temp;
        return true;
    }

    // Search the rest of the list                                                                                                                                                                              
    ItemNode* prev = head;
    ItemNode* curr = head->next;

    while (curr != nullptr) {
        if (curr->itemName == item) {
            prev->next = curr->next;
            delete curr;
            return true;
        }
        prev = curr;
        curr = curr->next;
    }

    return false; // item not found                                                                                                                                                                             
}

// Print all items in the inventory                                                                                                                                                                             
void printInventory(ItemNode* head) {
    if (head == nullptr) {
        cout << "Inventory is empty.\n";
        return;
    }

    cout << "You are carrying:\n";

    ItemNode* curr = head;
    while (curr != nullptr) {
        cout << " - " << curr->itemName << "\n";
        curr = curr->next;
    }
}

// Delete the entire list                                                                                                                                                                                       
void deleteInventory(ItemNode*& head) {
    while (head != nullptr) {
        ItemNode* temp = head;
        head = head->next;
        delete temp;
    }
}

#endif

