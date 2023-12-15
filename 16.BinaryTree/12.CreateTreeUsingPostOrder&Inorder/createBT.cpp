#include<iostream>
#include<map>
using namespace std;

// Problem || Leetcode : 106 
/*  
    -> Given post-order and in-order traversal of tree.
    -> Create a tree using it.
*/

class Node{
    public:
        int data;
        Node *left;
        Node *right;

        // default constructor (made by me - babbar didn't make this, I don't know if this is needed)
        Node(){
            this -> data = 0;
            this -> left = NULL;
            this -> right = NULL;
        }

        // parameterized constructor
        Node(int val){
            this -> data = val;
            this -> left = NULL;
            this -> right = NULL;
        }

};


// Solution
/*
    -> Only difference here from pre order question will be:
        1) Traverse post order from back
        2) Give call for right subtree first for creation then left tree as post order has Left - Right - Root, as we are checking from back right will come first.
*/

// NOTE : post Index is passed by reference
Node *construct(int inorder[], int postorder[], int &postIndex, int start, int end, int size, map<int, int> m){
    // base case
    if(postIndex < 0 || start > end)
        return NULL;
    
    // solve 1 case
    int element = postorder[postIndex];
    postIndex--;
    Node *root = new Node(element); 
    int position = m[element];                                                                         // search this element in inorder

    
    // rest will be done by recursion
    root -> right = construct(inorder, postorder, postIndex, position + 1, end, size, m);             // right is done before left in post order
    root -> left = construct(inorder, postorder, postIndex, start, position - 1, size, m);

    return root;
}


void createMapping(map<int, int> &m, int inorder[], int size){
    for(int i = 0;i < size; i++)
        m[inorder[i]] = i;
}

int main(){
    int inorder[] = {10,8,6,2,4,12};
    int postorder[] = {2,8,10,6,4,12};

    map <int, int> m;
    createMapping(m, inorder, 7);
    int postIndex = 6;                                                                               // NOTE : post Index is passed by reference 
    Node *root = construct(inorder, postorder, postIndex, 0, 7, 7, m);

    return 0;
}