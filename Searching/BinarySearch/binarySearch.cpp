#include<iostream>
using namespace std;

/*

    *** CONDITION ***
    -> Array should be monotonic < mark the words >


*/


int binarySearch(vector<int> &v,int n,int target){
    int low = 0,high = n - 1;
    // there is a flaw in the below line
    // int mid = (low + high) / 2;     // flaw is it is possible that 'low + high' might give an integer which is greater than range of 'int' i.e. 2^31 - 1. Then it can't be stored in the temporary buffer create by compiler.
    
    // either use this ↓
    // int mid = (low / 2) + (high / 2);
    // or
    
    // best practice ↓
    int mid = low + (high - low) / 2;
    while(low <= high){
        if(v[mid] == target)
        return mid;
        else if(v[mid] > target){
            high = mid - 1;
        }
        else if(v[mid] < target){
            low = mid + 1;
        }
        mid = low + (high - low) / 2;
    }
    return -1;
}

int main(){
    int n;
    cout << "Enter the sorted array size:" << endl;
    cin >> n;
    vector<int> v;
    cout << "Enter the non duplicate elements of sorted array:" << endl;
    for(int i = 0;i < n;i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
    int target;
    cout << "Enter the target:" << endl;
    cin >> target;
    int res = binarySearch(v,n,target);
    if(res == -1)
    cout << "Element not found!" << endl;
    else
    cout << "Element found at " << res << endl;
}