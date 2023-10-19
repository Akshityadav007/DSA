#include<iostream>
using namespace std;

/*
    -> Based on divide and conquer principle.
    -> Step1 : Divide the array in two parts.
    -> Step2 : Sort the left part, sort the right part.
    -> Step3 : Merge both parts.

    # Note: These are the basic steps in merge Sort. Solve for one case and rest will be handled by recursion.

    -> The last step is the tricky part. #MERGING.
    -> For merging,
        - Create two array, left part and right part
        - We have our two arrays, we traverse through it
        - We keep inserting the value which is lower among both in the original array
        - This is how we merge both ( actually we aren't merging we just insert/update elements in the original array).

*/

/*
    Time complexity:
    T(n) =  k          + T(n/2)                      +     T(n/2)                        +       nk
            ↑             ↑                                ↑                                     ↑
            Base case   Left Half Recursive call        Right Half Recursive call               merge

    T.C. = O(nlogn).
*/

// Step 2 & 3:
void merge(int arr[],int low, int high){
    // get the mid first
    int mid = low + ((high - low) >> 1);

    // first get the lengths of both arrays
    int leftSize = mid - low + 1;
    int rightSize = high - mid;

    // now let us create both the array dynamically
    int *leftArray = new int[leftSize];
    int *rightArray = new int[rightSize];

    // let us fill/copy both the arrays with elements
    int originalArrayIndex = low;                       // - used to traverse original array
    // left array
    for(int i = 0;i < leftSize; i++){
        leftArray[i] = arr[originalArrayIndex];
        originalArrayIndex++;
    }
    // right array
    originalArrayIndex = mid + 1;                   // starting index of right array in original array
    for(int i = 0;i < rightSize; i++){
        rightArray[i] = arr[originalArrayIndex];
        originalArrayIndex++;
    }


    // now let us begin merging (both arrays are sorted here)
    int left = 0;                   // to traverse left array
    int right = 0;                  // to traverse right 
    originalArrayIndex = low;       // we'll begin inserting from 'low' in original array   
    // # Note this is low

    // we'll insert the lower element in the original array
    while(left < leftSize && right < rightSize){
        // if element at left array is lower
        if(leftArray[left] < rightArray[right]){
            arr[originalArrayIndex] = leftArray[left];
            originalArrayIndex++;
            left++;
        }
        // if element at right array is lower
        else{
            arr[originalArrayIndex] = rightArray[right];
            originalArrayIndex++;
            right++;
        }
    }

    // what if left array is left to be traversed and right is traversed
    while(left < leftSize){
        arr[originalArrayIndex] = leftArray[left];
        originalArrayIndex++;
        left++;
    }

    // what if right array is left to be traversed and left is traversed
     while(right < rightSize){
        arr[originalArrayIndex] = rightArray[right];
        originalArrayIndex++;
        right++;
    }

    // now as a good coder, delete the heap memory
    delete[] leftArray;                                 // since it is an array (sequence of integers), we delete it this way and not delete(element)
    delete[] rightArray;
}

// Step 1:
void mergeSort(int arr[],int left, int right){
    // base case
    if(left >= right)
        return;

    // pre - processing
    int mid = left + ((right - left) >> 1);

    // Step 1: function call

    // - left array    -  from left to mid
    mergeSort(arr, left, mid);
    // -right array    - from mid + 1 to right
    mergeSort(arr, mid + 1, right);

    // Step 2 & 3: post - prcoessing
    merge(arr, left, right);                    // that one case, which we solve in recursion.

}

void printArray(int arr[],int size){
    for(int i = 0;i < size;i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main(){
    int arr[8] = {100,-2,35,0,1,18,5,30};
    cout << "Before sort: " << endl;
    printArray(arr,8);
    cout << "After sort: " << endl;
    mergeSort(arr,0,7);
    printArray(arr,8);

    return 0;
}