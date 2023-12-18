#include<iostream>
using namespace std;

// Problem
/*
    -> Given an array of integers.
    -> Make a heap with this array.
*/

// Solution
/*
    -> All leaf nodes are valid heap, hence no need to check them.
    -> In a CBT, from (n / 2 + 1)th node to nth node are all leaf nodes.
    -> We need to check all nodes from 1st to (n / 2)th node

    # T.C. = O(n)
       Ques. :  how ?
*/

void heapify(int *arr, int n, int index){
    int leftIndex = 2 * index;
    int rightIndex = 2 * index + 1;
    int largestIndex = index;
 
    // get max of these 3
    if(leftIndex <= n && arr[leftIndex] > arr[largestIndex])
        largestIndex = leftIndex;
    if(rightIndex <= n && arr[rightIndex] > arr[largestIndex])
        largestIndex = rightIndex;
    

    // after these 2 conditions, largestIndex will be pointing towards largest element among 3
    if(index != largestIndex){
        swap(arr[index], arr[largestIndex]);
        // recursive call
        index = largestIndex;
        heapify(arr, n ,index);
    }
}

void buildHeap(int arr[], int n){
    for(int index = n / 2; index > 0;index--){
        heapify(arr, n, index);
    }
}

int main(){
    int arr[6] = {5,10,15,20,25,12};
    buildHeap(arr, 6);

    return 0;
}