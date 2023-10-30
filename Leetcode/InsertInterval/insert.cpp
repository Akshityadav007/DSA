#include<iostream>
using namespace std;

// Problem || Leetcode : 57
/*
    -> You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti.
    -> You are also given an interval newInterval = [start, end] that represents the start and end of another interval.
    -> Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).
    -> Return intervals after the insertion.

*/

// Solution
/*
    -> It is really very simple if you know 'Leetcode 56'

*/

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    // to store answer
    vector< vector<int> > ans;
    // take two indices = start/end
    int start = 0;
    int end = 0;

    // traverse the array
    for(int i = 1;i < intervals.size();i++){
        // check if current interval's 'start' is greater than previous(end) interval's 'end' - non overlapping interval
        if(intervals[end][1] < intervals[i][0]){
            vector<int> v;                                     // temporary array
            v.push_back(intervals[start][0]);                 // insert start
            v.push_back(intervals[end][1]);                   // insert end
            ans.push_back(v);                       // insert the interval in answer

            start = i;            // update start to current interval's start
            end = i;              // reset end
        }
        // overlapping interval
        else{
            // if this is the greatest 'end' of all overlapping intervals
            if(intervals[i][1] >= intervals[end][1])
                end = i;                            // update end
        }
    }
    // what about the last element ?
    // start element is fixed, we only need to get the greatest of all ends.
    vector<int> v;
    v.push_back(intervals[start][0]);       // insert start
    v.push_back(intervals[end][1]);             // insert end
    ans.push_back(v);                                   // insert last interval

    return ans;
}

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // first we get the place to insert the interval
        int index = 0;                                      // to trace array
        while(index < intervals.size()){
            // check next interval's start
            if(intervals[index][0] > newInterval[0])
                break;
            index++;
        }

        // now we simply insert new interval at index
        intervals.insert(intervals.begin() + index, newInterval);

        // merge overlapping intervals (if any) using the algo we implemented in 'Leetcode 56'
        intervals = merge(intervals);

        return intervals;
    }

int main(){

    return 0;
}