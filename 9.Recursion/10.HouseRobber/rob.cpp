#include<iostream>
using namespace std;

// Problem || Leetcode : 198
/*
    -> You are a professional robber planning to rob houses along a street.
    -> Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
    -> Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
*/

// Solution
/*
    # Method : Exploring -- Recursion (TLE)
    -> We check for every possible way.
    -> Two cases:
        - 1. We rob the current house (move from current house + 2 to last).
        - 2. We don't rob the current house (move from current house + 1 to last).
    -> We get the maximum of both the cases.

    -> Base case - when we are out of houses to rob.
*/

int solve(vector<int> &v,int index){
    int n = v.size();

    // base case
    if(index > v.size())
        return 0;

    // Processing + Function call
    // Case 1 : rob the current house
    int rob = v[index] + solve(v, index + 2);
    // Case 2 : don't rob the current house
    int dontRob = solve(v, index + 1);

    return max(rob, dontRob);
}

int rob(vector<int>& nums) {
    int n = nums.size();
    return solve(nums, 0);
}

int main(){
    vector<int> v{1,2,3,1};
    cout << rob(v) << endl;

    return 0;
}