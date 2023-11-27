#include<iostream>
#include<queue>
#include<stack>
using namespace std;

// Problem : 1 || Coding Ninjas - Easy
/*
    -> You have been given a queue of 'N' distinct integers. For a given queue, you need to reverse all elements in it.
*/

// Problem : 2 || Coding Ninjas - Easy
/*
    -> Reverse first 'k' elements in queue.
*/


// Solution 1
/*  
    # Method : 1
    -> Use stack to reverse it.

    # Method : 2
    -> Use recursion
*/


// Method : 1
void reverse(queue < int > & q) {
    // we can use stack to reverse
    // also we'll keep removing elements in the 'q' as we insert it in stack, so space complexity is maintained to O(n) only.
    stack<int> st;
    while(!q.empty()){
        st.push(q.front());
        q.pop();
    }

    // now insert back into the queue
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
}


// # Method : 2
void reverse(queue < int > & q) {
    // base case
    if(q.empty())
        return;
    
    int temp = q.front();
    q.pop();
    reverse(q);
    q.push(temp);
}



// Solution 1
/*
    -> First put 'k' elements in stack
    -> Insert them in queue
    -> Now re - position the remaining elements of queue to the back
*/

// Solution 2
queue<int> reverseElements(queue<int> q, int k)
{
    stack<int> st;
    for(int i = 0;i < k;i++){
        st.push(q.front());
        q.pop();
    }
    
    // now push the elements from stack to queue
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }

    // now re - position the elements
    for(int i = 0;i < q.size() - k;i++){
        int num = q.front();
        q.pop();
        q.push(num);
    }

    return q;

}

int main(){


    return 0;
}