
// Programming Question 1
//
//#pragma once
//
//Write three functions that are not methods of the Tree class that provides information about a Tree(HINT : think traversal of a tree) :
//
//	A function that, for a reference to the root of a Tree passed as a reference parameter, returns an integer value is the number of nodes in the Tree.
//	Write a function that counts the number of internal(non - leaf) nodes of the Tree whose root is passed a reference argument to the function.
//	The external path length of a tree is the sum of length of each path from a leaf to the root of a tree.Write a recursive function to compute this value where your function will have two parameters : a reference to the root of a tree, and a reference to integer summation value.The body of your function should add 1 to the integer and then recursively call the function for both children


// Function to get the number of nodes in the Tree
int countNodes(const TreeNode* root) 
{
    if (root == nullptr) 
    {
        return 0;
    }

    return 1 + countNodes(root->left) + countNodes(root->right);
}


// Function to count internal (non-leaf) nodes of the Tree
int countInternalNodes(const TreeNode* root) 
{
    if (root == nullptr || (root->left == nullptr && root->right == nullptr)) 
    {
        return 0;
    }

    return 1 + countInternalNodes(root->left) + countInternalNodes(root->right);
}

// Function to count internal (non-leaf) nodes of the Tree
int countInternalNodes(const TreeNode* root) {
    if (root == nullptr || (root->left == nullptr && root->right == nullptr)) 
    {
        return 0;
    }

    return 1 + countInternalNodes(root->left) + countInternalNodes(root->right);
}
