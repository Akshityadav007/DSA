#include<iostream>
using namespace std;

// Given an array. Check if it is sorted using recursion.

bool checkSortedArray(int arr[], int size, int index){
    // base case
    if(index >= size)               // here '>' to handle if the array is empty or single element
        return true;

    // processing   -   We check if the current element is smaller than the last/previous element
    if(arr[index] < arr[index - 1])
        return false;
    
    // function call
    return checkSortedArray(arr, size, index + 1);

}

int main(){
    int arr[7] = {10,20,30,40,50,60,70};
    cout << checkSortedArray(arr, 7, 1) << endl;

    return 0;
}