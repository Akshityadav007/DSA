#include<iostream>
using namespace std;

// Quick Sort

/*
    #  Main logic
    -> In this algo, we place a 'pivot', to the right of which all elements are greater than 'pivot' and to the left of this are smaller than 'pivot'.
    -> Basicallly we are creating two partitions beside 'pivot'.

    # Core logic
    -> We need to get the pivot point, for this we need to create partition.
    -> But we can't really create partition of the array (😂).
    -> We'll instead alter the element positions.
    -> First we'll consider the last element as 'pivot'.
        - Then start checking elements from starting.
        - Maintain two points:
            - 1. Left of which all elements are smaller than 'pivot'
            - 2. To compare with 'pivot'. (if smaller than pivot, we'll place that number inside the first part).

*/

/*
    T.C = O(n ^ 2)
*/

int partition(int arr[],int low, int high){
    // consider 'high' as pivot point
    int pivot = arr[high];

    int i = low - 1;            // start from behind low
    for(int j = low;j < high;j++){
        // if element is smaller than or equal to pivot (considering equal to also because we need to shift 'i')
        if(arr[j] <= pivot){
            ++i;
            swap(arr[i], arr[j]);               // place this element within 'left' side (point 1)
        }
    }

    // we have placed all elements to the left of a point, where all elements are smaller than 'pivot'.
    // So, let's place pivot to it's right position now.
    swap(arr[i + 1],arr[high]);                                 // don't put pivot instead of arr[high], because we need to swap the elements within the array
    
    // Hence, this point is the real pivot to be sent.
    return i + 1;       // left of (i + 1), all elements are smaller than arr[i + 1]
}

void quickSort(int arr[],int low, int high){
    // base case
    if(low >= high)
        return;
    
    // processing
    int pivot = partition(arr, low, high);

    // recursive call
    quickSort(arr, low, pivot - 1);         // left part
    quickSort(arr, pivot + 1, high);        // right part

}

void printArray(int arr[],int size){
    for(int i = 0;i < size;i++)
        cout << arr[i] << " ";
    
    cout << endl;
}


int main(){
    int arr[8] = {100,-5,30,0,27,-89,67,9};
    cout << "Before sort: " << endl;
    printArray(arr,8);

    quickSort(arr, 0, 7);

    cout << "After sort: " << endl;
    printArray(arr, 8);

    return  0;
}