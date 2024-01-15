#include<iostream>
#include<vector>
using namespace std;


// Problem || Leetcode : 72
/*
    -> Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.
    -> You have the following three operations permitted on a word:
        - Insert a character
        - Delete a character
        - Replace a character
*/


// Solution
/*
    # Method 1 : Recursion (TLE)

    # Method 2 : Dp - memoization

    # Method 3 : Dp - tabulation

    # Method 4 : Space optimization
        -> This is similar to the previous question 'longest common subsequence'

*/

// Method 1
class Solution {
public:
    int solve(string &s1,string &s2,int index1,int index2){
        // base case
        if(index1 == s1.length())
            return s2.length() - index2;
        if(index2 == s2.length())
            return s1.length() - index1;

        
        int ans = 0;
        if(s1[index1] == s2[index2])
            ans = 0 + solve(s1, s2, index1 + 1, index2 + 1);
        else{
            int replace = 1 + solve(s1, s2, index1 + 1,  index2 + 1);
            int insert = 1 + solve(s1, s2, index1 , index2 + 1);
            int remove = 1 + solve(s1, s2, index1 + 1, index2);

            ans = min(insert, min(remove, replace));
        }

        return ans;
    }
    int minDistance(string word1, string word2) {
         int index1 = 0;
         int index2 = 0;

         int ans = solve(word1, word2, index1, index2);
         return ans;
    }
};



// Method 2
class Solution {
public:
    int solveUsingMemoization(string &s1,string &s2,int index1,int index2, vector< vector<int>> &dp){
        // base case
        if(index1 == s1.length())
            return s2.length() - index2;
        if(index2 == s2.length())
            return s1.length() - index1;

        if(dp[index1][index2] != -1)
            return dp[index1][index2];

        
        int ans = 0;
        if(s1[index1] == s2[index2])
            ans = 0 + solveUsingMemoization(s1, s2, index1 + 1, index2 + 1, dp);
        else{
            int replace = 1 + solveUsingMemoization(s1, s2, index1 + 1,  index2 + 1, dp);
            int insert = 1 + solveUsingMemoization(s1, s2, index1 , index2 + 1, dp);
            int remove = 1 + solveUsingMemoization(s1, s2, index1 + 1, index2, dp);

            ans = min(insert, min(remove, replace));
        }
        dp[index1][index2] = ans;

        return dp[index1][index2];
    }
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector< vector<int> > dp(m + 1, vector<int> (n + 1, -1));
         int index1 = 0;
         int index2 = 0;

         dp[m][n] = solveUsingMemoization(word1, word2, index1, index2, dp);
         return dp[m][n];
    }
};


// Method 3
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector< vector<int> > dp(m + 1, vector<int> (n + 1, -1));

        // base case analysis
        for(int col = 0; col <= n; col++)
            dp[m][col] = n - col;
        for(int row = 0; row <= m; row++)
            dp[row][n] = m - row;

        for(int index1 = m - 1; index1 >= 0; index1--){
            for(int index2 = n - 1; index2 >= 0; index2--){
                int ans = 0;
                if(word1[index1] == word2[index2])
                    ans = 0 + dp[index1 + 1][index2 + 1];
                else{
                    int replace = 1 + dp[index1 + 1][index2 + 1];
                    int insert = 1 + dp[index1][index2 + 1];
                    int remove = 1 + dp[index1 + 1][index2];

                    ans = min(insert, min(remove, replace));
                }
                
                dp[index1][index2] = ans;
            }
        }


         return dp[0][0];
    }
};


// Method 4
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<int> curr(m + 1, 0);
        vector<int> next(m + 1, 0);

        // base case analysis
        for(int row = 0; row <= m; row++)
            next[row] = m - row; 
        
        for(int index2 = n - 1; index2 >= 0; index2--){
            // fill answer at last block of each column
            curr[m] = n - index2;
            for(int index1 = m - 1; index1 >= 0; index1--){
                int ans = 0;
                if(word1[index1] == word2[index2])
                    ans = 0 + next[index1 + 1];
                else{
                    int replace = 1 + next[index1 + 1];
                    int insert = 1 + next[index1];
                    int remove = 1 + curr[index1 + 1];

                    ans = min(insert, min(remove, replace));
                }
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