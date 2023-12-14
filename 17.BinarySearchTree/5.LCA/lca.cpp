#include<iostream>
using namespace std;

// Problem || Leetcode : 235
/*
    -> Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

    -> According to the definition of LCA on Wikipedia: 
        - “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Solution
/*
    -> There will be 4 cases in BST for LCA:
        - Case 1 : Both are in left subtree
        - Case 2 : Both are in right subtree
        - Case 3 : 'p' is in left subtree and 'q' is in right subtree
        - Case 4 : 'p' is in right subtree and 'q' is in left subtree
    
    -> We are traversing from top - bottom.
    -> If we reach case 3 or 4, this means we've reached the common ancestor.
*/


TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == NULL)
    return NULL;
    
    int curr = root -> val;
    int pVal = p -> val;
    int qVal = q -> val;
    
    // Case 1 : Both are in left subtree
    if(pVal < curr && qVal < curr)
        return lowestCommonAncestor(root -> left, p, q);

    // Case 2 : Both are in right subtree
    else if(pVal > curr && qVal > curr)
        return lowestCommonAncestor(root -> right, p, q);
        
    // Case 3 & 4 : 
    return root;
}


int main(){


    return 0;
}