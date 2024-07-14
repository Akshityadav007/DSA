#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<limits.h>
using namespace std;

// Bellman Ford
/*
    -> Apply loop 'n - 1' times, get the answer simple, (where n is the no. of nodes).
    -> The algo is run 'n - 1' times because that is the maximum time we can run it and be sure that we've got shortest path level wise.
    -> Although we can modify it if after a certain time we run the algo there is no update being done in the array.
    -> Given graph:

                                        2
                            ---> B ------------
                          /     / \  ↖         |
                      -1 /     /   \   \       |  
                        /   3 /     \   \ 1    ⬇
                       A     /     2 \   \     E
                        \   |         \   \    /
                       4 \  |          \   |  / -3
                          ↘ ⬇           ↘ | ↙
                           C <------------ D
                                   5
    
    -> This algorithm is used in case of negative cycle where Dijkstra algo fails.
    -> This algo can detect if there is any negative cycle unlike Dijkstra.

    -> Post running the algo(relaxation) 'n - 1' times, if we run it again and there is an updation in the answer array, we can say there is negative cycle present.
*/

class Graph{
    public:
        unordered_map<char, list<pair<char,int>>> adj;

        void addEdge(char u, char v, int wt, bool direction){
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

        void bellmanFord(int n, char src){
            // initial state
            vector<int> dist(n, INT_MAX);
            dist[src - 'A'] = 0;

            // n - 1 times, relaxation
            for(int i = 1;i < n; i++){
                // traverse on entire edge list
                for(auto a : adj){
                    for(auto b : a.second){
                        int u = a.first - 'A';
                        int v = b.first - 'A';
                        int weight = b.second;

                        // perform relaxation
                        if(dist[u] != INT_MAX && dist[u] + weight < dist[v]){
                            dist[v] = dist[u] + weight;
                        }
                    }
                }
            }
            // shortest distance is ready here
            // we can check for -ve cycle
            bool update = false;

            for(int i = 1;i < n; i++){
                // traverse on entire edge list
                for(auto a : adj){
                    for(auto b : a.second){
                        int u = a.first - 'A';
                        int v = b.first - 'A';
                        int weight = b.second;

                        // perform relaxation
                        if(dist[u] != INT_MAX && dist[u] + weight < dist[v]){
                            update = true;
                            break;
                            dist[v] = dist[u] + weight;
                        }
                    }
                }
            }

            if(update)
                cout << "Negative cycle present!" << endl;
            else{
                cout << "No negative cycle present!" << endl;
                cout << "Distance array:" << endl;
                for(auto i : dist)
                    cout << i << ", ";
            }
            cout << endl;

        }
};


int main(){
    Graph g;
    g.addEdge('A', 'B', -1, 1);
    g.addEdge('A', 'C', 4, 1);
    g.addEdge('B', 'E', 2, 1);
    g.addEdge('B', 'D', 2, 1);
    g.addEdge('B', 'C', 3, 1);
    g.addEdge('E', 'D', -3, 1);
    g.addEdge('D', 'C', 5, 1);
    g.addEdge('D', 'B', 1, 1);

    // g.printList();
    g.bellmanFord(5, 'A');

    return 0;
}