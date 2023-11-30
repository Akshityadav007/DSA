#include<iostream>
using namespace std;

/*
    -> There are 3 types of traversals in BT:
        1) Pre - order = root -> Left -> Right
        2) In - order = Left -> root -> right
        3) Post - order = Left -> Right -> root

    -> S.C. = O(n)
    -> To counter this S.C., we have Morris - traversal where we use loops.
*/

class Node{
    public:
        int data;
        Node *left;
        Node *right;

        // parameterized constructor
        Node(int val){
            this -> data = val;
            this -> left = NULL;
            this -> right = NULL;
        }

};

Node *createTree(){
    cout << "Enter the value of node: " << endl;
    int data;
    cin >> data;

    // if we don't want to make tree further, we assume input to be -1 (base case)
    if(data == -1)
        return NULL;

    // Step 1: create node
    Node *root = new Node(data);

    // Step 2 : create left subtree
    root -> left = createTree();             // recursive call

    // Step 3 : create right subtree
    root -> right = createTree();            // recursive call

    return root;
}


// 1) Pre order
void preOrder(Node *root){
    if(root == NULL)
        return;
    
    cout << root -> data << " ";        // root
    preOrder(root -> left);             // left
    preOrder(root -> right);            // right
}

// 2) In order
void inOrder(Node *root){
    if(root == NULL)
        return;
    
    preOrder(root -> left);             // left
    cout << root -> data << " ";        // root
    preOrder(root -> right);            // right
}

// 3) Post order
void postOrder(Node *root){
    if(root == NULL)
        return;
    
    preOrder(root -> left);             // left
    preOrder(root -> right);            // right
    cout << root -> data << " ";        // root
}



int main(){

    Node *root = createTree();

    preOrder(root);
    cout << endl;
    inOrder(root);
    cout << endl;
    postOrder(root);
    cout << endl;

    return 0;
}

/*
    -> Generic tree/ N - arry - Trees having 'n' children.
    -> For generic trees, make an array of children in the definition of Node class, instead of left/right.

*/