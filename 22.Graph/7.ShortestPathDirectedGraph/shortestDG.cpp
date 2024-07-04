#include<iostream>
#include<unordered_map>
#include<list>
#include<stack>
#include<vector>
#include<limits.h>
using namespace std;

// Problem
/*
    -> Given a directed weighted graph, find the shortest path to a 'destination' node from a single 'source'.
    ->    
            0️⃣ ----5----> 1️⃣ ------3------> 3️⃣
             \           ↗                  ↗ ⬆
              3        2                  /    1
               \     /  ---------3------/       \
                ↘   / /                          \
                  2️⃣ --------------6-------------> 4️⃣
*/

// Solution
/*
    -> Here we can't use BFS algorithm, because the weight of the edges won't be uniform.
    -> We will use DFS algorithm + topological ordering for traversal.

    -> To store the shortest distance we'll use an array/vector initialized with highest value possible(except for the source node, which has 0).
    -> Use a stack to store the topologial order of the graph.
    -> Now, get the shortest distance for each of the nodes and assign to their neighbours.
*/

class Graph{
    public:
        unordered_map<int, list<pair<int, int>>> adj;       // stores neighbour nodes along with their distance/weight

        void addEdge(int u, int v, int wt, bool direction){
            if(direction){
                // directed graph
                adj[u].push_back({v,wt});
            }
            else{
                // undirected graph
                adj[u].push_back({u,wt});
                adj[v].push_back({v,wt});
            }
        }

        void printGraph(){
            for(auto i : adj){
                cout << i.first << " : {";
                for(auto j : i.second){
                    cout << " ( " << j.first << " , " << j.second << " ) ";
                }
                cout << "}" << endl;
            }
        }

        void topologicalOrderDFS(int src, stack<int> &topo, vector<bool> &visited){
            visited[src] = true;
            for(auto nbrPair : adj[src]){
                int nbr = nbrPair.first;
                if(!visited[nbr])
                    topologicalOrderDFS(nbr, topo, visited);
            }
            topo.push(src);
        }

        vector<int> shortestPath(stack<int> &topo, int totalNodes){
            vector<int> dist(totalNodes, INT_MAX);        // to store answer

            // first work out for the first/source node.
            int src = topo.top();
            dist[src] = 0;
            topo.pop();

            for(auto i : adj[src]){
                int nbr = i.first;
                int nbrDist = i.second;

                // assign the minimum distance from where we can reach the nbr node 
                // check which is small the distance used to reach it earlier, or the distance from the current node
                dist[nbr] = min(dist[nbr], dist[src] + nbrDist);                
            }


            // then work out for the other nodes similarly

            while(!topo.empty()){
                int src = topo.top();
                topo.pop();

                for(auto i : adj[src]){
                    int nbr = i.first;
                    int nbrDist = i.second;
                    dist[nbr] = min(dist[nbr], dist[src] + nbrDist);                
                }
            }

            return dist;
        }

};



int main(){

    Graph g;
    g.addEdge(0,1,5,true);
    g.addEdge(0,2,3,true);
    g.addEdge(1,3,3,true);
    g.addEdge(2,1,2,true);
    g.addEdge(2,3,3,true);
    g.addEdge(2,4,6,true);
    g.addEdge(4,3,1,true);

    // g.printGraph();

    // get the topological order
    stack<int> topo;
    vector<bool> visited(5, false);
    g.topologicalOrderDFS(0, topo, visited);

    vector<int> shortestPathFromSrc = g.shortestPath(topo, 5);

    for(int i = 0;i < shortestPathFromSrc.size(); i++)
        cout << "Shortest path from source to " << i << " is " << shortestPathFromSrc[i] << endl;

    return 0;
}