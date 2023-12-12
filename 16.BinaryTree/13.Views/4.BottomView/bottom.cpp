#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

// Problem || GFG
/*
Given a binary tree, print the bottom view from left to right.
A node is included in bottom view if it can be seen when we look at the tree from bottom.

                      20
                    /    \
                  8       22
                /   \        \
              5      3       25
                    /   \      
                  10    14

For the above tree, the bottom view is 5 10 3 14 25.
If there are multiple bottom-most nodes for a horizontal distance from root, then print the later one in level traversal. For example, in the below diagram, 3 and 4 are both the bottommost nodes at horizontal distance 0, we need to print 4.

                      20
                    /    \
                  8       22
                /   \     /   \
              5      3 4     25
                     /    \      
                 10       14

For the above tree the output should be 5 10 4 14 25.

Note: The Input/Output format and Example given are used for the system's internal purpose, and should be used by a user for Expected Output only. As it is a function problem, hence a user should not read any input from the stdin/console. The task is to complete the function specified, and not to write the full code.
 
    
*/
struct Node {
    int data;
    Node *left;
    Node *right;
};


// Solution
/*
    -> Same as top view code, only difference is we should override the mapped data as we need the lowest in this case.
    
*/

  vector<int> bottomView(Node *root){
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
            
            // override the previous insertion if already available
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