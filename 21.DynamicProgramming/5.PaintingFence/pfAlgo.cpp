#include<iostream>
#include<vector>
using namespace std;

// Problem || GFG
/*
    -> Given a fence with n posts and k colors, find out the number of ways of painting the fence so that not more than two consecutive posts have the same colors. 
    -> Since the answer can be large return it modulo 109 + 7.
*/

// Solution
/*
    # Method 1 : Recursion
        -> Same combination = last two posts' colors will be same
        -> Different combin = last two posts' colors will be different.

        --------------------------------------------------------------------------------------
        |               |    n = 1     |    n = 2    |   n = 3         |    n = 4            |
        |---------------|--------------|-------------|-----------------|---------------------|
        |   same        |   R          |    RR       |    RBB          |  RBRR  BGRR   RRBB  |
        |               |   G          |    GG       |    RGG          |  RBGG  BGBB   RRGG  |
        |               |   B          |    BB       |    GRR          |  RGRR  GRBB   GGRR  |
        |               |              |             |    GBB          |  RGBB  GRGG   GGBB  |
        |               |              |             |    BRR          |  BRBB  GBRR   BBRR  |
        |               |              |             |    BGG          |  BRGG  GBGG   BBGG  |
        |---------------|              |-------------|-----------------|---------------------|
        |               |              |    RB       |  RRG  RBR  BGB  |                     |
        |   different   |              |    RG       |  RRB  RBG  BGR  |                     |
        |               |              |    BR       |  GGR  RGR  GRG  |                     |
        |               |              |    BG       |  GGB  RGB  GRB  |                     |
        |               |              |    GR       |  BBR  BRB  GBG  |                     |
        |               |              |    GB       |  BBG  BRG  GBR  |                     |
        --------------------------------------------------------------------------------------

        -> Notice we are using previous answers to make current answers:
            - For any same combination, we use previous two 'same' answer.
            - For different combination, we use previous 'different' answer.
        
        => F(n) = same + different
                = f(n - 2) * (k - 1) + f(n - 1) * (k - 1)
                = (k - 1) * [f(n - 2) + f(n - 1)]

        -> The above expression is important to get:
            - For same, every post has got (k - 1) choices.
            - We get the expression from this, and solve using recursion.

    # Method 2 : Dp (memoization)

    # Method 3 : Dp (tabulation)

    # Method 4 : Space optimization
*/


// Method 1
class Solution{
    public:
    long long solve(int n, int k){
        // base case
        if(n == 1)
            return k;
        if(n == 2)
            return (k + k * (k - 1));
        
        long long ans = (k - 1) * (solve(n - 1, k) + solve(n - 2, k));
        return ans;
    }
    long long countWays(int n, int k){
        long long ans = solve(n, k);
        long long divider = 1000000007;
        return ans % divider;
    }
};


// Method 2 : Dp (memoization)
class Solution{
    public:
    long long solveUsingMemoization(long long n, long long k, vector<long long> &dp){
        long long divider = 1000000007;
        // base case
        if(n == 1)
            return k;
        if(n == 2)
            return (k + k * (k - 1));
        
        if(dp[n] != -1)
            return dp[n];
        
        unsigned long long res = (k - 1) * (solveUsingMemoization(n - 1, k, dp) + solveUsingMemoization(n - 2, k, dp));
        dp[n] = res % divider;
        
        return dp[n];
    }
    long long countWays(int n, int k){
        vector<long long> dp(n + 1, -1);
        long long ans = solveUsingMemoization(n, k, dp);
        return ans;
    }
};


// Method 3 : Dp (tabulation)
class Solution{
    public:
    long long countWays(int n, int k){
        // step 1
        vector<long long> dp(n + 1, -1);
        long long divider = 1000000007;
        long long kLong = k;                            // this is necessary because during operations, compiler converts result to int
        
        // step 2
        dp[1] = kLong;
        dp[2] = kLong + kLong * (kLong - 1);
        
        
        // step 3
        for(long long i = 3;i <= n; i++){
            unsigned long long res = (kLong - 1) * (dp[i - 2] + dp[i - 1]);
            dp[i] = res % divider;
        }
        
        return dp[n];
    }
};


// Method 4 : Space optimization
class Solution{
    public:
    long long countWays(int n, int k){
        // step 1
        long long ans = 0;
        long long divider = 1000000007;
        long long kLong = k;                            // this is necessary because during operations, compiler converts result to int
        
        // step 2
        long long prev = kLong;
        long long curr = kLong + kLong * (kLong - 1);
        ans = n == 1 ? prev : curr;
        
        // step 3
        for(long long i = 3;i <= n; i++){
            unsigned long long res = (kLong - 1) * (prev + curr);
            ans = res % divider;
            prev = curr;
            curr = ans;
        }
        
        return ans;
    }
};


int main(){


    return 0;
}