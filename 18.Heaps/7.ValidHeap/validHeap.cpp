#include<iostream>
#include<queue>
using namespace std;

// Problem || GFG
/*
    -> Given a binary tree. 
    -> The task is to check whether the given tree follows the max heap property or not.
    # Note: Properties of a tree to be a max heap - Completeness and Value of node greater than or equal to its child.
*/

class Node{
    public:
        int data;
        Node *left;
        Node *right;
};

class Info{
    public:
        int maxVal;
        bool isHeap;

        Info(){
            this -> maxVal = INT_MIN;
            this ->  isHeap = true;
        }

        Info(int val, bool b){
            this -> maxVal =val;
            this -> isHeap = b;
        }
    };

class Solution {
  public:
  
    Info checkMaxHeap(Node *root){
        // last node
        if(root == NULL){
            Info temp;
            return temp;
        }
        
        // leaf node
        if(root -> left == NULL && root -> right == NULL){
            Info temp;
            temp.maxVal = root -> data;
            temp.isHeap = true;
            return temp;
        }
    
        Info leftAns = checkMaxHeap(root -> left);
        Info rightAns = checkMaxHeap(root -> right);
    
        // solve 1 case
        if(root -> data > leftAns.maxVal && root -> data > rightAns.maxVal && leftAns.isHeap && rightAns.isHeap){
            Info ans;
            ans.maxVal = root -> data;
            ans.isHeap = true;
            return ans;
        }
        else{
            Info ans;
            ans.maxVal = max(root -> data, max(leftAns.maxVal, rightAns.maxVal));
            ans.isHeap = false;
            return ans;
        }
    }
    
    bool bfs(Node *root){
        queue<Node*> q;
        q.push(root);
        bool nullFound = false;
        
        while(!q.empty()){
            int size = q.size();
            for(int i = 0;i < size; i++){
                Node *frontNode = q.front();
                q.pop();
                
                if(frontNode == NULL)
                    nullFound = true;
                else{
                    if(nullFound)
                        return false;
                    
                    q.push(frontNode -> left);
                    q.push(frontNode -> right);
                }
            }
        }
        return true;
    }
    
    bool isHeap(Node* tree) {
        return bfs(tree) && checkMaxHeap(tree).isHeap;
    }
};

int main(){

    return 0;
}