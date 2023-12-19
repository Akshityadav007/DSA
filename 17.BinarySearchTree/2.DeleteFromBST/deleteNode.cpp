#include<iostream>
#include<queue>
using namespace std;


// Problem || Leetcode : 450
/*
    -> Given a root node reference of a BST and a key, delete the node with the given key in the BST. 
    -> Return the root node reference (possibly updated) of the BST.
    -> Basically, the deletion can be divided into two stages:
        - Search for a node to remove.
        - If the node is found, delete the node.
*/
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };


// Solution
/*
    # Method 1 : Love babbar's code
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

    # Method 2 : Lakshay 's code
        -> Most of the methodology is same as method 1, only the way to delete the node is different.
        -> We need to delete node.
        -> Can do either by using maximum of left subtree or minimum of right sub tree.

        ->  1) Maximum of left subtree
                - Attach maximum of left subtree 's right to the right of node
                - Delete node.

        ->  2) Minimum of right subtree
                - Attack the left subtree to the left of minimum of right subtree.
                - Delete node. 
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

// Method : 1
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



// Method 2 : (minimum of right subtree)
TreeNode* deleteNode(TreeNode* root, int key) {
        // base case
        if(root == NULL)
            return NULL;
        
        // node found
        if(root -> val == key){
            // case 1 : leaf node
            if(root -> left == NULL && root -> right == NULL){
                delete root;
                return NULL;
            }
            // case 2 : 
            else if(root -> left == NULL && root -> right != NULL){
                TreeNode *temp = root;
                root = root -> right;
                delete temp;
                return root;
            }
            // case 3 :
            else if(root -> left != NULL && root -> right == NULL){
                TreeNode *temp = root;
                root = root -> left;
                delete temp;
                return root;
            }
            // case 4 : node with both children non null
            else{
                // get the minimum node of right subtree
                TreeNode *minNode = root -> right;
                while(minNode -> left != NULL)
                    minNode = minNode -> left;
                
                // attach the left subtree to the left of minNode of right subtree
                minNode -> left = root -> left;

                TreeNode *temp = root;
                root = root -> right;
                delete temp;

                return root;
            }
        }
        else if(root -> val > key)
            root -> left = deleteNode(root -> left, key);
        else
            root -> right = deleteNode(root -> right, key);
        
        return root;
    }


// Method 2 : (maximum o left subtree)
TreeNode* deleteNode(TreeNode* root, int key) {
    // base case
    if(root == NULL)
        return NULL;
    
    // node found
    if(root -> val == key){
        // case 1 : leaf node
        if(root -> left == NULL && root -> right == NULL){
            delete root;
            return NULL;
        }
        // case 2 : 
        else if(root -> left == NULL && root -> right != NULL){
            TreeNode *temp = root;
            root = root -> right;
            delete temp;
            return root;
        }
        // case 3 :
        else if(root -> left != NULL && root -> right == NULL){
            TreeNode *temp = root;
            root = root -> left;
            delete temp;
            return root;
        }
        // case 4 : node with both children non null
        else{
            // get the maximum node of left subtree
            TreeNode *maxNode = root -> left;
            while(maxNode -> right != NULL)
                maxNode = maxNode -> right;

            maxNode -> right = root -> right;
            TreeNode *temp = root;
            root = root -> left;
            delete temp;

            return root;
        }
    }
    else if(root -> val > key)
        root -> left = deleteNode(root -> left, key);
    else
        root -> right = deleteNode(root -> right, key);
    
    return root;
}

int main(){
    Node *root = NULL;
    createBST(root);

    return 0;
}