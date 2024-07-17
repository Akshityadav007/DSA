#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;


// Bridge in a graph
/*
    -> A bridge in a graph is an edge in a graph which if removed will lead to increase in no. of disconnected components.
    ->
                    1️⃣ --------- 0️⃣ ------------3️⃣
                    |             /               |
                    |           /                 |
                    |         /                   |
                    |       /                     |
                    |     /                       |
                    |   /                         |
                    2️⃣                           4️⃣

    -> We need to get that bridge.
*/

// Solution
/*
    -> Brute force approach won't work in this as removing one edge and then counting all the components will give TLE.
    -> Optimized approach isn't intuitive. We'll need to learn it only then we'll get intuition.

    -> We'll maintain two types of time for each node : 
        1) curr : tin (when we reached that node, then what was the time).
        2) low : low (minimum time to reach that node).


    -> Mark the tin/low for each node while traversing it.
    -> While backtracking if there comes node where there is a difference b/w low of current and previous node, then that means there is another place from where we can reach this node, hence that edge is not a bridge.
*/


// Problem || Leetcode : 1192
/*
    -> There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi.
    -> Any server can reach other servers directly or indirectly through the network.
    -> A critical connection is a connection that, if removed, will make some servers unable to reach some other server.
    -> Return all critical connections in the network in any order.
*/






int main(){


    return 0;
}