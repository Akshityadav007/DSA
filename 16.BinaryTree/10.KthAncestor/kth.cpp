#include<iostream>
#include<vector>
using namespace std;

// Problem || GFG
/*
    -> Given a binary tree of size  N, a node, and a positive integer k., Your task is to complete the function kthAncestor(), the function should return the kth ancestor of the given node in the binary tree. If there does not exist any such ancestor then return -1.
    -> Note:
        1. It is guaranteed that the node exists in the tree.
        2. All the nodes of the tree have distinct values.
*/
struct Node
{
	int data;
	struct Node *left, *right;
};

// Solution
/*

*/
Node *solve(Node *&root, int &ans, int &k, int node){
    // base case
    if(root == NULL || root -> data == node)
        return root;
    
    Node *leftAns = solve(root -> left, ans, k, node);
    Node *rightAns = solve(root -> right, ans, k, node);
    
    // we have got the node till now
    if(leftAns == NULL && rightAns == NULL)
        return NULL;
    
    k--;
    if(k == 0)
        ans = root -> data;
    
    if(leftAns != NULL && right == NULL)
        return leftAns;
    else if(rightAns != NULL && left == NULL)
        return rightAns;
    else
        return root;
}
int kthAncestor(Node *root, int k, int node)
{
    int ans = -1;
    solve(root, ans, k, node);
    return ans;
}

int main(){


    return 0;
}