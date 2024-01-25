#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

/*
                a
             ↙    ↘
            b       c
                  ↙  ↘
                 d --> e
                      ↙
                     f

    -> Use recursion to solve this.
    -> Here also we need to track of visited nodes.

    # Note : there is no need of base case in this.


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



        void dfs(T src, unordered_map <T,bool> &visited){
            visited[src] = true;
            cout << src << " ";

            for(auto nbr : adjList[src]){
                T nbrData = nbr.first;
                if(!visited[nbrData])
                    dfs(nbrData, visited);
            }
        }
};


int main(){
    Graph<char> g;
    g.addEdge('a','b', 100, 1);
    g.addEdge('a','c', 50, 1);
    g.addEdge('c','d', 200, 1);
    g.addEdge('c','e', 150, 1);
    g.addEdge('d','f', 300, 1);
    g.addEdge('e','f', 180, 1);

    unordered_map<char, bool> vis;

    for(char node = 'a'; node <= 'f'; node++)
        if(!vis[node])
            g.dfs('a', vis);

    return 0;
}

// H.W. : Find out no. of disconnected components