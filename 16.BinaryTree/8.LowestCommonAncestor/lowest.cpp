#include<iostream>
using namespace std;

// Probelm || Leetcode : 236
// V. V. Important
/*
    -> Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

    -> According to the definition of LCA on Wikipedia: 
        “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that 
        has both p and q as descendants (where we allow a node to be a descendant of itself).”
*/
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

// Solution
/*
    -> LCA will be the position where we meet first time while traversing from both nodes in bottom up approach.

    -> While solving there will be some cases:
        1. 'p' is in left node and 'q' is in right node.
        2. 'p' is in right node and 'q' is in left node.
        3. 'p' and 'q' are both in either sides of the nodes.
            - a) 'p' comes before 'q'
            - b) 'q' comes before 'p'
        
    
*/

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == NULL || root == p || root == q)
        return root;
    
    TreeNode *lAns = lowestCommonAncestor(root -> left, p, q);
    TreeNode *rAns = lowestCommonAncestor(root -> right, p, q);

    // Case 1: 'p' and 'q' are on different nodes
    if(lAns == NULL && rAns == NULL)
        return NULL;

    // Case 2: 'p' and 'q' are on either of the nodes
    else if(lAns != NULL && rAns == NULL)
        return lAns;
    else if(lAns == NULL && rAns != NULL)
        return rAns;

    // Case 3: we are on the answer, i.e. both are non null
    else
        return root;
}

int main(){

    return 0;
}