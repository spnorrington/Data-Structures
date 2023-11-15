/*

C++ Template Class: List (Doubly-Linked List Implementation)

 Description: 
 The purpose of this code was to add iterators to the List class that behave like the iterator of the STL containers library. Containers implemented in this repository will use the same iterator interface.

 See more information regarding common interfaces of containers after the code below **
*/


#pragma once
#include <iostream>
#include <functional>


template <typename T>
class List
{
private:
    // new field to the Node nested class to indicate if the node is hidden
    class Node {
    public:
        T  data;
        Node* prev;
        Node* next;
        bool isHiddenNode = false;
    };
    Node* head;
    Node* tail;
     
    // Helper function 
    void deleteListContents() 
    {
        Node* temp = nullptr;
        Node* current = head;
        while (current != nullptr) 
        {
            temp = current->next;
            delete current;
            current = temp;
        }
    }

    //helper function
    void setupList() 
    {
        Node* newNode = new Node();
        newNode->next = nullptr;
        newNode->prev = nullptr;
        head = newNode;
        tail = newNode;
    }

    //
public:
    //
    // Nested iterator classes //
    // 
    // iterator: an object that represents a position within a
    // container, with both the iterator and the thing referenced being mutable
    // const_iterator : an object represents a position within a container, with the iterator being mutable and thing being referenced as being imutable
    class const_iterator 
    {
    protected:
        Node* current;
        T& retrieve() const { return current->data; }
        const_iterator(Node* p) : current(p) { }
        friend class List<T>;

    public:
        const_iterator() : current(nullptr) { }
        T& operator*() const 
        {
            return retrieve();
        }

        const_iterator& operator++() 
        {
            current = current->next;
            return *this;
        }

        const_iterator operator++(int) 
        {
            const_iterator old = *this;
            ++(*this);
            return old;
        }

        bool operator==(const const_iterator& rhs) const 
        {
            return current == rhs.current;
        }

        bool operator!=(const const_iterator& rhs) const 
        {
            return !(*this == rhs);
        }
    };

    class iterator : public const_iterator 
    {
    protected:
        iterator(Node* p) : const_iterator(p) { }
        friend class List<T>;

    public:
        iterator() { }
        T& operator *() 
        {
            return const_iterator::retrieve();
        }

        const T& operator* () const 
        {
            return const_iterator::operator*();
        }

        iterator& operator++ () 
        {
            this->current = const_iterator::current->next;
            return *this;
        }

        iterator operator++ (int)
        {
            iterator old = *this;
            **(*this);
            return old;
        }
    };

    // Default Constructor
    List() {
        head = new Node();
        head->isHiddenNode = true;
        tail = new Node();
        tail->isHiddenNode = true;
        head->prev = nullptr;
        head->next = tail;
        tail->prev = head;
        tail->next = nullptr;
    };

    // Constructor with one parameter
    List(T newData) 
    {
        setupList();
        head->data = newData;
    }

    
    // copy constructor
    List(List& rhs) 
    {
        deleteListContents();
        head = rhs.head;
        tail = rhs.tail;
    }

    // Destructor
    ~List()
    {
        deleteListContents();
    }

    bool  empty() 
    {
        return (head->next == tail);
    }

    void push_front(T data)
    {
        if (this->empty())
        {
            setupList();
            Node* actualHead = head->next;
            actualHead->data = data;
        }
        else
        {
            Node* actualHead = head->next;
            Node* newNode = new Node();
            newNode->data = data;
            newNode->next = actualHead;
            actualHead->prev = newNode;
            newNode->prev = head;
            head->next = newNode;
        }

    }

    void push_back(T data) 
    {
        if (this->empty())
        {
            setupList();
            Node* actualTail = tail->prev;
            actualTail->data = data;
        }
        else
        {
            Node* actualTail = tail->prev;
            Node* newNode = new Node();
            newNode->data = data;
            newNode->prev = actualTail;
            actualTail->next = newNode;
            newNode->next = tail;
            tail->prev = newNode;
        }

    }


    T& front()
    {
        Node *actualHead = head->next;
        return (actualHead->data);
    }
    T back()
    {
        Node *actualTail = tail->prev;
        return (actualTail->data);
    }


    // Move constructor 
    List(List&& rhs) 
    {
        Node* current = head;
        Node* temp = nullptr;
        while (current != nullptr) 
        {
            temp = current->next;
            delete current;
            current = temp;
        }
        head = rhs.head;
        tail = rhs.tail;
    }

    // Delete List Contents
    void deleteListContents() 
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


    iterator begin() { return { head->next }; }
    iterator end() { return tail; }

    const_iterator cbegin() const { return { head->next }; }
    const_iterator cend() const { return { tail }; }

    // Removes last node in list
    void pop_back() {
        Node* lastNode = tail->prev;
        tail->prev = lastNode->prev;
        Node* newLastNode = tail->prev;
        newLastNode->next = tail;
        delete lastNode;
        lastNode = nullptr;

    }

    // Remove the first node in list
    void pop_front()
    {
        Node* firstNode = head->next;
        head->next = firstNode.next;
        Node* newFirstNode = head.next;
        newFirstNode->prev = head;
        delete firstNode;
        firstNode = nullptr;
    }

    // Print data
    void printTheList() 
    {
        Node* current = head;
        while (current != tail) 
        {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // apply a function to each node's data of the list
    void traverse(std::function<void(T& data)> doIt)
    {
        Node* current = head->next;
        while (current != tail)
        {
            doIt(current->data);
            current = current->next;
        }
    }
};


// Containers: Common Interface
// ----------------------------
// The container classes support a common interface, including the following operations:

// Constructors and Destructors:
// - Default and copy constructors
// - Destructor
// - Assignment operators

// Size and Capacity Methods:
// - size(): Returns the current size of the container.
// - max_size(): Returns the maximum possible size of the container.
// - empty(): Returns a boolean indicating whether the container is empty.
// - swap(): Swaps the contents of two containers.
// - clear(): Removes all elements from the container.

// Comparison Operators:
// - Lexicographic comparison operators, comparing container contents.
// - Returns booleans indicating the result of the comparison.

// This common interface ensures consistency and a standard set of behaviors
// across different container classes, facilitating their use in generic scenarios.
