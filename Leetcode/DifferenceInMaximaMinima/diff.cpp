#include<iostream>
#include<vector>
using namespace std;

// Problem || Leetcode : 2058
/*
    A critical point in a linked list is defined as either a local maxima or a local minima.

A node is a local maxima if the current node has a value strictly greater than the previous node and the next node.

A node is a local minima if the current node has a value strictly smaller than the previous node and the next node.

Note that a node can only be a local maxima/minima if there exists both a previous node and a next node.

Given a linked list head, return an array of length 2 containing [minDistance, maxDistance] where minDistance is the minimum distance between any two distinct critical points and maxDistance is the maximum distance between any two distinct critical points. If there are fewer than two critical points, return [-1, -1].
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
    

*/

 vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans = {-1,-1};          // initially answer
        
        // if list is of two or less elements
        if(head == NULL || head -> next == NULL || head -> next -> next == NULL)
            return ans;

        ListNode *prev = head;
        ListNode *curr = head -> next;
        ListNode *nextNode = curr -> next;

        vector<int> index;                      // to store all indices of critical points
        int count = 1;
        while(nextNode != NULL){
            ++count;
            // minima
            if(curr -> val < prev -> val && curr -> val < nextNode -> val)
                index.push_back(count);
            // maxima
            else if(curr -> val > prev -> val && curr -> val > nextNode -> val)
                index.push_back(count);
            
            prev = prev -> next;
            curr = curr -> next;
            nextNode = nextNode -> next;
        }
        // if there are no or only one maxima / minima
        if(index.empty() || index.size() == 1)
            return ans;

        // now let's get the answer
        int minDistance = INT_MAX;
        int maxDistance = index[index.size() - 1] - index[0];               // diff b/w greatest and smalllest index
        for(int i = 1;i < index.size(); i++)
            minDistance = min(minDistance, index[i] - index[i - 1]);
        

        ans[0] = minDistance;
        ans[1] = maxDistance;

        return ans;
    }

int main(){

    return 0;
}