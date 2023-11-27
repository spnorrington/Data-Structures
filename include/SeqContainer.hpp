
// Base Class for sequential (logical order) containers


#pragma once
template <typename T>
class SeqContainer 
{
protected:
    class Node 
    {
    public:
        T data;
        Node* prev;
        Node* next;
        bool isHiddenNode = false;
        Node() = default;
        Node(T d, Node* p, Node* n) : data(d), prev(p), next(n) {};
    };
    Node* head;
    Node* tail;

    void setupList() 
    {
        Node* newNode = new Node();
        newNode->next = tail;
        newNode->prev = head;
        head->next = newNode;
        tail->prev = newNode;
    }
    void deleteListContents() 
    {
        Node* current = head->next;
        Node* temp = nullptr;
        while (current != tail->prev) 
        {
            temp = current->next;
            delete current;
            current = temp;
        }
    }
public:


    class const_iterator 
    {
    protected:
        Node* current;
        T& retrieve() const { return current->data; }
        const_iterator(Node* p) : current(p) { }
        friend class SeqContainer<T>;

    public:
        const_iterator() : current(nullptr) { }

        T& operator*() const {
            return retrieve();
        }

        const_iterator& operator++() 
        {
            current = current->next;
            return *this;
        }

        const_iterator  operator++(int) 
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

public:
    class iterator : public const_iterator 
    {
    protected:
        iterator(Node* p) : const_iterator(p) { }
        friend class SeqContainer<T>;
    public:
        iterator() { }

        T& operator *() {
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
            ++(*this);
            return old;
        }
    };

    SeqContainer() 
    {
        head = new Node();
        head->isHiddenNode = true;
        tail = new Node();
        tail->isHiddenNode = true;
        head->prev = nullptr;
        head->next = tail;
        tail->prev = head;
        tail->next = nullptr;
    }

    SeqContainer(T newData) 
    {
        setupList();
        (head->next)->data = newData;
    }

    SeqContainer(SeqContainer& rhs) 
    {
        // copy constructor
        deleteListContents();
        head = rhs.head;
        tail = rhs.tail;
    }

    virtual ~SeqContainer() 
    {
        // And a destructor
        deleteListContents();
        delete head;
        delete tail;
    }
    // iterator related methods
    virtual iterator begin() { return { head->next }; }

    virtual iterator end() { return tail; }

    virtual const_iterator cbegin() const 
    {
        return { head->next };
    }

    virtual const_iterator cend() const
    {
        return { tail };
    }


    virtual iterator insert(iterator itr, const T& x) 
    {
        Node* p = itr.current;
        Node* newNode = new Node{ x, p->prev, p };
        p->prev = p->prev->next = newNode;
        return itr;
    }

    virtual iterator erase(iterator itr) 
    {
        Node* p = itr.current;
        iterator iterToReturn{ p->next };
        p->prev->next = p->next;
        p->next->prev = p->prev;
        return iterToReturn;
    }

    virtual iterator erase(iterator from, iterator to) 
    {
        iterator itr = from;
        while (itr != to) {
            itr = erase(itr);
        }
        return to;
    }
};


// *************** NOTES ************** 
// //Abstract class : A class that cannot be instantiated and has one
//or more pure virtual functions which serves only as a base class
//for derived classes.
//Interface : An interface has no implementation and contains
//only a virtual destructor and pure virtual functions.(AKA pure virtual functions)		
// 
// Must use type parameter T everywhere base class 
/*
EXAMPLE:


template <class T>
class Rectangle { ... };
template <class T>
class Square<T> : public Rectangle<T>
{
    ...
};

*/
/*
Base class: Class inherited from
Derived class: Inherits from the base class
*/