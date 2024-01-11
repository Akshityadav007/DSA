#include<iostream>
#include<vector>
using namespace std;

// Problem || leetcode : 279
/*
    -> Given an integer n, return the least number of perfect square numbers that sum to n.
    -> A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. 
    -> For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.
*/


// Solution
/*
    # Method 1 : Recursion (TLE)
        -> Check for each number.
    
    # Method 2 : Dp [memoization]

    # Method 3 : Dp [Tabulation]
*/


// Method 1 : recursion
class Solution{
    public:
    int solve(int n){
        // base case
        if(n == 0) return 1;        // include
        if(n < 0)  return 0;        // exclude
        
        int ans = INT_MAX;

        // only perfect squares upto 'n' will be of use
        for(int i = 1;i * i <= n; ++i){
            int perfectSquare = i * i;
            int totalPf = 1 + solve(n - perfectSquare);
            if(totalPf < ans)                                               // we need to get least number of integers
                ans = totalPf;
        }
        return ans;
    }

    int numSquares(int n) {
        int ans = solve(n) - 1;
        return ans;
    }

};

// Method 2 : DP - [memoization]
class Solution {
public:
    int solve(int n, vector<int> &dp){
        // base case
        if(n == 0) return 1;        // include
        if(n < 0)  return 0;        // exclude

        if(dp[n] != -1)
            return dp[n];
        
        int ans = INT_MAX;

        // only perfect squares upto 'n' will be of use
        for(int i = 1;i * i <= n; ++i){
            int perfectSquare = i * i;
            int totalPf = 1 + solve(n - perfectSquare, dp);
            if(totalPf < ans)                                               // we need to get least number of integers
                ans = totalPf;
        }

        dp[n] = ans;
        return dp[n];
    }

    int numSquares(int n) {
        // s1 : make dp array
        vector<int> dp(n + 1, -1);
        int ans = solve(n, dp) -1;
        return ans;
    }
};

int main(){


    return 0;
}