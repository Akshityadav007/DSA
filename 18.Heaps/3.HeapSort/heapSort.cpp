#include<iostream>
using namespace std;

/*
    -> Swap with last.
    -> Heapify.

    # T.C. : O(nlogn)
*/

void printHeap(int arr[], int size){
    for(int i = 1;i <= size;i ++){
        cout << arr[i] << " ";
    }
}

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
    for(int index = n / 2; index > 0; index--){
        heapify(arr, n, index);
    }
}

void heapSort(int arr[], int size){
    while(size != 1){
        swap(arr[1], arr[size]);
        size--;
        heapify(arr, size, 1);
    }
}

int main(){
    int arr[] = {-1, 5, 10, 15, 20, 25, 12};                                // '-1' as we aren't accessing index 0, can out any random number
    buildHeap(arr, 6);

    cout << "Heap: " << endl;
    printHeap(arr, 6);
    
    cout << endl;

    heapSort(arr, 6);

    cout << "Heap: " << endl;
    printHeap(arr, 6);


    return 0;
}