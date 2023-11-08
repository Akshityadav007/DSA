#include<iostream>
using namespace std;

// Problem || Leetcode : 167
/*
    -> Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order,
    -> find two numbers such that they add up to a specific target number. 
    -> Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 < numbers.length.
    -> Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.
    -> The tests are generated such that there is exactly one solution. 
    -> You may not use the same element twice.
    -> Your solution must use only constant extra space.
*/


// Solution
/*
    # Method 1: Brute force

    # Method 2 : 2 pointer approach
*/

 vector<int> twoSum(vector<int>& numbers, int target) {
        // to store the ans
        vector<int> ans;

        // # Method 1: Brute Force
        // n1 + n2 = target

        // for(int i = 0;i < numbers.size();i++){
        //     for(int j = i + 1;j < numbers.size(); j++){
        //         if(numbers[i] + numbers[j] == target){
        //             ans.push_back(i + 1);
        //             ans.push_back(j + 1);
        //             return ans;
        //         }
        //     }
        // }

        // Method 2: Two pointer
        int high = numbers.size() - 1;
        int low = 0;
        while(low < high){
            // target sum achieved
            if(numbers[low] + numbers[high] == target){
                ans.push_back(low + 1);
                ans.push_back(high + 1);
                break;
            }
            else if(numbers[low] + numbers[high] < target)
                low++;
            else
                high--;
        }


        return ans;
    }

int main(){


    return 0;
}