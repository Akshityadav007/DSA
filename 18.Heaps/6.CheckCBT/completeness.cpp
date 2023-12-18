#include<iostream>
#include<queue>
using namespace std;

// Problem || Leetcode : 958
/*
    -> Given the root of a binary tree, determine if it is a complete binary tree.
    -> In a complete binary tree, every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. 
    -> It can have between 1 and 2h nodes inclusive at the last level h.
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
    # Method : Use level order traversal
        -> Maintain a flag to track non null nodes.
        -> Once we found a NULL node, we'll trigger the flag.
        -> If we get another non null node after the flag is triggered, this means this is not a valid complete BT.
*/


bool levelOrderTraversal(TreeNode *root){
    queue<TreeNode *> q;
    q.push(root);
    bool nullFound = false;

    while(!q.empty()){
        int size = q.size();
        for(int i = 0;i < size; i++){
            TreeNode *frontNode = q.front();
            q.pop();

            if(frontNode == NULL)
                nullFound = true;
            else{
                if(nullFound)
                    return false;                                           // a non null node found post a null node being found
                
                q.push(frontNode -> left);
                q.push(frontNode -> right);
            }
        }
    }

    return true;
}

bool isCompleteTree(TreeNode* root) {
    return levelOrderTraversal(root);
}

int main(){

    return 0;
}