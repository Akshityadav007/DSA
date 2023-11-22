#include<iostream>
#include<stack>
using namespace std;

// Problem || 
/*
    -> Sort the given stack
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

void sortStack(stack<int> &s){
    if(s.empty())
        return;
    
    int num = s.top();
    s.pop();
    sortStack(s);


    // backtrack - we need to insert but like insertedSorted question
    insertSorted(s, num);
}

void printStack(stack<int> s){
    while(!s.empty()){
        cout << s.top() << endl;
        s.pop();
    }
}

int main(){
    stack<int> st;
    st.push(40);
    st.push(20);
    st.push(3);
    st.push(32);
    st.push(50);
    st.push(0);
    st.push(70);
    st.push(10);

    sortStack(st);
    
    printStack(st);

    
    return 0;
}