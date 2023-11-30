#include<iostream>
using namespace std;

/*
    
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




int main(){

    Node *root = createTree();

    return 0;
}
