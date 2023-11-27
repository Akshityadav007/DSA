#include<iostream>
using namespace std;


// Problem || Leetcode : 19
/*
    -> Given the head of a linked list, remove the nth node from the end of the list and return its head.
*/

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode *reverseList(ListNode *&head) {
    if(head == NULL)
        return head;
    ListNode *curr = head;
    ListNode *prev = NULL;
    do{
        ListNode *temp = curr;
        curr = curr -> next;
        temp -> next = prev;
        prev = temp;
    }
    while(curr != NULL);
    return prev;
}

ListNode* removeNthFromEnd(ListNode* head, int n) {
    // reverse the list
    // remove 'nth' node
    // reverse it again

    if(head == NULL)
        return head;
    
    head = reverseList(head);

    ListNode *prevNode = NULL;              // node previous to the node to be deleted
    ListNode *currNode = head;              // node to be deleted
    while(n > 1){
        prevNode = currNode;
        currNode = currNode -> next;
        n--;
    }

    // if originally n == 1
    if(prevNode == NULL)
        head = currNode -> next;
    else
        prevNode -> next = currNode -> next;
    
    currNode -> next = NULL;
    delete(currNode);
    
    head =reverseList(head);

    return head;    
}

int main(){


    return 0;
}