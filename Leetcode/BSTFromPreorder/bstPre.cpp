#include<iostream>
#include<vector>
using namespace std;

// Problem || Leetcode : 1008
/*
    -> Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), construct the tree and return its root.
    -> It is guaranteed that there is always possible to find a binary search tree with the given requirements for the given test cases.
    -> A binary search tree is a binary tree where for every node, any descendant of Node.left has a value strictly less than Node.val, and any descendant of Node.right has a value strictly greater than Node.val.
    -> A preorder traversal of a binary tree displays the value of the node first, then traverses Node.left, then traverses Node.right.
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
        -> Sort the array - to get the inorder.
        -> Build tree using preorder and inorder.
    
    # Method 2 : Optimised
        -> First element of preorder (pre[0]), will be the root.
        -> Leftmost and rightmost element of the tree is the smallest and highest value of the preorder array respectively.
        -> Numbers smaller than pre[0] will be the left subtree of the tree and numbers greater than pre[0] will be to the right subtree of the tree.
        -> Same will be repeated for the next element too.
        -> One case is solved, rest will be solved by recursion.

        -> Base case : 
                        - when the current element gets bigger than the lowest element till now or the current element gets higher than the highest element till now.
                        - of course if the index gets out of range.
    
*/

TreeNode *buildTree(vector<int> &pre, int low, int high, int &index){
    // base case
    if(index >= pre.size() || pre[index] < low || pre[index] > high)
        return NULL;

    TreeNode *newNode = new TreeNode(pre[index]);
    index++;
    newNode -> left = buildTree(pre, low, newNode -> val, index);              // lowest number to current number will be to the left
    newNode -> right = buildTree(pre, newNode -> val, high, index);            // current number to the highest number will be to the right

    return newNode;
}

TreeNode* bstFromPreorder(vector<int>& preorder) {
    // preorder is unique for every tree
    int index = 0;

    // get high - highest number in tree
    int high = INT_MIN, low = INT_MAX;
    for(int i = 0;i < preorder.size(); i++)
        if(preorder[i] > high)
            high = preorder[i];
            
    // get low - lowest number in the tree
    for(int i = 0;i < preorder.size(); i++)
        if(preorder[i] < low)
            low = preorder[i];
        

    TreeNode *root = buildTree(preorder, low, high, index);      

    return root;
}


int main(){

    return 0;
}