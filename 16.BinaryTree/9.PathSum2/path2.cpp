#include<iostream>
#include<vector>
using namespace std;

// Problem || Leetcode : 113
/*
    -> Given the root of a binary tree and an integer targetSum.
    -> Return all root-to-leaf paths where the sum of the node values in the path equals targetSum. 
    -> Each path should be returned as a list of the node values, not node references.
    -> A root-to-leaf path is a path starting from the root and ending at any leaf node.
    -> A leaf is a node with no children.
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
    -> Before this revise Path sum 1 (Given below)
    -> Similar to that question, only difference we'll have to push the path where we get targetSum.

*/

void solve(TreeNode* root, int targetSum, vector<vector<int>> &ans, vector<int> v){
    if(root == NULL)
        return;
    int diff = targetSum - root -> val;
    v.push_back(root -> val);
    // base case
    if(root -> left == NULL && root -> right == NULL){
        if(diff == 0)
            ans.push_back(v);
        else
            return;
    }

    solve(root -> left, diff, ans, v);          // left tree
    solve(root -> right, diff, ans, v);         // right tree
}
vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector <vector<int>> ans;
    solve(root, targetSum, ans, vector<int> ());
    return ans;
}



int main(){


    return 0;
}


// Path sum 1
bool hasPathSum(TreeNode* root, int targetSum) {
    if(root == NULL)
        return false;
    
    int diff = targetSum - root -> val;

    if(root -> left == NULL && root -> right == NULL){
        
        if(diff == 0)
            return true;
        else
            return false;
    }
    
    bool lAns = hasPathSum(root -> left, diff);
    bool rAns = hasPathSum(root -> right, diff);

    return lAns || rAns;
}