#include<iostream>
#include<map>
using namespace std;

// Problem 
/*  
    -> Given pre-order and in-order traversal of tree.
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
    -> Create a mapping of inorder traversal of the tree along with index as key.

    Inorder  = Left - Root - Right
    Preorder = Root - Left - Right

    -> So, first element of preorder will definetly be a root.
    -> In Inorder , to the left of the root will be left sub tree and to the right of it will be right sub tree.

    -> Create a new node of that value of root.
    -> Next find the position of that element in inorder traversal from the mapping done earlier.

    -> Towards it's left will be left subtree of the current root.
    -> Towards it's right will be right subtree of the current root.
*/


// NOTE : pre Index is passed by reference
Node *construct(int inorder[], int preorder[], int &preIndex, int inStart, int inEnd, int size, map<int,int> m){
    // base case
    if(preIndex >= size || inStart > inEnd)
        return NULL;
    
    // solve 1 case
    int element = preorder[preIndex];
    preIndex++;
    Node *root = new Node(element); 
    // search this element in in order
    int position = m[element];                      // this search is optimized using map (index, element)

    
    // rest will be done by recursion
    root -> left = construct(inorder, preorder, preIndex, inStart, position - 1, size, m);
    root -> right = construct(inorder, preorder, preIndex, position + 1, inEnd, size, m);

    return root;
}

void createMapping(map<int, int> &m, int inorder[], int size){
    for(int i = 0;i < size; i++)
        m[inorder[i]] = i;
}



int main(){
    int inorder[] = {10,8,6,2,4,12};
    int preorder[] = {2,8,10,6,4,12};

    map <int, int> m;
    createMapping(m, inorder, 7);                         
    int preIndex = 6;                                                    // NOTE : pre Index is passed by reference
    Node *root = construct(inorder, preorder, preIndex, 0, 7, 7, m);

    return 0;
}