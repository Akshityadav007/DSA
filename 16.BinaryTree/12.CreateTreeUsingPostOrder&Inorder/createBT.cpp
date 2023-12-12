#include<iostream>
#include<map>
using namespace std;

// Problem 
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



// NOTE : post Index is passed by reference
Node *construct(int inorder[], int postorder[], int &postIndex, int inStart, int inEnd, int size, map<int, int> m){
    // base case
    if(postIndex >= size || inStart > inEnd)
        return NULL;
    
    // solve 1 case
    int element = postorder[postIndex];
    postIndex--;
    Node *root = new Node(element); 
    // search this element in in order
    int position = m[element];

    
    // rest will be done by recursion
    root -> right = construct(inorder, postorder, postIndex, position + 1, inEnd, size, m);             // right is done before left in post order
    root -> left = construct(inorder, postorder, postIndex, inStart, position - 1, size, m);

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
    int postIndex = 6;                          // NOTE : pre Index is passed by reference
    Node *root = construct(inorder, preorder, postIndex, 0, 7, 7, m);

    return 0;
}