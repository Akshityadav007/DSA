#include<iostream>
using namespace std;

// Problem || Leetcode : 1448
/*
    -> Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.
    -> Return the number of good nodes in the binary tree.
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
    # Method : 1 Brute force
        -> At every node keep checking from root to that node if it is valid and increment counter accordingly.

    # Method : 2 Optimized
        -> Keep track of the node value which is greatest till the current node and keep checking and incrementing further.
        
*/

void dfs(TreeNode *curr, int maxTillNow, int &ans){
    // base case
    if(curr == NULL)
        return;
    
    if(curr -> val >= maxTillNow){
        ++ans;
        maxTillNow = curr -> val;
    }

    dfs(curr -> left, maxTillNow, ans);
    dfs(curr -> right, maxTillNow, ans);
}
int goodNodes(TreeNode* root) {
    if(root -> left == NULL && root -> right == NULL)
        return 1;

    int ans = 0;                                // root is always a good node

    dfs(root, root -> val, ans);               // preorder

    return ans;
}

int main(){

    return 0;
}