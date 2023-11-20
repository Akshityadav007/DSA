#include<iostream>
using namespace std;

// Problem || Leetcode : 876
/*
    -> Given the head of a singly linked list, return the middle node of the linked list.
    -> If there are two middle nodes, return the second middle node

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
    # Method 1 : Average approach
     -> Get length of the LL.
     -> Return the mid of LL.

    
    # Method 2 : Slow / Fast approach or Hare / Tortoise algorithm
     -> Slow moves with speed of 1 steps at a time
     -> Fast moves with speed of 2 steps at a 
     
     -> When fast reaches end of the node, slow will be at mid point of the node.

*/


ListNode* middleNode(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast != NULL){
            fast = fast -> next;
            if(fast != NULL){
                fast = fast -> next;
                // here we can say, fast has moved 2 steps and we can move slow 1 step

                slow = slow -> next;
            }
        }

        return slow;
}

int main(){

    return 0;
}