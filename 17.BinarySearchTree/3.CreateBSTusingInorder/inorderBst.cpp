#include<iostream>
using namespace std;

// Problem
/*
    -> Given in order traversal.
    -> Create BST using it.
*/

class Node{
    public:
        int data;
        Node *left;
        Node *right;

        Node(int val){
            this -> data = val;
            this -> left = NULL;
            this -> right = NULL;
        }
};


// Solution
/*
    -> Get mid of the traversal.
    -> Left of mid will be left subtree, right of mid will be right subtree.
*/

Node *bstFromInorder(int inorder[], int start, int end){
    // base case
    if(start > end)
        return NULL;
    
    // solve 1 case
    int mid = start + ((end - start) >> 1);
    int curr = inorder[mid];
    Node *root = new Node(curr);

    // recursive call
    root -> left = bstFromInorder(inorder, start, mid - 1);
    root -> right = bstFromInorder(inorder, mid + 1, end);

    return root;
}

int main(){
    int inorder[] = {10,20,30,40,50,60};
    int size = 6;
    int start = 0;
    int end = size - 1;
    
    Node *bst = bstFromInorder(inorder, start, end);

    return 0;
}