#include<iostream>
#include<vector>
using namespace std;

// Problem || GFG
/*
    -> Serialization is to store a tree in an array so that it can be later restored and Deserialization is reading tree back from the array. 
    -> Now your task is to complete the function serialize which stores the tree into an array A[ ] and deSerialize which deserializes the array to the tree and returns it.
    
    # Note: The structure of the tree must be maintained. Multiple nodes can have the same data.
    # Note : NULL is denoted by -1.

*/
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


// Solution
/*

*/

class Solution
{
    public:
    void getPre(vector<int> &pre, Node *root){
        // base case
        if(root == NULL){
            pre.push_back(-1);
            return;
        }
        
        pre.push_back(root -> data);
        getPre(pre, root -> left);
        getPre(pre, root -> right);
    }
    //Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root) 
    {
        vector<int> pre;
        getPre(pre, root);
        
        return pre;
    }
    
    
    Node *buildTree(vector<int> &v, int &index){
        // base case
        if(index >= v.size())
            return NULL;
        
        if(v[index] == -1){
            index++;
            return NULL;
        }
        
        Node *newNode = new Node(v[index++]);
        newNode -> left = buildTree(v, index);
        newNode -> right = buildTree(v, index);
        
        return newNode;
    }
    
    //Function to deserialize a list and construct the tree.
    Node * deSerialize(vector<int> &A)
    {
        int index = 0;
        Node *root = buildTree(A, index);
        
        return root;
    }

};

int main(){

    return 0;
}