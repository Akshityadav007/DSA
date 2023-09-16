#include<iostream>
using namespace std;
 
 // V.V.V.V. Important - asked in interviews

void rotate(vector<vector<int>>& matrix) {
        // step - 1 = transpose
        // step - 2 = reverse the elements of the rows
        transpose(matrix);
        reverseRows(matrix);
    }

void transpose(vector<vector<int>> &v){
        for(int i = 0;i < v.size();i++){
            for(int j = i + 1;j < v[i].size();j++){
                swap(v[i][j],v[j][i]);
            }
        }
    }

void reverseRows(vector<vector<int>> &v){
        for(int i = 0;i < v.size();i++){
            int low = 0,high = v.size() - 1;
            while(low < high){
                swap(v[i][low],v[i][high]);
                low++;high--;
            }
        }
    }

void swap(int &a,int &b){
        int temp = a;
        a = b;
        b = temp;
}

int main(){

    // implement a matrix and pass it to rotate function and print it
    return 0;
}