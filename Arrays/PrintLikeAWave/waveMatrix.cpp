#include<iostream>
#include<vector>
using namespace std;

vector<int> wavePrint(vector< vector<int> > arr, int nRows, int mCols)
{
    // answer vector
    vector<int> ans;

    // it begins
    for(int j = 0;j < mCols;j++){

        // first loop increasing rows
        int i = 0;
        for(;i < nRows;i++){
            ans.push_back(arr[i][j]);
        }

        // change colummn
        j++;
        // update row
        i = nRows - 1;

        // second loop decreasing rows
        for(;i >= 0 && j < mCols;i--){
            ans.push_back(arr[i][j]);
        }
    }
    return ans;
}

void printArray(vector<int>& v){
    for(int i = 0;i < v.size();i++)
    cout << v[i] << " ";
    cout << endl;
}

int main(){
    vector< vector<int> > v;
    int rows,cols;
    cout << "Enter number of rows, columns: " << endl;
    cin>>rows>>cols;
    for(int i = 0;i < rows;i++){
        vector<int> a;
        for(int j = 0;j < cols;j++){
            cout << "Enter v[" << i << "][" << j << "]: " << endl;
            int z;
            cin>>z;
            a.push_back(z);
        }
        v.push_back(a);
    }
    vector<int> ans = wavePrint(v,rows,cols);
    cout << "Wave like print of this vector is: " << endl;
    printArray(ans);
}