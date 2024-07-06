#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>
using namespace std;

// Problem || Leetcode : 207
/*
    -> There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1.
    -> You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
    -> For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
    -> Return true if you can finish all courses. Otherwise, return false.
*/

// Solution
/*
    -> Use topological sorting to solve this. In topo sort, for cycles it doesn't sort.
*/


void topologicalSortBFS(int n, vector<int> &topOrder, unordered_map<int, vector<int>> &adj){
    queue<int> q;
    unordered_map<int, int> indegree;

    for(auto i : adj)
        for(auto nbr : i.second)
            indegree[nbr]++;
        
    // push all 0 indegree node to queue
    for(int node = 0; node < n; node++)
        if(indegree[node] == 0)
            q.push(node);
    
    // BFS
    while(!q.empty()){
        int frontNode = q.front();
        q.pop();
        topOrder.push_back(frontNode);

        for(auto nbr : adj[frontNode]){
            indegree[nbr]--;

            // check for zero
            if(indegree[nbr] == 0)
                q.push(nbr);
        }
    }
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    // first create the adj list of graph
    unordered_map<int, vector<int>> adj;

    for(auto i : prerequisites){
        int u = i[1];
        int v = i[0];
        adj[u].push_back(v);
    }

    // perform topological sort
    vector<int> topoSort;

    topologicalSortBFS(numCourses, topoSort, adj);
    
    if(topoSort.size() == numCourses)
        return true;
    return false;
}   

int main(){

    return 0;
}