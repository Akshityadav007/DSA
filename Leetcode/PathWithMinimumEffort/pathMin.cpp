#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// Problem || Leetcode : 1631
/*
    -> You are a hiker preparing for an upcoming hike. 
    -> You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). 
    -> You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed).
    -> You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.
    -> A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.
    -> Return the minimum effort required to travel from the top-left cell to the bottom-right cell.
*/


// Solution
/*
    -> 
*/


class Solution {
public:
    bool isSafe(int newX,int newY,int rows,int cols,vector<vector<int>> &diff, int currX, int currY){
        // 1. should not go out of bound
        // 2. new node should not already have a diff lesser than current difference
        if(newX >= 0 && newY >= 0 && newX < rows && newY < cols && diff[currX][currY] < diff[newX][newY]){
            return true;
        }
        return false;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int,pair<int, int>>>> minHeap;
        // min heap used to store minimum effort, to the node coordinates

        int rows = heights.size();
        int cols = heights[0].size();
        int destX = rows - 1;
        int destY = cols - 1;

        vector<vector<int>> diff(rows, vector<int> (cols, INT_MAX));
        // diff stores max difference of minimum effort to reach a node

        // initial state
        // set source(0,0) distance to 0, and enter it to min heap
        diff[0][0] = 0;
        minHeap.push({0, {0,0}});

        while(!minHeap.empty()){
            auto topPair = minHeap.top();
            minHeap.pop();

            int currDiff = topPair.first;
            pair<int, int> currNodeIndices = topPair.second;
            int currX = currNodeIndices.first;
            int currY = currNodeIndices.second; 

            // now travel to all it's neighbour - top, down, left, right
            int dx[] = {-1, 1, 0, 0};       // row - top, down movement => + 1
            int dy[] = {0, 0, -1, 1};       // col - left, right movement => - 1

            for(int i = 0;i < 4; i++){
                int newX = currX + dx[i];
                int newY = currY + dy[i];

                if(isSafe(newX, newY, rows, cols, diff, currX, currY)){
                    int maxDiff = max(currDiff, abs(heights[currX][currY] - heights[newX][newY]));
                    // update minimum difference in diff array
                    diff[newX][newY] = min(diff[newX][newY], maxDiff);

                    // make entry in min heap
                    if(newX != destX || newY != destY)
                        minHeap.push({diff[newX][newY], {newX, newY}});
                }
            }
        }
        return diff[destX][destY];
    }
};


int main(){

    return 0;
}