#include<iostream>
using namespace std;

// Problem || Leetcode : 76
/*
    -> Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
    -> You must do it in place.
*/

/*
    -> Simple, like brute - force approach.
    -> First marked the cells which are 0 in a separate boolean matrix.
    -> Then traversed the array and marked their row/col to 0.
*/

void solve(vector<vector<int>>& matrix, int row, int col, vector< vector< bool > > &isVisited){
    int m = matrix.size();
    int n = matrix[0].size();

    // set all row of column 'col' to 0
    for(int i = 0; i < m; i++){
        matrix[i][col] = 0;
    }
    // set all column of row 'row' 0
    for(int j = 0; j < n; j++){
        matrix[row][j] = 0;
    }
}

void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    vector < bool> v(n, false);
    vector< vector<bool> > isVisited(m, v);              // to track pre visited cells

    // mark cells with zero
    for(int i = 0;i < m;i++)
        for(int j = 0;j < n;j++)
            if(matrix[i][j] == 0)
                isVisited[i][j] = true;

    for(int row = 0; row < m; row++){
        for(int col = 0; col < n; col++){
            if(matrix[row][col] == 0 && isVisited[row][col] == true){
                solve(matrix, row, col, isVisited);
            }
        }
    }
}

int main(){

    return 0;
}