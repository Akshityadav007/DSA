#include<iostream>
using namespace std;

// Problem || Leetcode : 1669
/*
    -> You are given two linked lists: list1 and list2 of sizes n and m respectively.
    -> Remove list1's nodes from the ath node to the bth node, and put list2 in their place.
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

void deleteNodes(ListNode *&head){
    ListNode *curr = head;
    while(curr != NULL){
        ListNode *temp = curr;
        curr = curr ->next;
        delete temp;
    }
}
ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
    ListNode *start = list1;
    ListNode *end = list1;

    while(--a)
        start = start -> next;
    
    while(b--)
        end = end -> next;
    
    ListNode *temp = start -> next;
    start -> next = list2;

    // get end of list2
    ListNode *end2 = list2;
    while(end2 -> next != NULL)
        end2 = end2 -> next;
    end2 -> next = end -> next;

    end -> next = NULL;                 // Isolate  
    deleteNodes(temp);                  // free memory

    return list1;  
}


int main(){

    return 0;
}