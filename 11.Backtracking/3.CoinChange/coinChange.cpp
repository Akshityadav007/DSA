#include<iostream>
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
    # Method 1 : Explore all possible ways - Recursion (TLE)
    -> We check for every element in array.
    -> Return the minimum number of coins among all possible ways.

    # Method 2 : DP
*/

int coinChangeRecursion(vector<int>& coins, int amount) {
    // base case
    if(amount == 0)
        return 0;

    int res = INT_MAX;
    int ansForThisAmount = INT_MAX;
    // function call
    for(int i = 0;i < coins.size();i++){
        // only use current coin when it is smaller ir equal to the amount
        if(coins[i] <= amount){
            int recAns = coinChangeRecursion(coins, amount - coins[i]);
            if(recAns != INT_MAX)
                ansForThisAmount = 1 + recAns; 
        } 
        res = min(res, ansForThisAmount);
    }
    if(res == INT_MAX)
        return -1;
    return res;
}

int main(){
    vector<int> coins{1,2,5};
    int amount = 11;
    cout << coinChangeRecursion(coins, amount) << endl;

    return 0;
}