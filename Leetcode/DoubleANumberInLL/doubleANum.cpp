#include<iostream>
using namespace std;

// Problem || Leetcode : 2816
/*
    -> You are given the head of a non-empty linked list representing a non-negative integer without leading zeroes.
    -> Return the head of the linked list after doubling it.
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
    -> First reverse the list because to double it we need to start from unit place.
    -> Start doubling it one by one and make answer list.
    -> Reverse the answer list.
*/
ListNode *reverseLL(ListNode *head){
    ListNode *curr = head;
    ListNode *prev = NULL;
    while(curr != NULL){
        ListNode *temp = curr;
        curr = curr -> next;
        temp -> next = prev;
        prev = temp;
    }
    return prev;
}
ListNode* doubleIt(ListNode* head) {
    // Step : 1) reverse the given list
    head = reverseLL(head);

    // Step : 2) double it
    ListNode *ans = NULL;
    ListNode *iterator = ans;           // to iterate answer node
    ListNode *curr = head;
    int carry = 0;
    while(curr != NULL){
        int num = curr -> val;
        num = (num * 2) + carry;
        ListNode *newNode = new ListNode(num % 10);
        carry = num / 10;

        if(ans == NULL){
            ans = newNode;
            iterator = ans;
        }
        else{
            iterator -> next = newNode;
            iterator = iterator -> next;
        }
        curr = curr -> next;
    }

    // what if carry is still left to be inserted
    while(carry > 0){
        ListNode *newNode = new ListNode(carry % 10);
        carry /= 10;
        iterator -> next = newNode;
        iterator = iterator -> next;
    }

    // Step : 3) Reverse the answer node
    ans = reverseLL(ans);

    return ans;
}

int main(){

    return 0;
}