#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

// Problem || Leetcode : 547
/*
    -> There are n cities. Some of them are connected, while some are not.
    -> If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.
    -> A province is a group of directly or indirectly connected cities and no other cities outside of the group.
    -> You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.
    -> Return the total number of provinces.
*/

// Solution
/*
    -> Simple solve it using DFS.
    -> We need to count components of graph.
*/


class Solution {
public:
    void dfs(int src, unordered_map<int, bool> &isVis, vector<vector<int>>& isConnected){
        isVis[src] = true;

        // to traverse neighbours of src/row node, we can traverse the columns
        for(int col = 0; col < isConnected.size(); col++)
            if(isConnected[src][col] && !isVis[col])
                dfs(col, isVis, isConnected);

    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int components = 0;

        unordered_map<int, bool> isVis;

        for(int i = 0;i < n; i++){
            if(!isVis[i]){
                dfs(i, isVis, isConnected);
                ++components;
            }
        }

        return components;
    }
};

int main(){

    return 0;
}