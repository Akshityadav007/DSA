#include<iostream>
using namespace std;

// Problem || Leetcode : 83
/*
    -> Given the head of a sorted linked list, delete all duplicates such that each element appears only once. 
    -> Return the linked list sorted as well.
*/

class ListNode{

    public:
        int val;                   // data of the current ListNode
        ListNode *next;                 // pointer to store address of next 'ListNode'

        // default constructor
        ListNode(){
            this -> next = NULL;
        }

        // parameterized constructor
        ListNode(int val){
            this -> val = val;
            this -> next = NULL;
        }

};


// Solution

 ListNode* deleteDuplicates(ListNode* head) {
          if(head == NULL || head -> next == NULL)
        return head;
        ListNode *temp = head;
        while(temp){
            if(temp -> next && temp -> val == temp -> next -> val){
                // remove
                // isolate
                ListNode *nextListNode = temp -> next;
                temp -> next = temp -> next -> next;
                nextListNode -> next = NULL;

                delete(nextListNode);
            }
            else{
                temp = temp -> next;
            }
        }
        return head;
    }

int main(){


    return 0;
}