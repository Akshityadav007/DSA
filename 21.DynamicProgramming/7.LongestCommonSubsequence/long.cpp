#include<iostream>
#include<vector>
using namespace std;

// Problem || Leetcode : 1143
/*
    -> Given two strings text1 and text2, return the length of their longest common subsequence. 
    -> If there is no common subsequence, return 0.
    -> A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.
    -> For example, "ace" is a subsequence of "abcde".
    -> A common subsequence of two strings is a subsequence that is common to both strings.
*/


// Solution
/*
    # Method 1 : Recursion
        -> Use inclusion/exclusion method to create subsequences.
        -> If matches add 1, rest will be given by recursion
        -> If doesn't match, don't add 1 and move forth.
    
    # Method 2  : Dp (memoization)

    # Method 3 : Dp (tabulation)

    # Method 4 : Space optimized
        -> Notice that ans depends on either [i,j+1] or [i+1,j] or [i+1,j+1]
*/

// Method 1
class Solution {
public:
    int solve(string s1, string s2, int index1, int index2){
        // base case
        if(index1 >= s1.length() || index2 >= s2.length())
            return 0;
        

        // recursive call
        int ans = 0;
        if(s1[index1] == s2[index2])
            ans = 1 + solve(s1, s2, index1 + 1, index2 + 1);
        else
            ans = 0 + max(solve(s1, s2, index1 + 1, index2), solve(s1, s2, index1, index2 + 1));
        
        return ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
        int ans = solve(text1, text2, 0, 0);
        return ans;
    }
};


// Method 2
class Solution {
public:
    int solveUsingMemoization(string &s1, string &s2, int index1, int index2, vector< vector<int>> &dp){
        // base case
        if(index1 >= s1.length() || index2 >= s2.length())
            return 0;
        
        if(dp[index1][index2] != -1)
            return dp[index1][index2];

        // recursive call
        int ans = 0;
        if(s1[index1] == s2[index2])
            ans = 1 + solveUsingMemoization(s1, s2, index1 + 1, index2 + 1, dp);
        else
            ans = 0 + max(solveUsingMemoization(s1, s2, index1 + 1, index2, dp), 
                                        solveUsingMemoization(s1, s2, index1, index2 + 1, dp));
                                        
        dp[index1][index2] = ans;
        return dp[index1][index2];
    }
    int longestCommonSubsequence(string text1, string text2) {
        // step 1 : dp array
        int n = text1.size();
        int m = text2.size();
        vector< vector<int> > dp(n + 1, vector<int> (m + 1, -1));
        dp[n][m] = solveUsingMemoization(text1, text2, 0, 0, dp);
        return dp[n][m];
    }
};



// Method 3
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // step 1 : dp array
        int n = text1.size();
        int m = text2.size();
        vector< vector<int> > dp(n + 1, vector<int> (m + 1, 0));

        for(int index1 = n - 1; index1 >= 0; index1--){
            for(int index2 = m - 1; index2 >= 0; index2--){
                int ans = 0;

                 if(text1[index1] == text2[index2])
                    ans = 1 + dp[index1 + 1][index2 + 1];
                else
                    ans = 0 + max(dp[index1 + 1][index2], dp[index1][index2 + 1]);
                
                dp[index1][index2] = ans;
            }
        }

        return dp[0][0];
    }
};



// Method 4
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // step 1 : dp array
        int n = text1.size();
        int m = text2.size();
        vector<int> curr(n + 1, 0);
        vector<int> next(n + 1, 0);

        for(int index2 = m - 1; index2 >= 0; index2--){
            for(int index1 = n - 1; index1 >= 0; index1--){
                int ans = 0;

                 if(text1[index1] == text2[index2])
                    ans = 1 + next[index1 + 1];
                else
                    ans = 0 + max(next[index1], curr[index1 + 1]);
                
                curr[index1] = ans;
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