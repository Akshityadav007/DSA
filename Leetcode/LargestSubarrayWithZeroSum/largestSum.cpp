#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


// Problem || GFG
/*
    -> Given an array having both positive and negative integers. 
    -> The task is to compute the length of the largest subarray with sum 0.
*/

// Solution
/*
    -> if at a point i, j (j > i)
    -> we get prefixSum[j] = prefixSum[i], we can count that as one subarray having 0 sum.
    -> How ?
        - prefixSum[i] = A[0] + A[1] + A[2] + .......... + A[i]
        - prefixSum[j] = A[0] + A[1] + A[2] + .......... + A[i] + A[i + 1] + ... + A[j] => prefixSum[i] + A[i + 1] + ....... + A[j]
        - prefixSum[j] - prefixSum[i] = A[i + 1] + A[i + 2] + ...... + A[j].
    -> we need the subarray A[i + 1] + A[i + 2] + ..... + A[j] = 0
    -> hence, prefixSum[j] - prefixSum[i] = 0 or prefixSum[i] = prefixSum[j]

*/

int maxLen(vector<int>&A, int n)
{    
    // build a prefix sum
    unordered_map<int, int> prefixSum;
    prefixSum[A[0]] = 0;                // initial state - prefixSum, index
    
    int ans = 0;
    int sum = 0;
    
    for(int i = 0;i < n;i++){
        sum += A[i];                                            // get prefix Sum
        if(sum == 0)
            ans = i + 1;                                        // this is done in case of an array of 0 values
        
        // check if this already exists
        if(prefixSum.find(sum) != prefixSum.end())
            ans = max(ans, i - prefixSum[sum]);                 // store the length
        else
            prefixSum[sum] = i;
    }
    
    return ans;
}

int main(){

    return 0;
}