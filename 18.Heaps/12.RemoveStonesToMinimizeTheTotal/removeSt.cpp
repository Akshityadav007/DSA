#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;

// Problem || Leetcode : 1962
/*
    -> You are given a 0-indexed integer array piles, where piles[i] represents the number of stones in the ith pile, and an integer k.
    -> You should apply the following operation exactly k times:
        - Choose any piles[i] and remove floor(piles[i] / 2) stones from it.
    -> Notice that you can apply the operation on the same pile more than once.
    -> Return the minimum possible total number of stones remaining after applying the k operations.
    -> floor(x) is the greatest integer that is smaller than or equal to x (i.e., rounds x down).
*/

// Solution
/*
    # Greedy based approach
     -> Use max heap to store stones (it will contain maximum number at top).
     -> Keep removing top element / 2 'k' times.
*/

int minStoneSum(vector<int>& piles, int k) {
    priority_queue<int> maxHeap;

    for(int i = 0;i < piles.size(); i++)
        maxHeap.push(piles[i]);
    
    while(k--){
        int topElement = maxHeap.top();
        maxHeap.pop();

        topElement = topElement - floor(topElement / 2);

        maxHeap.push(topElement);
    }

    int sum = 0;
    while(!maxHeap.empty()){
        int topEle = maxHeap.top();
        sum += topEle;
        maxHeap.pop();
    }
    return sum;
}

int main(){

    return 0;
}