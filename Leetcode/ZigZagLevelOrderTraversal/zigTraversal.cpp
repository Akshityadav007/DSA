#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

// Problem || Leetcode : 103
/*
    -> Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. 
    -> (i.e., from left to right, then right to left for the next level and alternate between).
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
    -> In normal level order traversal we insert each level in a queue and traverse it while inserting next level.
    -> In this case we need to traverse levels in reverse order at every alternate level.
    -> Hence to track this we'll keep a trigger/ counter.
    -> And at alternate levels we'll reverse the level to store the level in order to reverse it.
*/

 vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector <int>> ans;
        if(root == NULL)
            return ans;
        
        queue<TreeNode *> q;
        q.push(root);
        
        bool leftToRight = true;

        while(!q.empty()){
            vector<int> levels;
            int size = q.size();

            if(leftToRight){
                for(int i = 0; i < size; i++){
                    TreeNode *frontNode = q.front();
                    q.pop();
                    levels.push_back(frontNode -> val);

                    if(frontNode -> left != NULL)
                        q.push(frontNode -> left);
                    if(frontNode -> right != NULL)
                        q.push(frontNode -> right);
                }
                leftToRight = false;        // toggle trigger
            }
            else{
                for(int i = 0; i < size; i++){
                    TreeNode *frontNode = q.front();
                    q.pop();
                    levels.push_back(frontNode -> val);

                    if(frontNode -> left != NULL)
                        q.push(frontNode -> left);
                    if(frontNode -> right != NULL)
                        q.push(frontNode -> right);
                }
                reverse(levels.begin(), levels.end());
                leftToRight = true;     // toggle trigger
            }
            ans.push_back(levels);
        }

        return ans;
    }

int main(){

    return 0;
}