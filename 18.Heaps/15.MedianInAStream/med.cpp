#include<iostream>
#include<queue>
using namespace std;


// Problem || Leetcode : 295
/*
    -> The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.
        - For example, for arr = [2,3,4], the median is 3.
        - For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
    -> Implement the MedianFinder class:
        - MedianFinder() initializes the MedianFinder object.
        - void addNum(int num) adds the integer num from the data stream to the data structure.
        - double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.
*/


// Solution
/*
    # Method
        -> Median is only solved for a sorted list.
        -> So we need a sorted list.
        -> But for every number we can't sort it i.e. time complexty of - O(n(nlogn)).

        -> We use max-heap and min-heap.
        -> Create max-heap and min-heap in such manner:
            - start to mid   = max-heap
            - mid + 1 to end = min-heap
            - To make sure this happens take care while insertion, that (absolute difference of their size is 0 or 1).
        -> 3 case :
            1) max-heap.size = min-heap.size           -> avg(max.top, min.top)
            2) max-heap.size = min-heap.size + 1       -> max.top
            3) max-heap.size = max-heap.size + 1       -> min.top
        
        -> Insertion:
            1) max-heap.size == min-Heap.size
                i) number > median
                    min-heap.push(number)
                ii) number < median
                    max-heap(number)
            2) max-heap.size = min-Heap.size + 1
                i) number > median
                    min-heap.push(number)
                ii) number < median
                     max-heap.push(number)
                     
            3) min-heap.size = max-Heap.size + 1
                i) number > median
                    max-heap.push(number)
                ii) number < median
                     min-heap.push(number)                     
*/



class MedianFinder {
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
    }
    
    double findMedian() {
        
    }
};


// Babbar solved
// (try to solve this using switch case)
void solveForMedian(double median,priority_queue<int> maxi,priority_queue<int, vector<int>, greater<int> > &mini, int element){

    if(maxi.size() == mini.size()){
        if(element > median){
            mini.push(element);
            median = mini.top();
        }
        else{
            maxi.push(element);
            median = maxi.top();
        }
    }
    else if(maxi.size() == mini.size() + 1){
        if(element > median){
            mini.push(element);
        }
        else{
            int maxTop = maxi.top();
            maxi.pop();
            mini.push(maxTop);
            maxi.push(element);
        }
        median = (mini.top() + maxi.top())/ 2.0;
    }
    else if(mini.size() == maxi.size() + 1){
        if(element > median){
            int minTop = mini.top();
            mini.pop();
            maxi.push(minTop);
            mini.push(element);
        }
        else{
            maxi.push(element);
        }
        median = (mini.top() + maxi.top())/ 2.0;
    }
}

int main(){
    int arr[] = {12, 10, 8, 4, 2, 3, 15};
    int n = 7;
    double median = 0;
    priority_queue<int> maxi;
    priority_queue<int, vector<int>, greater<int> > mini;

    for(int i = 0;i < 7; i++){
        int element = arr[i];
        solveForMedian(median, maxi, mini, element);
        cout << "Median found: " << median << endl;
    }
    return 0;
}