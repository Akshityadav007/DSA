#include<iostream>
#include<numeric>
using namespace std;

//  -> Wasn' table to solve this question
// GFG - medium             || Leetcode: 1552

// Problem
/*

    -> You are given an array consisting of n integers which denote the position of a stall. 
    -> You are also given an integer k which denotes the number of aggressive cows. 
    -> You are given the task of assigning stalls to k cows such that the minimum distance between any two of them is the maximum possible.

*/

/*
    -> Approach is similar to book allocation.
    
    -> We need to find maximum possible distance to keep the cows away from each other.
    -> There will be multiple permutations to keep the cows at different positions (on number line).
    -> Also as the positions should be increasing as the cows need to be put on stalls number wise, the array should be sorted.
    -> The maximum distance between '2' cows can be between 'first' and 'last' stall, i.e. 'highest number' of the array to 'lowest number' of the array.
    -> ∴ Search space in this problem will be from 0 to (highest number - lowest number).

    -> We'll apply binary search and for every mid we'll check if it is a possible solution.
    ->  Case 1: Possible Solution:
                - Store the mid as answer (because mid is the distance in this permutation.)
                - Move right - because we need to get maximum possible distance between them.
        Case 2: Not possible Solution:
                - Move left - mid (distance) was too high and the cows couldn't be placed on the limited stalls.

    -> While checking for possible solution:
        - First place the first cow at first position.
        - Keep track of the last cow placed.
        - Keep checking the distance between the current stall and last placed cow's position (kept track), check if it exceeds the maximum possible distance (mid) chosen this time.
        - If it exceeds or is equal to maximum distance (mid) chosen, we need to place the current cow here and keep track of this position and move ahead.
        - Before moving to the next position, check if all cows have been placed already (keep track of this too).
        - If all cows have been placed return true, as it is a possible solution.
        - If were not able to place all cows in the stalls, i.e. basically we ran out of stalls, return false as this isn't a possible distance to be taken.

*/

// Solution
bool isPossibleDistance(vector<int>& stalls,int maximumSpaceAllowed,int cows){
    // first cow placed at first position
    int position = stalls[0];       // tracking position of last cow placed
    int cowsCount = 1;          // tracking cows

    for(int i = 1;i < stalls.size() - 1;i++){
        // check the distance between the cow placed at last position and current position
        if((stalls[i] - position) >= maximumSpaceAllowed){
            position = stalls[i];
            cowsCount++;
        }
        // if all cows have been placed in stalls already
        if(cowsCount == cows)
            return true;
        
    }
    // ran out of stalls i.e. space chosen was higher
    return false;
}

int solve(int n, int k, vector<int> &stalls) {
        // first sort the array
        sort(stalls.begin(),stalls.end());
        // let's get search space
        int high = stalls[stalls.size() - 1] - stalls[0];       // highest number - lowest number
        int low = 0;
        int ans = -1;
        while(low <= high){
            int mid = low + ((high - low) >> 1);
            if(isPossibleDistance(stalls,mid,k)){
                ans = mid;
                low = mid  + 1;             // we need to increase the distance between them
            }
            else{
                high = mid - 1;             // distance taken was high, that's why it wasn't a possible solution
            }
            mid = low + ((high - low) >> 1);
        }
        return ans;
    }

int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(4);
    v.push_back(8);
    v.push_back(9);
    int k = 3; 

    cout << "Ans = " << solve(v.size(),k,v) << endl;

    return 0;
}