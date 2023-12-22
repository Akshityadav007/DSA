#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


// Problem || Leetcode : 99
/*
    -> You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. 
    -> Recover the tree without changing its structure.
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
    # Method 1 : Use vector [T.C. - O(nlogn), S.C. - O(n)]
        -> Get the inorder traversal of BST.
        -> sort the vector.

        -> place the values of vector in BST.

    # Method 2 : [T.C. - O(n)  , S.C. - O(n)]
        -> Two cases:
            1) Can be adjacent nodes.
            2) Can not be adjacent nodes.
        -> 4 pointers - previous node, current node, both nodes to be swapped (node1, node2).
        
        -> Get the nodes to be swapped using in order traversal.
        -> Swap them.
*/

// Method 1 : Brute force
void inorder(vector<int> &v, TreeNode *&root){
    // base case
    if(root == NULL)
        return;
    
    // left
    inorder(v, root -> left);

    // root
    v.push_back(root -> val);


    // right
    inorder(v, root -> right);
}

void placeValues(TreeNode *&root, vector<int> &v, int &index){
    // base case
    if(root == NULL)
        return;
    
    // left
    placeValues(root -> left, v, index);
    
    // root
    root -> val = v[index++];

    // right
    placeValues(root -> right, v, index);
}

void recoverTree(TreeNode* root) {
    // get inorder of the tree
    vector<int> v;
    inorder(v, root);


    sort(v.begin(), v.end());

    int index = 0;
    placeValues(root, v, index);
}


// Method 2 : 
void inorder(TreeNode *&prev, TreeNode *&curr, TreeNode *&node1, TreeNode *&node2){
    // base case
    if(curr == NULL)
        return;
    
    // left
    inorder(prev, curr -> left, node1, node2);

    // root
    if(prev != NULL && prev -> val > curr -> val){
        // get the nodes to be swapped
        if(node1 == NULL)
            node1 = prev;
        node2 = curr;                   // could be a non adjacent node, hence we keep looking for such nodes
    }

    // right
    prev = curr;
    inorder(prev, curr -> right, node1, node2);
}

void recoverTree(TreeNode* root) {
    // get inorder of the tree
    TreeNode *prev = NULL;
    TreeNode *curr = root;
    TreeNode *node1 = NULL;
    TreeNode *node2 = NULL;
    inorder(prev, curr, node1, node2);

    // swap
    swap(node1 -> val, node2 -> val);
}


int main(){

    return 0;
}