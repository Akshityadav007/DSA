#include<iostream>
#include<queue>
using namespace std;

/*
    -> Minimum value node in a BST will be at the left - most subtree.
    -> Maximum value node in a BST will be at the right - most subtree.

    # This is if we do in - order traversal.


    -> Searching in BST is similar to binary search.
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

Node *insertInBST(Node *root, int data){
    // if it is first node
    if(root == NULL){
        root = new Node(data);
        return root;
    }
    
    // if it is not first node
    if(data > root -> data){
        root -> right = insertInBST(root -> right, data); 
    }
    else{
        root -> left = insertInBST(root -> left, data);
    }

    return root;
}

void createBST(Node *&root){
    cout << "Enter data : " << endl;
    int data;
    cin >> data;

    while(data != -1){
        root = insertInBST(root, data);
        cout << "Enter data : " << endl;
        cin >> data;
    }
}


int minNode(Node *root){
    if(root == NULL)
        return -1;

    Node *temp = root;

    while(temp -> left != NULL)
        temp = temp -> left;
    
    return temp -> data;
}

int maxNode(Node *root){
    if(root == NULL)
        return -1;

    Node *temp = root;

    while(temp -> right != NULL)
        temp = temp -> right;
    
    return temp -> data;
}


// Problem || Leetcode : 700
bool searchBST(Node *root, int target){
    // base case
    if(root == NULL)
        return false;
    
    if(root -> data == target)
        return true;
    
    else if(root -> data > target)
        return searchBST(root -> left, target);
    
    else
        return searchBST(root -> right, target);
}




int main(){
    Node *root = NULL;
    createBST(root);

    cout << "Min : " << minNode(root) << endl;
    cout << "Max : " << maxNode(root) << endl;

    int t;
    cout << "Enter target :" << endl;
    cin >> t;
    while(t != -1){
        bool res =  searchBST(root, t);
        if(res)
            cout << "found!" << endl;
        else
            cout << "Not found!" << endl;

        cout << "Enter target :" << endl;
        cin >> t;
    }

    return 0;
}