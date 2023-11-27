#include<iostream>
#include<queue>
using namespace std;

// Problem || Coding Ninjas : Easy
/*
    -> You have been given a queue of integers.
    -> You need to rearrange the elements of the queue by interleaving the elements of the first half of the queue with the second half.
*/

// Solution
/*
    -> Break the queue into two parts.
    -> Start insertion in the queue from each of the queues simultaneously.
*/

void interLeaveQueue(queue < int > & q) {
    queue<int> first;       // storing first part of the queue

    int size = q.size();

    for(int i = 0;i < size / 2; i++){
        first.push(q.front());
        q.pop();
    }

    // merging the queue

    for(int i = 0;i < size / 2; i++){
        // insertion from first queue
        q.push(first.front());
        first.pop();

        // insertion from second half
        int temp = q.front();
        q.pop();
        q.push(temp);
    }
}

int main(){



    return 0;
}