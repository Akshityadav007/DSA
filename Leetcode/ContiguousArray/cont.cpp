#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// Problem || Leetcode : 525
/*
    -> Given a binary array nums.
    -> Return the maximum length of a contiguous subarray with an equal number of 0 and 1.
*/


// Solution
/*
    -> Before solving this, please solve 'subarray with 0 sum' question.
*/

int findMaxLength(vector<int>& nums) {
    // same as subarray with 0 sum - we can convert this to that question by inserting -1 at the place of 0
    int n = nums.size();
    vector<int> v(n, 0);

    for(int i = 0; i < n; i++)
        v[i] = nums[i] == 0 ? -1 : 1;
        
    // now we only need to get the answer of the maximum subarray with 0 sum
    unordered_map<int, int> prefixSum;

    int sum = 0;
    int ans = 0;

    for(int i = 0;i < n; i++){
        sum += v[i];

        if(sum == 0)
            ans = i + 1;
        
        if(prefixSum.find(sum) != prefixSum.end())
            ans = max(ans, i - prefixSum[sum]);
        else
            prefixSum[sum] = i;
    }
    
    return ans;
}

int main(){

    return 0;
}