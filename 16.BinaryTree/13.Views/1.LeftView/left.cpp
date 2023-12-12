#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// Problem || GFG
/*
    -> Print the left view of binary tree.
    -> Left view = If I see tree form left.
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
    # Method 1 : Level order traversal


    # Method 2 : Recursion
        -> Take level count into consideration
        -> We need to take 1 value from each level.
        -> Hence we need to check if the level count matches with the current level, if so we'll store the value of the node.
        -> Also since this is left view, we should get the first value from left to be stored at each level.
*/

// Method 1
vector<int> leftSideView(TreeNode* root) {
    vector <int> ans;
    if(root == NULL)
        return ans;
    
    queue<TreeNode *> q;
    q.push(root);

    while(!q.empty()){
        vector<int> level;
        int size = q.size();

        for(int i = 0;i < size; i++){
            TreeNode *front = q.front();
            level.push_back(front -> val);
            q.pop();
            
            if(front -> left != NULL)
                q.push(root -> left);

            if(front -> right != NULL)
                q.push(root -> right);
        }

        // last node of the current level will be right side view
        ans.push_back(level[0]);
    }

    return ans;
}


// Method 2
void solve(TreeNode *&root, vector<int> &v, int level){
    if(level == v.size()){
        v.push_back(root -> val);
    }
        
    if(root -> left != NULL)
        solve(root -> left, v, level + 1);

    if(root -> right != NULL)
        solve(root -> right, v, level + 1);
    
}

vector<int> leftSideView(TreeNode* root) {
    vector <int> ans;
    if(root == NULL)
        return ans;
    
    int level = 0;
    
    solve(root, ans, level);

    return ans;
}


int main(){

    return 0;
}