#include<iostream>
#include<stack>
using namespace std;

// Problem || 
/*
    -> Reverse the given stack
*/


// Solution
/*
    -> Same pattern as of 'insertAtBottom' question.
*/

void insertAtBottom(stack<int> &s, int data){
    // base case
    if(s.size() == 0){
        s.push(data);
        return;
    }

    // operation
    int num = s.top();
    s.pop();

    // recursion
    insertAtBottom(s, data);

    // backtrack
    s.push(num);
}


void reverseStack(stack<int> &s){
    // base case
    if(s.empty())
        return;
    
    // operation
    int num = s.top();
    s.pop();
    reverseStack(s);

    insertAtBottom(s, num);
}

void printStack(stack<int> s){
    while(!s.empty()){
        cout << s.top() << endl;
        s.pop();
    }
}

int main(){
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);
    st.push(70);
    st.push(80);

    printStack(st);

    reverseStack(st);
    
    printStack(st);

    
    return 0;
}