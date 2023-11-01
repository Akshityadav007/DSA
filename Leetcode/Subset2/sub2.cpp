#include<iostream>
#include<set>
using namespace std;

// Problem || Leetcode : 90
/*
    -> Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
    -> The solution set must not contain duplicate subsets. 
    -> Return the solution in any order.
*/

 void solve(vector<int> &nums, set< vector<int> > &ans, vector<int> &v, int index){
        // base case
        if(index >= nums.size()){
            ans.insert(v);
            return;
        }

        // include
        v.push_back(nums[index]);
        solve(nums, ans, v, index + 1);

        // exclude
        v.pop_back();
        solve(nums, ans, v, index + 1);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set< vector<int> > ans;          // to store unique the answer
        vector<int> v;
        solve(nums, ans, v, 0);

        vector< vector<int> > res;
        for(auto sub: ans){
            res.push_back(sub);
        }

        return res;
    }

int main(){


    return 0;
}