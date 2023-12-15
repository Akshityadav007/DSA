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

int solve(TreeNode *&root, int &k){
    // base case
    if(root == NULL)
        return -1;

    // Left                                         -- First get to the leftmost element i.e. smallest element of BST
    int leftAns = solve(root -> left, k);
    if(leftAns != -1)
        return leftAns;                             // check if we got the answer
    
    // Root
    k--;                                            // start reducing the value of k after reaching smallest element
    if(k == 0)                                      // once k is 0 we have our answer
        return root -> val;
    
    
    // Right                                        -- If not found in left subtree, move towards right subtree
    int rightAns = solve(root -> right, k);
    if(rightAns != -1)
        return rightAns;                            // check if we got the answer
    
    return -1;
}

int kthSmallest(TreeNode* root, int k) {
    return solve(root, k);
}


int main(){

    return 0;
}