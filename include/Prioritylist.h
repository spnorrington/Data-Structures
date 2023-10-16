//A priority list changes the definition of a list so that items are arranged in some numerical priority order.   
// Build a new class that keeps an instance of your LIst class to store the list that keeps track of the priority value for each item (use a structure that is stored within the List instance). 
//     
// Modify the List class to include a insert method, that given a pointer to an insert point, inserts a new entry in a List right before the item pointed to by the pointer.    
// Use this new function on the List class to insert as the way to insert items into the priority list at the correct location.


#pragma once	


#include "list.h" // Include the list.h header file

// Structure for items with priority
template <typename T>      // template declaration (specifying PriorityItem struct is a class template)
struct PriorityItem 
{
    T data;                 // member variable templated with 'T', meaning it can hold data of any type T
    int priority;           // stores priority value associated with item

    PriorityItem(T newData, int newPriority) : data(newData), priority(newPriority) {} // Constructor taking two parameters t newData & int newPriority
};

// Step 2: PriorityList class 
template <typename T>
class PriorityList 
{
private:
    List<PriorityItem<T>> priorityList; // Use List with PriorityItem

public:
    // Method to insert items into the priority list based on their priority
    void insert(T data, int priority) 
    {
        PriorityItem<T> itemToInsert(data, priority);

        // Find the appropriate insert point based on priority
        typename List<PriorityItem<T>>::Node* insertPoint = priorityList.head;
        while (insertPoint && insertPoint->data.priority >= priority) 
        {
            insertPoint = insertPoint->next;
        }

        // Insert the item at the desired point
        priorityList.insert(itemToInsert, insertPoint);
    }


};
