#include<iostream>
#include<stack>
#include<vector>
using namespace std;

// Problem || Leetcode : 150
/*
    -> You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.
    -> Evaluate the expression. Return an integer that represents the value of the expression.
    -> Note that:
        - The valid operators are '+', '-', '*', and '/'.
        - Each operand may be an integer or another expression.
        - The division between two integers always truncates toward zero.
        - There will not be any division by zero.
        - The input represents a valid arithmetic expression in a reverse polish notation.
        - The answer and all the intermediate calculations can be represented in a 32-bit integer.
*/


// Solution
/*
    # Method 1: Use stack
*/

int evalRPN(vector<string>& tokens) {
    stack<int> st;

    for(int i = 0;i < tokens.size(); i++){
        if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
            if(tokens[i] == "+"){
                int op1 = st.top();
                st.pop();
                int op2 = st.top();
                st.pop();
                int ans = op1 + op2;
                st.push(ans);
            }
            else if(tokens[i] == "-"){
                int op1 = st.top();
                st.pop();
                int op2 = st.top();
                st.pop();
                int ans = op2 - op1;
                st.push(ans);
            }
            else if(tokens[i] == "*"){
                int op1 = st.top();
                st.pop();
                int op2 = st.top();
                st.pop();
                int ans = op1 * op2;
                st.push(ans);
            }
            else{
                int op1 = st.top();
                st.pop();
                int op2 = st.top();
                st.pop();
                int ans = op2 / op1;
                st.push(ans);
            }
        }
        else{
            int curr = stoi(tokens[i]);
            st.push(curr);
        }
    }

    return st.top();
}



int main(){

    return 0;
}