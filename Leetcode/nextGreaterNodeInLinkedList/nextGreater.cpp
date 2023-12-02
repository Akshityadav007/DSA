#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

// Problem || Leetcode : 1019
/*
    -> You are given the head of a linked list with n nodes.
    -> For each node in the list, find the value of the next greater node. 
    -> That is, for each node, find the value of the first node that is next to it and has a strictly larger value than it.
    -> Return an integer array answer where answer[i] is the value of the next greater node of the ith node (1-indexed). 
    -> If the ith node does not have a next greater node, set answer[i] = 0.
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
    # Method : Use stack
     -> Based on 'next smaller number' question
*/

ListNode *reverseLL(ListNode *&head){
        if(head == NULL || head -> next == NULL)
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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        stack<int> st;
        st.push(0);                 // last element will always have answer 0

        // first reverse the linked list
        head = reverseLL(head);

        // now try to get the answer
        ListNode *curr = head;
        while(curr != NULL){
            int num = curr -> val;          // current number

            // remove all elements greater than current number from stack
            while(st.top() != 0 && st.top() <= num)
                st.pop();
            
            ans.push_back(st.top());     // store the answer
            st.push(num);           // because num might be answer for the upcoming numbers

            curr = curr -> next;
        }

        // reverse the answer
        reverse(ans.begin(), ans.end());

        return ans;
    }

int main(){

    return 0;
}