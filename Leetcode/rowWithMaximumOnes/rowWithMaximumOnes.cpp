#include<iostream>
using namespace std;

vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        vector<int> v;
        int maxCount = -1,row = -1;
        for(int i = 0;i < mat.size();i++){
            int count = 0;
            for(int j = 0;j < mat[i].size();j++){
                if(mat[i][j] == 1)
                count++;
            }
            if(count > maxCount){
                maxCount = count;
                row = i;
            }
        }
        v.push_back(row);
        v.push_back(maxCount);
        return v;
    }

int main(){

    // too tired to implement this
    return 0;
}