#include<iostream>
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
    # Method 1: Recursion (TLE)
        -> 3 operations, 3 recursive calls, get the minimum of all calls.

    #Method 2: Dp
*/

    
int solve(string &w1, string &w2, int i, int j){
    // 1) base cases

    // word1 has been traced and word2 is still left
    if(i >= w1.size()){
        return w2.size() - j;       // return remaining length left to be traced
    }
     // word2 has been traced and word1 is still left
    if(j >= w2.size()){
        return w1.size() - i;       // return remaining length left to be traced
    }

    int ans = 0;
    
    // 2) / 3) recursive calls + operation

    // if both the letters are matching - no operations needed
    if(w1[i] == w2[j]){
        ans = solve(w1,w2, i + 1, j + 1);
    }
    else{   // if mis - matching

        // 3 operations, 3 recursive calls (DO NOT FORGET TO ADD 1 HERE!)
        int insert = 1 + solve(w1, w2, i, j + 1);               // insertion in w2 will lead to j++
        int remove = 1 + solve(w1, w2, i + 1, j);               // to remove simply move to the next element (instead really removing it)
        int replace = 1 + solve(w1, w2, i + 1, j + 1);          // remove operation will lead to increament in both iterators
        
        ans = min(insert, min(remove, replace));            // get the minimum of all and return it
    }
    return ans;
}

int minDistance(string word1, string word2) {
    int i = 0;      // to iterate word1
    int j = 0;      // to iterate word2
    return solve(word1, word2, i, j);
}
int main(){

    return 0;
}