#include<iostream>
#include<map>
using namespace std;


// Problem || Leetcode : 1171
// Couldn't solve
/*
    -> Given the head of a linked list, we repeatedly delete consecutive sequences of nodes that sum to 0 until there are no such sequences.
    -> After doing so, return the head of the final linked list. 
    -> You may return any such answer.
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
    -> Not solved by me, still can't understand
*/

ListNode* removeZeroSumSublists(ListNode* head) {
    if(head == NULL)
        return 0;

    ListNode *result = new ListNode(0, head);      // to store prefix sum of head
    int sum = 0;
    map<int, ListNode*> prefix;                         // to store prefix sum
    prefix[sum] = result;

    ListNode *curr = head;
    while(curr != NULL){
        sum += curr -> val;
        prefix[sum] = curr;
        curr = curr -> next;
    }

    // we've stored all prefix sums
    sum = 0;
    curr = result;                                   // reset iterator to starting of first prefix

    // let us modify the list
    while(curr != NULL){
        sum += curr -> val;
        if(prefix[sum] != curr){
            // this means there is another element in linked list in the list further
            // so we skip the part in b/w
            curr -> next = prefix[sum] -> next;   
        }
        curr = curr -> next;
    }
    return result -> next;
}

int main(){


    return 0;
}