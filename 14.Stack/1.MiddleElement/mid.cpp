#include<iostream>
#include<stack>
using namespace std;

// Problem || Similar to GFG question : Delete middle element of stack
/*
    -> Return the middle element of stack.
*/


// Solution
/*
    -> For even sized stack : size / 2
    -> For odd sized stack : (size / 2) + 1

    -> Use recursion to remove the top element and backtrack to store them back in stack.
*/

void solve(stack<int> &st, int mid, int &ans){
    // base case
    if(mid == 1){
        ans = st.top();
        return;
    }

    // 1 case to be solved
    int num = st.top();
    st.pop();
    solve(st, mid - 1, ans);

    // backtrack
    st.push(num);
}

int getMid(stack<int> &st){
    if(st.empty())
        return -1;
    int size = st.size();
    int mid = 0;

    if(size && 1)
        mid = (size / 2) + 1;
    else
        mid = size / 2;
    
    int ans = 0;
    solve(st, mid, ans);
    return ans;
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

    cout << getMid(st) << endl;

    return 0;
}