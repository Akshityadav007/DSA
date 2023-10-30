#include<iostream>
using namespace std;

// Problem || Leetcode : 221
/*
    -> Given an m x n binary matrix filled with 0's and 1's.
    -> Find the largest square containing only 1's and return its area.
*/

// Solution
/*  
    # Method 1 : Recursion (TLE)
    -> For this we need to think shallow, don't go too deep.
    -> We solve one case, rest is handled by recursion.
    
    -> For every direction we check in three directions to check for square recursively.
    -> 3 directions:
        - Right
        - Diagonal
        - Bottom.
    -> As we start from the first position we move to these three positions. (First position is our that 'one case' which we solve in recursion).
    -> Now, we get the minimum of answers from all 3 positions to make a square.
    
    -> And then we save that answer in the result (which stores maximum of all answers).
*/

    
int solve(vector<vector<char>>& matrix, int rowLimit, int colLimit, int row, int col,int &maxSq){
    // base case
    if(row >= rowLimit || col >= colLimit){
        return 0;
    }

    // explore all 3 directions (recursive calls)
    int right = solve(matrix, rowLimit, colLimit, row, col + 1, maxSq);
    int diagonal = solve(matrix, rowLimit, colLimit, row + 1, col + 1, maxSq);
    int bottom = solve(matrix, rowLimit, colLimit, row + 1, col, maxSq);

    // operation/processing
    // only include position containing '1', as this would create a square
    if(matrix[row][col] == '1'){
        //        ↓ this 1 is the position of the current element
        int ans = 1 + min(right, min(diagonal, bottom));           // get minimum of answers from all direction
        maxSq = max(maxSq, ans);                                // get maximum square

        return ans;
    }
    // if current element is '0'
    else{
        return 0;
    }
}

int maximalSquare(vector<vector<char>>& matrix) {
    int row = 0;                              // for row
    int col = 0;                              // for columns
    int rowLimit = matrix.size();             // row size
    int colLimit = matrix[0].size();          // column size

    int maxSquare = 0;
    int ans = solve(matrix, rowLimit, colLimit, row, col, maxSquare);
    return maxSquare * maxSquare;
}


int main(){

    return 0;
}