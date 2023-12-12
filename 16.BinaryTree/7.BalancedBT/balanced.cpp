#include<iostream>
using namespace std;

// Problem || Leetcode 110
/*
    -> Given a binary tree, determine if it is height-balanced.
    -> A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.
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
    # Method
        -> Get the height of both left and right subtrees.
        -> If we get difference > 1 , return false.
*/

int getHeight(TreeNode *&root){
    if(root == NULL)
        return 1;
    return 1 + max(getHeight(root -> left), getHeight(root -> right));
}

bool isBalanced(TreeNode* root) {
    if(root == NULL)
        return true;
    int hL = getHeight(root -> left);
    int hR = getHeight(root -> right);

    if(abs(hL - hR) > 1)
        return false;
    else
        return isBalanced(root -> left) && isBalanced(root -> right);
}


int main(){

    return 0;
}