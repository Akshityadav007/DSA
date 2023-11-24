#include<iostream>
using namespace std;

// Problem || Leetcode : 92
/*
    -> Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.
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
    -> We'll do it in one pass.
    -> Have 3 pointers - prev (storing the previous node), 'start' and 'end'.
    -> First get 'prev -> next' to the 'end' node as post reversal it will be after the previous node.

    -> We'll reverse the nodes within range.
    -> At last we need to cover the edge cases.


    (Maybe this explaination isn't enough because am tired to right, couldn't solve it initially because of a minor error (was modifying prev after modifying start in the movement of start)).

*/


ListNode* reverseBetween(ListNode* head, int left, int right) {
    if(head == NULL || head -> next == NULL || left == right)
        return head;
    
    // first let's get to the positions
    ListNode *start = head;
    ListNode *prev = NULL;
    ListNode *end = head;

    while(left > 1){
        prev = start;
        start = start -> next;
        left--;
    }

    while(right > 1){
        end = end -> next;
        right--;
    }

    // change previous next
    if(prev != NULL)
        prev -> next = end;
    else
        head = end;

    prev = end -> next;                     // change position of 'prev'
    
    // start reversal from start
    while(start != end){
        ListNode *temp = start;
        start = start -> next;
        temp -> next = prev;
        prev = temp;
    }

    if(start != NULL){
        start -> next = prev;
    }

    return head;        
}



int main(){

    return 0;
}