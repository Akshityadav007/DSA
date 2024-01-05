#include<iostream>
#include<vector>
using namespace std;

// Problem || GFG : Medium
// V. Important pattern
/*
    -> Given an integer N denoting the Length of a line segment. 
    -> You need to cut the line segment in such a way that the cut length of a line segment each time is either x , y or z. 
    -> Here x, y, and z are integers.
    -> After performing all the cut operations, your total number of cut segments must be maximum.

    Note: if no segment can be cut then return 0.
*/

// Solution
/*
    # Method 1 - Exploring all possible ways (Gives TLE)

    # Method 2 - DP

    # Method 3 - Bit masking (Google yourself)
*/

int maximizeTheCuts(int n, int x, int y, int z, vector<int> &dp)
{
    // base case
    if(n <= 0)
        return 0;
    if(n < 0)
        return INT_MIN;                 // this is a case where we cut more than required to be cut i.e. the minimum length to be cut was more than the remaining segment length.

    if(dp[n] != INT_MIN)
        return dp[n];

    // function calls
    int call1 = 1 + maximizeTheCuts(n - x, x, y, z, dp);
    int call2 = 1 + maximizeTheCuts(n - y, x, y, z, dp);
    int call3 = 1 + maximizeTheCuts(n - z, x, y, z, dp);

    // now the result will be the maximum of the all three cases.
    dp[n] = max(call1, max(call2, call3));
    return dp[n];
}

int main(){
    int n = 4;
    int x = 1,y = 1, z = 1;

    vector<int> dp(n + 1, INT_MIN);
    cout << maximizeTheCuts(n, x, y, z, dp) << endl;

    return 0;
}