#include<iostream>
#include<queue>
using namespace std;

// Problem || GeeksforGeeks
/*
    -> Given an array arr[] and an integer K where K is smaller than size of array, the task is to find the Kth smallest element in the given array. 
    -> It is given that all array elements are distinct.
    -> Note :-  l and r denotes the starting and ending index of the array.
*/

// Solution
/*
    # Method 1 : Sorting


    # Method 2 : Take min heap

    
    # Method 3 : Take max heap
        -> Take a max heap.
        -> Build max heap using first 'k' elements.
        -> Now process next 'n - k' elements.
            - If current element is smaller than top of max heap, replace it in the heap.
*/

int kthSmallest(int arr[], int l, int r, int k) {
    priority_queue<int> pq;
    
    for(int i = 0;i < k; i++)
        pq.push(arr[i]);
        
    for(int i = k;i <= r;i++){
        if(pq.top() > arr[i]){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    
    return pq.top();
}

int main(){

    return 0;
}