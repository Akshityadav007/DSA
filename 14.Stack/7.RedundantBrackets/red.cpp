#include<iostream>
#include<stack>
using namespace std;

// Problem || Coding Ninjas : Easy
/*
    -> Given valid mathematical expressions in the form of a string. 
    -> You are supposed to return true if the given expression contains a pair of redundant brackets, else return false.
    -> The given string only contains '(',')','+','-','*','/' and lowercase Englise letters.

    Note:
    -> A pair of brackets is said to be redundant when a subexpression is surrounded by needless/useless brackets.
*/

// Solution
/*
    -> We use stack.
    -> We ignore english letters.
    -> If we find an opening bracket or operator we push it.
    -> If we find a closing bracket we match it with the last pushed element.

    -> If the last pushed element is an operator, we pop out last pushed operator and the opening bracket(there won't be any closing tag in the stack) with it, else return false
    -> At last we check if the stack is empty, if it is return true else false
    -> Actually we need not check at last, because it is a valid mathematical expression, hence it will be empty if we reach the end
*/

bool findRedundantBrackets(string &s)
{
    stack<char> st;
    for(int i = 0;i < s.length();i++){
        if(s[i] == '(' || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
            st.push(s[i]);
        else if(s[i] == ')'){
            int operatorCount = 0;
            while(!st.empty() && st.top() != '('){
                if(st.top() == '-' || st.top() == '+' || st.top() == '*' || st.top() == '/'){
                    operatorCount++;
                }
                st.pop();
            }
            st.pop();
            if(operatorCount == 0)
                return true;
        }
    }
    return false;    
}

int main(){


    return 0;
}