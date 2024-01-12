#include<iostream>
#include<vector>
using namespace std;


//  ***         2 - D Dp begins         ****

// Problem || GFG (0 - 1 Knapsack)
/*
    -> You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. 
    -> Note that we have only one quantity of each item.
    -> In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent values and weights associated with N items respectively. 
    -> Also given an integer W which represents knapsack capacity.
    -> find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. 
    -> You cannot break an item, either pick the complete item or dont pick it (0-1 property).
*/


// Solution
/*
    # Method 1 : Recursion (include/exclude)
        -> For every item we take both cases - include and exclude.
        -> Get maximum of both the cases.

    # Method 2 : 2 - D Dp (memoization)

    # Method 3 : 2 - D Dp(tabulation)

    # Method 4 : Space optimization 1 - D Dp
        -> We only need two columns of a row, to get answer.

    # Method 5 : More Space optimization 1 - D Dp
*/


// Method 1
class Solution
{
    public:
    int solve(int w, int wt[], int val[], int n, int index){
        // base case
        if(index == n - 1)
            return 0;
               
        
        int include = 0;
        if(wt[index] <= w){
            include = val[index] + solve(w - wt[index], wt, val, n, index + 1);
        }
        
        int exclude = 0 + solve(w, wt, val, n, index + 1);
        
        return max(include, exclude);
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       int ans = solve(W, wt, val, n, 0);
       return ans;
    }
};


// Method 2 : 2 - D Dp (memoization)
class Solution
{
    public:
    int solveUsingMemoization(int w, int wt[], int val[], int n, int index, vector< vector<int> > &dp){
        // base case
        if(index >= n)
            return 0;
        
        if(dp[w][index] != -1)
            return dp[w][index];
        
        int include = 0;
        if(wt[index] <= w)
            include = val[index] + solveUsingMemoization(w - wt[index], wt, val, n, index + 1, dp);
        
        int exclude = 0 + solveUsingMemoization(w, wt, val, n, index + 1, dp);
        
        dp[w][index] = max(include, exclude);
        
        return dp[w][index];
    }
    
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       vector< vector<int> > dp(W + 1, vector<int>(n + 1, -1));
       int ans = solveUsingMemoization(W, wt, val, n, 0, dp);
       return ans;
    }
};



// Method 3 : 2 - D Dp (tabulation)
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        // Step 1: dp array
       vector< vector<int> > dp(W + 1, vector<int>(n + 1, -1));
       
       // Step 2: base case analysis
       for(int row = 0; row <= W; row++)
           dp[row][n] = 0;
          
        // step 3 :
        for(int i = 0; i <= W; i++){
            for(int j = n - 1; j >= 0; j--){
                int include = 0;
                if(wt[j] <= i)
                    include = val[j] + dp[i - wt[j]][j + 1];
                
                int exclude = 0 + dp[i][j + 1];
                
                dp[i][j] = max(include, exclude);
            }
        }
       
       return dp[W][0];
    }
};


// Method 4 : Space optimization (two 1- D Dp)
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        // Step 1: dp array
        vector< int > next(W + 1, 0);
        vector< int > curr(W + 1, -1);
       
        // step 3 :
        
        for(int j = n - 1; j >= 0; j--){                    // traverse column first
            for(int i = 0; i <= W; i++){                    // traverse row first
                int include = 0;    
                if(wt[j] <= i)
                    include = val[j] + next[i - wt[j]];
                
                int exclude = 0 + next[i];
                
                curr[i] = max(include, exclude);
            }
            
            // shift ( the column keep shifting from right to left)
            next = curr;
        }
       
       return next[W]; 
    }
};



// Method 5 : Further space optimization (onlu one 1 - D Dp)
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        // Step 1: dp array
        vector< int > next(W + 1, 0);
       
        // step 3 :
        
        for(int j = n - 1; j >= 0; j--){                    // traverse column first
            for(int i = W; i >= 0; i--){                    // traverse row first
                int include = 0;    
                if(wt[j] <= i)
                    include = val[j] + next[i - wt[j]];
                
                int exclude = 0 + next[i];
                
                next[i] = max(include, exclude);
            }
        }
       
       return next[W]; 
    }
};

int main(){

    return 0;
}