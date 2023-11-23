#include<iostream>
using namespace std;

// Problem || Leetcode : 82
/*
    -> Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. 
    -> Return the linked list sorted as well.
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
    -> We move in the List and keep checking if next element is same as current element.
    -> We delete the duplicate elements marking the limit.
*/


void deleteNodes(ListNode *&from, ListNode *&to){
    while(from != to){
        ListNode *temp = from;
        from = from -> next;
        delete temp;
    }
    delete to;
}

ListNode* deleteDuplicates(ListNode* head) {
    if(head == NULL || head -> next == NULL)
        return head;

    ListNode *curr = head;
    ListNode *prev = NULL;
    
    while(curr != NULL){
        ListNode *limit = curr;

        while(limit -> next != NULL && limit -> val == limit -> next -> val)
            limit = limit -> next;
        
        
        // duplicate present ?
        if(limit != curr){
            // what if duplicates are present in starting ?
            if(prev == NULL){
                head = limit -> next;
                limit -> next = NULL;
                deleteNodes(curr, limit);
                curr = head;
            }
            else{
                prev -> next = limit -> next;
                limit -> next = NULL;
                deleteNodes(curr, limit);
                curr = prev;
            }
        }
        else{
            prev = curr;
            if(curr != NULL)
                curr = curr -> next;
        }
    }

    return head;
}



int main(){


    return 0;
}