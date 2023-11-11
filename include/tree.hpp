// This Program demonstrates a basic implementation of a binary tree in C++
// A Tree Class, referenced counted

#pragma once

#include <iostream>
#include <functional>
#include <memory> // for shared_ptr

using namespace std;


template<typename V>
class Tree 
{
private:
    struct Node 
    {
        Node(V v, shared_ptr<Node>& l, shared_ptr<Node>& r) :   // shared_ptr is being used for memory management
            value(v), left(l), right(r) {}
        V value;
        shared_ptr<Node> left;
        shared_ptr<Node> right;
    };
    explicit Tree(shared_ptr<Node>& node) : root(node) {}
    shared_ptr<Node> root;


public:
    Tree() {}
    Tree(Tree const& lft, V value, Tree const& rgt) :
        root(Node(value, lft.root, rgt.root)) {}

    bool isEmpty() const
    {
        return !root;
    }
    V root() const { return root->value; }
    Tree& left() const { return root->left; }
    Tree& right() const { return root->right; }

    bool member(V x) const
    {
        if (isEmpty())
            return false;
        V y = root();
        if (x < y)
            return left().member(x);
        else if (y < x)
            return right().member(x);
        else
            return true;
    }

    bool isLeaf() const; // Leaf is a node with no children
}
    {
        return !root || (!root->left && !root->right);





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
