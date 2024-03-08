#include<iostream>
#include<queue>
using namespace std;


// Problem || Leetcode : 933
/*
    -> You have a RecentCounter class which counts the number of recent requests within a certain time frame.
    -> Implement the RecentCounter class:
        - RecentCounter() Initializes the counter with zero recent requests.
        - int ping(int t) Adds a new request at time t, where t represents some time in milliseconds, and returns the number of requests that has happened in the past 3000 milliseconds (including the new request). 
        - Specifically, return the number of requests that have happened in the inclusive range [t - 3000, t].
        - It is guaranteed that every call to ping uses a strictly larger value of t than the previous call.
*/


// Solution
class RecentCounter {
public:
    queue<int> q;

    RecentCounter() {
        
    }
    
    int ping(int t) {
        while(!q.empty() && t - q.front() > 3000)
            q.pop();
        q.push(t);

        return q.size();
    }
};


int main(){

    return 0;
}