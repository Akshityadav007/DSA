#include<iostream>
#include<deque>
#include<vector>
using namespace std;


// Problem || Leetcode : 239 (Hard)
/*
    -> You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right.
    -> You can only see the k numbers in the window.
    -> Each time the sliding window moves right by one position.
    -> Return the max sliding window.
*/

// Solution
/*
        # Method 1: (Brute force)
            -> Process every window
        
        # Method 2 : Use queue
            -> Use queue to store index of all maximum numbers.
            -> How to do that ?
            -> If the current element is bigger than the element at front() index, replace the fron index with current element index,
            -> else if it is small simply push it's index to the queue
            -> Note : the last window will be missed in this way, so handle it.
*/

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ans;
    deque<int> dq;                       // to store indices
    int maxi = INT_MIN;

    // first process the 'k' elements of 'nums'
    for(int i = 0;i < k;i++){
        int element = nums[i];

        // remove all elements smaller than curr element
        while(!dq.empty() && element > nums[dq.back()])
            dq.pop_back();
        
        // insert the current index
        dq.push_back(i);
    }

    // process the remaining windows
    for(int i = k;i < nums.size();i++){
        // store the ans
        ans.push_back(nums[dq.front()]);

        // removal
        // 1. out of range
        if(!dq.empty() && i - dq.front() >= k)
            dq.pop_front();
        
        // 2. smaller elements
        int element = nums[i];
        while(!dq.empty() && element > nums[dq.back()])
            dq.pop_back();
        
        // addition
        dq.push_back(i);
    }

    // last window
    ans.push_back(nums[dq.front()]);
    
    return ans;
}

int main(){


    return 0;
}