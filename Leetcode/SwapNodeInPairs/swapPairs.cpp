#include<iostream>
using namespace std;

// Problem || Leetcode : 24
/*
    -> Given a linked list, swap every two adjacent nodes and return its head.
    -> You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)
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
ListNode* swapPairs(ListNode* head) {
    if(head == NULL || head -> next == NULL)
        return head;
    
    ListNode *prev = NULL;
    ListNode *curr = head;
    ListNode *nextNode = head -> next;

    while(nextNode != NULL){
        curr -> next = nextNode -> next;

        if(prev != NULL){ 
            prev -> next = nextNode;
            prev = curr;
        }
        else{
            prev = curr;                                // first node
            head = nextNode;
        }

        nextNode -> next = curr;

        curr = curr -> next;
        if(curr == NULL)                    // last node
            break;
        nextNode = curr -> next;
    }
    return head;
}

int main(){


    return 0;
}