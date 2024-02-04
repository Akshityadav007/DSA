#include<iostream>
#include<stack>
using namespace std;


// Problem || Leetcode : 1003
/*

*/


// Solution
/*
    # Method 1 : Recursion (Memory Limit Exceed / TLE)
        -> Used inclusion/ exclusion

    # Method 2 : Use stack
        -> Same as valid parenthesis solution.
        -> Only in this we also need to push and pop 'b'.
*/

bool isValid(string s) {
    // like valid parenthesis - 'a' = '(' and 'c' = ')'
    // 'b' is also there in this
    stack<char> st;
    if(s.size() < 3 || s[0] != 'a')
        return false;
    
    for(char &ch : s){
        if(ch == 'a')
            st.push(ch);
        else{
            if(st.empty())
                return false;
            else{
                if(ch == 'b'){
                    if(st.top() != 'a')
                        return false;
                    else
                        st.push(ch);
                }
                else if(ch == 'c'){
                    if(st.top() != 'b')
                        return false;
                    else{
                        // double pop
                        st.pop();       // 'b' popped
                        if(st.empty())
                            return false;
                        st.pop();       // 'a' poppped
                    }
                }
            }
        }
    }

    return st.empty();
}

int main(){

    return 0;
}