#include<iostream>
using namespace std;

// Problem || Leetcode : 31
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
    # Method 1 : Using STL


    # Method 2:
    -> We see that it was earlier a sorted array.
    -> Later it transformed into a permutation of itself and is currently at some stage.
    -> We need to find the next permutation.

    -> So, we get the maximum number in the array to know the place till where permutation has been done.
    -> To the left of the maximum number the array is not tranformed. Hence, we should leave it.
    -> Also if we get the maximum number at the first index of the array, this means this is the last permutation. So, just return the sorted form of the array(reverse the array).
    -> And if we get the maximum number at the last index of the array, return the same array.
    -> To the right of maximum number till the last element of the array, we need to find a 'swap' of the number to the right of maximum number with other numbers to the right of the maximum number, which is the next permutation.



*/
void nextPermutationUsingSTL(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
}

int main(){

    return 0;
}