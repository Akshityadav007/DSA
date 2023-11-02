#include<iostream>
using namespace std;

// Problem || Leetcode : 59
/*
    -> Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.
*/

// Solution
/*
    -> Go see spiral matrix 1, it is prity easy now.
*/

vector<vector<int>> generateMatrix(int n) {
    // to store ans
    vector<int> cols(n);                        // one row of n columns
    vector < vector<int> > matrix(n,cols);      // n rows of n columns

    int rowStart = 0;
    int rowEnd = n - 1;
    int colStart = 0;
    int colEnd = n - 1;
    int num = 1;

    while(rowStart <= rowEnd && colStart <= colEnd){
        // Step 1 : From colStart to colEnd (rowStart constant)
        for(int j = colStart; j <= colEnd; j++){
            matrix[rowStart][j] = num;
            num++;
        }
        rowStart++;         // rowStart has been filled

        // Step 2: From rowStart to rowEnd
        for(int i = rowStart; i <= rowEnd && rowStart <= rowEnd; i++){
            matrix[i][colEnd] = num;
            num++;
        }
        colEnd--;           // colEnd has been filled

        // Step 3: From colEnd to colStart
        for(int j = colEnd; j >= colStart && colStart <= colEnd; j--){
            matrix[rowEnd][j] = num;
            num++;
        }
        rowEnd--;           // rowEnd has been filled

        // Step 4: From rowEnd to rowStart
        for(int i = rowEnd;i >= rowStart && rowStart <= rowEnd; i--){
            matrix[i][colStart] = num;
            num++;
        }
        colStart++;        // colStart has been filled
    }

    return matrix;
}

int main(){

    return 0;
}