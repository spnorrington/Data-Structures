// Implementation of a double linked list

#pragma once
#include <iostream>

template <typename T>
class List
{
private:
    class Node //nested class representing individual nodes in the list
    {
    public:
        T data;
        Node* prev;                 //pointer to the previous node in the list
        Node* next;	               //pointer to the next node in the list 
        bool isHiddenNode = false;
    };

    Node* head;  //pointer to the first node(head) in the list
    Node* tail;     //pointer to the last node(tail) in the list

    void deleteListContents();      //frees memory
    void setupList();			   //sets up the list


public:
    List() : head(nullptr), tail(nullptr) {}                       //default constructor
    List(T newData);					//constructor creates new linked list with one element                                   (newData)

    List(const List& rhs); // copy constructor
    ~List();                         // destructor      
    bool empty();				   // returns true if the list is empty 
    void push_front(T data);         // adds a new node with data at the front of the list
    void push_back(T data);         // adds a new node with data at the back of the list
    T front();                      // returns the data stored in the first node of the list
    T back();                       // returns the data stored in the last node of the list
    void pop_back();                 // removes the last node from the list
    void pop_front();               // removes the first node from the list
    void printTheList();

    void traverse(void (*doIt)(T data));        //iterates through the list and calls the                                               function doIt on each node's data
};

// Define member functions outside the class

template <typename T>
void List<T>::setupList()
{
    Node* newNode = new Node();
    newNode->next = nullptr;
    newNode->prev = nullptr;
    head = newNode;
    tail = newNode;
}

template <typename T>
void List<T>::deleteListContents()
{
    Node* current = head;
    Node* temp = nullptr;
    while (current != nullptr)
    {
        temp = current->next;
        delete current;
        current = temp;
    }
}

template <typename T>
void List<T>::push_front(T data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = head;
    newNode->prev = nullptr;
    if (empty()) 
    {
        head = newNode;
        tail = newNode;
    }
    else 
    {
        head->prev = newNode;
        head = newNode;
    }
}

template <typename T>
void List<T>::push_back(T data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = tail;
    tail->next = newNode;
    if (empty()) 
    {
        tail = newNode;
        head = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
}

template <typename T>
void List<T>::pop_back()
{
    if (!empty))
    {
        Node* lastNode = tail->prev;
        tail->prev = lastNode->prev;
        Node* newLastNode = tail->prev;
        newLastNode->next = tail;
        delete lastNode;
    }
}

template <typename T>
void List<T>::pop_front()
{
    if (!empty())
    {
        Node* firstNode = head->next;
        head->next = firstNode->next;
        Node* newFirstNode = head->next;
        newFirstNode->prev = head;
        delete firstNode;

    }
}

template <typename T>
void List<T>::printTheList()
{
    Node* current = head;
    while (current != nullptr)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

template <typename T>
void List<T>::traverse(void (*doIt)(T data))
{
    Node* current = head;
    while (current != nullptr)
    {
        doIt(current->data);
        current = current->next;
    }
}

template <typename T>
List<T>::List()
{
    setupList();
}

template <typename T>
List<T>::List(T newData)
{
    setupList();
    head->data = newData;
}

template <typename T>
List<T>::List(const List& rhs)
{
    if (this != &rhs) 
    {
        Node* current = rhs.head;
        while (current != nullptr) 
        {
            // Create and copy new nodes
            Node* newNode = new Node;
            newNode->data = current->data;
            if (head == nullptr)
            {
                head = newNode;
                tail = newNode;
            }
            else
            {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode; 
            }

            current = current->next; // Moves to next node and iterates over list
        }
    }
}

template <typename T>
List<T>::~List()
{
    deleteListContents();
}

template <typename T>
bool List<T>::empty()
{
    return head == nullptr;
}

template <typename T>
T List<T>::front()
{
    if (!empty())
    {
        return head->data;
    }
    throw std::runtime_error("List is empty.");
}

template <typename T>
T List<T>::back()
{
    if (!empty())
    {
        return tail->data;
    }
    throw std::runtime_error("List is empty.");
}

