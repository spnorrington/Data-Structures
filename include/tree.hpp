// This Program demonstrates the use of a Tree using Smart Pointers

#pragma once




template<class V>
class Tree 
{
private:
    struct Node 
    {
        Node(V v, Node* l, Node* r) : value(v), left(l), right(r) {}
        V value;
        Node* left;
        Node* right;
    };
    explicit Tree(Node* node) : root(node) {}
    Node* root;
public:
    Tree() {}
    Tree(Tree* lft, V value, Tree rgt) :
        root(Node(val, lft->root, rgt.root)) {}
    bool isEmpty() const;
    V root() const;
    Tree* left() const;
    Tree* right() const;
    bool member(V x) const;
    bool isLeaf() const;
}


// Terminology //
// 
// Tree: A collection of nodes
// Subtree: Any node in a tree can be viewed as the root of a new smaller tree
// Node Depth : The number of steps to get from a node to the root of tree
// Tree Height : Maximum depth of any of the leaves of a tree
// Leaf : A node with no children
// Sibling : Nodes with the same parent
// Path : A sequence of nodes n1, n2, ..., nk such that ni is the parent of ni+1 for 1 <= i < k
