#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


// Problem || Leetcode : 133
// Couldn't solve
/*
    -> Given a reference of a node in a connected undirected graph.
    -> Return a deep copy (clone) of the graph.
    -> Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

        class Node {
            public int val;
            public List<Node> neighbors;
        }
 

    -> Test case format:

        - For simplicity, each node's value is the same as the node's index (1-indexed). 
        - For example, the first node with val == 1, the second node with val == 2, and so on.
        - The graph is represented in the test case using an adjacency list.
        - An adjacency list is a collection of unordered lists used to represent a finite graph.
        - Each list describes the set of neighbors of a node in the graph.
        - The given node will always be the first node with val = 1. 
        - You must return the copy of the given node as a reference to the cloned graph.
*/

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};




// Solution
/*
    -> We use dfs to solve this.
    -> We map old graph with new one.

*/

class Solution {
public:
    Node *dfs(Node *node, unordered_map<Node*, Node*> &mp){
        Node *newNode = new Node(node -> val);
        vector<Node*> nbrs;
        mp[node] = newNode;

        // dfs for each neighbour
        for(auto i : node -> neighbors){
            if(mp.find(i) != mp.end()){
                nbrs.push_back(mp[i]);
            }
            else
                nbrs.push_back(dfs(i, mp));
        }
        newNode -> neighbors = nbrs;
        return newNode;
    }
    Node* cloneGraph(Node* node) {
       // use dfs
       if(node == NULL)
        return NULL;

        // single element
        if(node -> neighbors.size() == 0){
            Node *newNode = new Node(node -> val);
            return newNode;
        }
        
        unordered_map<Node*, Node*> mp;
        return dfs(node, mp);
    }
};


int main(){


    return 0;
}