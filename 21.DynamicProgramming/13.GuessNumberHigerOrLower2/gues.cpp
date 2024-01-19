#include<iostream>
#include<vector>
using namespace std;

// Problem || Leetcode : 275
// (Real level : hard) || Concept : merge intervals
/*
    -> We are playing the Guessing Game. The game will work as follows:
        - I pick a number between 1 and n.
        - You guess a number.
        - If you guess the right number, you win the game.
        - If you guess the wrong number, then I will tell you whether the number I picked is higher or lower, and you will continue guessing.
        - Every time you guess a wrong number x, you will pay x dollars. If you run out of money, you lose the game.

    -> Given a particular n, return the minimum amount of money you need to guarantee a win regardless of what number I pick.

*/

// Solution
/*
    # Method 1 : Recursion (TLE)
        -> Suppose we have 'n', and we guess a number, that number can be correct or not. (2 cases)
        -> For every answer we guess there will be two cases : 1) Correct guess 2) Wrong guess
        -> So for every guess there will be two path, hence there will be multiple paths for each guess.

        -> We need minimum amount to guarantee a win, so we will get minimum of maximum of all the paths from 1 to n which we make in each number's guess.

    
    # Method 2 : Dp - memoization


    # Method 3 : Dp - tabulation


*/

// Method 1 : Recursion
class Solution {
public:
    int solve(int start, int end){
        // base case
        if(start >= end)
            return 0;               // out of range -> 0 penalty || single element -> 0 penalty


        int ans = INT_MAX;
        for(int i = start; i <= end; i++)
            ans = min(ans, i + max(solve(start, i - 1), solve(i + 1, end)));
                                // max of left sub interval and rigth sub interval
            
        return ans;
    }

    int getMoneyAmount(int n) {
        int start = 1;
        int end = n;
        int ans = solve(start, end);
        return ans;
    }
};


// Method 2 : Dp - memoization
class Solution {
public:
    int solveUsingMemoization(int start, int end, vector< vector<int> > &dp){
        // base case
        if(start >= end)
            return 0;               // out of range -> 0 penalty || single element -> 0 penalty

        if(dp[start][end] != -1)
            return dp[start][end];

        int ans = INT_MAX;
        for(int i = start; i <= end; i++)
            ans = min(ans, i + max(solveUsingMemoization(start, i - 1, dp), solveUsingMemoization(i + 1, end, dp)));
                                // max of left sub interval and rigth sub interval
        dp[start][end] = ans;
        return dp[start][end];
    }

    int getMoneyAmount(int n) {
        int start = 1;
        int end = n;

        vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
        int ans = solveUsingMemoization(start, end, dp);
        return ans;
    }
};


// Method 3 : Dp - tabulation
class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 2, vector<int> (n + 1, 0));
            
        for(int start_index = n; start_index >= 1; start_index--){
            for(int end_index = 1; end_index <= n; end_index++){
                if(start_index < end_index){
                    int ans = INT_MAX;
                    for(int i = start_index; i <= end_index; i++)
                        ans = min(ans, i + max(dp[start_index][i - 1], dp[i + 1][end_index]));
                                            
                    dp[start_index][end_index] = ans;
                }
            }
        }

        return dp[1][n];
    }
};

 


int main(){

    return 0;
}