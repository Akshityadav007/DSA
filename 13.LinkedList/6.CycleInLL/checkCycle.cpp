#include<iostream>
#include<map>
using namespace std;

// Problem || Leetcode : 141
/*
    -> Given head, the head of a linked list, determine if the linked list has a cycle in it.
    -> There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
    -> Return true if there is a cycle in the linked list. Otherwise, return false.
*/

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

// Solution
/*
     # Method 1 : Using map
        -> Map all nodes with their 'address' as their key.
        -> Once we get repeated value, we know there is a loop.

    # Method 2 : Slow / fast pointer
        -> Run slow and fast pointers.
        -> If they meet at any point, there is a loop.
        -> Or if fast reaches null, there is no loop.
*/

// Method 1
bool hasCycle(ListNode *head) {
    map < ListNode*, bool > mapping;

    ListNode *temp = head;

    while(temp != NULL){
        if(mapping[temp] == false){
            mapping[temp] = false;
        }
        else{
            return true;
        }
            temp = temp -> next;
    }
    return false;
}


// Method 2
 bool hasCycle2(ListNode *head) {
        if(head == NULL)
            return false;
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast != NULL){
            fast = fast -> next;
            if(fast != NULL){
                fast = fast -> next;
                slow = slow -> next;
                if(fast == slow)
                    return true;
            }  
        }
        return false;
        }

int main(){

    return 0;
}