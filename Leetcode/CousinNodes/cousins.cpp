#include<iostream>
#include<queue>
#include<map>
using namespace std;

// Problem || Leetcode : 993
/*
    -> Given the root of a binary tree with unique values and the values of two different nodes of the tree x and y.
    -> Return true if the nodes corresponding to the values x and y in the tree are cousins, or false otherwise.
    -> Two nodes of a binary tree are cousins if they have the same depth with different parents.
    -> Note that in a binary tree, the root node is at the depth 0, and children of each depth k node are at the depth k + 1.
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
    -> Use BFS.
    -> Keep mappning the nodes and parent to check if they are of the same parent.
*/

bool isCousins(TreeNode* root, int x, int y) {
    // level order traversal
    queue<TreeNode*> q;
    q.push(root);
    map<TreeNode *, TreeNode *> m;               // node, parent

    while(!q.empty()){
        int size = q.size();

        bool foundX = false;
        bool foundY = false;
        TreeNode *X = NULL;
        TreeNode *Y = NULL;

        for(int i = 0;i < size; i++){
            TreeNode *frontNode = q.front();
            q.pop();

            if(frontNode -> val == x){
                X = frontNode;
                foundX = true;
            }
            if(frontNode -> val == y ){
                Y = frontNode;
                foundY = true;
            }
            
            // insert next level nodes
            if(frontNode -> left != NULL){
                m[frontNode -> left] = frontNode;
                q.push(frontNode -> left);
            }
            if(frontNode -> right != NULL){
                m[frontNode -> right] = frontNode;
                q.push(frontNode -> right);
            }

            if(foundX && foundY){
                // if those nodes have different parents
                if(m[X] != m [Y])
                    return true;
                else
                    return false;
            }
        }
    }
    return false;
}

int main(){

    return 0;
}