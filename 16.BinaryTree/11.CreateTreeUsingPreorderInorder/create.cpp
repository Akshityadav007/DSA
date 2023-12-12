#include<iostream>
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


int searchInorder(int inorder[], int size, int target){
    for(int i = 0;i < size; i++){
        if(inorder[i] == target)
            return i;
    }
    return -1;
}


// NOTE : pre Index is passed by reference
Node *construct(int inorder[], int preorder[], int &preIndex, int inStart, int inEnd, int size){
    // base case
    if(preIndex >= size || inStart > inEnd)
        return NULL;
    
    // solve 1 case
    int element = preorder[preIndex];
    preIndex++;
    Node *root = new Node(element); 
    // search this element in in order
    int position = searchInorder(inorder, 7, element);                      // this search can be optimized using map (index, element)

    
    // rest will be done by recursion
    root -> left = construct(inorder, preorder, preIndex, inStart, position - 1, size);
    root -> right = construct(inorder, preorder, preIndex, position + 1, inEnd, size);

    return root;
}


int main(){
    int inorder[] = {10,8,6,2,4,12};
    int preorder[] = {2,8,10,6,4,12};

    int preIndex = 0;                          // NOTE : pre Index is passed by reference
    Node *root = construct(inorder, preorder, preIndex, 0, 7, 7);

    return 0;
}