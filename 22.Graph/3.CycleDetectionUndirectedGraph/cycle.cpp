#include<iostream>
#include<unordered_map>
#include<vector>
#include<list>
#include<queue>
using namespace std;


// Problem || GFG
/*
    -> Given an undirected graph with V vertices labelled from 0 to V-1 and E edges, check whether it contains any cycle or not. 
    -> Graph is in the form of adjacency list where adj[i] contains all the nodes ith node is having edge with.

*/


// Solution
// Theory
/*
    -> Cycle detection is done in both directed/undirected graph in two ways:
        - 1) BFS
        - 2) DFS
    
    # 1) Undirected graph
            0 ------ 1 ----- 2 ------ 5
                     |       |
                     3 ----- 4
        
        -> Cycle is present we can see.
        -> Let's solve this code wise:
            - 1) Using BFS
                - If we can reach a node from a node other than it's parent node (in BFS), then there is a cycle.
                - For this we need to keep track of parent node of each node along with keeping track of visited nodes.
                - i.e. if(visited[child] = True && parent[frontNode] != child), => then there is a cycle.
                - Set the parent of non visited nodes.
            - 2) Using DFS
                - Keep marking visited nodes and their parents.
                - If we get a node which is already visited and it's parent is different reutrn false;

*/

template <typename T>
class Graph{
    public:
        unordered_map<T, list<int> > adjList;

        void addEdge(T u, T v, bool direction){
            // u - starting node
            // v - ending node
            // direction = 0 -> undirected graph
            // direction = 1 -> directed graph

            if(direction){
                // from u to v : u -> v
                adjList[u].push_back({v});
            }
            else{
                // undirected
                // u <--> v 
                adjList[u].push_back({v});        // u ---> v
                adjList[v].push_back({u});        // u <--- v
            }
        }


        void printAdjList(){
            for(auto i : adjList){
                cout << i.first << ": { ";
                for(auto p : i.second){
                    cout << "{" << p.first << ", " << p.second << "}, ";
                }
                cout << "}" << endl;
            }
        }

        bool checkCyclicUndirectedGraphBFS(int src){
            queue<int> q;
            unordered_map<int, bool> visited;
            unordered_map<int, int> parent;             // keep track of parent nodes

            // initial state
            q.push(src);
            visited[src] = true;
            parent[src] = -1;

            while(!q.empty()){
                int frontNode = q.front();
                q.pop();

                for(auto nbr : adjList[frontNode]){
                    if(!visited[nbr]){
                        q.push(nbr);
                        visited[nbr] = true;
                        parent[nbr] = frontNode;
                    }
                    else if(visited[nbr] == true && nbr != parent[frontNode])
                        return true;                                                // cycle present
                }
            }
            return false;                       // cycle not present
        }
};



// GFG Solution
// BFS
class Solution {
  public:
 // Function to detect cycle in an undirected graph.
    bool solveUsingBFS(int src, unordered_map<int, bool> &visited, vector<int> adj[]){
        queue<int> q;
        unordered_map<int, int> parent;             // keep track of parent nodes

        // initial state
        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            
            // check each neighbour of current node (to check all nodes from which we can visit this node)
            for(auto nbr : adj[frontNode]){
                if(!visited[nbr]){                          // first time visit, then add parent node
                    q.push(nbr);
                    visited[nbr] = true;
                    parent[nbr] = frontNode;
                }
                else if(visited[nbr] == true && nbr != parent[frontNode])        // already visited
                    return true;                                                // cycle present
            }
        }
        return false;                       // cycle not present
    }
    bool isCycle(int V, vector<int> adj[]) {
        unordered_map<int, bool> visited;
       for(int i = 0;i < V; i++){
           if(!visited[i]){
            bool ans = solveUsingBFS(i, visited, adj);
            if(ans == true)
                return true;
           }
       }
       
       return false;
    }
};


// DFS
class Solution {
  public:
 // Function to detect cycle in an undirected graph.
    bool solveUsingDFS(int src, unordered_map<int, bool> &visited, vector<int> adj[], int parent){
        visited[src] = true;
        
        for(auto nbr : adj[src]){
            if(nbr == parent)
                continue;                       // don't check for it's parent
                
            if(!visited[nbr]){
                bool ans = solveUsingDFS(nbr, visited, adj, src);
                if(ans == true)
                    return true;
            }
            else if(visited[nbr] == 1)          // if it is already visited, this means there is a cycle
                return true;
        }
        
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        unordered_map<int, bool> visited;
       for(int i = 0;i < V; i++){
           if(!visited[i]){
                int parent = -1;
                bool ans = solveUsingDFS(i, visited, adj, parent);
                if(ans == true)
                    return true;
           }
       }
       
       return false;
    }
};









int main(){
    Graph<int> g;
    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    g.addEdge(1,3,0);
    g.addEdge(2,4,0);
    g.addEdge(3,4,0);
    g.addEdge(2,5,0);

    bool isCyclic = g.checkCyclicUndirectedGraphBFS(0);

    if(isCyclic)
        cout << "Cycle is present!" << endl;
    else
        cout << "Cycle is not present!" << endl;


    return 0;
}