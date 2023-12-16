#include<iostream>
using namespace std;

// Problem || Coding Ninjas
/*
    
*/
template <typename T>
class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };


// Solution
/*
    -> Same as BT to DLL
*/


void createList(TreeNode<int> *&head, TreeNode<int> *root){
    if(root == NULL)
        return;
    
    // Right
    createList(head, root -> right);
    
    // root
    root -> right = head;
    if(head != NULL)
        head -> left = root;
    head = root;
    
    
    // Left
    createList(head, root -> left);
}

TreeNode<int>* bstToSortedDLL(TreeNode<int> *root)
{
	if(root == NULL)
        return NULL;
    
    TreeNode<int> *head = NULL;

    createList(head, root);

    return head;
}

int main(){

    return 0;
}