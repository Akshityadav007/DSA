#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;

/*
    1) Using BFS
        -> The node touched for the first time is the shortest path (undirected graph).

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

        void shortestPathBFS(int src, int dest){
            queue<int> q;
            map<int, bool> visited;
            map<int, int> parent;

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
                        parent[nbr] = frontNode;
                        visited[nbr] = true;
                    }
                }
            }

            // parent is ready
            vector<int> ans;
            while(dest != -1){
                ans.push_back(dest);
                dest = parent[dest];
            }
            reverse(ans.begin(), ans.end());

            // print the shortest path
            for(int i : ans)
                cout << i << " ";
            cout << endl;
        }
};


int main(){

    Graph g;
    g.addEdge(0,5,0);
    g.addEdge(5,4,0);
    g.addEdge(4,3,0);
    g.addEdge(0,6,0);
    g.addEdge(6,3,0);
    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    g.addEdge(2,3,0);

    g.shortestPathBFS(0, 3);

    return 0;
}