#include<iostream>
#include<unordered_map>
#include<queue>
#include<list>
using namespace std;

// Graph traversal
/*
                a
             ↙    ↘
            b ----> c
                  ↙  ↘
                 d --> e
                      ↙
                     f


    -> There are two traversals:
        1) BFS - Breadth first search
        2) DFS - Depth first search
*/

// BFS
/*
    -> In a graph we traverse it's nodes level wise.
    -> Keep track of nodes we've already visited. (Use any DS)

    -> ** We also need to take care of disconnected graph ** 
        - To handle this, instead of calling function for only one node (source node), we call it for each node.

    -> T.C. : O() || S.C. : O()
*/

template <typename T>
class Graph{
    public:
        unordered_map<T, list< pair<T, int> > > adjList;

        void addEdge(T u, T v, int weight, bool direction){

            if(direction){
                adjList[u].push_back({v, weight});
            }
            else{
                adjList[u].push_back({v, weight});        
                adjList[v].push_back({u, weight});        
            }
        }

        void bfs(T src, unordered_map <T , bool > &visited){
                queue <T> q;                                 // to keep track of levels

                q.push(src);
                visited[src] = true;

                while(!q.empty()){
                    T frontNode = q.front();
                    cout << frontNode << " ";
                    q.pop();

                    // go to neighbour
                    for(auto nbr : adjList[frontNode]){
                        T nbrData = nbr.first;               // we only need the value of node, not the weight
                        
                        // if not already visited
                        if(!visited[nbrData]){
                            q.push(nbrData);
                            visited[nbrData] = true;
                        }
                    }
                }
        }
};



int main(){

    Graph<char> g;

    // connected graph
    // g.addEdge('a', 'b', 5, 0);
    // g.addEdge('a', 'c', 10, 0);
    // g.addEdge('b', 'c', 20, 0);
    // g.addEdge('c', 'd', 50, 0);
    // g.addEdge('c', 'e', 55, 0);
    // g.addEdge('d', 'f', 50, 0);

    // disconnected components
    g.addEdge('a', 'b', 5, 0);
    g.addEdge('a', 'c', 1, 0);
    g.addEdge('b', 'c', 10, 0);
    
    g.addEdge('d', 'e', 55, 0);
    g.addEdge('f', 'f', 50, 0);
    unordered_map < char , bool > visited;              // to keep track of visited nodes
    for(char node = 'a'; node <= 'f'; node++)
        if(!visited[node])
            g.bfs(node, visited);
    

    return 0;
}