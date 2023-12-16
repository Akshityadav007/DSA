#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

// Problem || GFG
/*
    -> Given below is a binary tree. 
    -> The task is to print the top view of binary tree.
    -> Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. 
    -> For the given below tree

                   1
                /     \
               2       3
             /  \    /   \
            4    5  6     7

    -> Top view will be: 4 2 1 3 7
    
    # Note: 
        - Return nodes from leftmost node to rightmost node. 
        - Also if 2 nodes are outside the shadow of the tree and are at same position then consider the left ones only(i.e. leftmost). 
        -> For ex - 1 2 3 N 4 5 N 6 N 7 N 8 N 9 N N N N N will give 8 2 1 3 as answer. 
        -> Here 8 and 9 are on the same position but 9 will get shadowed.
    
*/
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Solution
/*
    -> For top view we don't have any levels given so we'll consider our our own levels (to the left in -ve and to the right +ve).
    -> We'll use level order traversal for each level.    
*/

vector<int> topView(Node *root){
    vector<int> ans;
    if(root == NULL)
        return ans;

    queue<pair<Node *, int>> q;
    q.push({root, 0});
    int hD = 0;
    map < int, int > m;                       // horizontal distance, value
    m[hD] = root -> data;

    while(!q.empty()){
        int size = q.size();                         

        for(int i = 0;i < size; i++){
            pair<Node *, int> p = q.front();
            q.pop();                        // remove prev level node

            Node *frontNode = p.first;
            int hD = p.second;
            
            // if not mapped earlier
            if(m.find(hD) == m.end())
                m[hD] = frontNode -> data;
            
            // insert next level
            if(frontNode -> left != NULL)
                q.push({frontNode -> left, hD - 1});                 // level decrease
            
            if(frontNode -> right != NULL)
                q.push({frontNode -> right, hD + 1});                // level increase
        }
    }

    for(auto i: m){
        ans.push_back(i.second);
    }
    return ans;
}


int main(){

    return 0;
}