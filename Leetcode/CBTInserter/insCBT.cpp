#include<iostream>
#include<queue>
using namespace std;


// Problem || Leetcode : 919
/*
    -> A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible.
    -> Design an algorithm to insert a new node to a complete binary tree keeping it complete after the insertion.

    -> Implement the CBTInserter class:
        - CBTInserter(TreeNode root) Initializes the data structure with the root of the complete binary tree.
        - int insert(int v) Inserts a TreeNode into the tree with value Node.val == val so that the tree remains complete, and returns the value of the parent of the inserted TreeNode.
        - TreeNode get_root() Returns the root node of the tree.
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
    -> Method 1 : Using Level order traversal (bfs)
*/

class CBTInserter {
public:
    TreeNode *r;
    CBTInserter(TreeNode* root) {
        r = root;
    }
    
    int insert(int val) {
        TreeNode *newNode = new TreeNode(val);
        int parentNodeVal = ((r == NULL) ? val : r -> val);

        queue<TreeNode *> q;
        q.push(r);

        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode *frontNode = q.front();
                q.pop();

                if(frontNode -> left != NULL)
                    q.push(frontNode -> left);
                else{
                    frontNode -> left = newNode;
                    parentNodeVal = frontNode -> val; 
                    return parentNodeVal;
                    break;
                }
            
                if(frontNode -> right != NULL)
                    q.push(frontNode -> right);
                else{
                    frontNode -> right = newNode;
                    parentNodeVal = frontNode -> val; 
                    return parentNodeVal;
                }  
            }
        }
        return parentNodeVal;
    }
    
    TreeNode* get_root() {
        return r;
    }
};



int main(){


    return 0;
}