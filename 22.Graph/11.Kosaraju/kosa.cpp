#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<stack>
using namespace std;


// Kosaraju Algorithm
/*
    -> This algo bring out strongly connected component(a component in which we can reach from one node to another node).
    ->

                0️⃣ -------------> 1️⃣
                 ⬆                 |
                 |                 |
                 |                 |                         5️⃣
                 |                 |                      ↗      \
                 |                 |                    /         \
                 |                 ⬇                   /            ↘
                 3️⃣ <------------ 2️⃣ ------------> 4️⃣ <------------ 6️⃣ -------------> 7️⃣

                        SCC1                                SCC2                        SCC3

    -> Question:
        1) Count all SCCs (strongly connected graphs).
        2) Print all SCCs.
    
*/


// Solution
/*
    -> We'll use 2 tools: 1) Edge reversal , 2) DFS
    -> Get the ordering of nodes : If we follow this ordering, either this ordering will make us traverse the current component or will take us to already visited components.
    -> Reverse all edges.
    -> Count the components.

    -> Keep track of visited nodes to avoid unnecessary traversal thus optimising the algo.
*/



class Graph{
    public:
        unordered_map<int, list<int>> adj;

        void addEdge(int u, int v, bool direction){
            if(direction){
                // directed
                adj[u].push_back(v);
            }
            else{
                // undirected
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }

        void printList(){
            for(auto i : adj){
                cout << i.first << " : [ ";
                for(auto j : i.second){
                    cout << j << ", ";
                }
                cout << "]" << endl;
            }
        }



        void dfs1(int node, stack<int> &ordering, unordered_map<int, bool> &vis){
            vis[node] = true;

            for(auto nbr : adj[node]){
                if(!vis[nbr])
                    dfs1(nbr, ordering, vis);
            }

            // on return push in stack
            ordering.push(node);
        }

        void dfs2(int node, unordered_map<int, list<int>> &adjNew, unordered_map<int, bool> &vis2){
            vis2[node] = true;
            cout << node << ", ";

            for(auto nbr : adjNew[node]){
                if(!vis2[nbr])
                    dfs2(nbr, adjNew, vis2);
            }
            
        }

        void getStronglyConnectedComponents(int n){
            // step 1: get the ordering
            stack<int> ordering;
            unordered_map<int, bool> vis;

            for(int i = 0;i < n; i++){
                if(!vis[i]){
                    dfs1(i, ordering, vis);
                }
            }


            // step 2: edge reversal
            unordered_map<int, list<int>> adjNew;
            for(auto a : adj){
                for(auto b : a.second){
                    int u = a.first;
                    int v = b;
                    // create v -> u entry (reverse the edge)
                    adjNew[v].push_back(u);
                }
            }

            // step 3 : traverse using ordering and count components
            int count = 0;
            unordered_map<int, bool> vis2;

            while(!ordering.empty()){
                int node = ordering.top();
                ordering.pop();

                if(!vis2[node]){
                    cout << "SCC #" << count + 1 << ": ";
                    dfs2(node, adjNew, vis2);
                    ++count;
                    cout << endl;
                }
            }

            cout << "Total SCC : " << count << endl;
        }

};




int main(){

    Graph g;
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 0, 1);

    g.addEdge(2, 4, 1);

    g.addEdge(4, 5, 1);
    g.addEdge(5, 6, 1);
    g.addEdge(6, 4, 1);

    g.addEdge(6, 7, 1);


    g.getStronglyConnectedComponents(8);

    return 0;
}