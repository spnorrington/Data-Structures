#pragma once
// Assignment 3 - Part 1
// Purpose of this code is to use the linked list class created in part 1 to create a second version of the Bag class, replacing vector class with your list class
//

template <typename T>
class List
{
private:
    class Node //nested class representing individual nodes in the list
    {
    public:
        T data;
        Node* prev;     //pointer to the previous node in the list
        Node* next;	    //pointer to the next node in the list 
        bool isHiddenNode = false;
    };
    Node* head;  //pointer to the first node(head) in the list
    Node* tail;     //pointer to the last node(tail) in the list

    void deleteListContents();      //frees memory by iterating                                     through the list and deleting each node

    void setupList();			   //sets up the list by creating a new node and setting head and tail to point to it

public:
    List();                             //default constructor
    List(T newData);					//constructor creates new linked list with one element (newData)

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

    void traverse(void (*doIt)(T data));        //iterates through the list and calls the function doIt on each node's data
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
    head = newNode;
}

template <typename T>
void List<T>::push_back(T data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode;
}

template <typename T>
void List<T>::pop_back()
{
    if (tail != nullptr)
    {
        Node* lastNode = tail;
        tail = tail->prev;
        if (tail != nullptr)
        {
            tail->next = nullptr;
        }
        delete lastNode;
    }
}

template <typename T>
void List<T>::pop_front()
{
    if (head != nullptr)
    {
        Node* firstNode = head;
        head = head->next;
        if (head != nullptr)
        {
            head->prev = nullptr;
        }
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
    setupList();
    Node* currentRHS = rhs.head;
    Node* current = head;
    while (currentRHS != nullptr)
    {
        current->data = currentRHS->data;
        if (currentRHS->next != nullptr)
        {
            current->next = new Node();
            current->next->prev = current;
            current = current->next;
        }
        else
        {
            tail = current;
        }
        currentRHS = currentRHS->next;
    }
}

template <typename T>
List<T>::~List()
{
    deleteListContents();
}
