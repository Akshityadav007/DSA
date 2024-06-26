#include<iostream>
#include<queue>
using namespace std;


// Problem || Leetcode : 225
/*
    -> Implement a last-in-first-out (LIFO) stack using only two queues. 
    -> The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).
    -> Implement the MyStack class:
        - void push(int x) Pushes element x to the top of the stack.
        - int pop() Removes the element on the top of the stack and returns it.
        - int top() Returns the element on the top of the stack.
        - boolean empty() Returns true if the stack is empty, false otherwise.
    -> Notes:
        - You must use only standard operations of a queue, which means that only push to back, peek/pop from front, size and is empty operations are valid.
        - Depending on your language, the queue may not be supported natively. 
        - You may simulate a queue using a list or deque (double-ended queue) as long as you use only a queue's standard operations.

*/


// Solution
class MyStack {
public:
    queue<int> q;
    int topElement = -1;

    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        this -> topElement = x;
    }
    
    int pop() {
        int sizeSt = q.size() - 1;

        // bring the last element to the front
        while(sizeSt--){
            int temp = q.front();
            q.pop();
            q.push(temp);

            this -> topElement = temp;
        }

        int ans = q.front();
        q.pop();

        return ans;
    }
    
    int top() {
        return this -> topElement;
    }
    
    bool empty() {
        return q.empty();
    }
};


int main(){


    return 0;
}