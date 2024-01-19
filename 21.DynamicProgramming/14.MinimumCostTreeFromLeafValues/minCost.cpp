#include<iostream>
#include<map>
#include<vector>
using namespace std;


// Problem || Leetcode : 1130
/*
    -> Given an array arr of positive integers, consider all binary trees such that:
        - Each node has either 0 or 2 children;
        - The values of arr correspond to the values of each leaf in an in-order traversal of the tree.
        - The value of each non-leaf node is equal to the product of the largest leaf value in its left and right subtree, respectively.
        - Among all possible binary trees considered, return the smallest possible sum of the values of each non-leaf node. It is guaranteed this sum fits into a 32-bit integer.
    -> A node is a leaf if and only if it has zero children.

*/


// Solution
/*
    # Method 1 : Recursion
        -> Consider each partition and build left and right sub trees.
        -> Instead of computing maximum of left / right subtrees at every point, pre - compute maximum at each point.

    # Method 2 : Dp - memoization


    # Method 3 : Dp - tabulation


*/

// Method 1
class Solution {
public:
    int solve(vector<int> &arr,map < pair<int, int>, int> &maxi, int start, int end){
        // base case
        if(start >= end)
            return 0;                   // out of range and single element
        
        int ans = INT_MAX;
        for(int i = start; i < end; i++){
            // i used for partitioning
            ans = min(ans, (maxi[{start, i}] * maxi[{i + 1, end}])
                            + solve(arr, maxi, start, i)                                // left subtree
                            + solve(arr, maxi, i + 1, end));                             // right subtree
        }
        
        return ans;
    }
    int mctFromLeafValues(vector<int>& arr) {
        // pre computation
        map < pair<int, int>, int> maxi;
        for(int i = 0; i < arr.size(); i++){
            maxi[{i, i}] = arr[i];
            for(int j = i + 1; j < arr.size(); j++)
                maxi[{i,j}] = max(arr[j], maxi[{i, j - 1}]);
        }

        return solve(arr, maxi, 0, arr.size() - 1);
    }
};


// Method 2 : Dp - memoization
class Solution {
public:
    int solveUsingMemoization(vector<int> &arr,map < pair<int, int>, int> &maxi, int start, int end, vector< vector<int> > &dp){
        // base case
        if(start >= end)
            return 0;                   // out of range and single element
        
        if(dp[start][end] != -1)
            return dp[start][end];

        int ans = INT_MAX;
        for(int i = start; i < end; i++){
            // i used for partitioning
            ans = min(ans, (maxi[{start, i}] * maxi[{i + 1, end}])
                            + solveUsingMemoization(arr, maxi, start, i, dp)                                // left subtree
                            + solveUsingMemoization(arr, maxi, i + 1, end, dp));                             // right subtree
        }
        
        dp[start][end] = ans;
        return dp[start][end];
    }
    int mctFromLeafValues(vector<int>& arr) {
        // pre computation
        int n = arr.size();
        map < pair<int, int>, int> maxi;
        for(int i = 0; i < n; i++){
            maxi[{i, i}] = arr[i];
            for(int j = i + 1; j < n; j++)
                maxi[{i,j}] = max(arr[j], maxi[{i, j - 1}]);
        }

        vector< vector<int> > dp(n, vector<int> (n, - 1));

        return solveUsingMemoization(arr, maxi, 0, n - 1, dp);
    }
};


// Method 3 : Dp - tabulation
class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        // pre computation
        int n = arr.size();
        map < pair<int, int>, int> maxi;
        for(int i = 0; i < n; i++){
            maxi[{i, i}] = arr[i];
            for(int j = i + 1; j < n; j++)
                maxi[{i,j}] = max(arr[j], maxi[{i, j - 1}]);
        }

        vector< vector<int> > dp(n, vector<int> (n, 0));

        for(int s_index = n; s_index >= 0; s_index--){
            for(int e_index = 0; e_index < n; e_index++){
                if(s_index < e_index){
                    int ans = INT_MAX;
                    for(int i = s_index; i < e_index; i++){
                        // i used for partitioning
                        ans = min(ans, (maxi[{s_index, i}] * maxi[{i + 1, e_index}])
                                        + dp[s_index][i]                                // left subtree
                                        + dp[i + 1][e_index]);                             // right subtree
                    }
                    
                    dp[s_index][e_index] = ans;
                }
            }
        }
        
        return dp[0][n - 1];
    }
};

int main(){

    return 0;
}