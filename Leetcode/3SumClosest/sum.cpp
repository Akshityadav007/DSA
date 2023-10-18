#include<iostream>
using namespace std;

// Problem || Leetcode : 16
// I couldn't solve properly 95/99 test cases were passed by my solution, so i checked the solutions tab - and the real solution was much simpler
/*
    -> Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.
    -> Return the sum of the three integers.
    -> You may assume that each input would have exactly one solution.
*/

int threeSumClosest(vector<int>& nums, int target) {
    // size of the array
    int n = nums.size();
    // to store the ans
    int sum = nums[0] + nums[1] + nums[2];          // sum of first 3 nos
    int minDiff = INT_MAX;

    // first sort the array
    sort(nums.begin(), nums.end());

    // traverse the array
    for(int i = 0;i < n;i++){
        // let's traverse from two sides
        int low = i + 1,high = n - 1;
        while(low < high){
            // get the current sum
            int currSum = nums[i] + nums[low] + nums[high];
            int currDiff = abs(target - currSum);                    // get the difference between current sum and target

            // check if this difference is lesser than minimum Difference till now
            if(currDiff < minDiff){
                minDiff = currDiff;     // update minimum difference till now
                sum = currSum;          // update our sum
            }
            // check where does target lie
            if(target > currSum){
                low++;
            }
            else{
                high--;
            }
        }
    }
    return sum;
}

int main(){


    return 0;
}