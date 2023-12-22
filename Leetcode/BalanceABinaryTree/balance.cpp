#include<iostream>
#include<vector>
using namespace std;


// Problem || Leetcode : 1382
/*
    -> Given the root of a binary search tree, return a balanced binary search tree with the same node values. 
    -> If there is more than one answer, return any of them.
    -> A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.
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
    # Method : DFS + buildTree
        -> Step : 1
            - Get the inorder of the tree (dfs).
            - It will be time and space efficient to store the nodes in the vector instead of values. (in - place).
        
        -> Build the tree
            - Inorder is sorted, hence the mid element will be the root element (left of this are smaller elements to it and to the right greater).
            - Solve it recursively.
*/

void getInorder(vector<TreeNode*> &v, TreeNode* root){
    // base case
    if(root == NULL)
        return;
    
    getInorder(v, root -> left);
    v.push_back(root);
    getInorder(v, root -> right);
}

TreeNode *buildTree(vector<TreeNode*> &v, int low, int high){
    // base case
    if(low > high)
        return NULL;

    // mid will be the root
    int mid = low + ((high - low) >> 1);
    
    v[mid] -> left = buildTree(v, low, mid - 1);
    v[mid] -> right = buildTree(v, mid + 1, high);

    return v[mid];
}

TreeNode* balanceBST(TreeNode* root) {
    // step 1 : get the inorder traversal (because inorder of a BST is sorted)
    vector<TreeNode *> v;
    getInorder(v, root);

    // step 2 : build a tree
    TreeNode *bst = buildTree(v, 0, v.size() - 1);

    return bst;
}

int main(){

    return 0;
}