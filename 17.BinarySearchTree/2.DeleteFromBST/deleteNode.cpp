#include<iostream>
#include<queue>
using namespace std;

/*
    -> 4 types of nodes can be deleted : 
      - Case 1: Leaf node (left & right are NULL)
      - Case 2: Node having left NULL and right non NULL
      - Case 3: Node having right NULL and left non NULL
      - Case 4: Node having both non NULL
            

    -> Case 1
        - Replace that node with NULL and free memory.

    -> Case 2
        - Replace that node with the node below it and free memory.

    -> Case 3
        - Replace that node with the node below it and free memory.

    -> Case 4 (most difficult)
        - Can be deleted using two ways :
            a) Get maximum element of left sub tree and replace it with the current node and free memory.
            b) Get minimum element of right sub tree and replace it with the current node and free memory.
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



Node *getMax(Node *root){
    if(root == NULL)
        return NULL;
    
    Node *temp = root;
    while(temp -> right != NULL)
        temp = temp -> right;
    
    return temp;
}

Node *deleteFromBST(Node *root , int target){
    // search the target
    // delete the target

    if(root == NULL){
        return NULL;
    }

    if(root -> data == target){
        // start deletion

        // case 1
        if(root -> left == NULL && root -> right == NULL){
            delete root;
            return NULL;
        }

        // case 2
        else if(root -> left == NULL && root -> right != NULL){
            Node *childSubtree = root -> right;
            delete root;
            return childSubtree;
        }

        // case 3
        else if(root -> left != NULL && root -> right == NULL){
            Node *childSubtree = root -> left;
            delete root;
            return childSubtree;
        }

        // case 4
        else{
            // get max of left subtree
            Node *leftMax = getMax(root -> left);

            // replace it with current node
            root -> data = leftMax -> data;

            // delete left max node
            root -> left = deleteFromBST(root -> left, leftMax -> data);
            return root;
        }
    }
    else if(root -> data > target){
        // go to left subtree
        root -> left = deleteFromBST(root -> left, target);
    }
    else{
        // go to right subtree
        root ->right = deleteFromBST(root -> right, target);
    }

    return root;
}

int main(){
    Node *root = NULL;
    createBST(root);

    return 0;
}