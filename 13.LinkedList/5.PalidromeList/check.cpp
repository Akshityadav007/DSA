#include<iostream>
using namespace std;

// Problem || Leetcode : 234
/*
   -> Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

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
    # Method 1 : Make reverse list
     -> Make a reverse list and then compare both
    

    # Method 2 : Middle element
     -> Get the mid of the linked list
     -> Reverse the list from mid.
     -> Break the list into two.
     -> Compare both linked list.
     -> No extra space is used.

     -> Only catch is the original LL is tampered.

*/

ListNode *reverseList(ListNode *head){
    if(head == NULL || head -> next == NULL)
        return head;
    
    ListNode *prev = NULL;
    ListNode *curr = head;

    while(curr){
        ListNode *temp = curr;
        curr = curr -> next;
        temp -> next = prev;
        prev = temp;        
    }

    return prev;
}

ListNode* middleNode(ListNode* &head) {
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast -> next != NULL){                // we need the left node in case of 'even' sized LL, hence changed this code
            fast = fast -> next;
            if(fast -> next != NULL){
                fast = fast -> next;
                // here we can say, fast has moved 2 steps and we can move slow 1 step

                slow = slow -> next;
            }
        }

        return slow;
}

bool compare(ListNode *h1, ListNode *h2){
    while(h1 !=NULL && h2!=NULL){
        if(h1 -> val != h2 -> val)
            return false;
        h1 = h1 -> next;
        h2 = h2 -> next;
    }
    return true;
}

bool isPalindrome(ListNode* head) {
    // get the middle 
    ListNode *mid = middleNode(head);
    ListNode *head2 = mid -> next;
    mid -> next = NULL;                     // breaking the list into two

    head2 = reverseList(head2);
    
    return compare(head, head2);

}

int main(){

    return 0;
}