#include<iostream>
#include<vector>
using namespace std;

/*
    -> Used to traverse tree.
    -> T.C. : O(n) ; S.C. : O(1)
*/

class Node{
    public:
    int val;
    Node *left;
    Node *right;    
};



// Solution
/*
      -> In any traversal (inorder, preorder, postorder), we have a defined path and we use recursion/stack to traverse back in path to print.
      -> But if we don't have to use stack (memory) and we want to traverse back, what should we do?

      -> If we won't use any stack/recursion that means no backtracking, which means we only have to move forward in loop.
      -> So, if anyhow we get to mark the next element to be printed to the upcoming path, we can do it.

      -> This is done by Morris traversal algo.
      -> In this we mark a predecessor to travel next.

      -> For example, in any tree/subtree we move back to the root only after printing the right most node of left subtree.
      -> Hence, if we connect the right most part of left subtree to the root/next node then we only need to move forward.

*/

// Inorder morris traversal
vector<int> InorderMorris(Node *root){
    vector<int> ans;
    if(root == NULL)
        return ans;

    Node *curr = root;
    while(curr){
        // left is null, then visit it and go right i.e left has already been visited
        if(curr -> left == NULL){
            ans.push_back(curr -> val);
            curr = curr -> right;
        }
        // left node is not null
        else{
            // 1) find inorder predecessor (go to the right most node of left child / predecessor)
            Node *pred = curr -> left;
            while(pred -> right != curr && pred -> right != NULL)
                pred = pred -> right;

            // 2) if pred ' s right node is null, then go left after establishing link from predecessor to curr.

            if(pred -> right == NULL){
                pred -> right = curr;
                curr = curr -> left;
            }
            else{
                // left is already visited, go right after visiting curr node, while removing the link
                pred -> right = NULL;
                ans.push_back(curr -> val);
                curr = curr -> right;
            }
        }
    }
    return ans;
}


// learnt from youtube
vector<int> InorderMorris(Node *root){
    vector<int> ans;
    if(root == NULL)
        return ans;

    Node *curr = root;
    while(curr){
        // left is null, then visit it and go right i.e left has already been visited
        if(curr -> left == NULL){
            ans.push_back(curr -> val);
            curr = curr -> right;
        }
        // left node is not null
        else{
            // 1) find inorder predecessor (go to the right most node of left child / predecessor)
            Node *pred = curr -> left;
            while(pred -> right != NULL)
                pred = pred -> right;

            // 2) if pred ' s right node is null, then go left after establishing link from predecessor to curr.
            pred -> right = curr;

            Node *temp = curr;
            curr = curr -> left;
            temp -> left = NULL;                    // make sure to make left node pointer of each visited node to NULL, so that this doesn't end up in infinite loop
        }
    }
    return ans;
}

int main(){

    return 0;
}