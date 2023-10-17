


#pragma once
#include "List.h"
template <typename T>
class CircularList : public List<T>
{
private:
    typename CircularList<T>::iterator findInList(T data)
    {
        //
        typename CircularList<T>::iterator placeInList = this->begin();
        typename CircularList<T>::iterator endOfList = this->end();
        bool found = false;
        while (!found && placeInList != endOfList)
        {
            if (*placeInList == data)
            {
                found = true;
            }
            placeInList++;
        }
        return placeInList;
    }
public:
    CircularList() : List<T>()
    {

        // Structure of a circular linked list: tail of the list points at the head and the head points at the tail.

        this->tail->next = this->head;   //connecting tail to head
        this->head->prev = this->tail;   //connecting head to tail  
    }


    // Member function to add element to front of list
    void push_front(T data)
    {
        if (this->empty())
        {
            // If list is empty data is assigned to single node with ptrs both set to head of list
            this->setupList();
            this->head->next->data = data;
        }
        else
        {
            // new node is added to the back of the list
            // the pointers to connect it to the existing tail and the previous tail.
            Node* actualHead = this->head->next;
            Node* newNode = new Node();
            newNode->data = data;
            newNode->next = actualHead;
            actualHead->prev = newNode;
            newNode->prev = this->head;
            this->head->next = newNode;

            // maintain circularity after insertion
            this->tail->next = this->head;
            this->head->prev = this->tail; 
        }
    }

    // Member function that updates the pointers of new node, head/tail, and nodes to circularlist structure 
    void push_back(T data)
    {
        if (this->empty())
        {
            this->setupList();
            this->tail->prev->data = data;
        }
        else
        {
            Node* actualTail = this->tail->prev;
            Node* newNode = new Node();
            newNode->data = data;
            newNode->prev = actualTail;
            actualTail->next = newNode;
            newNode->next = this->tail;
            this->tail->prev = newNode;

            // updating head prev to point to new tail
            this->head->next->prev = this->tail;

            // Setting tail next to point to head, completeing the circle
            this->tail->next = this->head->next;  
        }
    }
    //traverses the list using erase and push_back to move the node to the back of the list
    typename CircularList<T>::iterator findIt(T data)
    {
        typename CircularList<T>::iterator whereFound = findInList(data);
        if (whereFound != this->end())
        {
            T& temp = *whereFound;
            this->erase(whereFound);
            this->push_front(temp)
        }
        return whereFound;
    }
};
