#include<iostream>
using namespace std;

void print2DVector(vector< vector<int> > &v){
    for(int row = 0; row < v.size(); row++){
        for(int col = 0; col < v[row].size(); col++)
            cout << v[row][col] << " ";
        cout << endl;
    }
}

// Problem || Leetcode : 46
// Solved it on my own on the day of learning the question 'print all permutation of a string'.
/*
    -> Given an array nums of distinct integers, return all the possible permutations. 
    -> You can return the answer in any order.
*/

// Solution
/*
    -> This question is solely based on backtracking question of 'print all permutation of a string'.

*/


void permutations(vector<int> &nums, int i, vector< vector<int> > &result){
    // base case
    if(i >= nums.size()){
        result.push_back(nums);         // insert that permutation in result
        return;
    }
    // from 'i' to end of the array all permutations
    for(int j = i;j < nums.size();j++){
        swap(nums[i], nums[j]);          // create a permutation

        // recursive call
        permutations(nums, i + 1, result);      // call for next 'i'

        swap(nums[i], nums[j]);         // backtrack (as it is pass by reference, rectify the swap done earlier)
    }
}
vector< vector<int> > permute(vector<int>& nums) {
    vector < vector <int> > result;           // no. of permutations will be factorial of size of array
    permutations(nums, 0, result);
    return result;
}

int main(){
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    vector< vector <int> > output = permute(nums);
    print2DVector(output);

    return 0;
}