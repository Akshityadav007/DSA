#include<iostream>
#include<unordered_map>
#include<vector>
#include<list>
using namespace std;

// Floyd Warshall Algorithm
/*
    -> This algorithm is used to get shortest path to multiple destination from mulitple sources.
    ->
                         5
                0️⃣ ------------> 3️⃣
               ↗ |             ↗  |
              /  |           /    |
             /  3|         /      |
           2|    |      4/        | 2
             \   |      /         |
               \ |    /           |
                |⬇  /             ⬇
                1️⃣ <------------ 2️⃣
                         1
    
    -> Get the shortest path from each node to every node.
*/

// Solution
/*
    -> We will return a 2 - D array of shortes distance.
    -> Initial state will be like from source -> source shortest path will be 0, hence put 0 where i == j. Rest all be initally ♾️.

    -> It's a brute force approach where we get all paths from src -> destination and store the minimum distance of them all.
    -> We use all helper nodes from src -> dest  i.e. (dist[src -> helper] + dist[helper -> dest]) in this approach. All nodes in except src and destination form helper nodes.


    => T.C. : O(n ^ 3)
    => S.C. : O(n ^ 2)
*/


class Graph{
    public:
        unordered_map<int, list<pair<int,int>>> adj;

        void addEdge(int u, int v, int wt, bool direction){
            if(direction){
                // directed
                adj[u].push_back({v, wt});
            }
            else{
                // undirected
                adj[u].push_back({v, wt});
                adj[v].push_back({u, wt});
            }
        }

        void printList(){
            for(auto i : adj){
                cout << i.first << " : [ ";
                for(auto j : i.second){
                    cout << "{" << j.first << ", " << j.second << "}" << ", ";
                }
                cout << "]" << endl;
            }
        }

        void floydWarshall(int n){
            vector<vector<int>> dist(n, vector<int> (n, 1e9));                  // why 1e9 instead INT_MAX ?

            // initial state
            for(int i = 0;i < n; i++){
                dist[i][i] = 0;
            }

            // update dist array according to the weights given in the graph
            for(auto a : adj){
                for(auto b : a.second){
                    int u = a.first;
                    int v = b.first;
                    int wt = b.second;

                    dist[u][v] = wt;
                }
            }

            // main logic - helper logic
            for(int helper = 0; helper < n; helper++){
                for(int src = 0; src < n; src++){
                    for(int dest = 0; dest < n; dest++){
                        dist[src][dest] = min(dist[src][dest], dist[src][helper] + dist[helper][dest]);
                    }
                }
            }

            // printing the distance array
            for(auto v : dist){
                for(auto n: v){
                    cout << n << " ";
                }
                cout << endl;
            }

        }
};



int main(){

    Graph g;
    g.addEdge(0, 1, 3, 1);
    g.addEdge(0, 3, 5, 1);
    g.addEdge(1, 0, 2, 1);
    g.addEdge(1, 3, 4, 1);
    g.addEdge(2, 1, 1, 1);
    g.addEdge(3, 2, 2, 1);

    g.floydWarshall(4);

    return 0;
}