#include<iostream>
#include<unordered_map>
#include<list>
#include<map>
#include<stack>
#include<queue>
using namespace std;


/*
    -> This is a linear ordering of vertices such that  for edge [u -> v], u comes before v  in that ordering.
    -> This can only be applied on DAG (Directed acylic graph).

    -> We can solve using both DFS and BFS.
        1) DFS : 
         =>  0
                ↘
                    1
                      ↘
                        2
                          ↘
                            3 --> 5
                            |    |
                            ⬇    ⬇
                            4 --> 6 --> 7
        
        2) BFS : 
         =>  0
                ↘
                  1
                    ↘
                      2 --> 4
                      |     |    6
                      ⬇     ⬇ ↗
                      3 --> 5 
                              ↘
                                7
        -> The node having indegree = 0 (independent) is to be pushed in the queue.
    
    -> We can detect cycle in a graph using topological sort using BFS.
*/


class Graph{
    public:
        unordered_map<int, list<int>> adjList;

        void addEdge(int u, int v, bool direction){
            // undirected : direction = 0
            // directed   : direction = 1
            if(direction == 1){
                adjList[u].push_back(v);
            }
            else{
                adjList[u].push_back(v);
                adjList[v].push_back(u);
            }
        }


        void printList(){
            for(auto i : adjList){
                cout << i.first << " : ";
                for(auto j : i.second){
                    cout << j << ",";
                }
                cout << endl;
            }
        }


        void topSortDFS(int src, map<int, bool> &visited, stack<int> &st){
            visited[src] = true;

            for(auto nbr : adjList[src]){
                if(!visited[nbr]){
                    topSortDFS(nbr, visited, st);               // for every neighbour call topological sort
                }
            }

            st.push(src);
        }

        // Kahn's Algorithm
        void topSortBFS(int n){
            queue<int> q;
            map<int, int> indegree;

            // initialise indegree
            for(auto i : adjList){
                for(auto nbr : i.second){
                    indegree[nbr]++;
                }
            }

            // push all zero indegree nodes into queue
            for(int node = 0; node < n; node++){
                if(indegree[node] == 0)
                    q.push(node);
            }
                                 
            // let's run BFS
            while(!q.empty()){
                int frontNode = q.front();
                q.pop();

                cout << frontNode << " ";

                for(auto nbr : adjList[frontNode]){
                    indegree[nbr]--;

                    // check for zero
                    if(indegree[nbr] == 0)
                        q.push(nbr);
                }
            }
        }
};



int main(){

    Graph g;
    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(2,3,1);
    g.addEdge(3,4,1);
    g.addEdge(3,5,1);
    g.addEdge(4,6,1);
    g.addEdge(5,6,1);
    g.addEdge(6,7,1);

    // g.printList();

    int n = 8;              // no. of nodes
    map<int, bool> visited;
    stack<int> st;
    for(int node = 0; node < n; node++){
        if(!visited[node])
            g.topSortDFS(node, visited, st);
    }

    cout << "Topological sort : "<< endl;
    while(!st.empty()){
        cout << st.top() << endl;
        st.pop();
    }

    // g.topSortBFS(n);

    return 0;
}