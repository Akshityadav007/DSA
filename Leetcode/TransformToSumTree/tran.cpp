#include<iostream>
using namespace std;


// Problem || GeeksForGeeks
/*
    -> Given a Binary Tree of size N , where each node can have positive or negative values. 
    -> Convert this to a tree where each node contains the sum of the left and right sub trees of the original tree. 
    -> The values of leaf nodes are changed to 0.
*/
struct Node
{
    int data;
    Node* left, * right;
};



// Solution
/*
    -> We simply do it with recursion.
    -> At the leaf node we return the node value and replace them with 0.
    -> For other nodes we simply add and replace the node value with left and right subtree sum which we got, and return the sum with the value of node.
*/


int solve(Node *&root){
    // edge case
    if(root == NULL)
        return 0;
    // leaf node
    if(root -> left == NULL && root -> right == NULL){
        int num = root -> data;
        root -> data= 0;
        return num;
    }
    else{
        int sum = solve(root -> left) + solve(root -> right);
        int num = root -> data;
        root -> data = sum;
        return num + sum;
    }
}

void toSumTree(Node *node)
{
    // edge case
    if(node == NULL)
        return;
    
    solve(node);                // shouldn't modify root
}

int main(){

    return 0;
}