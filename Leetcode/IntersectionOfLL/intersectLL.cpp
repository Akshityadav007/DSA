#include<iostream>
#include<unordered_map>
using namespace std;


// Problem || Leetcode : 160
/*
    -> Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect.
    -> If the two linked lists have no intersection at all, return null.
    -> For example, the following two linked lists begin to intersect at node c1:

        - The test cases are generated such that there are no cycles anywhere in the entire linked structure.
        - Note that the linked lists must retain their original structure after the function returns.

    -> Custom Judge:

        - The inputs to the judge are given as follows (your program is not given these inputs):

        - intersectVal - The value of the node where the intersection occurs. This is 0 if there is no intersected node.
        - listA - The first linked list.
        - listB - The second linked list.
        - skipA - The number of nodes to skip ahead in listA (starting from the head) to get to the intersected node.
        - skipB - The number of nodes to skip ahead in listB (starting from the head) to get to the intersected node.
        - The judge will then create the linked structure based on these inputs and pass the two heads, headA and headB to your program. 
        - If you correctly return the intersected node, then your solution will be accepted.
*/
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};


// Solution
/*
    # Method 1 : Hashmap

    # Method 2 : Two pointers
*/


ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    // use hashmap
    unordered_map <ListNode*, int> m;

    ListNode *curr = headA;
    while(curr!= NULL){
        m[curr] = 1;
        curr = curr -> next;
    }
    
    curr = headB;
    while(curr != NULL){
        if(m.find(curr) != m.end())
            return curr;
        curr = curr -> next;
    }
    return NULL;
}

// Method 2 :

int getSize(ListNode *head){
    int size = 0;
    while(head != NULL){
        size++;
        head = head -> next;
    }

    return size;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    
    // first align the nodes in same position
    int sizeA = getSize(headA);
    int sizeB = getSize(headB);

    while(sizeA > sizeB){
        headA = headA -> next;
        sizeA--;
    }
    while(sizeA < sizeB){
        headB = headB -> next;
        sizeB--;
    }

    // once aligned, check for common node and return it
    while(headA != NULL && headB != NULL && headA != headB){
        headA = headA -> next;
        headB = headB -> next;
    }

    if(headA == NULL || headB == NULL)
        return NULL;
    else
        return headA;
}

int main(){


    return 0;
}