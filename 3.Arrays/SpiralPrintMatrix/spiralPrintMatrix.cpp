#include<iostream>
#include<vector>
using namespace std;


vector<int> spiralOrder(vector<vector<int>>& matrix) {
        /* 
        -> move from start/first row to end/last column on the edges.
        -> once reached end/last column then move towards start/first row.
        -> update start++ and end--;
        -> basically there will be 4 loops within the main loop for the movement.
        */
        
        // m X n matrix (row - major)
        int m = matrix.size();         // rows
        int n = matrix[0].size();     // columns
        int totalElements = m * n;

        // declare ans vector
        vector<int> ans;

        int startRow = 0;
        int endRow = m - 1;
        int startCol = 0;
        int endCol = n - 1;
        while(totalElements > 0){
            // we need to keep checking the count of elements inserted after every insertion

            // -> Loop 1    keep 'i' constant
            for(int j = startCol;j <= endCol;j++){
                ans.push_back(matrix[startCol][j]);
                totalElements--;
            }

            // update the start Row
            startRow++;

            // -> Loop 2    keep 'j' constant
            for(int i = startRow;i <= endRow && totalElements > 0;i++){
                ans.push_back(matrix[i][endCol]);
                totalElements--;
            }

            // update the end Col
            endCol--;
                
            // -> Loop 3    keep 'i' constant
            for(int j = endCol;j >= startCol && totalElements > 0;j--){
                ans.push_back(matrix[endRow][j]);
                totalElements--;
            }

            // update the end Row
            endRow--;

            // -> Loop 4    keep 'i' constant
            for(int i = endRow;i >= startRow && totalElements > 0;i--){
                ans.push_back(matrix[i][startCol]);
                totalElements--;
            }

            //update the start Column
            startCol++;
            
        }
            
        return ans;
}    

int main(){
        // implement vector initialisation
}