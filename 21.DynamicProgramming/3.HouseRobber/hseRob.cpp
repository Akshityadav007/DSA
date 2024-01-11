#include<iostream>
#include<vector>
using namespace std;

// Problem || Leetcode : 198
/*
    -> You are a professional robber planning to rob houses along a street. 
    -> Each house has a certain amount of money stashed, 
    -> the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
    -> Given an integer array nums representing the amount of money of each house.
    -> return the maximum amount of money you can rob tonight without alerting the police.

*/


// Solution
/*
    # Method 1 : Recursion (TLE)
        - Use inclusion/exclusion principle.
    
    # Method 2 : Dp (memoization)
    
    # Method 3 : Dp (tabulation - bottom up)

    # Method 4 : Space optimzed


*/

// Method 2 : Memoization
class Solution {
public:
    int solveUsingMemoization(vector<int> &nums, int index, vector<int> &dp){
        // base case
        if(index >= nums.size())
            return 0;
        
        if(dp[index] != -1)
            return dp[index];
        
        int include = nums[index] + solveUsingMemoization(nums, index + 2, dp);
        int exclude = 0 + solveUsingMemoization(nums, index + 1, dp);
        
        dp[index] = max(include, exclude);

        return dp[index];
    }
    int rob(vector<int>& nums) {
        // step 1:
        vector<int> dp(nums.size(), -1);
        int index = 0;
        int ans = solveUsingMemoization(nums, index, dp);
        return ans;
    }
};


// Method 3 : Tabulation
int rob(vector<int>& nums) {
    int n = nums.size();
    // step 1 :
    vector<int> dp(n, -1);

    // step 2 :
    dp[n - 1] = nums[n - 1];
    

    // step 3 :
    for(int index = n - 2; index >= 0; index--){

        int include = index + 2 < n ? (nums[index] + dp[index + 2]) : nums[index];              // handle out of bound case        
        int exclude = 0 + dp[index + 1];

        dp[index] = max(include, exclude);
    }

    return dp[0];
}


// Method 4 : Space optimization - O(1)
int rob(vector<int>& nums) {
    int n = nums.size();

    int curr = 0;
    int next = nums[n - 1];
    int nextNext = 0;
    
    for(int index = n - 2; index >= 0; index--){

        int include = nums[index] + nextNext;
        int exclude = 0 + next;

        curr = max(include, exclude);
        
        nextNext = next;
        next = curr;
    }

    return next;
}


int main(){

    return 0;
}