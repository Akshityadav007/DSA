#include<iostream>
#include<vector>
using namespace std;

// V.V.V. Important
// Revise find Pivot question of binary search before seeing this

// # Note: For this question array elements are unique and the array should be rotated at least once

// we need to find end of array
int findHigh(vector<int>& v){
    int n  = v.size();
    int low = 0,high = n - 1;
    int mid = low + (high - low) / 2;

    while(low <= high){
        // for single element array
        if(low == high)
            return mid;
        // pivot is at mid - 1, also not we can't access v[-1]
        if(mid > 0 && v[mid] < v[mid - 1])
            return mid - 1;
        // pivot is at mid, also not we can't access v[n]
        else if(mid < (n - 1) && v[mid] > v[mid + 1])
            return mid;
        // mid is present in part A
        else if(v[mid] >= v[low]){
            low = mid + 1;
        }
        // mid is present in part B
        else{
            high = mid - 1;
        }
        // update mid
        mid = low + (high - low) / 2;
    }
    return -1;
}

// now since we know high and low of target, we can find our target using binary search
int binarySearch(vector<int>& v,int low,int high,int target){
    int mid = low + (high - low) / 2;
    while(low <= high){
        if(v[mid] == target)
            return mid;
        else if(v[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
        mid = low + (high - low) / 2;
    }
    return -1;
}

int main(){
    // take input
    
    vector<int> v;
    int n;
    cout << "Enter the size of array: " << endl;
    cin >> n;
    cout << "Enter the elements of the sorted - rotated array: " << endl;
    for(int i = 0;i < n;i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
    cout << "Enter the target: " << endl;
    int target;
    cin >> target;

    // before finding the target we need to first find the end or pivot/highest element in the array to apply binary search since it is sorted and rotated
    int high = findHigh(v);
    // we need to get low of the array
    int low = (high + 1) % n;

    /*
        -> There will be two cases of target:
            - Either it lies in part A:
                i.e. from 0 to high
            - Or part B:
                i.e. from low to n - 1
        -> ∴ We'll apply binary search to the part where target is present

    */

    // target lies in part A
    if(target >= v[0] && target <= v[high])
        low = 0;
    // target lies in part B
    else
        high = n - 1;
    int indexOfTarget = binarySearch(v,low,high,target);
    cout << target << " is present at index: " << indexOfTarget << endl;

    return 0;
}