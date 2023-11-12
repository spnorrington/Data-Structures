// This Program demonstrates a basic implementation of a binary search tree Class in C++
//
// Code from textbook, but modified to accept smart pointers
// Reference: "Data Structures and Algorithm Analysis in C++, Fourth Edition, Mark Allen Weiss" Codes

#pragma once

#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
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
    BinarySearchTree(const BinarySearchTree& rhs) : root{ nullptr }
    {
		root = clone(rhs.root);
	}

    //Move constructor
    BinarySearchTree(BinarySearchTree&& rhs) : root{ rhs.root }
    {
		rhs.root = nullptr;
	}

	//Destructor for the tree
    ~BinarySearchTree()
    {
		makeEmpty(root);
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
            throw; //UnderflowException{ };
        return findMin(root)->value;
    }

    //Find the largest item in the BinarySearchTree. Throw UnderflowException if empty.
    const V& findMax() const
    {
        if (isEmpty())
            throw; //UnderflowException{ };
        return findMax(root)->value;
    }

    // Returns true if x is found in the tree
    bool isLeaf(const V& x) const
    {
        return isLeaf(x, root);
    }

    bool isEmpty() const
    {
        return root == nullptr;
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
    void insert(V&& x)
    {
        insert(move(x), root);
    }

    //remove x from the tree if it is found
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

        Node(V, v, shared_ptr<Node> l, shared_ptr<Node> r) : value(v), left(l), right(r) {}
        // shared_ptr is being used for memory management. Insures that the memory is freed when no longer needed 
    };

    //The use of the private explicit constructor is a trick to encapsulate the details about the root within the tree class
    explicit BinarySearchTree(shared_ptr<Node>& node) : root(node) {}
    shared_ptr<Node> root;


    // Internal Method to insert into a substree; x is val to insert. t is the node that roots the subtree.
    // Set the new root of the subtree

    //RVALUE:which is an object that persists beyong a single expression (address can be determined/assigned)
    void insert(const V& x, shared_ptr<Node>& node)
    {
		if (!node)
			node = make_shared<Node>(x, nullptr, nullptr);
		else if (x < node->value)
			insert(x, node->left);
		else if (node->value < x)
			insert(x, node->right);
        else
            return 

	}

    // Internal method to insert into a subtree; x is val to insert. t is the node that roots the subtree.
    // LVALUE: accept temporary values or values that the caller has explicitly moved.
    void insert(V&& x, shared_ptr<Node>& node)
    {
		if (!node)
			node = make_shared<Node>(move(x), nullptr, nullptr);
		else if (x < node->value)
			insert(move(x), node->left);
		else if (node->value < x)
			insert(move(x), node->right);
		else
			; // Duplicate; do nothing
	}   

    void remove(const V& x, shared_ptr<Node>& node)
    {
        if (!node)
			return; // Item not found; do nothing
        if (x < node->value)
            remove(x, node->left);
		else if (node->value < x)
            remove(x, node->right);
        else if (node->left && node->right) // Two children
        {
			node->value = findMin(node->right)->value;
			remove(node->value, node->right);
		}
        else
        {
			node = (node->left) ? node->left : node->right;
		}


    }
    // Internal method to find the smallest item in a subtree t.
    // Return node containing the smallest item.
    shared_ptr<Node> findMin(const shared_ptr<Node>& t) const 
    {
        if (!t)
            return nullptr;
        if (!t->left)
            return t;
        return findMin(t->left);
    }

    // Internal method to find the largest item in a subtree t.
    // Return node containing the largest item.
    shared_ptr<Node> findMax(const shared_ptr<Node>& t) const 
    {
        if (t)
            while (t->right)
                t = t->right;
        return t;
    }
    // x is item to search for.
    // t is the node that roots the subtree.


    bool isLeaf(const shared_ptr<Node>& t) const
    {
        if (t == nullptr)
			return false;
        else if (x < t->value)
			return isLeaf(x, t->left);
		else if (t->value < x)
			return isLeaf(x, t->right);
		else
			return true; // Match
	}
    void makeEmpty(shared_ptr<Node>& t)
    {
        if (t != nullptr)
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            t = nullptr;
        }
    }

    void printTree(const shared_ptr<Node>& t, ostream& out) const
    {
        if (t != nullptr)
        {
			printTree(t->left, out);
			out << t->value << endl;
			printTree(t->right, out);
		}
	}

    // Internal method to clone subtree.
    shared_ptr<Node> clone(const shared_ptr<Node>& t) const
    {
		if (t == nullptr)
			return nullptr;
		else
			return make_shared<Node>(t->value, clone(t->left), clone(t->right));
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
