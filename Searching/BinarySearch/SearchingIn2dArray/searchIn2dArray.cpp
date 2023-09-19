#include<iostream>
#include<vector>
using namespace std;

// This code is present in Leetcode

// Make sure it needs to be a sorted matrix

/*

    -> There is no difference between 1 - D array and 2 - D array in memory
    -> Rows of 2 - D array are stored consecutively in memory as a 1 - D array
    -> Therefore we will consider it similar to 1 - D array (of course post modifications in formuale)

    # The catch lies only in conversion of 2 - D to 1 - D array

    --> Note: Refer to 2 - D array for revision

*/

bool binarySearch(vector< vector<int> > v, int target){
    // size of rows
    int rows = v.size();
    // size of cols
    int cols = v[0].size();
    // size of array
    int n = rows * cols;

    int low = 0,high = n - 1;
    int mid = low + (high - low) / 2;

    // Let's begin
    while(low <= high){
        // get the row number at which mid is present
        int rowIndex = mid / cols;
        // get the column number at which mid is present
        int colIndex = mid % cols;

        if(v[rowIndex][colIndex] == target)
            return true;
        else if(v[rowIndex][colIndex] > target)
            high = mid - 1;
        else
            low = mid + 1;
        
        // update mid
        mid = low + (high - low) / 2;
    }
    return false;
    
}

// get indices of target
vector<int> indexSearch(vector< vector<int> > v, int target){

    // ans vector   v[0] = row number , v[1] = column number
    vector<int> ans;

    // size of rows
    int rows = v.size();
    // size of cols
    int cols = v[0].size();
    // size of array
    int n = rows * cols;

    int low = 0,high = n - 1;
    int mid = low + (high - low) / 2;

    // Let's begin
    while(low <= high){
        // get the row number at which mid is present
        int rowIndex = mid / cols;
        // get the column number at which mid is present
        int colIndex = mid % cols;

        if(v[rowIndex][colIndex] == target){
            ans.push_back(rowIndex);
            ans.push_back(colIndex);
            return ans;
        }
        else if(v[rowIndex][colIndex] > target)
            high = mid - 1;
        else
            low = mid + 1;
        
        // update mid
        mid = low + (high - low) / 2;
    }
    ans.push_back(-1);
    ans.push_back(-1);
    return ans;
    
}


int main(){
    // take input
    vector< vector<int> > v;
    cout << "Enter number of rows in array: " <<endl;
    int rows;
    cin >> rows;
    cout << "Enter number of columns in array: " << endl;
    int cols;
    cin >> cols;
    for(int i = 0;i < rows;i++){
        vector<int> temp;
        for(int j = 0;j < cols;j++){
            cout << "Enter v[" << i << "][" << j <<"]:" << endl;
            int a;
            cin>>a;
            temp.push_back(a);
        }
        v.push_back(temp);
    }
    cout << "Enter target to be searched: " << endl;
    int target;
    cin >> target;

    // if present ? if yes, at which index ?
    bool isPresent = binarySearch(v,target);
    if(isPresent){
        vector<int> ans = indexSearch(v,target);
        cout << "Present at " << ans[0] << " row and " << ans[1] << " column, i.e. v[" << ans[0] << "][" << ans[1] << "]" << endl;
    } 
    else{
        cout << "Not Present" << endl;
    }
    
}

// test