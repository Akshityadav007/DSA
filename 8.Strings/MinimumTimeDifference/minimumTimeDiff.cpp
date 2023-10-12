#include<iostream>
#include<limits.h>
using namespace std;

// Problem  || Leetcode : 539
// # Couldn't solve this, although attempted it - later had to watch video and solve this.
/*
    -> Given a list of 24-hour clock time points in "HH:MM" format.
    -> Return the minimum minutes difference between any two time-points in the list.
*/

// Solution
/*
    -> First convert all time in hours
    -> Sort the array (because minimum will be achieved by difference of adjacent time)
    -> Get the minimum of the difference.

    -> There are two types of differences:
        - Moving in minor - segment
        - Moving in major - segment
    -> But which is the minor segment ?
    
    -> Basically issue comes with day and night
        - We can consider day after night or night after day
        - Both are valid, but which is the minimum consideration ?

    -> The trick is we need to check the first and last element's time difference too at the last to check for anticlock wise time difference.
    -> Why do we check only for first and last elements? 
        - Because as we've sorted the time, all other elements are already consecutive and monotonically increasing. So, the clockwise direction time is the minimum time in these cases. 
        - Only the first and last time have the possiblity of anticlockwise movement to be minimum
    
*/

// convert time in minutes
vector<int> getTimeInMins(vector<string> &st){
    vector<int> res;
    for(int i = 0;i < st.size();i++){
        string time = st[i];                                // time at 'i'
        int hours = stoi(time.substr(0,2));          
        int minutes = stoi(time.substr(3,2));
        int totalMinutes = (hours * 60) + minutes;          // convert time in minutes
        res.push_back(totalMinutes);
    }
    return res;
}

// get the minimum difference among them
int getMin(vector<int> &time){
    int minimumDifference = INT_MAX;
    int n = time.size();

    // get the minimum time difference
    for(int i = 1;i < n;i++)
        minimumDifference = min(minimumDifference, time[i] - time[i - 1]);

    // we also need to get the round about difference i.e. anti clockwise time difference between first and last element of the array
    int antiClockTime = 24 * 60 - time[n - 1];
    minimumDifference = min(minimumDifference, antiClockTime + time[0]);
    return minimumDifference;
}

int findMinDifference(vector<string> &s){
    // get time in minutes
    vector<int> time = getTimeInMins(s);              // shallow copy
    sort(time.begin(),time.end());                    // sort the time

    int minDiff = getMin(time);                           // get the min diff

    return minDiff;
}

int main(){
    vector<string> v;
    v.push_back("12:35");
    v.push_back("00:10");

    cout << "The minimum time difference is: " << findMinDifference(v) << endl;

    return 0;
}
