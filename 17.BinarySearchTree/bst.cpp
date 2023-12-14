#include<iostream>
#include<queue>
using namespace std;

/*
    -> BST is a tree which has,
        - Left subtree of a node will always have values less than right sub tree.
    -> A binary search tree (BST), also called an ordered or sorted binary tree.

    # R.S.T. > Node > L.S.T.
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


// print the tree
void levelOrderTraversal(Node *root){
    if(root == NULL)
        return;
    
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        int size = q.size();

        for(int i = 0;i < size; i++){
            Node *frontNode = q.front();
            cout << frontNode -> data << " ";
            q.pop();

            // insert the next nodes
            if(frontNode -> left != NULL)
                q.push(frontNode -> left);
            
            if(frontNode -> right != NULL)
                q.push(frontNode -> right);
        }
        cout << endl;
    }
}

int main(){
    Node *root = NULL;
    createBST(root);

    levelOrderTraversal(root);

    return 0;
}