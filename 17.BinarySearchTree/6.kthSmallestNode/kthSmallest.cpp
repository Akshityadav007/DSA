#include<iostream>
using namespace std;

// Problem || Leetcode : 230
/*
    -> Given the root of a binary search tree, and an integer k.
    -> return the kth smallest value (1-indexed) of all the values of the nodes in the tree.
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// Solution
/*
    -> Use inorder traversal to find this.
    -> Inorder traversal gives us ascending order in BST, hence we'll use it.

    -> Get to the smallest node of BST, and start reducing k after returning from it in reverse order.
    -> The node at which k becomes 0, we have our answer.
*/

int kthSmallest(TreeNode* root, int k) {
    if(root == NULL)
        return -1;
    
    // Left 
    int leftAns = kthSmallest(root -> left, k);
    if(leftAns != -1)
        return leftAns;
    
    // root
    k--;
    if(k == 0)
        return root -> val;
    
    // right
    int rightAns = kthSmallest(root -> right, k);
    if(rightAns != -1)
        return rightAns;
}


int main(){

    return 0;
}