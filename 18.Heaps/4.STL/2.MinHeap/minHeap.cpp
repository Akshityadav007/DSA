#include<iostream>
#include<queue>
using namespace std;

/*
    https://en.cppreference.com/w/cpp/container/priority_queue
*/

int main(){
    // min heap
    priority_queue<int, vector<int>, greater<int> > pq;                         // params : <type_of_data, which type of container to be used to store data, comparator>

    // insertion
    pq.push(100);
    pq.push(90);
    pq.push(70);
    pq.push(80);
    pq.push(95);

    
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