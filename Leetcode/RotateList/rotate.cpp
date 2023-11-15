#include<iostream>
using namespace std;

// Problem || Leetcode : 61
/*
    -> Given the head of a linked list, rotate the list to the right by k places.
*/

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};



// Solution
int lengthLL(ListNode* head){
        int size = 0;
        ListNode *temp = head;
        while(temp){
            size++;
            temp = temp -> next;
        }
        return size;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        // empty list or single element list
        if(head == NULL || head -> next == NULL)
            return head;

        int size = lengthLL(head);
        k = k % size;
        
        while(k--){
            // get the previous of tail
            ListNode *tail = head;
            while(tail -> next -> next)
                tail = tail -> next;
            
            // rotate
            tail -> next -> next = head;
            head = tail -> next;
            tail -> next = NULL;           

        }
        return head;
    }

int main(){


    return 0;
}