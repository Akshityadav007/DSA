#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

// Graph theory
/*
    # What is a Graph ?
        -> A type of DS built by edges and nodes.
        -> Nodes are connected using edges with each other.

    - Types of edges
        1) Directed edge    - Edge with directions (->)
        2) Undirected edge  - Edges with no direction.
    
    - Convert undirected graph to directed graph :
        -> Assign direction in both direction of nodes.
            E.g. : 1) 
                        A -- B -- C
                        |  /    /
                        D------|

                        This is an undirected graph. Convert it to directed graph.
                    Ans =     A <--> B <--> C
                              ⬆     ↗       ⬆
                              |  ↙          |
                              ⬇             |
                              D <----------⤴
    - Use of graph : Google maps, Facebook, Instagram, etc. all networking things..

    - Number written on edge is called weight. Graph with weight on edges is called weighted graph.

    # Cycles
        -> Cyclic graph : If starting from a node, we reach to the same starting node then it is a cyclic graph.
        -> Acyclic graph: If on starting from a node, we can't reach the same starting node, then it is called acyclic graph.

    # Degree
        -> The no. of nodes a node is connected is called it's degree. (this comes in undirected graph.)
        => Indegree : No. of nodes pointing to a particular node is called it's indegree. (this comes in directed graph.)
        => Outdegree : No. of nodes a node is pointing to is called it's outdegree.
    
    # Path
        -> The way by which we can reach a particular node from a node using the connected edges in a graph is called a path.
        -> A path can't have repeating nodes i.e. no cycle.
    
    # Components
        -> All parts including edges, nodes, connected/disconnected graphs make up components of graph.
    
    # Ques. Is every tree a graph ?
        Ans. Yes but vice versa is not true.


    # Questions repeating on graph:
        1) Clone a graph
        2) 
*/


// Graph creation
/*
    # Can be built using two ways:
        1) Adjacency matrix
        2) Adjacency list

    Ques. Below is given a graph:

            0 ------> 1
                    ↙   ↘
                   2 ---> 3
            
            Implement it.
        
    Ans. 
        Edge list:
            0 -> 1
            1 -> 2
            2 -> 3
            1 -> 3
    
    - It can be implemented in using adjacency matrix:

    1) Adjacency matrix
        -> Create a n * n matrix, where n = no. of edges in  graph.
            R/C 0   1   2   3
            0  [0   1   0   0] 
            1  [0   0   1   1]
            2  [0   0   0   1]
            3  [0   0   0   0]  
        
        -> Fill the row and columns of matrix in a way:
            - row -> col = 1      (from edge list)
            - E.g. 0 -> 1, then matrix of [0,1] = 1, i.e. arr[0][1] = 1
            - Mark 1 where there is an edge from row -> column, rest others to be marked 0.

        -> S.C. : O(n ^ 2)
        -> T.C. : O(n ^ 2)

    Ques. Below is given a graph:

               0 ---> 1
                    ↙   ↘
                   2 ---> 3 --> 4
                          ⬆  ↙
                          5
            
            Implement it.

    2) Adjacency list
        -> We need to create a list displaying immediate neighbour of a node.

        -> Adjacency list:
            0: {1}
            1: {2,3}
            2: {3}
            3: {4}
            4: {5}
            5: {3}
        
        -> Now use hashmap to store these values:
            map<int, list<int>> m;                                      // here instead of list, we can also use vector<int>
        -> But to store weight we need to store in pairs, i.e.
            map<int, list< pair<int, int> > m;
                ⬆
              source node
        
    
    # To learn about list:
        goto -> https://en.cppreference.com/w/cpp/container/list

*/


class Graph{
    public:
        unordered_map<int, list< pair<int, int> > > adjList;

        void addEdge(int u, int v, int weight, bool direction){
            // u - starting node
            // v - ending node
            // direction = 0 -> undirected graph
            // direction = 1 -> directed graph

            if(direction){
                // from u to v : u -> v
                adjList[u].push_back({v, weight});
            }
            else{
                // undirected
                // u <--> v 
                adjList[u].push_back({v, weight});        // u ---> v
                adjList[v].push_back({u, weight});        // u <--- v
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
};


// We can make this generic by using template   :   We can have any data type at the places where we write 'T'
template <typename T>
class Graph2{
    public:
        unordered_map<T, list< pair<T, int> > > adjList;

        void addEdge(T u, T v, int weight, bool direction){
            // u - starting node
            // v - ending node
            // direction = 0 -> undirected graph
            // direction = 1 -> directed graph

            if(direction){
                // from u to v : u -> v
                adjList[u].push_back({v, weight});
            }
            else{
                // undirected
                // u <--> v 
                adjList[u].push_back({v, weight});        // u ---> v
                adjList[v].push_back({u, weight});        // u <--- v
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
};




int main(){

    cout << "Non - generic graph: " << endl;
    Graph g;
    g.addEdge(0,1,30,1);
    g.addEdge(1,2,50,1);
    g.addEdge(1,3,60,1);
    g.addEdge(2,3,20,1);
    
    g.printAdjList();


    cout << "Generic graph: " << endl;

    // generic graph
    Graph2<int> g2;          // or Graph2<string> g2;
    g2.addEdge(4,5,60,1);
    g2.addEdge(5,6,80,1);
    g2.addEdge(5,8,40,1);
    g2.addEdge(6,8,340,1);

    g2.printAdjList();
    return 0;
}