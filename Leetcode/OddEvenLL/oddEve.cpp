#include<iostream>
using namespace std;

// Problem || Leetcode : 328
/*
    -> Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.
    -> The first node is considered odd, and the second node is even, and so on.
    -> Note that the relative order inside both the even and odd groups should remain as it was in the input.
    -> You must solve the problem in O(1) extra space complexity and O(n) time complexity.
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
    -> We need to traverse the linked list and keep changing the nodes of even and odd linked list. This will divide the LL in two parts.
    -> After we have done this, we should join both linked lists.
    -> Note : We should keep check of the edge cases like even node pointer is pushed forward next to odd node pointer, hence it might either get to the last node or can also reach NULL.
*/

ListNode* oddEvenList(ListNode* head) {
    if(head == NULL || head -> next == NULL)
        return head;

    // seperate head's of both nodes
    ListNode *odd = head;
    ListNode *evenHead = head -> next;
    ListNode *even = evenHead;

    while(even != NULL && even -> next != NULL && odd != NULL){
        odd -> next = even -> next;
        even -> next = even -> next -> next;

        odd = odd -> next;
        even = even -> next;
    }

    if(even == NULL || even -> next == NULL)
        odd -> next = evenHead;
    else{
        even -> next = even -> next -> next;
        odd -> next = evenHead;
    }

    return head;        
}

int main(){


    return 0;
}