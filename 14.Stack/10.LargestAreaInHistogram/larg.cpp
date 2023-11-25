#include<iostream>
#include<vector>
#include<stack>
using namespace std;

// Problem || Leetcode : 84
// Revise 'Next smaller' question.
// Couldn't solve it on my own, took Babbar's help.
/*
    -> Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.
*/


// Solution
/*
    -> We'll extend in both left/right direction (if possible) and collect the area.
    -> We can move in a direction if on the direction of movement the bar value is equal or greater than the current bar.

    -> We need to know the bar values upto which we can stretch for current bar value, so for that we need to know 'next smaller element' and 'previous smaller element'.
    -> Only change here is that the values here are written on the basis of 'index'. So we'll amend the code accordingly.

*/

vector<int> nextSmaller(vector<int> &arr){
    int n = arr.size();
    vector<int> ans(n, 0);
    stack<int> s;
    s.push(-1);

    for(int i = n - 1;i >= 0;i--){

        while(s.top() != -1 && arr[s.top()] >= arr[i])
            s.pop();
        
        ans[i] = s.top();
        s.push(i);                      // changed this as we need to get the indexes not the values
    }

    return ans;
}

vector<int> prevSmaller(vector<int> &arr){
    int n = arr.size();
    vector<int> ans(n, 0);
    stack<int> s;
    s.push(-1);

    for(int i = 0;i < n;i++){

        while(s.top() != -1 && arr[s.top()] >= arr[i])
            s.pop();
        
        ans[i] = s.top();
         s.push(i);
    }

    return ans;
}


int largestRectangleArea(vector<int>& heights) {
    
    vector<int> next = nextSmaller(heights);

    // no element's next smaller can be -1 (can be for previous though), so we change it
    for(int i = 0;i < next.size(); i++){
        // because if there is no element smaller than the current element, that means we need to extend it to the right most bar
        if(next[i] == -1)
            next[i] = heights.size();
    }

    vector<int> prev = prevSmaller(heights);

    int maxArea = INT_MIN;
    for(int i = 0;i < heights.size(); i++){
        int width = next[i] - prev[i] - 1;
        int length = heights[i]; 
        int area = length * width;

        maxArea = max(maxArea, area);
    }

    return maxArea;     
}


int main(){


    return 0;
}