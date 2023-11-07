#include<iostream>
using namespace std;

// Problem || Leetcode : 31 (Couldn't solve)
/*
    -> A permutation of an array of integers is an arrangement of its members into a sequence or linear order.
    -> For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
    -> The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

    -> For example, the next permutation of arr = [1,2,3] is [1,3,2].
    -> Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
    -> While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
    -> Given an array of integers nums, find the next permutation of nums.

    => The replacement must be in place and use only constant extra memory.

*/

// Solution
/*
    -> What is lexicographical order?
        - We have to check that the order of the array sequence is greater than the previous array sequence. 
        - The output will be just larger sequence of the array.


    # Method 1 : Using STL


    # Method 2: Copied from GFG
    -> Iterate over the given array from end and find the first index (pivot) which doesn’t follow property of non-increasing suffix, (i.e,  arr[i] < arr[i + 1]).
    -> Check if pivot index does not exist 
        - This means that the given sequence in the array is the largest as possible. So, swap the complete array.
    -> Otherwise, Iterate the array from the end and find for the successor of pivot in suffix.
    -> Swap the pivot and successor
    -> Minimize the suffix part by reversing the array from pivot + 1 till N.



*/
// # Method 1
void nextPermutationUsingSTL(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
}

// # Method 2 : Copied idea from GFG
void reverseArray(vector<int> &v, int start, int end){
    while(start < end){
        swap(v[start], v[end]);
        start++; end--;
    }
}

int getPivot(vector<int> &v){
    int ans = -1;                               // if pivot is not found
    for(int i = v.size() - 2;i >= 0;i--){
        if(v[i] < v[i + 1]){                       // get first index of non increasing suffix
            ans = i;
            break;
        }
    }
    return ans;
}

int getSuccessor(vector<int> &v, int pivot){
    int ans = pivot;                                // to get the successor of pivot

    for(int i = v.size() - 1;i > pivot; i--){
        // if we get an element greater than pivot in suffix
        if(v[i] > v[ans]){
            ans = i;
            break;
        }
    }
    return ans;
}

void nextPermutation(vector<int>& nums) {
    // find pivot
    int pivotIndex = getPivot(nums);

    // check if this is the largest possible permutation
    if(pivotIndex < 0)
        reverseArray(nums, 0, nums.size() - 1);
    // else, find the successor of the pivot (i.e. next element greater than pivot)
    else{
        int successorIndex = getSuccessor(nums, pivotIndex);            // get successor
        swap(nums[pivotIndex], nums[successorIndex]);                   // swap pivot and successor
        reverseArray(nums, pivotIndex + 1, nums.size() - 1);            // reverse the successor part (next to pivot)
    }
}

int main(){

    return 0;
}