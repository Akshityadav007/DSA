#include<iostream>
#include<stack>
#include<vector>
using namespace std;

// Problem || Leetcode : 739
/*
    -> Given an array of integers temperatures represents the daily temperatures.
    -> Return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature.
    -> If there is no future day for which this is possible, keep answer[i] == 0 instead.
*/

// Solution
/*
    -> We'll initially consider all temperatures to have 0 days to wait.
    -> Start traversing the array from last element, this will make us easier to get the next greater temperature as we'll have already traced it.
    -> Store index of all temperatures in a stack.
    -> Remove all temperature indices which are greater than current temperature, as we need to get the next peak from current element at the top.
    -> There will be two cases :
        - Case 1 : Stack becomes empty, i.e. there is no peak found from current temperature to last temperature.
        - Case 2 : Stack has an index left, this will give us the distance/days at which we'll have a peak from current temperature.
    -> For the current ans get the distance and push it.
    -> Push the current index in the stack, as this could now be a peak for upcoming temperatures.
*/


vector<int> dailyTemperatures(vector<int>& temperatures) {                     
    stack<int> st;
    int n = temperatures.size();
    vector<int> ans(n, 0);                                  // initialise all elements with 0 days

    for(int i = n - 1; i >= 0; i--){
        // pop elements smaller than or equal to current element from stack
        while(!st.empty() && temperatures[i] >= temperatures[st.top()])
            st.pop();
        
        // we only check for non empty stacks because if it is empty this means we don't have a peak post current element
        // and for every non empty stack at the top we'll have a peak for current element (temperature greater than current element)
        if(!st.empty())
            ans[i] = st.top() - i;              // distance between next greater element and current element
        
        st.push(i);                             // current element might be peak to some other element for next elements to come
    }
    
    return ans;
}

int main(){

    return 0;
}