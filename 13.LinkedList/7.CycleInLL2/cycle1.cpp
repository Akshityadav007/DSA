#include<iostream>
using namespace std;

// Problem || Leetcode : 142
/*
    -> Given the head of a linked list, return the node where the cycle begins. 
    -> If there is no cycle, return null.
    -> There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. 
    -> Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). 
    -> It is -1 if there is no cycle. Note that pos is not passed as a parameter.
    -> Do not modify the linked list.
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Solution
/*
    -> Check if loop is present using slow / fast pointer.                          # NOTE : Slow / fast need not necessarily meet at  the starting point of loop.
    -> If not present return NULL, else
    -> Step 1) Point slow to head.
    -> Step 2) Move slow and fast one step each.
    -> Step 3) They'll meet at the starting point of loop.


    -> Why do they meet at starting point of loop ? 
        => At the end of the loop i.e. 'node before starting point of the loop', slow would have moved 'n' steps and fast would have moved '2n' steps.
        => This means slow is at mid point of list and fast is at end of list.

        < Distance travelled by 'fast' = 2 * Distance travelled by 'slow'. >

        => Now as they move and meet at a point in loop, let's solve this mathematically

        - Let distance from start to starting of loop be 'A'.
        - Let distance from starting of loop to point of meet be 'B'.
        - Let the distance of loop be 'C'.

        - So, we can say that,
            Distance travelled by 'fast' = 2 * Distance travelled by 'slow'
            A + k1 * C + B               = 2 * [A + k2 * C + B]                             , here k1 and k2 are number of times 'fast' and 'slow' encircle the loop before they meet
            A + k1 * C + B               = 2A + 2k2C + 2B
            k1 * C + 2 k2 * C            = A + B

            A + B = k * C                                               , where k is a constant.

        - Now let's get the distance between fast (still at point of meet) and the starting point of loop
            => Distance of loop = C
            => Distance of meet = B
            => Remaining distance = C - B
            => But it is not necessary that 'fast' will meet 'slow' at starting point after one loop, it might take some amount of circles = x * C
            => Remaining distance = (C - B) + x * C

        - On closely looking the remaining distance,
            (C - B) + x * C = A                                             (from the previous expression)
            Hence, remaining distance is 'A'.

        => And this is why both are equidistant from each other if we start 'slow' from 'head'.

    -> It doesn't matters how many circles it does, it will come to the same point. (because in a circle it will traverse constant number of nodes in any number of circles)


*/

//   Additional problem : Remove the cycle from linked list

ListNode *getStartingPointOfLoop(ListNode *head){
    ListNode *fast = head;
    ListNode *slow = head;

    while(fast != NULL){
        fast = fast -> next;

        if(fast != NULL){
            fast = fast -> next;
            slow = slow -> next;
            if(slow == fast)
                break;
        }
    }
    slow = head;

    while(fast != slow){
        slow = slow -> next;
        fast = fast -> next;
    }
    return slow;
}

ListNode *detectCycle(ListNode *head) {
    ListNode *fast = head;
    ListNode *slow = head;
    bool cyclePresent = false;

    while(fast != NULL){
        fast = fast -> next;
        if(fast != NULL){
            fast = fast -> next;
            slow = slow -> next;

            if(slow == fast){
                cyclePresent = true;
                break;
            }
        }
    }
    if(cyclePresent)
        return getStartingPointOfLoop(head);
    else
        return NULL;
}



int main(){


    return 0;
}