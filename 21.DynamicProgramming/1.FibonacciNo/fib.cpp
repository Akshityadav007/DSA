#include<iostream>
#include<vector>
using namespace std;

// Problem || Leetcode : 509
/*
    -> The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1.
    -> That is,
        - F(0) = 0, F(1) = 1
        - F(n) = F(n - 1) + F(n - 2), for n > 1.

    -> Given n, calculate F(n).
*/

// Solution
/*
    -> There are 3 method of solving:
        1) Method 1 : Brute force
        2) Method 2 : Memoization
        3) Method 3 : Tabulation
*/

// Method 1 : Might give TLE in some platforms (doesn't give in leetcode)   || T.C. : O(2 ^ n)
int fib(int n) {
    // base case
    if(n == 0 || n == 1)
        return n;
    
    return fib(n - 1) + fib(n - 2);
}



// Method 2 : Top - down approach (recursion + memoization)     || T.C. : O(n)
int solveUsingMemoization(int n, vector<int> &dp){
    // base case
    if(n == 0 || n == 1)
        return n;
    
    // step 3 : if ans already exists, then return it
    if(dp[n] != -1)
        return dp[n];

    // step 2 : store and return using dp array
    dp[n] = solveUsingMemoization(n - 1, dp) + solveUsingMemoization(n - 2, dp);
    return dp[n];
}
int fib(int n) {
    // step 1 : create dp array
    vector<int> dp(n + 1, -1);

    return solveUsingMemoization(n, dp);
}



// Method 3 : Bottom - up approach (iteration + tabulation)
int fib(int n) {
    // step 1 : create dp array
    vector<int> dp(n + 1, -1);

    // step 2 : analyse base case and fill dp array
    dp[0] = 0;
    if(n == 0)
        return dp[0];
    dp[1] = 1;

    // step 3 : fill the remaining dp array
    for(int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];

    return dp[n];
}



int main(){

    return 0;
}