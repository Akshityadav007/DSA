#include<iostream>
using namespace std;


// Problem || Leetcode : 543
/*
    -> Given the root of a binary tree, return the length of the diameter of the tree.
    -> The diameter of a binary tree is the length of the longest path between any two nodes in a tree. 
    -> This path may or may not pass through the root.
    -> The length of a path between two nodes is represented by the number of edges between them.
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// Solution
/*  
    # Method 1 : Brute force
    -> Case 1 : Both nodes lie in left sub tree
    -> Case 2 : Both nodes lie in right sub tree
    -> Case 3 : Both nodes lie in either sub trees
    -> We got 3 answers, we'll return maximum of three

    # Method 2 : 
*/

int height(TreeNode* root) {
    if(root == NULL)
        return 0;
        
    int leftHeight = height(root -> left);
    int rightHeight = height(root -> right);
    int height = 1 + max(leftHeight, rightHeight);

    return height;
}


// Method 1
int diameterOfBinaryTree(TreeNode* root) {
    // base case
    if(root == NULL)
        return 0;
    
    int option1 = diameterOfBinaryTree(root -> left);               // case 1
    int option2 = diameterOfBinaryTree(root -> right);              // case 2
    int option3 = height(root -> left) + height(root -> right);     // case 3

    return max(option1, max(option2, option3));
}

int main(){



    return 0;
}
