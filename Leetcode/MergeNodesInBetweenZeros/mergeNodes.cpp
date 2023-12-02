#include<iostream>
using namespace std;

// Problem || Leetcode : 2181
/*
    -> You are given the head of a linked list, which contains a series of integers separated by 0's. 
    -> The beginning and end of the linked list will have Node.val == 0.
    -> For every two consecutive 0's, merge all the nodes lying in between them into a single node whose value is the sum of all the merged nodes. 
    -> The modified list should not contain any 0's.
    -> Return the head of the modified linked list.
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
    # Method : Simple Brute force

*/

ListNode* mergeNodes(ListNode* head) {
    ListNode *ans = new ListNode();             // node to carry answer
    ans = NULL;
    ListNode *curr = head -> next;              // start from next node to head as head is 0

    ListNode *currAns;                          // pointer to traverse through ans node
    int sum = 0;                                // initially sum b/w nodes
    while(curr != NULL){
        // if we hit 0
        if(curr -> val == 0){
            ListNode *newNode = new ListNode(sum);
            // first node
            if(ans == NULL){
                ans = newNode;
                currAns = ans;
            }
            else{
                currAns -> next = newNode;
                currAns = currAns -> next;
            }
            sum = 0;                            // reset sum
        }
        else
            sum += curr -> val;
        curr = curr -> next;
    }
    return ans;
}

int main(){


    return 0;
}