#include<iostream>
using namespace std;

bool linearSearch(int arr[], int size, int target, int index){
    // base case
    if(index >= size)
        return false;

    // operation
    if(arr[index] == target)
        return true;

    // recursive call
    return linearSearch(arr, size, target, index + 1);
}

bool binarySearch(int a[], int low, int high, int target){
    // base case
    if(low > high)
        return false;
    
    // operation
    int mid = low + ((high - low) >> 1);
    if(a[mid] == target)
        return true;

    // recursive call
    else if(a[mid] > target)
        return binarySearch(a, low, mid - 1, target);
    else
        return binarySearch(a, low + 1, high, target);
}

// we can return index also

int main(){
    int a[7] = {10,20,30,40,50,60,70};
    int target = 30;

    cout << linearSearch(a,7,target,0) << endl;

    cout << binarySearch(a,0,6,target) << endl;

    return 0;
}