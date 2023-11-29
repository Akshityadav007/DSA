#include<iostream>
using namespace std;

// Problem || Leetcode : 148
// I copied the solution from a leetcode solution as I couldn't do it on my own.
/*
    -> Given the head of a linked list, return the list after sorting it in ascending order.
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 

// Solution
/*
    # Merge sort
    -> The methodolgy is same, only the way it is done is different.
    -> Try to understand this on your own.
*/

ListNode *merge(ListNode *&left, ListNode *&right){
    ListNode *temp = new ListNode();
    ListNode *curr = temp;

    while(left != NULL && right != NULL){
        if((left -> val) < (right -> val)){
            curr -> next = left;
            left = left -> next;
        }
        else{
            curr -> next = right;
            right = right -> next;
        }
        curr = curr -> next;
    }

    while(left != NULL){
        curr -> next = left;
        curr = curr -> next;
        left = left -> next;
    }

    while(right != NULL){
        curr -> next = right;
        curr = curr -> next;
        right = right -> next;
    }

    ListNode *head = temp -> next;
    temp -> next = NULL;
    delete temp;

    return head;
}

ListNode* sortList(ListNode* head) {
    if(head == NULL || head -> next == NULL)
        return head;

    // get the mid node using slow/fast algo
    ListNode *mid = NULL;
    ListNode *slow = head;
    ListNode *fast = head;

    while(fast != NULL && fast -> next != NULL){
        mid = slow;
        slow = slow -> next;
        fast = fast -> next -> next;
    }

    // divide the list
    mid -> next = NULL;

    ListNode *left = sortList(head);
    ListNode *right = sortList(slow);

    return merge(left, right);        
}

int main(){


    return 0;
}