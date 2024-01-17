#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Problem || Leetcode : 354
/*
    -> You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.
    -> One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.
    -> Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).
    -> Note: You cannot rotate an envelope.
*/



// Solution
/*
    # Method 1 : Tabulation (TLE)

    # Method 2 : BinarySearch

*/


// Method 1
class Solution {
public:
    bool check(vector<int> &curr, vector<int> &prev){
        if(curr[0] > prev[0] && curr[1] > prev[1])
            return true;
        else
            return false;
    }
    int solveUsingTabulationSO(vector<vector<int>> &env){
        int n = env.size();   
        vector<int> currRow(n + 1, 0); 
        vector<int> nextRow(n + 1, 0);
        
        for(int currIndex = n - 1; currIndex >= 0; currIndex--){
            for(int prevIndex = n - 1; prevIndex >= -1; prevIndex--){

                int include = 0;
                if(prevIndex == -1 || check(env[currIndex] , env[prevIndex])){
                    include = 1 + nextRow[currIndex + 1];
                }
                int exclude = 0 + nextRow[prevIndex + 1];
                currRow[prevIndex + 1] = max(include, exclude);

            }
            // shifting
            nextRow = currRow;
        }

        return nextRow[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end());
        return solveUsingTabulationSO(envelopes);
    }
};


int main(){


    return 0;
}