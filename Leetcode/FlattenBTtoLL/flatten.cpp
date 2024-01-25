#include<iostream>
using namespace std;

// Problem || Leetcode : 114
/*
    -> Given the root of a binary tree, flatten the tree into a "linked list":
    -> The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
    -> The "linked list" should be in the same order as a pre-order traversal of the binary tree.
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
    -> Use morris traversal.
    -> Make few changes as in below code.

*/

class Solution {
public:
    void morrisTraversal(TreeNode *&root){
        if(root == NULL)
            return;

        TreeNode *curr = root;

        while(curr != NULL){
            if(curr -> left != NULL){
                // get predecessor
                TreeNode *pred = curr -> left;
                while(pred -> right != NULL)
                    pred = pred -> right;
                
                pred -> right = curr -> right;              // amend the rightmost node of left subtree to the right of current
                curr -> right = curr -> left;               // now shift left subtree to right subtree of current node
                curr -> left = NULL;                        // amend curr node's left
            }     
            curr = curr -> right;                           // shift current
        }
    }

    void flatten(TreeNode* root) {
        if(root == NULL)
            return;

        // solve it using morris traversal
        morrisTraversal(root);
    }
};

int main(){


    return 0;
}