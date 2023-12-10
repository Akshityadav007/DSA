#include<iostream>
using namespace std;

// Problem || Leetcode : 143
/*
    -> You are given the head of a singly linked-list. The list can be represented as:
    -> L0 → L1 → … → Ln - 1 → Ln
        - Reorder the list to be on the following form:
    -> L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
        - You may not modify the values in the list's nodes. Only nodes themselves may be changed.

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
    
*/

ListNode *reverseList(ListNode *&head){
    ListNode *prev = NULL;
    ListNode *curr = head;
    while(curr != NULL){
        ListNode *temp = curr;
        curr = curr -> next;
        temp -> next = prev;
        prev = temp;
    }
    return prev;
}
void reorderList(ListNode* head) {
    if(head == NULL && head -> next == NULL)
        return;
    // Step 1 : Get mid of list
    // Step 2 : Reverse the second part
    // Step 3 : Insert the second part in first

    ListNode *mid = head;
    ListNode *start = head;

    // slow - fast approach
    while(start != NULL && start -> next != NULL ){
        mid = mid -> next;
        start = start -> next -> next;
    }

    start = head;
    // isolate (handle case of two elements, when start == mid)
    while(start != mid && start -> next != mid){
        start = start -> next;
    }
    start -> next = NULL;

    mid = reverseList(mid);

    start = head;
    while(start != NULL){
        ListNode *nextNode = start -> next;
        ListNode *midNext = mid -> next;

        start -> next = mid;
        mid -> next = nextNode;

        start = nextNode;
        mid = midNext;
    }

    // in case of odd elements there will be one element left
    start = head;
    while(start -> next != NULL)
        start = start -> next;
    
    start -> next = mid;
}


int main(){


    return 0;
}