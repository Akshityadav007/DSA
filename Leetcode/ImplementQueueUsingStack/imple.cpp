#include<iostream>
#include<stack>
using namespace std;

// Problem || Leetcode : 232
/*
    Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

Implement the MyQueue class:

void push(int x) Pushes element x to the back of the queue.
int pop() Removes the element from the front of the queue and returns it.
int peek() Returns the element at the front of the queue.
boolean empty() Returns true if the queue is empty, false otherwise.
Notes:

You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.
*/


// Solution
class MyQueue {
public:
    stack<int> q;           // main stack which stores elements
    stack<int> helper;          // helper stack
    MyQueue() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        // transfer all stack elements to helper stack
        while(!q.empty()){
            helper.push(q.top());
            q.pop();
        }

        // remove top element from helper stack
        int ans = helper.top();
        if(!helper.empty())
            helper.pop();

        // transfer all elements back to main stack
         while(!helper.empty()){
            q.push(helper.top());
            helper.pop();
        }

        return ans;
    }
    
    int peek() {
         // transfer all stack elements to helper stack
        while(!q.empty()){
            helper.push(q.top());
            q.pop();
        }

        // store top element from helper stack
        int ans = helper.top();

        // transfer all elements back to main stack
         while(!helper.empty()){
            q.push(helper.top());
            helper.pop();
        }

        return ans;
    }
    
    bool empty() {
        return q.empty();
    }
};

int main(){

    return 0;
}