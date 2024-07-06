#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;


// Problem || Leetcode : 210
/*
    -> There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1.
    -> You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
    -> For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
    -> Return the ordering of courses you should take to finish all courses.
    -> If there are many valid answers, return any of them.
    -> If it is impossible to finish all courses, return an empty array.
*/

void topoSortBFS(int n, vector<int> &topo, unordered_map<int, vector<int>> &adj){
    // get the indegree
    queue<int> q;
    unordered_map<int, int> indegree;

    // mark indegree
    for(auto i : adj)
        for(auto nbr : i.second)
            indegree[nbr]++;

    // push the 0 indegree nodes to queue
    for(int node = 0; node < n; node++)
        if(indegree[node] == 0)
            q.push(node);
    
    // BFS
    while(!q.empty()){
        int frontNode = q.front();
        q.pop();
        topo.push_back(frontNode);

        for(auto nbr : adj[frontNode]){
            indegree[nbr]--;

            if(indegree[nbr] == 0)
                q.push(nbr);
        }
    }
}
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    unordered_map<int, vector<int>> adj;

    for(auto i : prerequisites){
        int u = i[1];
        int v = i[0];
        adj[u].push_back(v);
    }

    vector<int> topSort;
    topoSortBFS(numCourses, topSort, adj);

    if(numCourses == topSort.size())
        return topSort;
    else
        return vector<int>();
}



int main(){

    return 0;
}