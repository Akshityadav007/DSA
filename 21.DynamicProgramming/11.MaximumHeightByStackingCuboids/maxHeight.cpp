#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


// Problem || Leetcode : 1691 || (Didn't get anything in this)
/*
    -> Given n cuboids where the dimensions of the ith cuboid is cuboids[i] = [widthi, lengthi, heighti] (0-indexed). 
    -> Choose a subset of cuboids and place them on each other.
    -> You can place cuboid i on cuboid j if widthi <= widthj and lengthi <= lengthj and heighti <= heightj. 
    -> You can rearrange any cuboid's dimensions by rotating it to put it on another cuboid.
    -> Return the maximum height of the stacked cuboids.
*/



// Solution
/*
    # Method 1 : tabulation
*/


// Method 1
class Solution {
public:
    bool check(vector<int> &curr, vector<int> &prev){
        if(curr[0] >= prev[0] && curr[1] >= prev[1] && curr[2] >= prev[2])
            return true;
        else
            return false;
    }
    int solveUsingTabulationSO(vector<vector<int>> &cuboids){
        int n = cuboids.size();   
        vector<int> currRow(n + 1, 0); 
        vector<int> nextRow(n + 1, 0);
        
        for(int currIndex = n - 1; currIndex >= 0; currIndex--){
            for(int prevIndex = n - 1; prevIndex >= -1; prevIndex--){

                int include = 0;
                if(prevIndex == -1 || check(cuboids[currIndex] , cuboids[prevIndex])){
                    int heightToAdd = cuboids[currIndex][2];
                    include = heightToAdd + nextRow[currIndex + 1];
                }
                int exclude = 0 + nextRow[prevIndex + 1];
                currRow[prevIndex + 1] = max(include, exclude);

            }
            // shifting
            nextRow = currRow;
        }

        return nextRow[0];
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        // sort the cuboids to get the maximum base
        for(auto &cuboid : cuboids)
            sort(cuboid.begin(), cuboid.end());
        
        sort(cuboids.begin(), cuboids.end());
        int ans = solveUsingTabulationSO(cuboids);
        return ans;
    }
};


int main(){

    return 0;
}