#include<iostream>
#include<vector>
#include<queue>
using namespace std;


// Problem || Leetcode : 23
/*
    -> You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
    -> Merge all the linked-lists into one sorted linked-list and return it.
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
    # Method 1 : Brute force
        -> Get a merge function to merge 2 sorted lists.
        -> Get the first two lists merged and return them as a new list.
        -> Now do the same for next 'k - 2' lists.

        -> T.C. - O(n ^ 2) || S.C. - O(1)
    
    # Method 2 : Optimized
        -> Use priority queue (min - heap).

*/

class compare{
    public:
        bool operator()(ListNode *a, ListNode *b){
            return a -> val > b -> val;
        }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, compare> pq;

    // process first 'k' elements
    for(int i = 0; i < lists.size(); i++){
        ListNode *listHead = lists[i];
        if(listHead != NULL)                       // handle empty list
        pq.push(listHead);
    }
    
    // ans list
    ListNode *head = NULL;
    ListNode *tail = NULL;

    while(!pq.empty()){
        ListNode *topNode = pq.top();
        pq.pop();

        if(head == NULL){
            // first node
            head = topNode;
            tail = topNode;
        }
        else{
            tail -> next = topNode;
            tail = topNode;
        }
        
        // insert next node in queue
        if(tail -> next != NULL)
            pq.push(tail -> next);
    }

    return head;
}


int main(){


    return 0;
}