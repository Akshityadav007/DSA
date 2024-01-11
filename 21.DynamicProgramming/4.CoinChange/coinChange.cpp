#include<iostream>
#include<vector>
using namespace std;


// Problem || Leetcode : 322
/*
    -> You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
    -> Return the fewest number of coins that you need to make up that amount. 
    -> If that amount of money cannot be made up by any combination of the coins, return -1.
    -> You may assume that you have an infinite number of each kind of coin.

*/

// Solution
/*
    # Method 1 : Recursion
        -> Check for every case recursively.
    
    # Method 2 : Dp (memoization)
        -> Create a dp array of size 'amount'.
        -> Keep storing the number of coins used for amount and then return answer for that amount after base case.
    
    # Method 3 : Dp (tabulation)
        
    
    => Space optimization in this case is not possible.
*/

// Method 1 : Recursion (TLE)
class Solution {
public:
    int solveUsingRecursion(vector<int> &coins, int amount){
        // base case
        if(amount == 0)
            return 0;

        // recursive relation
        int mini = INT_MAX;
        for(int i = 0;i < coins.size(); i++){
            // find ans using i'th coin

            if(amount - coins[i] >= 0){                                                             //  call for only valid case
                int recursionAns = solveUsingRecursion(coins, amount - coins[i]);
                if(recursionAns != INT_MAX){                                                       //   valid ans only
                    int ans = 1 + recursionAns;
                    mini = min(mini, ans);
                }
            }
        }
        return mini;
    }
    int coinChange(vector<int>& coins, int amount) {
        int ans = solveUsingRecursion(coins, amount);
        ans = ans == INT_MAX ? -1 : ans;

        return ans;
    }
};


// Method 2 : Dp (memoization)
class Solution {
public:
    int solveUsingMemoization(vector<int> &coins, int amount, vector<int> &dp){
        // base case
        if(amount == 0)
            return 0;

        if(dp[amount] != -1)
            return dp[amount];

        // recursive relation
        int mini = INT_MAX;
        for(int i = 0;i < coins.size(); i++){
            // find ans using i'th coin

            if(amount - coins[i] >= 0){
                int recursionAns = solveUsingMemoization(coins, amount - coins[i], dp);
                if(recursionAns != INT_MAX){
                    int ans = 1 + recursionAns;
                    mini = min(mini, ans);
                }
            }
        }
        dp[amount] = mini;
        return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        int ans = solveUsingMemoization(coins, amount, dp);
        ans = ans == INT_MAX ? -1 : ans;

        return ans;
    }
};


// Method 3 : Dp (tabulation)
int coinChange(vector<int>& coins, int amount) {
    // step 1 : dp array
    vector<int> dp(amount + 1, INT_MAX);
    
    // step 2 : base case analysis
    dp[0] = 0;

    // step 3 :
    for(int value = 1; value <= amount; value++){
        int mini = INT_MAX;
        for(int i = 0;i < coins.size(); i++){
            // find ans using i'th coin
            if(value - coins[i] >= 0){
                int recursionAns = dp[value - coins[i]];
                if(recursionAns != INT_MAX){
                    int ans = 1 + recursionAns;
                    mini = min(mini, ans);
                }
            }
        }
        dp[value] = mini;
    }
    dp[amount] = dp[amount] == INT_MAX ? -1 : dp[amount];
    return dp[amount];
}



int main(){


    return 0;
}