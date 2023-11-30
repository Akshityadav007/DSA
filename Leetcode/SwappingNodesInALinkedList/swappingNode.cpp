#include<iostream>
using namespace std;


// Problem || Leetcode : 1721
/*
    -> You are given the head of a linked list, and an integer k.
    -> Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).
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
    -> Its simple brute force.
*/

int getLength(ListNode *&head){
    ListNode *curr = head;
    int size = 0;
    while(curr != NULL){
        ++size;
        curr = curr -> next;
    }
    return size;
}
ListNode* swapNodes(ListNode* head, int k) {
    // get the length of the list
    int size = getLength(head);

    ListNode *nodeStart = head;
    ListNode *nodeEnd = head;
    
    for(int i = 1;i < k; i++)
        nodeStart = nodeStart -> next;
    
    for(int i = 0;(i + k) < size; i++)
        nodeEnd = nodeEnd -> next;
    
    int temp = nodeStart -> val;
    nodeStart -> val = nodeEnd -> val;
    nodeEnd -> val = temp;

    return head;
}


int main(){


    return 0;
}