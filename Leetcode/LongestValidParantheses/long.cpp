#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;


// Problem || leetcode : 32
/*
    -> Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses substring.
*/


// Solution
/*
    # Method 1 : Dp(I don't know where it is used)

*/


// Method 1

int longestValidParentheses(string s) {
    stack<int> st;
    st.push(-1);
    int ans = 0;
    for(int i = 0;i < s.length(); i++){
        int t = st.top();
        if(t != -1 && s[i] == ')' && s[t] == '('){
            // valid parentheses case
            st.pop();
            ans = max(ans, i - st.top());               // note it is st.top here, and not 't'
        }
        else
            st.push(i);
    }
    
    return ans;
}


int main(){


    return 0;
}