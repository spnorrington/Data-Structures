// Along with using the unit testing framework provided by instructor, I am including a main.cpp file to see how I can implement the PriorityList class and test it personally
//


#include <iostream>
#include "Prioritylist.h" // Include the prioritylist.h header file

int main() {
    // Create a PriorityList for int data
    PriorityList<int> priorityList;

    char choice;
    do {
        int data, priority;
        std::cout << "Enter data: ";
        std::cin >> data;
        std::cout << "Enter priority: ";
        std::cin >> priority;

        priorityList.insert(data, priority);

        std::cout << "Add another item? (y/n): ";
        std::cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    // Print the priority list
    std::cout << "Priority List:\n";
    List<PriorityItem<int>>::Node* current = priorityList.priorityList.head;
    while (current != nullptr) {
        std::cout << "Data: " << current->data.data << ", Priority: " << current->data.priority << std::endl;
        current = current->next;
    }

    return 0;
}