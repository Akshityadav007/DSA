#include<iostream>
#include<stack>
using namespace std;


// Problem || Leetcode : 394
/*
    -> Given an encoded string, return its decoded string.
    -> The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.
    -> You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. 
    -> For example, there will not be input like 3a or 2[4].
    -> The test cases are generated so that the length of the output will never exceed 105.
*/


// Solution
/*
    # Method 1 : Stack
        -> Solved it using stack

*/


string decodeString(string s) {
    stack<string> st;

    for(int i = 0;i < s.size(); i++){
        // got a closing bracket
        if(s[i] == ']'){
            string temp = "";

            // get the string
            while(!st.empty() && st.top() != "["){
                temp  = st.top() + temp;
                st.pop();
            }
            st.pop();       // remove '['

            // get the count
            string count = "";
            while(!st.empty() && st.top() >= "0" && st.top() <= "9"){
                count = st.top() + count;
                st.pop();
            }

            int cnt = stoi(count);
            string ans = "";
            while(cnt--)
                ans += temp;

            st.push(ans);               // push it back to the stack        
        }
        else{
            // either it is a number or letter or a closing bracket
            string str = "";
            str += s[i];
            st.push(str);
        }
    }


    string res = "";

    while(!st.empty()){
        res = st.top() + res;
        st.pop();
    }

    return res;
}


int main(){

    return 0;
}