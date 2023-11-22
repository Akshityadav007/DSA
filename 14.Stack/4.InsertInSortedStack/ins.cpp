#include<iostream>
#include<stack>
using namespace std;

// Problem || 
/*
    -> Insert an element in the given sorted stack
*/


// Solution
/*
    -> Same pattern as of 'insertAtBottom' question.
*/


void insertSorted(stack<int> &s, int element){
    // base case
    if(s.empty() || element > s.top()){
        s.push(element);
        return;
    }

    int num = s.top();
    s.pop();
    insertSorted(s, element);

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

    insertSorted(st, 25);
    
    printStack(st);

    
    return 0;
}