#include<iostream>
#include<vector>
using namespace std;

// Problem || GFG
/*
    -> Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 

        - Left boundary nodes: defined as the path from the root to the left-most node ie- the leaf node you could reach when you always travel preferring the left subtree over the right subtree. 
        - Leaf nodes: All the leaf nodes except for the ones that are part of left or right boundary.
        - Reverse right boundary nodes: defined as the path from the right-most node to the root. 
        - The right-most node is the leaf node you could reach when you always travel preferring the right subtree over the left subtree. 
        - Exclude the root from this as it was already included in the traversal of left boundary nodes.
        - Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary. 
    
*/
struct Node
{
    int data;
    Node* left, * right;
}; 

// Solution
/*
    -> Break this into 3 parts to print:
        Part A : Left side (till leaf node)
        Part B : Leaf nodes
        Part C : Right side (till leaf node)    - To be printed in reverse order
    

*/

  
void leftSide(Node *&root, vector<int> &ans){
    if(root == NULL)
        return;

    // leaf node
    if(root -> left == NULL && root -> right == NULL)
        return;

    ans.push_back(root -> data);

    if(root -> left != NULL)
        leftSide(root -> left, ans);
    else
        leftSide(root -> right, ans);
}

void leaf(Node *&root, vector<int> &ans){
    if(root == NULL)
        return;
    
    // leaf node
    if(root -> left == NULL && root -> right == NULL)
        ans.push_back(root -> data);
        
    leaf(root -> left, ans);
    leaf(root -> right, ans);
}

void rightSide(Node *&root, vector<int> &ans){
    if(root == NULL)
        return;
    
    // leaf node
    if(root -> left == NULL && root -> right == NULL)
        return;
        
    if(root -> right != NULL)
        rightSide(root -> right, ans);
    else
        rightSide(root -> left, ans);
    
    ans.push_back(root -> data);
}

vector <int> boundary(Node *root)
{  
    vector<int> ans;

    if(root == NULL)
        return ans;

    ans.push_back(root -> data);

    // Part A
    leftSide(root -> left, ans);

    // Part B
    leaf(root -> left, ans);
    leaf(root -> right, ans);

    // Part C
    rightSide(root -> right, ans);

    return ans;
}

int main(){

    return 0;
}