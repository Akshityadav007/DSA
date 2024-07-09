#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// Problem || Leetcode : 994
/*
    -> Can call this question Rotting oranges or rotten tomatoes.
    -> You are given an m x n grid where each cell can have one of three values:
        - 0 representing an empty cell,
        - 1 representing a fresh orange, or
        - 2 representing a rotten orange.
    -> Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.
    -> Return the minimum number of minutes that must elapse until no cell has a fresh orange.
    -> If this is impossible, return -1.
*/


// Solution
/*
    -> Similar to flood fill / number of islands.
    -> In case of connected components, return -1.
    -> We can't use DFS here because in case of multiple rotten oranges, T.C. will increase as we need to apply dfs starting from each node.
    -> We'll use BFS instead, as it traverses on each level at same time. Because we insert all source nodes at t = 0 seconds(initial state) in the queue.
*/

class Solution {
    public:
    bool isSafe(int newX, int newY, vector<vector<int>> &temp){
        if(newX >= 0 && newY >= 0 && newX < temp.size() && newY < temp[0].size() && temp[newX][newY] == 1)
            return true;
        return false;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        // BFS
        queue< pair<pair<int,int>, int> > q;    // coordinates[x,y], time
        vector<vector<int>> temp = grid;
        int minTime = 0;

        // inital state - insert all rotten oranges in queue
        for(int row = 0; row < temp.size(); row++)
            for(int col = 0; col < temp[0].size(); col++)
                if(temp[row][col] == 2)
                    q.push({{row,col}, 0});   // time of source = 0
        
        // BFS logic
        while(!q.empty()){
            auto frontPair = q.front();
            q.pop();

            auto frontNodeCoordinates = frontPair.first;
            int frontNodeTime = frontPair.second;

            int nodeX = frontNodeCoordinates.first;
            int nodeY = frontNodeCoordinates.second;

            // we can travel in 4 directions from here - top, down, left, right
            int dx[] = {-1, 1, 0, 0};
            int dy[] = {0, 0, -1, 1};

            for(int i = 0; i < 4; ++i){
                int newX = nodeX + dx[i];
                int newY = nodeY + dy[i];

                if(isSafe(newX, newY, temp)){
                    q.push({{newX, newY}, frontNodeTime + 1});
                    minTime = frontNodeTime + 1;  // update the minimum time
                    // mark this node as rotten
                    temp[newX][newY] = 2;
                }
            }
        }

        // till now all oranges that had to be rotten are done.
        for(int i = 0;i < temp.size(); ++i)
            for(int j = 0;j < temp[0].size(); ++j)
                if(temp[i][j] == 1)
                    return -1;
        
        return minTime;
    }
};


int main(){


    return 0;
}