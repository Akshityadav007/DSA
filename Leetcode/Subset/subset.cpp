#include<iostream>
using namespace std;

// Problem || Leetcode : 78
/*
    -> Given an integer array nums of unique elements, return all possible subsets (the power set).
    -> The solution set must not contain duplicate subsets. Return the solution in any order.

*/

// Solution
/*
    -> Simple include/not include method of recursion + bactracking is used.
    -> We simply have two cases:
        - Case 1: Include the current element.
        - Case 2: Not include the current element.
    -> Follow recursion!
*/

void getSubset(vector<int> &subSet, vector<int> &nums,vector< vector <int> > &ans, int index){
    // base case
    if(index >= nums.size()){
        ans.push_back(subSet);          // insert the current subset in the answer
        return;
    }

    // include
    subSet.push_back(nums[index]);
    getSubset(subSet, nums, ans, index + 1);

    // not include
    subSet.pop_back();                      // backtrack
    getSubset(subSet, nums, ans, index + 1);
}

vector<vector<int>> subsets(vector<int>& nums) {
    // to store the answer
    vector< vector<int> > ans;
    // to store subset
    vector<int> v;
    // function call
    getSubset(v, nums, ans, 0);
    // return the answer
    return ans;
}

int main(){

    return 0;
}