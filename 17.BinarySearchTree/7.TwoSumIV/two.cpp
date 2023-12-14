#include<iostream>
#include<vector>
using namespace std;

// Problem || Leetcode : 653
/*
    -> Given the root of a binary search tree and an integer k.
    -> Return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// Solution
/*
    -> Same as two sum of array.
    -> There we needed to sort the array, here we already have BST which is sorted in inorder.
    -> Use two pointers.

    -> Get the inorder traversal and solve it like array.
*/

void getInorder(vector<int> &inorder, TreeNode *root){
    if(root == NULL)
        return;
    
    // Left
    getInorder(inorder, root -> left);

    // root
    inorder.push_back(root -> val);

    // right
    getInorder(inorder, root -> right);
}

bool findTarget(TreeNode* root, int k) {
    vector<int> inorder;
    getInorder(inorder, root);

    int start = 0, end = inorder.size() - 1;

    while(start <= end){
        int sum = inorder[start] + inorder[end];
        if(sum == k)
            return true;
        else if(sum < k)
            start++;
        else
            end--;
    }
    return false;
}


int main(){

    return 0;
}