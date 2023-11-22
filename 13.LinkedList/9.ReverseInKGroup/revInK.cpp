#include<iostream>
using namespace std;

// Problem || Leetcode : 25
/*
    -> Given the head of a linked list, reverse the ListNodes of the list k at a time, and return the modified list.
    -> k is a positive integer and is less than or equal to the length of the linked list. 
    -> If the number of ListNodes is not a multiple of k then left-out ListNodes, in the end, should remain as it is.
    -> You may not alter the values in the list's ListNodes, only ListNodes themselves may be changed.
*/

class ListNode{

    public:
        int data;                   // data of the current ListNode
        ListNode *next;                 // pointer to store address of next 'ListNode'

        // default constructor
        ListNode(){
            this -> next = NULL;
        }

        // parameterized constructor
        ListNode(int val){
            this -> data = val;
            this -> next = NULL;
        }

};

// to print the linked list
void printLL(ListNode *&head){
    ListNode *curr = head;
    while(curr != NULL){
        cout << curr -> data << " -> ";
        curr = curr -> next;
    }
    cout << endl;
}



// Solution
/*
    -> Reverse first 'k' group.
    -> Rest work will be done by recursion.
*/


 int lengthLL(ListNode *&head){
        int size = 0;
        ListNode *curr = head;
        while(curr){
            size++;
            curr = curr -> next;
        }
        return size;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head -> next == NULL)
        return head;

        
        int len = lengthLL(head);
        if(len < k){
            // if 'k' is smaller than the required number of reversal nodes
            return head;
        }

        int pos = 0;
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *nextNode = curr -> next;
        while(pos < k && len >= k){
            nextNode = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = nextNode; 
            pos++;          
        }
        // when it reaches the last node
        if(nextNode == NULL){
            return prev;
        }
        // recursion
        ListNode *recursionAns = reverseKGroup(nextNode, k);
        head -> next = recursionAns;
        return prev;
}

int main(){

    return 0;
}