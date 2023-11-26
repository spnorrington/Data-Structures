// This Program demonstrates a basic implementation of a binary search tree Class in C++
//
// Reference: "Data Structures and Algorithm Analysis in C++, Fourth Edition, Mark Allen Weiss" Codes

#pragma once

#include <iostream>
#include <vector>
#include <functional>
#include <memory> // for shared_ptr


using namespace std;


template<typename V>
class BinarySearchTree
{
public:
    BinarySearchTree() : root{ nullptr }
    {
	}

    //Copy constructor
    BinarySearchTree(const Tree& rhs) : root{ nullptr }
    {
		root = clone(rhs.root);
	}

    //Move constructor
    BinarySearchTree(BinarySearchTree&& rhs) : root{ rhs.root }
    {
		rhs.root = nullptr;
	}

	//Destructor for the tree
    ~Tree()
    {
		makeEmpty();
	}

	//Copy assignment
    BinarySearchTree& operator=(const BinarySearchTree& rhs)
    {
		BinarySearchTree copy = rhs;
		swap(*this, copy);
		return *this;
	}

	//Move assignment
    BinarySearchTree& operator=(BinarySearchTree&& rhs)
    {
		swap(root, rhs.root);
		return *this;
	}


    //Find the smallest item in the tree. Throw UnderflowException if empty.
    const V& findMin() const
    {
        if (isEmpty())
			throw UnderflowException{ };
        return findMin(root)->value;
    }

    //Find the largest item in the BinarySearchTree. Throw UnderflowException if empty.
    const V& findMax() const
    {
		if (isEmpty())
            throw UnderflowException{ };
        return findMax(root)->value;
    }

    // Returns true if x is found in the tree
    bool contains(const V& x) const
    {
        return contains(x, root);
    }


    // Print Contents of the tree in sorted order
    void printTree(ostream& out = cout) const
    {
		if (isEmpty())
			out << "Empty tree" << endl;
		else
			printTree(root, out);
	}

    // Empty contents
    void makeEmpty()
    {
        makeEmpty(root);
    }


    // Insert x into the tree; duplicates are ignored
    void insert(const V& x)
    {
		insert(x, root);
	}


    // Insert x into the tree; duplicates are ignored
    void remove(const V& x)
	{
        remove(x, root);
    }


private:
    struct Node
    {
        V value;
        shared_ptr<Node> left;
        shared_ptr<Node> right;

        //Constructor for Node, takes a value V and left/right shared_ptr<Node> reference

        Node(V, v, shared_ptr<Node>& l, shared_ptr<Node>& r) : value(v), left(l), right(r) {}
        // shared_ptr is being used for memory management. Insures that the memory is freed when no longer needed 
    };

    //The use of the private explicit constructor is a trick to encapsulate the details about the root within the tree class
    explicit BinarySearchTree(shared_ptr<Node>& node) : root(node) {}
    shared_ptr<Node> root;

    // Internal Method to insert into a substree; x is val to insert. t is the node that roots the subtree.
    // Set the new root of the subtree

    void insert(const V& x, shared_ptr<Node>& node)
    {
		if (!node)
			node = make_shared<Node>(x, nullptr, nullptr);
		else if (x < node->value)
			insert(x, node->left);
		else if (node->value < x)
			insert(x, node->right);
		else
			; // Duplicate; do nothing
	}

    // Internal method to insert into a subtree; x is val to insert. t is the node that roots the subtree.
    void insert(V&& x, shared_ptr<Node>& node)
    {
		if (!node)
			node = make_shared<Node>(std::move(x), nullptr, nullptr);
		else if (x < node->value)
			insert(std::move(x), node->left);
		else if (node->value < x)
			insert(std::move(x), node->right);
		else
			; // Duplicate; do nothing
	}   

public:
    BinarySearchTree() {}
    BinarySearchTree(BinarySearchTree const &lft, V value, BinarySearchTree const &rgt) :
        root(Node(value, lft->root, rgt->root )) {}

    bool isEmpty() const
    {
        return !root;
    }
    V root() const { return root->value; }
    BinarySearchTree &left() const { return root->left; }
    BinarySearchTree &right() const { return root->right; }

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

    bool isLeaf() const // Leaf is a node with no children
    {
        return !root || (!root->left && !root->right);
    }


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
