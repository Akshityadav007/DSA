#include<iostream>
using namespace std;


// Problem || Leetcode : 109
/*
    -> Given the head of a singly linked list where elements are sorted in ascending order, convert it to a height-balanced binary search tree.
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

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
    -> Had this been an array instead of linked list, would have solved like : 
        - Get the mid of array.
        - Mid is definetly the root of the tree, left of which is left subtree and right of which is right subtree. (Inorder of BST)
    -> But for this we'll use recursion to do the task.
*/

TreeNode *createTree(ListNode *&head, int n){
    // base case 
    if(head == NULL || n <= 0)          // right subtree || left subtree
        return NULL;
    
    // Left
    TreeNode *leftSubtree = createTree(head, n / 2);

    // Root
    TreeNode *root = new TreeNode(head -> val);
    root -> left = leftSubtree;
    head = head -> next;


    // Right
    TreeNode *rightSubtree = createTree(head, n - n / 2 - 1);
    root -> right = rightSubtree;

    return root;
}

int sizeLL(ListNode *head){
    if(head == NULL)
        return 0;
    int size = 0;
    ListNode *temp = head;
    while(temp != NULL){
        ++size;
        temp = temp -> next;
    }
    return size;
}

TreeNode* sortedListToBST(ListNode* head) {
    int n = sizeLL(head);                   // get size of linked list

    TreeNode *root  = createTree(head, n);
    return root;
}

int main(){

    return 0;
}