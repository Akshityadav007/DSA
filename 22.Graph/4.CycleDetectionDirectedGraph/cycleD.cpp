#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

// Problem || GFG
/*
    -> Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.

*/


// Solution
/*
    # Using DFS
    -> Keep track of calls for each node.
    -> Also backtrack if we move back from a node in calls.
    -> If already made a call for current node, cycle present.

    ->        0
            ↙   ↘
           1 ---> 2
                  ⬇
                  3
                ↙  ↘
               4 --> 5
                   ↙  ↘
                  6 --> 7
                

*/

class Solution {
  public:
    bool checkCyclic(int src, unordered_map<int, bool> &vis, unordered_map<int, bool> &dfsTrack, vector<int> adj[]){
        
        vis[src] = true;
        dfsTrack[src] = true;
        
        for(auto nbr : adj[src]){
            if(!vis[nbr]){
                bool ans = checkCyclic(nbr, vis, dfsTrack, adj);
                if(ans == true)
                    return true;
            }
            else if(vis[nbr] == 1 && dfsTrack[nbr] == 1)
                return true;
        }
        
        // backtrack                --  Usually we forget this
        dfsTrack[src] = false;
        
        return false;
    }
    
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        unordered_map<int, bool> vis;
        unordered_map<int, bool> dfsTrack;
        for(int i = 0;i < V; i++){
            if(!vis[i]){
                bool cyclePresent = checkCyclic(i, vis, dfsTrack, adj);
                if(cyclePresent == true)
                    return true;
            }
        }
        return false;
    }
};



int main(){

    return 0;
}