// Purpose of this code is to implement the List class studied in Mod 3 to my own Library
//

template <typename T>
class List 
{
private:
    class Node 
    {
    public:
        T data;
        Node* prev;
        Node* next;
        bool isHiddenNode = false;
    };
    Node* head;
    Node* tail;
    void deleteListContents();
    void setupList();
public:
    List();
    List(T newData);
    List(List& rhs); // copy constructor
    ~List();
    bool  empty();
    void push_front(T data);
    void push_back(T data);
    T front();
    T back();
    void pop_back() :
        void pop_front();
    void traverse(void (*doIt)(T data));
};


//Setting up the initial structure of a linked list
void setupList() 
{
    Node* newNode = new Node(); //serves as both head and tail of the list
    newNode->next = nullptr;
    newNode->prev = nullptr;
    head = newNode;
    tail = newNode;
}


//frees up memory used by the list
void deleteListContents() 
{
    Node* current = head;
    Node* temp = nullptr;
    while (current != nullptr) {
        temp = current.next;
        delete current;
        current = temp;
    }
}


void push_front(T data) 
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = head;
    newNode->prev = nullptr;
    head = newNode;
}

Void push_back(T data) 
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = tail;
    tail = newNode;
}

void pop_back() 
{
    Node *lastNode = tail;
    tail = tail.prev;
    tail.next = nullptr;
    delete lastNode;
}

void pop_front() 
{
    Node *firstNode = head;
    head = head.next;
    head.prev = nullptr;
    delete firstNode;
}

void printTheList() 
{
    Node* current = head;
    while (current != tail) {
        std::cout << current->data << " ";
    }
    std::cout << std::endl;
}
void traverse(void (*doIt)(T data)) 
{
    Node* current = head;
    while (current != tail) {
        doIt(current.data);
    }
}
List() // default constructor (This initializes a new linked list by calling setupList)
{
    setupList();
}
List(T newData) // this constructor creates a new linked list with one 
{                   /// element (newData) where that element typically the data type of elements stored in the list
    setupList();
    head->data = newData;
}


//revised copy constructor and destructor
List(List& rhs) { // copy constructor
 deleteListContents();
 head = rhs.head;
 tail = rhs.tail;
}
~List(){
 deleteListContents();
}
