#include<iostream>
#include<vector>
using namespace std;


// Problem || Leetcode : 416
/*
    -> Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.
*/

// Solution
/*
    -> Instead of searching for two subsets, we take sum of whole array and search if there exists a subset having sum / 2 as it's sum of elements.
    # Method 1 : Recursion 
        -> Use include/exclude.
    
    # Method 2 : Dp - memoization

    # Method 3 : Dp - tabulation

    # Method 4 : Space optimized
    

*/

// Method 1
class Solution {
public:
    bool solve(vector<int> &nums, int index, int currSum, int target){
        // base case
        if(index >= nums.size() || currSum > target)
            return false;
        if(currSum == target)
            return true;
        
        // recursion
        bool include = solve(nums, index + 1, currSum + nums[index], target);
        bool exclude = solve(nums, index + 1, currSum, target);

        
        return include || exclude;
    }
    bool canPartition(vector<int>& nums) {
        // first get sum of nums
        int sum = 0;
        for(auto i : nums)
            sum += i;
        
        // search if any subset exists with sum of elements = sum / 2
        if(sum & 1)
            return false;               // there can't be partition for odd sum
        return solve(nums, 0, 0, sum / 2);
    }
};


// Method 2 : Dp - memoization
class Solution {
public:
    bool solveUsingMemoization(vector<int> &nums, int index, int currSum, int target, vector< vector<int> > &dp){
        // base case
        if(index >= nums.size() || currSum > target)
            return 0;
        if(currSum == target)
            return 1;
        
        if(dp[index][currSum] != -1)
            return dp[index][currSum];

        // recursion
        bool include = solveUsingMemoization(nums, index + 1, currSum + nums[index], target, dp);
        bool exclude = solveUsingMemoization(nums, index + 1, currSum, target, dp);

        return dp[index][currSum] = (include || exclude);
    }
    bool canPartition(vector<int>& nums) {
        // first get sum of nums
        int sum = 0;
        for(auto i : nums)
            sum += i;
        
        // search if any subset exists with sum of elements = sum / 2
        if(sum & 1)
            return false;               // there can't be partition for odd sum
        
        int n = nums.size();
        vector< vector<int> > dp(n + 1, vector<int> (sum + 1, -1));
        return solveUsingMemoization(nums, 0, 0, sum / 2, dp);
    }
};


// Method 3 : Dp - tabulation
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // first get sum of nums
        int sum = 0;
        for(auto i : nums)
            sum += i;
        
        // search if any subset exists with sum of elements = sum / 2
        if(sum & 1)
            return false;               // there can't be partition for odd sum
        
        int n = nums.size();
        vector< vector<int> > dp(n + 2, vector<int> (sum + 1, 0));

        // base case analysis
        for(int row = 0; row <= n; row++)
            dp[row][sum / 2] = 1;

        for(int index = n - 1; index >= 0; index--){
            for(int s = sum / 2; s >= 0; s--){
                bool include = 0;
                if(s + nums[index] <= sum / 2)
                    include = dp[index + 1][s + nums[index]];

                bool exclude = dp[index + 1][s];
                dp[index][s] = (include || exclude);
            }
        }

        return dp[0][0];
    }
};


// Method 4 : Space optimized
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // first get sum of nums
        int sum = 0;
        for(auto i : nums)
            sum += i;
        
        // search if any subset exists with sum of elements = sum / 2
        if(sum & 1)
            return false;               // there can't be partition for odd sum
        
        int n = nums.size();
        int target = sum / 2;
        vector<int> curr(target + 1, 0);
        vector<int> next(target + 1, 0);

        curr[target] = 1;
        next[target] = 1;

        for(int index = n - 1; index >= 0; index--){
            for(int s = target; s >= 0; s--){
                bool include = 0;
                if(s + nums[index] <= target)
                    include = next[s + nums[index]];

                bool exclude = next[s];
                curr[s] = (include || exclude);
            }
            // shifting
            next = curr;
        }

        return next[0];
    }
};


int main(){

    return 0;
}