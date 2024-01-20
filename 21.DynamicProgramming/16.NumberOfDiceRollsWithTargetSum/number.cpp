#include<iostream>
#include<vector>
using namespace std;


// Problem || Leetcode : 1155
/*
    -> You have n dice, and each dice has k faces numbered from 1 to k.
    -> Given three integers n, k, and target, return the number of possible ways (out of the kn total ways) to roll the dice, so the sum of the face-up numbers equals target.  
    -> Since the answer may be too large, return it modulo 109 + 7.
*/


// Solution
/*
    # Method 1  :Recursion (TLE)
        - Doesn't run test cases

    # Method 2 : Dp - memoization

    # Method 3 : Dp - tabulation

    # Method 4 : Space optimized

*/

// Method 2
class Solution {
public:
    long long int MOD = 1000000007;
    int solveUsingMemoization(int n, int k, int target, vector< vector<int>> &dp){
        // base cases
        if(target == 0 && n == 0)
            return 1;
        if((target != 0 && n == 0) || (target == 0 && n != 0))
            return 0;
        
        if(dp[n][target] != -1)
            return dp[n][target];

        int ans = 0;
        for(int i = 1; i <= k; i++){
            int recAns = 0;
            if(target - i >= 0)
                recAns = solveUsingMemoization(n - 1, k, target - i, dp) % MOD;
            ans = (ans % MOD + recAns % MOD) % MOD;
        }

        dp[n][target] = ans;

        return dp[n][target];
    }
    int numRollsToTarget(int n, int k, int target) {
        vector< vector<int> > dp(n + 1, vector<int> (target + 1, -1));
        return solveUsingMemoization(n, k, target, dp);
    }
};



// Method 3
class Solution {
public:
    long long int MOD = 1000000007;
    int numRollsToTarget(int n, int k, int target) {
        vector< vector<int> > dp(n + 1, vector<int> (target + 1, 0));

        dp[n][target] = 1;

        for(int dice = n - 1; dice >= 0; dice--){
            for(int sum = target; sum >= 0; sum--){
                int ans = 0;
                for(int face = 1; face <= k; face++){
                    int recAns = 0;
                    if(sum + face <= target)
                        recAns = dp[dice + 1][sum + face];
                    ans = (ans % MOD + recAns % MOD) % MOD;
                }
                dp[dice][sum] = ans;
            }
        }

        return dp[0][0];
    }
};


// Method 4
class Solution {
public:
    long long int MOD = 1000000007;
    int numRollsToTarget(int n, int k, int target) {
        vector<int> curr(target + 1, 0);
        vector<int> next(target + 1, 0);

        next[target] = 1;

        for(int dice = n - 1; dice >= 0; dice--){
            for(int sum = target; sum >= 0; sum--){
                int ans = 0;
                for(int face = 1; face <= k; face++){
                    int recAns = 0;
                    if(sum + face <= target)
                        recAns = next[sum + face];
                    ans = (ans % MOD + recAns % MOD) % MOD;
                }
                curr[sum] = ans;
            }

            // shifting
            next = curr;
        }
        return next[0];
    }
};


int main(){


    return 0;
}