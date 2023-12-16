#include<iostream>
using namespace std;

// Problem || GeeksforGeeks (hard)
/*
    -> Given a Binary Tree (BT), convert it to a Doubly Linked List(DLL) In-Place. 
    -> The left and right pointers in nodes are to be used as previous and next pointers respectively in converted DLL. 
    -> The order of nodes in DLL must be same as Inorder of the given Binary Tree. 
    -> The first node of Inorder traversal (leftmost node in BT) must be the head node of the DLL.
    -> Note: H is the height of the tree and this space is used implicitly for the recursion stack.
*/
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};


// Solution
/*
    # Method 1 : My Solution
        -> Simply do in order traversal and keep building LL.
    
    # Method 2 : (Love babbar ' s code)
        -> Instead of building from left and later getting confused to get head, we solve it from right.
        -> Do reverse in order traversal.

*/

// Methos 1 : My Solution
void createList(Node *&prev, Node *&head, Node *&curr, Node *root){
    if(root == NULL)
        return;
    
    // Left
    createList(prev, head, curr, root -> left);
    
    // root
    Node *newNode = new Node(root -> data);
    // first node
    if(head == NULL && prev == NULL){
        head = newNode;
        curr = newNode;
    }
    // other nodes
    else{
        curr -> right = newNode;
        prev = curr;
        curr = curr -> right;
        curr -> left = prev;
    }
    
    // Right
    createList(prev, head, curr, root -> right);
}

//Function to convert binary tree to doubly linked list and return it.
Node * bToDLL(Node *root)
{
    if(root == NULL)
        return root;
        
    Node *prev = NULL;
    Node *head = NULL;
    Node *curr = NULL; 
    
    createList(prev, head, curr, root);
    return head;
}



// Method 2
void createList(Node *&head,Node *root){
    if(root == NULL)
        return;
    
    // Right
    createList(head, root -> right);
    
    // root
    root -> right = head;
    if(head != NULL)
        head -> left = root;
    head = root;
        
    // Left
    createList(head, root -> left);
}
//Function to convert binary tree to doubly linked list and return it.

Node *bToDLL(Node *root)
{
    if(root == NULL)
        return root;
        
    Node *head = NULL;
    
    createList(head, root);
    return head;
}

int main(){

    return 0;
}