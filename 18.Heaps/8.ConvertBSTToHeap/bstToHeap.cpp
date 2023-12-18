#include<iostream>
#include<vector>
using namespace std;


// Problem
/*
    -> Given a tree which is CBT + BST.
    -> Convert it to heap.
*/

class Node{
    public:
        int data;
        Node *left;
        Node *right;
};

// Solution
/*
    -> Heap is a CBT having heap property.
    -> Given tree is already a CBT.
    -> So, we need to change the structure, only values should be changed.

    -> To change values we need to traverse tree, for traversal we have DFS(preorder, inorder, postorder), or BFS.
        -> Using preorder and inorder, we won't get the max heap property.
        -> Using postorder and level order, we can get max heap property.
    -> First we need to store it in an array (in sorted order).
*/

void getInorder(Node *root, vector<int> &inorder){
    if(root == NULL)
        return;

    // left -> root -> right
    getInorder(root -> left, inorder);
    inorder.push_back(root -> data);
    getInorder(root -> right, inorder);
}

void replaceUsingPostorder(Node *root, vector<int> in, int &index){
    if(root == NULL)
        return;
    
    // Left -> Right -> Root
    replaceUsingPostorder(root -> left, in, index);
    replaceUsingPostorder(root -> right, in, index);
    root -> data = in[index];
    index++;
}

Node *convertBSTtoHeap(Node *root){
    // store inorder
    vector<int> inorder;
    getInorder(root, inorder);

    // replace the node values with the sorted inorder values, using postorder traversal
    int index = 0;
    replaceUsingPostorder(root, inorder, index);

    return root;
}


int main(){

    return 0;
}