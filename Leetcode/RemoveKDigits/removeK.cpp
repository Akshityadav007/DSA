#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;


// Problem || Leetcode : 402
/*
    -> Given string num representing a non-negative integer num, and an integer k, 
    -> return the smallest possible integer after removing k digits from num.

*/



// Solution

string removeKdigits(string num, int k) {
    string ans = "";       // default answer
    
    /*
        -> To get minimum of a number, what is the condition ? 
            - Keep the smallest to the left (most significant) and greatest to the right (least significant).
        -> So, we'll traverse the string from the right, and make sure we are not adding any element greater than the last element (more significant than current).
        -> If we find any such element, we immediately replace the last significant element with the current element.

        -> After doing this make sure 'k' is fully used, if left (if all numbers were monotonically increasing , like "6789"), perfrom pop.
    */

    stack <char> st;    

    for(int i = 0;i < num.size(); i++){
        while(k > 0 && !st.empty() && num[i] < st.top()){
            // first remove all elements greater than current element in stack
            --k;
            st.pop();
        }

        st.push(num[i]);            // add / replace the current element

        if(st.size() == 1 && num[i] == '0')
            st.pop();                        // remove any preceding zeroes
    }

    // handle monotonically increasing strings
    while(k > 0 && !st.empty()){
        --k;
        st.pop();
    }

    // build the result
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());

    if(ans.length() == 0)
        ans = "0";

    return ans;
}



int main(){

    return 0;
}