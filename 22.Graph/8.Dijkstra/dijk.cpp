#include<iostream>
#include<unordered_map>
#include<list>
#include<stack>
#include<vector>
#include<set>
using namespace std;

// Dijkstra Algorithm
/*
    -> It is a greedy algorithms.
    -> 
                                5️⃣
                             /      \
                           9          6       
                          /            \
                        6️⃣             4️⃣
                        | \            / |
                        |   2        11  |
                        |    \      /    |
                       14       3️⃣      15
                        |     /    \     |  
                        |   9       10   |
                        | /           \  |
                        1️⃣ ----- 7 -----2️⃣ 
    
    -> We need to get shortest path from one given node to another nodes.
*/

/*
    -> We will use a set/min_heap to store the node and their distance. 
    -> Because in sets/min_heaps the first node is got in O(1) T.C.
    -> And here we need shortest distance node in least T.C.


    -> Limitations of Dijkstra:
        - Unreachable nodes.
        - Negative cycle (on adding weight, it becomes -ve).
        - Negative weights.
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
                adj[u].push_back({v,wt});
                adj[v].push_back({u,wt});
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

        int dijkstraShortestDistance(int totalNodes, int src, int dest){
            vector<int> dist(totalNodes + 1, INT_MAX);
            set<pair<int, int>> st;                     // stores {distance, node}

            // initial state
            st.insert({0,src});
            dist[src] = 0;

            while(!st.empty()){
                auto topElement = st.begin();              // got the reference of starting
                pair<int, int> topPair = *topElement;      // derefrenced

                int topDistance = topPair.first;
                int topNode = topPair.second;

                // remove the top node
                st.erase(st.begin());

                // update distance of neighbour
                for(auto nbr : adj[topNode]){
                    int nbrNode = nbr.first;
                    int nbrDistance = nbr.second;

                    if(nbrDistance + topDistance < dist[nbrNode]){
                        // found a new shorter distance
                        // update - 1) set entry ; 2) dist entry
                        // to update set entry, we need to erase the entry first and then add it again (no direct updation in set is possible)
                        auto previousEntry = st.find({dist[nbrNode], nbrNode});
                        if(previousEntry != st.end())
                            st.erase(previousEntry);
                        

                        dist[nbrNode] = nbrDistance + topDistance;
                        st.insert({dist[nbrNode], nbrNode});
                    }
                }
            }

            return dist[dest];
        }

};



int main(){

    Graph g;
    g.addEdge(1,6,14,false);
    g.addEdge(1,3,9,false);
    g.addEdge(1,2,7,false);
    g.addEdge(2,3,10,false);
    g.addEdge(2,4,15,false);
    g.addEdge(3,4,11,false);
    g.addEdge(6,3,2,false);
    g.addEdge(6,5,9,false);
    g.addEdge(5,4,6,false);

    // g.printGraph();

    int totalNodes = 6, source = 6, destination = 4;
    
    int ans = g.dijkstraShortestDistance(totalNodes, source, destination);

    cout << "Shortest path from " << source << " to " << destination << " is " << ans << endl;

    return 0;
}