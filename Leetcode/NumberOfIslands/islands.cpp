#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;

// Problem || Leetcode: 200
/*
    -> Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
    -> An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
    ->  You may assume all four edges of the grid are all surrounded by water.
*/


// Solution
/*
    -> Similar to number of provinces where we had to count components.
    -> Here also we can count components.
    -> We've solved similar problem earlier using DFS, now we'll solve using BFS.

    -> In earlier problem (number of provinces), we considered index as nodes. But in this problem we'll consider the cell as node.
*/


class Solution {
public:
    bool isSafe(int newX,int newY, vector<vector<char>> &grid, map<pair<int,int>, bool> &isVis){
        if(newX >= 0 && newY >= 0 && newX < grid.size() && newY < grid[0].size() && grid[newX][newY] == '1' && !isVis[{newX, newY}])
            return true;
        return false;
    }
    void bfs(int srcX, int srcY, map<pair<int,int>, bool> &isVis, vector<vector<char>> &grid){
        queue<pair<int, int>> q;

        // initial state
        q.push({srcX,srcY});
        isVis[{srcX, srcY}] = true;

        while(!q.empty()){
            pair<int, int> island = q.front();
            q.pop();

            int nbrX = island.first;
            int nbrY = island.second;

            // we can travel top, down, left, right
            int dRow[] = {-1, 1, 0, 0};
            int dCol[] = {0, 0, -1, 1};

            for(int i = 0;i < 4; i++){
                int newX = nbrX + dRow[i];
                int newY = nbrY + dCol[i];
                if(isSafe(newX, newY, grid, isVis)){
                    q.push({newX, newY});
                    isVis[{newX, newY}] = true;
                }
            }
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        // similar to number of provinces
        map<pair<int,int>, bool> isVis;

        int totalRows = grid.size();
        int totalColumns = grid[0].size();
        int islands = 0;

        for(int row = 0; row < totalRows; row++){
            for(int col = 0; col < totalColumns; col++){
                // bfs call only for unvisited 'islands'
                if(!isVis[{row, col}] && grid[row][col] == '1'){
                    bfs(row, col, isVis, grid);
                    islands++;
                }
            }
        }
        return islands;
    }
};



int main(){


    return 0;
}