#include<iostream>
#include<queue>
using namespace std;


// Problem || Leetcode : 104
/*
    -> Given the root of a binary tree, return its maximum depth.
    -> A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
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
    # Method : 1 (Use queue)
        - Can use level order traversal having one variable to count them
        - The number of 'NULL' we have is the height of tree.
        - Hence whenever we push 'NULL' in the queue we'll increase count.
    
    # Method : 2 (Use stack / recursion)
        - Use recursion
*/

int maxDepth(TreeNode* root) {
    if(root == NULL)
        return 0;
        
    int leftHeight = maxDepth(root -> left);
    int rightHeight = maxDepth(root -> right);
    int height = 1 + max(leftHeight, rightHeight);

    return height;
}

int main(){



    return 0;
}
