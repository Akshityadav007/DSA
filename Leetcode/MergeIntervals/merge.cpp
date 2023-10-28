#include<iostream>
using namespace std;

// Problem || Leetcode : 56

/*
    -> Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, 
    -> and return an array of the non-overlapping intervals that cover all the intervals in the input.
*/

// Solution
/*
    -> 1) Sort the array using custom comparator (according to the 'start' of every interval).
    -> 2) Take two pointers - start and end.
    -> 3) Start a loop for the array, insert the non overlapping intervals straight a way and merge the overlapping ones before inserting.
        - How do we merge?
        - We check if the current interval's 'start' is smaller than 'end' pointer interval's 'end', if yes, this is overlapping array we move to the next element.
        - If not, we found a non overlapping interval, we insert start and end pointer's interval's start and end.
    
    
    # Check the code for more understanding! Wrote this solution description in hurry!
*/

static bool myComp(vector<int> a, vector<int> b){
    return a[0] < b[0];         // sorting on the basis of first element - 'start'
}

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    // sort the array using custom comparator
    sort(intervals.begin(), intervals.end(), myComp);

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

int main(){

    return 0;
}