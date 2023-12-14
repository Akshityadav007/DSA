#include<iostream>
using namespace std;

// Problem || Leetcode : 98
/*
    -> Given the root of a binary tree, determine if it is a valid binary search tree (BST).
    -> A valid BST is defined as follows:
        - The left subtree of a node contains only nodes with keys less than the node's key.
        - The right subtree of a node contains only nodes with keys greater than the node's key.
        - Both the left and right subtrees must also be binary search trees.
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
    # Method 1 :
        -> Get max of left subtree, min of right subtree.
        -> Compare the value with root value.
            - Root value > leftMax and Root value < rightMin  : Valid BST case
        
    # Method 2 : Range based
        -> Left subtree should have values from (-infinity, root -> val).
        -> Right subtree should have values from (root -> val, infinity).

        -> If values lie in range then good, else invalid BST.
*/

bool solve(TreeNode* root, long long int lowerBound, long long int upperBound){
    // base case
    if(root == NULL)
        return true;
    
    // check current node
    bool cond1 = (root -> val > lowerBound);
    bool cond2 = (root -> val < upperBound);

    // check for left and right sub tree of current node
    bool leftSubtree = solve(root -> left, lowerBound, root -> val);
    bool rightSubtree = solve(root -> right, root -> val, upperBound);

    // check the results of current node and children trees
    if(cond1 && cond2 && leftSubtree &rightSubtree)
        return true;
    else
        return false;
}

bool isValidBST(TreeNode* root) {
    
    long long int lowerBound = -100000000000;           // random number lesser than INT_MIN
    long long int upperBound = 100000000000;            // random number greater than INT_MAX

    return solve(root, lowerBound, upperBound);
}



int main(){

    return 0;
}