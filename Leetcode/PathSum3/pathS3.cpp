#include<iostream>
#include<queue>
using namespace std;

// Problem || Leetcode : 437
/*
    -> Given the root of a binary tree and an integer targetSum.
    -> Return the number of paths where the sum of the values along the path equals targetSum.
    -> The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).
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
    # Method 1:
     -> Apply DFS at every node.
     -> To get to every node, I used bfs (can use any traversal).

    # Method 2 : (Can be solved using map)
     -> Map can be used to track the sum till a node so that we need not traverse back.
*/

void dfs(TreeNode *root,int &ans, long long count, int targetSum){
    // base case 
    if(root == NULL)
        return;

    count += root -> val;
    if(count == targetSum)
        ans++;

    dfs(root -> left, ans, count, targetSum);
    dfs(root -> right, ans, count, targetSum);
}

int bfs(TreeNode *root, int targetSum){
    queue<TreeNode*> q;
    q.push(root);
    int ans = 0;

    while(!q.empty()){
        int size = q.size();
        for(int i = 0;i < size; i++){
            TreeNode *firstNode = q.front();
            q.pop();

            dfs(firstNode, ans, 0,targetSum);

            if(firstNode -> left != NULL)
                q.push(firstNode -> left);
            
            if(firstNode -> right != NULL)
                q.push(firstNode -> right);
        }
    }

    return ans;
}

int pathSum(TreeNode* root, int targetSum) {
    if(root == NULL)
        return 0;

    
    return bfs(root, targetSum);
}

int main(){

    return 0;
}