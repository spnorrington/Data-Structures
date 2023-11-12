// Modified version of the list test file 
// Purpose is to test the implementation of BinarySearchTree class




#include <iostream>
#include "BinarySearchTree.hpp"

void printItem(const int& item) 
{
    std::cout << item << " ";
}

int main() {
    BinarySearchTree<int> bst;

    // Insert some elements into the binary search tree
    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.insert(2);
    bst.insert(4);
    bst.insert(6);
    bst.insert(8);

    // Print the tree in sorted order
    std::cout << "Binary Search Tree: ";
    bst.printTree();
    std::cout << std::endl;

    // Test findMin and findMax
    std::cout << "Min: " << bst.findMin() << std::endl;
    std::cout << "Max: " << bst.findMax() << std::endl;

    // Test contains
    int valueToFind = 4;
    std::cout << "Contains " << valueToFind << "? " << (bst.isLeaf(valueToFind) ? "Yes" : "No") << std::endl;

    // Test remove
    int valueToRemove = 5;
    std::cout << "Removing " << valueToRemove << std::endl;
    bst.remove(valueToRemove);

    // Print the updated tree
    std::cout << "Binary Search Tree after removal: ";
    bst.printTree();
    std::cout << std::endl;

    return 0;
}
