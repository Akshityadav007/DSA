#include<iostream>
#include<vector>
using namespace std;

// Problem || Leetcode : 300
/*
    -> Given an integer array nums, return the length of the longest strictly increasing subsequence.
*/


// Solution
/*
    # Method 1 : Recursion (TLE)
        ->  Use include/exclude method.


    # Method 2 : Dp - memoization

    # Method 3 : Dp - tabulation


    # Method 4 : Space optimization


    # **** Method 5 : Binary Search ****
        -> For every number check if we have a number just greater than the current number (lower bound), is yes replace it with current number.
        -> Else add the current number.

*/



// Method 1
class Solution {
public:
    int solve(vector<int> &nums, int prevIndex, int currIndex){
        // base case
        if(currIndex >= nums.size())
            return 0;

        int include = 0;
        if(prevIndex == -1 || nums[currIndex] > nums[prevIndex])
            include = 1 + solve(nums, currIndex, currIndex + 1);
            
        int exclude = 0 + solve(nums, prevIndex, currIndex + 1);

        int ans = max(include, exclude);

        return ans;

    }
    int lengthOfLIS(vector<int>& nums) {
        int ans = solve(nums, -1, 0);
        return ans;
    }
};

// Method 2
class Solution {
public:
    int solveUsingMemoization(vector<int> &nums, int prevIndex, int currIndex, vector< vector<int> > &dp){
        // base case
        if(currIndex >= nums.size())
            return 0;

        // check in dp
        if(dp[currIndex][prevIndex + 1] != -1)
            return dp[currIndex][prevIndex + 1];

        int include = 0;
        if(prevIndex == -1 || nums[currIndex] > nums[prevIndex])
            include = 1 + solveUsingMemoization(nums, currIndex, currIndex + 1, dp);

        int exclude = 0 + solveUsingMemoization(nums, prevIndex, currIndex + 1, dp);

        dp[currIndex][prevIndex + 1] = max(include, exclude);

        return dp[currIndex][prevIndex + 1];

    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();   
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));            
        int ans = solveUsingMemoization(nums, -1, 0, dp);
        return ans;
    }
};


// Method 3 : Dp - Tabulation
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();   
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0)); 
        
        for(int currIndex = n - 1; currIndex >= 0; currIndex--){
            for(int prevIndex = n - 1; prevIndex >= -1; prevIndex--){
                int include = 0;
                if(prevIndex == -1 || nums[currIndex] > nums[prevIndex])
                    include = 1 + dp[currIndex + 1][currIndex + 1];

                int exclude = 0 + dp[currIndex + 1][prevIndex + 1];

                dp[currIndex][prevIndex + 1] = max(include, exclude);
            }
        }

        return dp[0][0];
    }
};


// Method 4 : Space optimization
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();   
        vector<int> currRow(n + 1, 0); 
        vector<int> nextRow(n + 1, 0);
        
        for(int currIndex = n - 1; currIndex >= 0; currIndex--){
            for(int prevIndex = n - 1; prevIndex >= -1; prevIndex--){
                int include = 0;
                if(prevIndex == -1 || nums[currIndex] > nums[prevIndex])
                    include = 1 + nextRow[currIndex + 1];

                int exclude = 0 + nextRow[prevIndex + 1];

                currRow[prevIndex + 1] = max(include, exclude);
            }
            // shifting
            nextRow = currRow;
        }

        return nextRow[0];
    }
};


// Method 5 : Binary search
class Solution {
public:
    int solveUsingBinarySearch(vector<int> &nums){
        vector<int> ans;
        ans.push_back(nums[0]);             //  initial state

        for(int i = 1;i < nums.size(); i++){
            if(nums[i] > ans.back())
                ans.push_back(nums[i]);
            else{
                int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();

                // replace
                ans[index] = nums[i];
            }
        }
        return ans.size();
    }
    int lengthOfLIS(vector<int>& nums) {
        return solveUsingBinarySearch(nums);  
    }
};

int main(){

    return 0;
}