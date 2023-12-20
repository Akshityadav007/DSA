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

      -> This is doner by Morris traversal algo.
      -> In this we mark a predecessor to travel next.

*/

// Inorder morris traversal
vector<int> InorderMorris(Node *root){
    vector<int> ans;
    if(root == NULL)
        return ans;

    Node *curr = root;
    while(curr){
        // left is null, then visit it and go right
        if(curr -> left == NULL){
            ans.push_back(curr -> val);
            curr = curr -> right;
        }
        // left node is not null
        else{
            // 1) find inorder predecessor
            Node *pred = curr -> left;
            while(pred -> right != curr && pred -> right)
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


void morrisTraversal(Node *root){

}

int main(){

    return 0;
}