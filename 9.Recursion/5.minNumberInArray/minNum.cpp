#include<iostream>
using namespace std;

int findMin(int arr[], int size, int minTillNow, int index){
    // base class
    if(index >= size)
        return minTillNow;
    
    // operation
    minTillNow = min(minTillNow, arr[index]);

    // recursive call
    return findMin(arr, size, minTillNow, index + 1);
}

// similarly we can find maximum number in an array

int main(){
    int arr[8] = {3,7,0,10,2,-5,INT_MIN,-32};
    int mini = INT_MAX;    
    cout << findMin(arr, 8, mini, 0) << endl;

    return 0;
}