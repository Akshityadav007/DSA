#include<iostream>
using namespace std;

// Problem || Leetcode : 213
/*
    -> You are a professional robber planning to rob houses along a street. 
    -> Each house has a certain amount of money stashed. 
    -> All houses at this place are arranged in a circle. 
    -> That means the first house is the neighbor of the last one. 
    -> Meanwhile, adjacent houses have a security system connected, 
        and it will automatically contact the police if two adjacent houses were broken into on the same night.
    
    -> Given an integer array nums representing the amount of money of each house, 
        return the maximum amount of money you can rob tonight without alerting the police.

*/

// Solution
/*
    -> The houses are in circular form.
    -> Hence, there are two edge cases:
        - 1. If we are on the first house, it is sure we won't be robbing last house.
        - 2. If we are on the last house, it is sure we won't be robbing first house.
    -> Our solution will be similar to " HOUSE ROBBER " question, only difference will be -
    -> For these two cases:
        - Case 1. Consider first house and don't consider last house.
        - Case 2. Consider last house and don't consider first house.
    -> Lastly take the maximum of both the cases to get the maximum loot possible.

    -> There will be additional edge case when there will be only one house.
*/

int solve(vector<int> &v, int start, int end){
    // base case
    if(start > end)
        return 0;
    
    // rob it
    int robIt = v[start] + solve(v, start + 2, end);

    // don't rob
    int dontRob = solve(v, start + 1, end);

    return max(robIt, dontRob);
}

int rob(vector<int> &nums){
    // size of nums
    int n = nums.size();

    // what if there is only one house #edge case
    if(n == 1)
        return nums[0];                // loot only one house

    // two edge cases
    int case1 = solve(nums, 0, n - 2);          // consider first house and not last
    int case2 = solve(nums, 1, n - 1);          // consider last house and not first

    return max(case1, case2);
}

int main(){
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(2);

    cout << rob(nums) << endl;

    return 0;
}