#include<iostream>
#include<queue>
using namespace std;

/*
    https://en.cppreference.com/w/cpp/container/priority_queue
*/

int main(){
    // create max-heap
    priority_queue<int> pq;

    // insertion
    pq.push(10);
    pq.push(20);
    pq.push(30);
    pq.push(40);
    pq.push(50);
    pq.push(60);
    pq.push(70);
    pq.push(80);

    cout << "Top element of Heap: " << pq.top() << endl;
    pq.pop();

    cout << "Top element of Heap: " << pq.top() << endl;

    cout << "Top element of Heap: " << pq.size() << endl;

    if(pq.empty())
        cout << "Empty" << endl;
    else
        cout << "Not empty!" << endl;

    return 0;
}