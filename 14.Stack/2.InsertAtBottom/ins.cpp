#include<iostream>
#include<stack>
using namespace std;

// Problem || 
/*
    -> Insert an element at the bottom of a stack
*/


// Solution
/*
    -> Same pattern as of 'middle element' question.
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

    insertAtBottom(st, 5);
    printStack(st);

    
    return 0;
}