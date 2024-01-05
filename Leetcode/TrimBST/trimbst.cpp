#include<iostream>
using namespace std;

// Problem || Leetcode : 669
/*
    -> Given the root of a binary search tree and the lowest and highest boundaries as low and high, trim the tree so that all its elements lies in [low, high]. 
    -> Trimming the tree should not change the relative structure of the elements that will remain in the tree (i.e., any node's descendant should remain a descendant). 
    -> It can be proven that there is a unique answer.
    -> Return the root of the trimmed binary search tree. Note that the root may change depending on the given bounds.
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
    -> As we need unique structure of bst and preorder is the only DFS which gives it, we'll use it.
    -> Only return root which has value in range.
*/

TreeNode* trimBST(TreeNode* root, int low, int high) {
    // base case
    if(root == NULL)
        return NULL;
    
    // Preorder - gives unique structure for each tree
    // 1. root
    if(root -> val < low)
        return trimBST(root -> right, low, high);
    if(root -> val > high)
        return trimBST(root -> left, low, high);
    
    root -> left = trimBST(root -> left, low, high);            // 2. left
    root -> right = trimBST(root -> right, low, high);          // 3. right

    return root;
}

int main(){

    return 0;
}